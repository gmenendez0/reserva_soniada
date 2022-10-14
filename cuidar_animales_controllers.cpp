#include "cuidar_animales_controllers.h"

using std::cout;
using std::cin;
using std::endl;

const int ELEGIR_ANIMAL = 1;
const int ALIMENTAR_A_TODOS = 2;
const int BANIAR_A_TODOS = 3;
const int ALIMENTAR = 1;
const int VOLVER = 3;
const int REGRESAR_AL_INICIO = 4;
const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;
const int NO_ENCONTRADO = -1;
const int BANIAR = 2;

//Pre Debe recibir una respuesta y dos valores para usar como límites en la comparacion
//Post Devuelve true en caso de que la respuesta sea válida (que esté entre los límites inclusive), false caso contrario
bool respuesta_valida(int respuesta, int limite_minimo, int limite_maximo){
    return (respuesta >= limite_minimo && respuesta <= limite_maximo);
}

//Pre Debe recibir una respuesta
//Post Chequea si la respuesta es válida, en caso de no serla vuelve a pedir una respuesta al usuario
void chequear_entrada_secundaria(int &respuesta){
    while(!respuesta_valida(respuesta, ELEGIR_ANIMAL, REGRESAR_AL_INICIO)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> respuesta;
        cout << endl;
    }
}

//Pre -
//Post Imprime por consola el menu de acciones de cuidado de animal
int mostrar_menu_secundario(){
    int respuesta;

    cout << endl;
    cout << "Usted ha elegido la opcion de cuidar animales. Seleccione que tipo de cuidado desea aplicar:" << endl;
    cout << "1. Elegir animal" << endl;
    cout << "2. Alimentar a todos" << endl;
    cout << "3. Bañar a todos" << endl;
    cout << "4. Regresar a inicio" << endl;
    cout << "Ingrese una opcion: ";
    cin >> respuesta;
    cout << endl;

    chequear_entrada_secundaria(respuesta);

    return respuesta;
}

//Post imprime aviso de que los animales fueron duchados
void imprimir_mensaje_de_ducha(){
    cout << "Todos los animales estan limpios!" << endl;
    cout << endl;
}

//Post Imprime aviso de que los animales fueron alimentados
void imprimir_mensaje_de_comida(){
    cout << "Todos los animales estan alimentados!" << endl;
    cout << endl;
}

//Pre Debe recibir la lista de animales
//Post Baña a todos los animales
void baniar_a_todos(Lista<Animal*> &registro_de_animales){
    while(registro_de_animales.hay_siguiente_animal()){
        registro_de_animales.get_siguiente_animal()->ducharse();
    }
    registro_de_animales.resetear_nodo_actual();

    imprimir_mensaje_de_ducha();
}

//Pre Debe recibir la lista de animales
//Post Alimenta a todos los animales
void alimentar_a_todos(Lista<Animal*> &registro_de_animales){
    while(registro_de_animales.hay_siguiente_animal()){
        registro_de_animales.get_siguiente_animal()->comer();
    }
    registro_de_animales.resetear_nodo_actual();

    imprimir_mensaje_de_comida();
}

//Pre Debe recibir la lista de animales
//Post Pide al usuario que ingrese un nombre para verificar si ese animal existe en la lista
int pedir_nombre(Lista<Animal*> &registro_de_animales){
    string nombre;

    cout << "Ingrese el nombre del animal que desea cuidar: ";
    std::getline(cin >> std::ws, nombre);
    cout << endl;

    int posicion_animal_elegido = registro_de_animales.get_posicion_animal(nombre);

    return posicion_animal_elegido;
}

//Pre Debe recibir la lista de animales
//Post Presenta a todos los animales de la lista
void presentar_animales(Lista<Animal*> &registro_de_animales){
    while(registro_de_animales.hay_siguiente_animal()){
        registro_de_animales.get_siguiente_animal()->presentar_animal();
    }
    registro_de_animales.resetear_nodo_actual();
}

//Pre Debe una accion
//Post Chequea que la accion sea válida, en caso de no serlo vuelve a pedir una accion al usuario
void chequear_accion_terciaria(int &accion_a_realizar){
    while(!respuesta_valida(accion_a_realizar, ALIMENTAR, VOLVER)){
        cout << "Usted a ingresado un valor invalido. Porfavor, vuelva a intentar:  ";
        cin.clear();
        cin.ignore(CANTIDAD_DE_CARACTERES_A_IGNORAR, '\n');
        cin >> accion_a_realizar;
        cout << endl;
    }
}

//Post Pide al usuario una accion a realizar y la devuelve
int pedir_accion(){
    int accion_a_realizar;

    cout << endl;
    cout << "Que accion desea realizar?" << endl;
    cout << "1. Alimentar" << endl;
    cout << "2. Bañar" << endl;
    cout << "3. Regresar a inicio" << endl;
    cout << "Ingrese una opcion: ";
    cin >> accion_a_realizar;
    cout << endl;

    chequear_accion_terciaria(accion_a_realizar);

    return accion_a_realizar;
}

//Pre Debe recibir la lista de animales, la posicion del animal a cuidar en la lista y la accion a realizar con el animal
//Post Realiza la accion elegida con el animal elegido
void realizar_accion_pedida(Lista <Animal*> &registro_de_animales, int posicion_animal_elegido, int accion_a_realizar){
    if(accion_a_realizar == ALIMENTAR){
        registro_de_animales.consulta(posicion_animal_elegido)->comer();
    } else if(accion_a_realizar == BANIAR){
        registro_de_animales.consulta(posicion_animal_elegido)->ducharse();
    }
}

//Pre Debe recibir la lista de animales
//Post Pone en marchas las debidas funciones para aplicar cuidados individuales a un animal
void elegir_animal(Lista<Animal*> &registro_de_animales){
    presentar_animales(registro_de_animales);

    int posicion_animal_elegido = pedir_nombre(registro_de_animales);
    while(posicion_animal_elegido == NO_ENCONTRADO){
        cout << "El nombre ingresado no corresponde a ningun animal registrado. Porfavor, vuelva a intentar." << endl;
        posicion_animal_elegido = pedir_nombre(registro_de_animales);
    }

    int accion_a_realizar = pedir_accion();
    realizar_accion_pedida(registro_de_animales, posicion_animal_elegido, accion_a_realizar);
}

void cuidar_animales(Lista<Animal*> &registro_de_animales){
    int respuesta = mostrar_menu_secundario();

    switch(respuesta){
        case ELEGIR_ANIMAL:
            elegir_animal(registro_de_animales);
            break;

        case ALIMENTAR_A_TODOS:
            alimentar_a_todos(registro_de_animales);
            break;

        case BANIAR_A_TODOS:
            baniar_a_todos(registro_de_animales);
            break;

        case REGRESAR_AL_INICIO:
            break;
    }
}


