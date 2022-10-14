#include "animal.h"
#include "lista.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int MINIMO_DE_METROS_REQUERIDOS = 1;
const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;

//Pre Debe recibir una respuesta
//Devuelve true en caso de que la respuesta tenga un valor válido o false en caso contrario
bool respuesta_invalida(int respuesta){
    return respuesta < MINIMO_DE_METROS_REQUERIDOS;
}

//Pre Debe recibir una respuesta
//Post Chequea que la respuesta sea válida y vuelve a pedirla en caso de que no lo sea
void chequear_espacio_disponible(int &respuesta){
    while(respuesta_invalida(respuesta)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
    }
}

//Post pregunta al usuario por el espacio disponible para el nuevo anima y devuelve la respuesta
int consultar_espacio_disponible(){
    int respuesta;
    cout << "Porfavor, ingrese el espacio disponible (en m2) en donde vaya a vivir el animal: ";
    cin >> respuesta;

    chequear_espacio_disponible(respuesta);

    return respuesta;
}

//Pre Debe recibir una lista de animales y una cantidad de espacio disponible positiva
//Post Muestra todos los animales adoptables segun la cantidad de espacio disponible
void mostrar_animales_adoptables(Lista <Animal*> &registro_de_animales, int espacio_disponible){
    cout << "Animales adoptables segun su espacio disponible:" << endl;

    while(registro_de_animales.hay_siguiente_animal()){
        if(registro_de_animales.get_animal_actual()->get_espacio_minimo_requerido() <= espacio_disponible){
            registro_de_animales.get_animal_actual()->presentar_animal();
        }
        registro_de_animales.avanzar_al_siguiente_animal();
    }
    registro_de_animales.resetear_nodo_actual();
}

void adoptar_animal(Lista<Animal*> &registro_de_animales){
    int espacio_disponible = consultar_espacio_disponible();
    mostrar_animales_adoptables(registro_de_animales, espacio_disponible);
}