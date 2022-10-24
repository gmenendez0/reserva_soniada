#include ""
#include <iostream>

using namespace std;

Animal *ingresar_nombre(Lista<Animal*> &registro_de_animales){
	string nombre;
	
	cout << "Introduce el nombre del animal que deseas buscar: ";
	getline(cin, nombre);
	cout << endl;
	
	return registro_de_animales.get_animal_buscado(nombre);
}

void proceso_de_busqueda(Lista<Animal*> &registro_de_animales){
	Animal* animal_buscado = ingresar_nombre(registro_de_animales);
	
    while(animal_buscado == nullptr){
        cout << "ERROR, el animal buscado no existe en nuestro registro. Intenta de nuevo" << endl;
        animal_buscado = pedir_nombre(registro_de_animales);
    }
    
    cout << "A continuacion te va a aparecer las informaciones acerca del animal buscado." << endl;
    registro_de_animales.get_animal_actual()->presentar_animal();
}
