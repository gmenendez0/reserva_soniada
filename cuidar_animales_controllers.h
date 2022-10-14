#ifndef CUIDAR_ANIMALES_CONTROLLERS_H
#define CUIDAR_ANIMALES_CONTROLLERS_H

#include "animal.h"
#include "lista.h"

//Pre Debe recibir la lista de animales
//Post Pone en marcha las debidas funciones para cumplir el cuidado del / de los animales elegidos por el usuario
void cuidar_animales(Lista<Animal*> &registro_de_animales);

#endif
