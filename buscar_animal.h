#ifndef __BUSCAR_ANIMAL_H__
#define __BUSCAR_ANIMAL_H__

//pre: Debe existir una cierta lista
//post: Devuelve un puntero al animal buscado por el usuario o a null si el animal no se encontro
Animal *ingresar_nombre(Lista<Animal*> &registro_de_animales);


//pre: Debe existir una cierta lista
//post: Busca y devuelve el animal buscado con todas sus caracteristicas
void proceso_de_busqueda(Lista<Animal*> &registro_de_animales);

#endif //__BUSCAR_ANIMAL_H__
