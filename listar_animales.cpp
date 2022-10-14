#include "listar_animales.h"

void listar_animales(Lista<Animal*> &registro_de_animales){
    while(registro_de_animales.hay_siguiente_animal()){
        registro_de_animales.get_animal_actual()->presentar_animal();
        registro_de_animales.avanzar_al_siguiente_animal();
    }
    registro_de_animales.resetear_nodo_actual();
}