#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "guardar.h"
#include "animal.h"
#include "lista.h"

const int ERROR = 1;

//pre: -
//post: abre el archivo, en el caso de no existir, manda un mensaje de error
void abrir_archivo(std::ofstream &archivo){
	archivo.open("animales.csv", std::ios::out);

	if (archivo.fail()){
        std::cout << "Los cambios no pudieron ser guardados porque el archivo no pudo ser abierto" << std::endl;
		exit(ERROR);
	}
}

void sobreescribir_archivo(std::ofstream &archivo, Lista<Animal*> &registro_de_animales){
    string animal, nombre, edad, tamanio, especie, personalidad;

    while(registro_de_animales.hay_siguiente_animal()){
        nombre = registro_de_animales.get_animal_actual()->get_nombre();
        edad = std::to_string(registro_de_animales.get_animal_actual()->get_edad());
        tamanio = registro_de_animales.get_animal_actual()->get_tamanio();
        especie = registro_de_animales.get_animal_actual()->get_especie();
        personalidad = registro_de_animales.get_animal_actual()->get_personalidad();

        animal = nombre + "," + edad + "," + tamanio + "," + especie + "," + personalidad + "\n";
        archivo << animal;

        registro_de_animales.avanzar_al_siguiente_animal();
    }
    registro_de_animales.resetear_nodo_actual();
}

void guardar_cambios(Lista<Animal*> &registro_de_animales){
    std::ofstream archivo;
    abrir_archivo(archivo);
    sobreescribir_archivo(archivo, registro_de_animales);
}
