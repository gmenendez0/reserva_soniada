#ifndef TP2_ANIMAL_H
#define TP2_ANIMAL_H
#include <string>

using std::string;

class Animal{
    protected:
        string nombre;
        int edad;
        string tamanio;
        char especie;
        string personalidad;
        int higene_actual;
        int hambre_actual;

    protected:
        //Pre: Debe recibir el nombre, la edad, el tamanio, la especie y la personalidad del animal.
        //Post: Inicializa el animal con los valores recibidos.
        Animal(string nombre, int edad, string tamanio, char especie, string personalidad);

        //Pre: -
        //Post: Imprime en pantalla una presentacion de todos los atributos del animal.
        void presentar_animal();

    private:
        //Pre: -
        //Post: Devuelve la especie del animal en forma completa.
        string get_especie_completa();
};

#endif
