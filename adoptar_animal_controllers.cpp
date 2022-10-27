#include "animal.h"
#include "lista.h"

struct Animales_adoptables{
    Animal* animal;
    int posicion_en_lista;
};

using std::string;
using std::cout;
using std::cin;
using std::endl;

const int MINIMO_DE_METROS_REQUERIDOS = 1;
const int CANTIDAD_DE_CARACTERES_A_IGNORAR = 100;
const int AUMENTO_DE_VECTOR = 20;
const int MARGEN_DE_PRECAUCION = 3;
const int MAXIMO_DE_ANIMALES_ADOPTABLES_INICIAL = 20;
const int NO_REALIZADA = -1;
const int REALIZADA = 1;
const int NINGUN_ANIMAL = 0;

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

//Pre Debe recibir un vector de animales adoptables junto a su tope y su maximo
//Post Aumenta el tamaño maximo del vector
void aumentar_maximo_vector(Animales_adoptables* &animales_adoptables, int &tope_animales_adoptables, int &maximo_animales_adoptables){
    maximo_animales_adoptables += AUMENTO_DE_VECTOR;
    Animales_adoptables* animales_adoptables_aux = new Animales_adoptables[maximo_animales_adoptables];

    for(int i = 0; i < tope_animales_adoptables; i++){
        animales_adoptables_aux[i] = animales_adoptables[i];
    }

    delete [] animales_adoptables;
    animales_adoptables = animales_adoptables_aux;
}

//Pre Debe recibir una lista de animales, una cantidad de espacio disponible positiva, un vector de animales adoptables junto a su tope y su maximo
//Post Inicializa el vector de animales adoptables
void inicializar_animales_adoptables(Lista <Animal*> &registro_de_animales, int espacio_disponible, Animales_adoptables* &animales_adoptables, int &tope_animales_adoptables, int
&maximo_de_animales_adoptables){
    int i = PRIMERA_POSICION;

    while(registro_de_animales.hay_siguiente_animal()){
        if(registro_de_animales.get_animal_actual()->get_espacio_minimo_requerido() <= espacio_disponible){
            animales_adoptables[tope_animales_adoptables].animal = registro_de_animales.get_animal_actual();
            animales_adoptables[tope_animales_adoptables].posicion_en_lista = i;
            tope_animales_adoptables++;

            if(tope_animales_adoptables == maximo_de_animales_adoptables - MARGEN_DE_PRECAUCION) aumentar_maximo_vector(animales_adoptables, tope_animales_adoptables, maximo_de_animales_adoptables);
        }
        registro_de_animales.avanzar_al_siguiente_animal();
        i++;
    }
    registro_de_animales.resetear_nodo_actual();
}

//Pre Debe recibir un vector de animales adoptables inicializado
//Post Muestra todos los animales adoptables segun la cantidad de espacio disponible
void mostrar_animales_adoptables(Animales_adoptables* animales_adoptables, int tope_animales_adoptables){
    cout << "Animales adoptables segun el espacio ingresado:" << endl;
    cout << endl;

    for(int i = 0; i < tope_animales_adoptables; i++){
        animales_adoptables[i].animal->presentar_animal();
    }
}

//Pre Debe recibir un vector de animales adoptables inicializado junto a su tope, el nombre del animal a eliminar y el registro de animales
//Post: Devuelve -1 en caso de que la baja no haya sido realizada y 1 en caso contrario
int realizar_baja(Animales_adoptables* animales_adoptables, int tope_animales_adoptables, string nombre_animal, Lista <Animal*> &registro_de_animales){
    int baja = NO_REALIZADA;
    int i = 0;

    while(i < tope_animales_adoptables && baja == NO_REALIZADA){
        if(animales_adoptables[i].animal->get_nombre() == nombre_animal){
            registro_de_animales.baja(animales_adoptables[i].posicion_en_lista);
            cout << "Adopcion exitosa!" << endl << endl;
            baja = REALIZADA;
        }
        i++;
    }
    return baja;
}

//Pre Debe recibir un vector de animales adoptables inicializado junto a su tope y la lista de animales
//Post Pide al usuario que ingrese el nombre del animal que desea adoptar y luego pone en marcha la funcion para realizar la baja (en caso de no querer cancelar adopcion)
void pedir_animal(Animales_adoptables* animales_adoptables, int tope_animales_adoptables, Lista <Animal*> &registro_de_animales){
    string respuesta;
    cout << "Porfavor, ingrese el nombre del animal que desea adoptar o 'cancelar adopcion' para abortar la adopcion: ";
    getline(cin >> std::ws, respuesta);

    if(respuesta == "cancelar adopcion"){
        cout << "La adopcion ha sido cancelada" << endl << endl;
        return;
    }

    int resultado_baja = realizar_baja(animales_adoptables, tope_animales_adoptables, respuesta, registro_de_animales);
    if(resultado_baja == NO_REALIZADA){
        cout << "El animal ingresado no se encuentra en la lista de animales adoptables." << endl;
        pedir_animal(animales_adoptables, tope_animales_adoptables, registro_de_animales);
    }
}

void adoptar_animal(Lista<Animal*> &registro_de_animales){
    if(registro_de_animales.get_tope_nodos() == LISTA_VACIA){
        cout << "No hay animales para adoptar en la reserva." << endl << endl;
        return;
    }

    int maximo_de_animales_adoptables = MAXIMO_DE_ANIMALES_ADOPTABLES_INICIAL;
    Animales_adoptables* animales_adoptables = new Animales_adoptables[maximo_de_animales_adoptables];
    int tope_animales_adoptables = 0;

    int espacio_disponible = consultar_espacio_disponible();
    inicializar_animales_adoptables(registro_de_animales, espacio_disponible, animales_adoptables, tope_animales_adoptables, maximo_de_animales_adoptables);
    mostrar_animales_adoptables(animales_adoptables, tope_animales_adoptables);

    if(tope_animales_adoptables > NINGUN_ANIMAL) {
        pedir_animal(animales_adoptables, tope_animales_adoptables, registro_de_animales);
    } else {
        cout << "No hay animales adoptables." << endl << endl;
    }

    delete [] animales_adoptables;

    cout << registro_de_animales.get_tope_nodos();
}