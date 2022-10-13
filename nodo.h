#ifndef NODO_H
#define NODO_H
#include <iostream>

template <typename  Tipo_de_animal>
class Nodo{
    private:
        Tipo_de_animal animal;
        Nodo* siguiente_nodo;

    public:
        Nodo(Tipo_de_animal nuevo_animal){
            animal = nuevo_animal;
            siguiente_nodo = nullptr;
        }

        Nodo* get_siguiente_nodo(){
            return siguiente_nodo;
        }

        void set_siguiente_nodo(Nodo* puntero_a_siguiente_nodo){
            siguiente_nodo = puntero_a_siguiente_nodo;
        }

        Tipo_de_animal get_animal(){
            return animal;
        }
};

#endif
