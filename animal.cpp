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
    std::cout << "Animal: " << std::endl;
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Edad: " << this->edad << std::endl;
    std::cout << "Tamaño: " << this->tamanio << std::endl;
    std::cout << "Especie: " << get_especie_completa() << std::endl;
    std::cout << "Personalidad: " << this->personalidad << std::endl;
    std::cout << "Higiene: " << this->higene_actual << std::endl;
    std::cout << "Hambre: " << this->hambre_actual << std::endl;
    std::cout << std::endl;
}

std::string Animal::get_especie_completa(){
    std::string especie_completa;

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
