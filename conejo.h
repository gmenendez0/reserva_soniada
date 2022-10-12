#ifndef TP2_CONEJO_H
#define TP2_CONEJO_H
#include "animal.h"
#include <string>

class Conejo: public Animal{
    private:
        std::string tipo_de_comida;

    public:
        //Pre: Debe recibir el nombre, la edad, el tamanio, la especie y la personalidad del animal para poder enviarlos al constructor de la clase padre.
        //Post: Llama al constructor de la clase padre y luego crea un perro seteando sus atributos.
        Conejo(std::string nombre, int edad, std::string tamanio, char especie, std::string personalidad);

        //Pre: -
        //Post: Si es necesario, baña al animal y en caso de no serlo, lo aclara con un mensaje por terminal.
        void ducharse();

        //Pre: -
        //Post: Restaura el hambre del animal al valor inicial e imprime por pantalla su nombre y lo que comio
        void comer();

        //Pre: -
        //Post: Pone en marcha los metodos ensuciarse y aumentar_hambre.
        void pasar_el_tiempo();

    private:
        //Pre: -
        //Post: Devuelve true si higene_actual = 0, false en caso contrario.
        bool esta_sucio();

        //Pre: -
        //Post: Devuelve true si hambre_actual = 100, false en caso contrario.
        bool esta_hambriento();

        //Pre: -
        //Post: Decrece la higene del animal el valor correspondiente segun la personalidad del mismo y si ya esta sucio o no.
        void ensuciarse();

        //Pre: -
        //Post: Aumenta el hambre del animal el valor correspondiente segun la personalidad del mismo y si ya esta hambriento o no.
        void aumentar_hambre();
};


#endif
