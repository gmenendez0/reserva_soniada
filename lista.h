#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

static const int PRIMERA_POSICION = 1;
const int UNA_POSICION = 1;
const int LISTA_VACIA = 0;
static const int ANIMAL_NO_ENCONTRADO = -1;

template <typename Tipo_de_animal>
class Lista{
    private:
        Nodo<Tipo_de_animal>* primer_nodo;
        int tope_nodos;
        Nodo<Tipo_de_animal>* nodo_actual;

    public:
        //Post Construye una lista vacia
        Lista(){
            primer_nodo = nullptr;
            nodo_actual = nullptr;
            tope_nodos = 0;
        }

        //Pre: Posicion debe ser mayor a 0 y menor o igual que (tope_nodos + 1). La primera posicion es 1!
        //Post: Da de alta un animal en la posicion que el usuario elijio
        void alta(Tipo_de_animal nuevo_animal, int posicion){
            Nodo<Tipo_de_animal>* nuevo_nodo = new Nodo<Tipo_de_animal>(nuevo_animal);

            if (posicion == PRIMERA_POSICION){
                nuevo_nodo->set_siguiente_nodo(primer_nodo);
                primer_nodo = nuevo_nodo;
                nodo_actual = primer_nodo;
            } else{
                Nodo<Tipo_de_animal>* anterior_nodo = get_nodo(posicion - UNA_POSICION);
                nuevo_nodo->set_siguiente_nodo(anterior_nodo->get_siguiente_nodo());
                anterior_nodo->set_siguiente_nodo(nuevo_nodo);
            }
            tope_nodos++;
        }

        //Pre Posicion debe ser mayor a 0 y menor o igual a tope_nodos
        //Post: Devuelve un puntero al animal que se encuentra en la posicion que el usuario elijio
        Tipo_de_animal consulta(int posicion){
            return (get_nodo(posicion)->get_animal());
        }

        //Pre: Debe recibir una posicion entre 1 y tope_nodos (incluyendo)
        //Post: Da de baja un animal en la posicion que el usuario elija y después lo devuelve
        void baja(int posicion){
            Nodo<Tipo_de_animal>* nodo_a_borrar;

            if (posicion == PRIMERA_POSICION){
                nodo_a_borrar = primer_nodo;
                primer_nodo = primer_nodo->get_siguiente_nodo();
                nodo_actual = primer_nodo;
            } else {
                Nodo<Tipo_de_animal>* anterior_nodo = get_nodo(posicion - UNA_POSICION);
                nodo_a_borrar = anterior_nodo->get_siguiente_nodo();
                anterior_nodo->set_siguiente_nodo(nodo_a_borrar->get_siguiente_nodo());
            }

            delete nodo_a_borrar->get_animal();
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

        //Post: Devuelve un puntero al animal a donde este apuntando nodo_actual
        Tipo_de_animal get_animal_actual(){
            Tipo_de_animal animal = nodo_actual->get_animal();
            return animal;
        }

        //Post: Mueve el nodo_actual al siguiente nodo
        void avanzar_al_siguiente_animal(){
            nodo_actual = nodo_actual->get_siguiente_nodo();
        }


        //Post: Apunta el puntero "nodo_actual" al mismo lugar que primer_nodo
        void resetear_nodo_actual(){
            nodo_actual = primer_nodo;
        }

        //Pre: Debe recibir el nombre de un animal y Tipo_de_animal debe ser de tipo Puntero si o si
        //Post: Devuelve un puntero al animal buscado o en caso de no existir, un puntero a nullptr
        Tipo_de_animal get_animal_buscado(std::string nombre_animal){
            Tipo_de_animal animal_buscado = nullptr;

            while(hay_siguiente_animal() && animal_buscado == nullptr){
                if(get_animal_actual()->get_nombre() == nombre_animal){
                    animal_buscado = get_animal_actual();
                }
                avanzar_al_siguiente_animal();
            }
            resetear_nodo_actual();

            return animal_buscado;
        }

        //Destrutor
        ~Lista(){
            while(!lista_esta_vacia()){
                baja(PRIMERA_POSICION);
            }
        }

    private:
        //Pre: Debe recibir una posicion entre 1 y tope_nodos (incluyendo)
        //Post:Devuelve un puntero al nodo que esté en la posicion que el usuario elijio
        Nodo<Tipo_de_animal>* get_nodo(int posicion){
            Nodo<Tipo_de_animal>* nodo_auxiliar = primer_nodo;
            for (int i = PRIMERA_POSICION; i < posicion; i++){
                nodo_auxiliar = nodo_auxiliar->get_siguiente_nodo();
            }

            return nodo_auxiliar;
        };

        //Devulve true en caso de que la lista este vacia, false en caso contrario
        bool lista_esta_vacia(){
            return (tope_nodos == LISTA_VACIA);
        }
};

#endif
