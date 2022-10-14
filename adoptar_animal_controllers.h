#ifndef ADOPTAR_ANIMAL_CONTROLLERS_H
#define ADOPTAR_ANIMAL_CONTROLLERS_H

#include "animal.h"
#include "lista.h"

//Pre Debe recibir el registro de animales
//Post Pone en marcha todas las funciones para que el usuario pueda adoptar un animal. En caso de adoptarlo, lo quita de la lista de animales
void adoptar_animal(Lista<Animal*> &registro_de_animales);

#endif
