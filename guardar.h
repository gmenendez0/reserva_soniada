#ifndef __GUARDAR_H__
#define __GUARDAR_H__

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

#include "lista.h"
#include "animal.h"

//pre: -
//post: abre el archivo, en el caso de no existir, manda un mensaje de error
void verificar_archivo_modo_escritura(ofstream &archivo);

//pre: Debe existir el archivo
//post: Imprime en el archivo todos los datos de la lista dinamica
void guardarDatosArchivos(Lista<Animal*> &registro_de_animales);

#endif //__GUARDAR_H__
