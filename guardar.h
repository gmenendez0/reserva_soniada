#ifndef __GUARDAR_H__
#define __GUARDAR_H__

#include "lista.h"
#include "animal.h"

//pre: Debe existir el archivo "animales.csv"
//post: Sobreescribe el archivo "animales.csv" con los datos de la lista
void guardar_cambios(Lista<Animal*> &registro_de_animales);

#endif //__GUARDAR_H__
