#include "rescatar_animal.h"

using namespace std;

const int INGRESAR_NOMBRE = 1;
const int VOLVER_AL_MENU = 2;
const int EDAD_MINIMA = 0;
const int EDAD_MAXIMA = 100;
const string ERROR = "Error. Animal listado.";

//Pre: Recibe la personalidad a validar.
//Post: Devuelve true si la personalidad es válida y false en caso contrario.
bool personalidad_es_valida(string personalidad){
    return((personalidad == "dormilon") || (personalidad == "jugueton") || (personalidad == "sociable") || (personalidad == "travieso"));
}

//Pre: Recibe la personalidad ingresada.
//Post: Si la personalidad ingresada es inválida, la solicita nuevamente.
void chequear_personalidad(string &personalidad){
    while(!personalidad_es_valida(personalidad)){
        cout << "La personalidad ingresada es inválida. Ingrese la personalidad del animal: ";
        getline(cin >> ws, personalidad);
    }
}

string ingresar_personalidad(){
    string personalidad;

    cout << "\nIngrese la personalidad del animal: ";
    getline(cin >> ws, personalidad);
    
    return personalidad;
}

//Pre: -
//Post: Imprime un menú con las posibles personalidades del animal.
void presentar_personalidades(){
    cout << "\nPersonalidad:\n" << endl
         << "dormilon" << endl
         << "jugueton" << endl
         << "sociable" << endl
         << "travieso" << endl;
}

//Pre: -
//Post: Solicita la personalidad del animal.
string pedir_personalidad(){
    string personalidad;

    presentar_personalidades();
    
    personalidad = ingresar_personalidad();

    chequear_personalidad(personalidad);
    
    return personalidad;
}

//Pre: Recibe la especie a validar.
//Post: Devuelve true si la especie es válida y false en caso contrario.
bool especie_es_valida(string especie){
    return((especie == "perro") || (especie == "gato") || (especie == "caballo") || (especie == "roedor") || (especie == "conejo") || (especie == "erizo") || (especie == "lagartija"));
}

//Pre: Recibe la especie ingresada.
//Post: Si la especie ingresada es inválida, la solicita nuevamente.
void chequear_especie(string &especie){
    while(!especie_es_valida(especie)){
        cout << "La especie ingresada es inválida. Ingrese la especie del animal: ";
        getline(cin >> ws, especie);
    }
}

string ingresar_especie(){
    string especie;

    cout << "\nIngrese la especie del animal: ";
    getline(cin >> ws, especie);

    return especie;
}

//Pre: -
//Post: Imprime un menú con las posibles especies del animal.
void presentar_especies(){
    cout << "\nEspecies:\n" << endl
         << "perro" << endl
         << "gato" << endl
         << "caballo" << endl
         << "roedor" << endl
         << "conejo" << endl
         << "erizo" << endl
         << "lagartija" << endl;
}

//Pre: -
//Post: Solicita la especie del animal.
char pedir_especie(){
    string especie;
    char inicial;

    presentar_especies();

    especie = ingresar_especie();

    chequear_especie(especie);
    inicial = toupper(especie[0]);
    if(especie == "conejo"){inicial = 'O';}

    return inicial;
}

//Pre: Recibe el tamaño a validar.
//Post: Devuelve true si el tamaño es válido y false en caso contrario.
bool tamanio_es_valido(string tamanio){
    return((tamanio == "diminuto") || (tamanio == "pequeño") || (tamanio == "mediano") || (tamanio == "grande") || (tamanio == "gigante"));
}

//Pre: Recibe el tamaño ingresado.
//Post: Si el tamaño ingresado es inválido, lo solicita nuevamente.
void chequear_tamanio(string &tamanio){
    while(!tamanio_es_valido(tamanio)){
        cout << "El tamaño ingresado es inválido. Ingrese el tamaño del animal: ";
        getline(cin >> ws, tamanio);
    }
}

string ingresar_tamanio(){
    string tamanio;
    
    cout << "\nIngrese el tamaño del animal: ";
    getline(cin >> ws, tamanio);

    return tamanio;
}

//Pre: -
//Post: Imprime un menú con los posibles tamaños del animal.
void presentar_tamanios(){
    cout << "\nTamaños:\n" << endl
         << "diminuto" << endl
         << "pequeño" << endl
         << "mediano" << endl
         << "grande" << endl
         << "gigante" << endl;
}

//Pre: -
//Post: Solicita el tamaño del animal.
string pedir_tamanio(){
    string tamanio;
    
    presentar_tamanios();
    
    tamanio = ingresar_tamanio();
    
    chequear_tamanio(tamanio);
    
    return tamanio;
}

//Pre: Recibe la edad a validar.
//Post: Devuelve true si la edad es válida y false en caso contrario.
bool edad_es_valida(int edad){
    return((edad >= EDAD_MINIMA) && (edad <= EDAD_MAXIMA));
}

//Pre: Recibe la edad ingresada.
//Post: Si la edad ingresada es inválida, la solicita nuevamente.
void chequear_edad(int &edad){
    while(!edad_es_valida(edad)){
        cout << "La edad ingresada es inválida. Ingrese la edad del animal (Entre 0 y 100 años): ";
        cin >> edad;
    }
}

//Pre: -
//Post: Solicita la edad del animal.
int pedir_edad(){
    int edad;
    
    cout << "Ingrese la edad del animal (Entre 0 y 100 años): ";
    cin >> edad;
    chequear_edad(edad);
    
    return edad;
}

//Pre: Pide los datos del animal.
//Post: Añade al animal a la lista.
void pedir_datos(Lista<Animal*> &registro_de_animales, string nombre){
    int edad = pedir_edad();
    string tamanio = pedir_tamanio();
    char especie = pedir_especie();
    string personalidad = pedir_personalidad();
    
    revisar_especie(nombre, edad, tamanio, especie, personalidad, registro_de_animales);
}

//Pre: Recibe la opción a validar.
//Post Chequea si la opción es válida. En caso de no serla, vuelve a pedir una opción al usuario.
void validar_opcion(int &opcion){
    while((opcion != INGRESAR_NOMBRE) && (opcion != VOLVER_AL_MENU)){
        cout << "La opción ingresada es inválida. Ingrese una opcion: ";
        cin >> opcion;
        cout << endl;
    }
}

//Pre: El animal ingresado por el usuario está en la lista.
//Post: Imprime un menú con las opciones de ingresar el nombre de otro animal o volver al menú.
int mostrar_menu(){
    int opcion;
    
    cout << "El animal ingresado ya está registrado.\n¿Que desea hacer?" << endl << endl;
    cout << "1. Ingresar el nombre de otro animal a rescatar." << endl;
    cout << "2. Volver al menú principal" << endl << endl;
    cout << "Ingrese una opción: ";
    cin >> opcion;
    cout << endl;
    validar_opcion(opcion);
    
    return opcion;
}

void opciones(Lista<Animal*> &registro_de_animales){
    int opcion = mostrar_menu();

    switch(opcion){
        case INGRESAR_NOMBRE:
            rescatar_animal(registro_de_animales);
            break;
        
        case VOLVER_AL_MENU:
            break;
    }
}

//Pre: Recibe la lista de animales.
//Post: Pide al usuario un nombre para verificar si el animal está en la lista. Devuelve un null en caso de no encontrarlo.
string pedir_nombre(Lista<Animal*> &registro_de_animales){
    string nombre;
    
    cout << "Ingrese el nombre del animal a rescatar: ";
    getline(cin >> ws, nombre);
    cout << endl;
    if(registro_de_animales.get_animal_buscado(nombre) != nullptr){nombre = ERROR;}
    
    return nombre;
}

//Pre: Recibe la lista de animales
//Post: Pone en marcha las funciones para rescatar un animal. En caso de que el animal ya esté en la lista, el usuario deberá ingresar otro o volver al menú.
void rescatar_animal(Lista<Animal*> &registro_de_animales){
    string nombre = pedir_nombre(registro_de_animales);
    
    if(nombre != ERROR){
        pedir_datos(registro_de_animales, nombre);
        cout << endl << "Animal listado correctamente." << endl << endl;
    } else{
        opciones(registro_de_animales);
    }
}
