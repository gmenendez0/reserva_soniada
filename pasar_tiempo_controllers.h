#ifndef TP2_PASAR_TIEMPO_CONTROLLERS_H
#define TP2_PASAR_TIEMPO_CONTROLLERS_H

#include "lista.h"
#include "animal.h"

//Pre Debe recibir la lista de animales
//Post Pasa el tiempo a todos los animales, aumentando su hambre y su higene (en caso de que corresponda).
void pasar_el_tiempo(Lista<Animal*> &registro_de_animales);

#endif
