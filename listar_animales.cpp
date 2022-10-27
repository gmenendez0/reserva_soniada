#include "listar_animales.h"

void listar_animales(Lista<Animal*> &registro_de_animales){
    if(registro_de_animales.get_tope_nodos() == LISTA_VACIA){
        std::cout << "No hay animales registrados." << std::endl << std::endl;
        return;
    }

    while(registro_de_animales.hay_siguiente_animal()){
        registro_de_animales.get_animal_actual()->presentar_animal();
        registro_de_animales.avanzar_al_siguiente_animal();
    }
    registro_de_animales.resetear_nodo_actual();
}