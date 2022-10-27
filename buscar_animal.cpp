#include <iostream>
#include "animal.h"
#include "lista.h"

using namespace std;

//pre: Debe recibir un nombre y la lista de animales
//post: Exige al usuario que ingrese un nombre de un animal existente
void comprobar_animal_buscado(string &nombre, Lista<Animal*> &registro_de_animales){
    while(registro_de_animales.get_animal_buscado(nombre) == nullptr){
        cout << "El animal ingresado no existe en nuestro registro. Intente de nuevo: ";
        getline(cin >> std::ws, nombre);
    }
    //falta agregar una opcion de salida
}

//pre: Debe existir una lista de animales
//post: Devuelve un puntero al animal buscado por el usuario
Animal* ingresar_nombre(Lista<Animal*> &registro_de_animales){
    string nombre;

    cout << "Introduzca el nombre del animal que desea buscar: ";
    getline(cin >> std::ws, nombre);
    cout << endl;

    comprobar_animal_buscado(nombre, registro_de_animales);

    return registro_de_animales.get_animal_buscado(nombre);
}

void proceso_de_busqueda(Lista<Animal*> &registro_de_animales){
    if(registro_de_animales.get_tope_nodos() == LISTA_VACIA){
        cout << "No hay animales en el registro. Por favor, ingrese un animal primero para luego poder buscarlo." << endl << endl;
        return;
    }

	Animal* animal_buscado = ingresar_nombre(registro_de_animales);

    cout << endl;
    animal_buscado->presentar_animal();
}
