#include <iostream>
#include "animal.h"

const int HIGENE_INICIAL = 100;
const int HAMBRE_INICIAL = 0;
const char PERRO = 'P';
const char GATO = 'G';
const char CONEJO = 'O';
const char CABALLO = 'C';
const char ERIZO = 'E';
const char LAGARTIJA = 'L';
const char ROEDOR = 'R';

using std::cout;
using std::string;
using std::endl;

Animal::Animal(std::string nombre, int edad, std::string tamanio, char especie, std::string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    this->higene_actual = HIGENE_INICIAL;
    this->hambre_actual = HAMBRE_INICIAL;
}

void Animal::presentar_animal(){
    cout << "Animal: " << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "Tamaño: " << this->tamanio << endl;
    cout << "Especie: " << get_especie_completa() << endl;
    cout << "Personalidad: " << this->personalidad << endl;
    cout << "Higiene: " << this->higene_actual << endl;
    cout << "Hambre: " << this->hambre_actual << endl;
    cout << endl;
}

string Animal::get_especie_completa(){
    string especie_completa;

    switch(this->especie){
        case PERRO:
            especie_completa = "Perro";
            break;

        case GATO:
            especie_completa = "Gato";
            break;

        case CONEJO:
            especie_completa = "Conejo";
            break;

        case ROEDOR:
            especie_completa = "Roedor";
            break;

        case ERIZO:
            especie_completa = "Erizo";
            break;

        case LAGARTIJA:
            especie_completa = "Lagartija";
            break;

        case CABALLO:
            especie_completa = "Caballo";
            break;
    }

    return especie_completa;
}

void Animal::ducharse(){
    cout << "La especie de " << nombre << ", " << get_especie_completa() << " no require baño!"<< endl;
}

string Animal::get_nombre(){
    return this->nombre;
}

int Animal::get_edad(){
    return this->edad;
}

string Animal::get_tamanio(){
    return this->tamanio;
}

char Animal::get_especie(){
    return this->especie;
}

string Animal::get_personalidad(){
    return this->personalidad;
}
