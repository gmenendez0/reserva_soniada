#include "lista.h"
#include "animal.h"
#include "pasar_tiempo_controllers.h"

void pasar_el_tiempo(Lista<Animal*> &registro_de_animales){
    while(registro_de_animales.hay_siguiente_animal()){
        registro_de_animales.get_animal_actual()->pasar_el_tiempo();
        registro_de_animales.avanzar_al_siguiente_animal();
    }
    registro_de_animales.resetear_nodo_actual();
}