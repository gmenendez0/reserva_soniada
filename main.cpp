#include "lista.h"
#include "archivo_controllers.h"
#include "animal.h"
#include "perro.h"

const int ERROR = -1;

int main(){
    Lista<Animal*> registro_de_animales;

    int resultado_lectura = abrir_archivo(registro_de_animales);
    if (resultado_lectura) return ERROR;

    //TODO Ya sea usando lo de abajo o virtualizando metodos en Animal, se debe solucionar el tema de que no se puede acceder a los metodos de las clases hijas de animal
    static_cast<Perro*>((registro_de_animales.consulta(1)))->ducharse();

    return 0;
}
