#ifndef RESCATAR_ANIMAL_H
#define RESCATAR_ANIMAL_H

#include "animal.h"
#include "lista.h"

//Pre: Recibe la lista de animales
//Post: Pone en marcha las funciones para rescatar un animal. En caso de que el animal ya esté en la lista, el usuario deberá ingresar otro o volver al menú.
void rescatar_animal(Lista<Animal*> &registro_de_animales);

#endif
