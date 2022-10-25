#ifndef RESCATAR_ANIMAL_H
#define RESCATAR_ANIMAL_H
#include "animal.h"
#include "lista.h"

//Pre: Recibe la lista de animales
//Post: Pone en marcha las funciones para rescatar un animal. En caso de que el animal ya esté en la lista, el usuario deberá ingresar otro o volver al menú.
void rescatar_animal(Lista<Animal*> &registro_de_animales);

//Pre: Debe recibir todas las caracteristicas de un animal.
//Post: Revisa a que especie pertenece el nuevo animal y llama a la funcion correspondiente para crearlo
void revisar_especie(string nombre, int edad, string tamanio, char especie, string personalidad, Lista<Animal*> &registro_de_animales);

#endif
