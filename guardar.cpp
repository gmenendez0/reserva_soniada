#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

#include "guardar.h"

void verificar_archivo_modo_escritura(ofstream &archivo){
	archivo.open("animales.csv", ios::out);
	if (archivo.fail()){
		cout << "No se pudo abrir el Archivo";
		exit(1);
	}
}

void guardarDatosArchivos(Lista<Animal*> &registro_de_animales){
	ofstream archivo;
	string linea_libro_adicional, nombre, edad, tamanio, especie, personalidad;
	
	verificar_archivo_modo_escritura(archivo);
	
	while(registro_de_animales.hay_siguiente_animal()){
		nombre = registro_de_animales.get_animal_actual()->get_nombre();
		edad = registro_de_animales.get_animal_actual()->get_edad();
		tamanio = registro_de_animales.get_animal_actual()->get_tamanio();
		especie = registro_de_animales.get_animal_actual()->get_especie();
		personalidad = registro_de_animales.get_animal_actual()->get_personalidad();
		
		linea_libro_adicional = nombre + "," + edad + "," + tamanio + "," + especie + "," + personalidad;
		archivo << linea_libro_adicional;
		
        registro_de_animales.avanzar_al_siguiente_animal();
    }
    registro_de_animales.resetear_nodo_actual();
}
