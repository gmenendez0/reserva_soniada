#ifndef __BUSCAR_ANIMAL_H__
#define __BUSCAR_ANIMAL_H__

#include "lista.h"
#include "animal.h"

//Pre: Debe existir una lista de animales
//post: Busca y devuelve el animal buscado con todas sus caracteristicas en caso de existir minimo un animal. En caso de no haberlo, lo avisa y no hace nada
void proceso_de_busqueda(Lista<Animal*> &registro_de_animales);

#endif //__BUSCAR_ANIMAL_H__
