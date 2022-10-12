#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

const int PRIMERA_POSICION = 1;
const int UNA_POSICION = 1;
const int LISTA_VACIA = 0;

template <typename Tipo_de_animal>
class Lista{
    private:
        //? Debe resolverse el error al declarar objetos de tipo Nodo.
        Nodo* primer_nodo;
        int tope_nodos;
        Nodo* nodo_actual;

    public:
        //Post Construye una lista vacia
        Lista(){
            primer_nodo = nullptr;
            nodo_actual = nullptr;
            tope_nodos = 0;
        }

        //Pre: Posicion debe ser mayor a 0 y menor o igual que (tope_nodos + 1). La primera posicion es 1!
        //Post: Da de alta un animal en la posicion que el usuario elijio
        void alta(Nodo<Tipo_de_animal> nuevo_animal, int posicion){
            Nodo* nuevo_nodo = new Nodo(nuevo_animal);
            if (posicion == PRIMERA_POSICION){
                nuevo_nodo->set_siguiente_nodo(primer_nodo);
                primer_nodo = nuevo_nodo;
            } else{
                Nodo* anterior_nodo = get_nodo(posicion - UNA_POSICION);
                nuevo_nodo->set_siguiente_nodo(anterior_nodo->get_siguiente_nodo());
                anterior_nodo->set_siguiente_nodo(nuevo_nodo);
            }
            tope_nodos++;
        }

        //Pre Posicion debe ser mayor a 0 y menor o igual a tope_nodos
        //Post: Devuelve el animal que se encuentra en la posicion que el usuario elijio
        Tipo_de_animal consulta(int posicion){
            return (get_nodo(posicion)->get_animal());
        }

        //Pre: Debe recibir una posicion entre 1 y tope_nodos (incluyendo)
        //Post: Da de baja un animal en la posicion que el usuario elija y después lo devuelve
        void baja(int posicion){
            Nodo* nodo_a_borrar;

            if (posicion == PRIMERA_POSICION){
                nodo_a_borrar = primer_nodo;
                primer_nodo = primer_nodo->get_siguiente_nodo();
            } else {
                Nodo* anterior_nodo = get_nodo(posicion - UNA_POSICION);
                nodo_a_borrar = anterior_nodo->get_siguiente_nodo();
                anterior_nodo->set_siguiente_nodo(nodo_a_borrar->get_siguiente_nodo());
            }

            delete nodo_a_borrar;
            tope_nodos--;
        }

        //Post: Devuelve la cantidad de nodos que tiene la lista
        int get_tope_nodos(){
            return tope_nodos;
        }

        //Devulve false si la lista esta vacia o si llege al final de la lista, true en caso contrario
        bool hay_siguiente_animal(){
            return (nodo_actual != nullptr);
        }

        //Post: Devuelve el animal y mueve el cursor
        Nodo<Tipo_de_animal> get_siguiente_animal(){
            Nodo<Tipo_de_animal> animal = nodo_actual->get_animal();
            nodo_actual = nodo_actual->get_siguiente_nodo();
            return animal;
        }

        //Post: Apunta el puntero "nodo_actuaL" al primer nodo de la lista
        void resetear_nodo_actual(){
            nodo_actual = primer_nodo;
        }

        //Destrutor
        ~Lista(){
            while(tope_nodos != LISTA_VACIA){
                baja(PRIMERA_POSICION);
            }
        }

    private:
        //Pre: Debe recibir una posicion entre 1 y tope_nodos (incluyendo)
        //Post:Devuelve un puntero al nodo que esté en la posicion que el usuario elijio
        Nodo* get_nodo(int posicion){
            Nodo* nodo_auxiliar = primer_nodo;
            for (int i = PRIMERA_POSICION; i < posicion; i++){
                nodo_auxiliar = nodo_auxiliar->get_siguiente_nodo();
            }

            return nodo_auxiliar;
        };
};

#endif
