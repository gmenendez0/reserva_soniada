#ifndef ARCHIVO_CONTROLLERS_H
#define ARCHIVO_CONTROLLERS_H

#include "animal.h"
#include "lista.h"

//Pre Debe recibir una lista de animales vacia y debe haber CREADO un archivo "animales.csv" en el directorio del programa para poder ser leido
//Post Devuelve 0 si pudo abrir el archivo y 1 si no pudo
int abrir_archivo(Lista<Animal*> &registro_de_animales);

//Pre: Debe recibir todas las caracteristicas de un animal.
//Post: Revisa a que especie pertenece el nuevo animal y llama a la funcion correspondiente para crearlo
void revisar_especie(string nombre, int edad, string tamanio, char especie, string personalidad, Lista<Animal*> &registro_de_animales);

#endif
