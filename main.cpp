#include "lista.h"
#include "archivo_controllers.h"
#include "animal.h"

const int ERROR = -1;

int main(){
    Lista<Animal*> registro_de_animales;

    int resultado_lectura = abrir_archivo(registro_de_animales);
    if (resultado_lectura) return ERROR;

    //cout << registro_de_animales.consulta(1);
    std::cout << registro_de_animales.get_tope_nodos() << std::endl;


    return 0;
}
