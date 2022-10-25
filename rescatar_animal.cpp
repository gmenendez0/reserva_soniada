#include "rescatar_animal.h"
using namespace std;
const int INGRESAR_NOMBRE = 1;
const int VOLVER_AL_MENU = 2;
const int EDAD_MINIMA = 0;
const int EDAD_MAXIMA = 100;

//Pre: Recibe la personalidad a validar.
//Post: Devuelve true si la personalidad es válida y false en caso contrario.
bool validar_personalidad(string personalidad){
    bool personalidad_valida = false;
    if((personalidad == "dormilon") || (personalidad == "jugueton") || (personalidad == "sociable") || (personalidad == "travieso")){
        personalidad_valida = true;
    }
    return personalidad_valida;
}

//Pre: -
//Post: Solicita la personalidad del animal.
string pedir_personalidad(){
    string personalidad;
    cout << "\nPersonalidad:\n" << endl
         << "dormilon" << endl
         << "jugueton" << endl
         << "sociable" << endl
         << "travieso" << endl
         << "\nIngrese la personalidad del animal: ";
    fflush(stdin);
    getline(cin >> ws, personalidad);
    while(!validar_personalidad(personalidad)){
        cout << "La personalidad ingresada es inválida. Ingrese la personalidad del animal: ";
        fflush(stdin);
        getline(cin >> ws, personalidad);
    }
    return personalidad;
}

//Pre: Recibe la especie a validar.
//Post: Devuelve true si la especie es válida y false en caso contrario.
bool validar_especie(string especie){
    bool especie_valida = false;
    if((especie == "perro") || (especie == "gato") || (especie == "caballo") || (especie == "roedor") || (especie == "conejo") || (especie == "erizo") || (especie == "lagartija")){
        especie_valida = true;
    }
    return especie_valida;
}

//Pre: -
//Post: Solicita la especie del animal.
char pedir_especie(){
    string especie;
    char inicial;
    cout << "\nEspecies:\n" << endl
         << "perro" << endl
         << "gato" << endl
         << "caballo" << endl
         << "roedor" << endl
         << "conejo" << endl
         << "erizo" << endl
         << "lagartija" << endl
         << "\nIngrese la especie del animal: ";
    fflush(stdin);
    getline(cin >> ws, especie);
    while(!validar_especie(especie)){
        cout << "La especie ingresada es inválida. Ingrese la especie del animal: ";
        fflush(stdin);
        getline(cin >> ws, especie);
    }
    inicial = toupper(especie[0]);
    if(especie == "conejo"){inicial = 'O';}
    return inicial;
}

//Pre: Recibe el tamaño a validar.
//Post: Devuelve true si el tamaño es válido y false en caso contrario.
bool validar_tamanio(string tamanio){
    bool tamanio_valido = false;
    if((tamanio == "diminuto") || (tamanio == "pequeño") || (tamanio == "mediano") || (tamanio == "grande") || (tamanio == "gigante")){
        tamanio_valido = true;
    }
    return tamanio_valido;
}

//Pre: -
//Post: Solicita el tamaño del animal.
string pedir_tamanio(){
    string tamanio;
    cout << "\nTamaños:\n" << endl
         << "diminuto" << endl
         << "pequeño" << endl
         << "mediano" << endl
         << "grande" << endl
         << "gigante" << endl
         << "\nIngrese el tamaño del animal: ";
    fflush(stdin);
    getline(cin >> ws, tamanio);
    while(!validar_tamanio(tamanio)){
        cout << "El tamaño ingresado es inválido. Ingrese el tamaño del animal: ";
        fflush(stdin);
        getline(cin >> ws, tamanio);
    }
    return tamanio;
}

//Pre: Recibe la edad a validar.
//Post: Devuelve true si la edad es válida y false en caso contrario.
bool validar_edad(string edad){
    bool edad_valida = false;
    int i = 0;
    while(edad_valida && (i < edad.length())){
        edad_valida = isdigit(edad[i]);
        i ++;
    }
    if((stol(edad) >= EDAD_MINIMA) && (stol(edad) <= EDAD_MAXIMA)){
        edad_valida = true;
    }
    return edad_valida;
}

//Pre: -
//Post: Solicita la edad del animal.
int pedir_edad(){
    string edad;
    cout << "Ingrese la edad del animal (Entre 0 y 100 años): ";
    fflush(stdin);
    cin >> edad;
    while(!validar_edad(edad)){
        cout << "La edad ingresada es inválida. Ingrese la edad del animal (Entre 0 y 100 años): ";
        fflush(stdin);
        cin >> edad;
    }
    return stol(edad);
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
    cout << "El animal ingresado ya está registrado.\n¿Que desea hacer?" << endl;
    cout << "1. Ingresar el nombre de otro animal a rescatar." << endl;
    cout << "2. Volver al menú principal" << endl;
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
//Post Pide al usuario un nombre para verificar si el animal está en la lista. Devuelve un null en caso de no encontrarlo.
string pedir_nombre(Lista<Animal*> &registro_de_animales){
    string nombre;
    cout << "Ingrese el nombre del animal a rescatar: ";
    fflush(stdin);
    getline(cin >> ws, nombre);
    cout << endl;
    if(registro_de_animales.get_animal_buscado(nombre) != nullptr){nombre = "Error. Animal listado.";}
    return nombre;
}

//Pre: Recibe la lista de animales
//Post: Pone en marcha las funciones para rescatar un animal. En caso de que el animal ya esté en la lista, el usuario deberá ingresar otro o volver al menú.
void rescatar_animal(Lista<Animal*> &registro_de_animales){
    string nombre = pedir_nombre(registro_de_animales);
    if(nombre != "Error. Animal listado."){
        pedir_datos(registro_de_animales, nombre);
        cout << endl << "Animal listado correctamente." << endl << endl;
    }
    else{
        opciones(registro_de_animales);
    }
}
