#include "lista.h"
#include "archivo_controllers.h"
#include "animal.h"

const int ERROR = -1;

int main(){
    Lista<Animal*> registro_de_animales;

    int resultado_lectura = abrir_archivo(registro_de_animales);
    if (resultado_lectura) return ERROR;

    registro_de_animales.consulta(3)->pasar_el_tiempo();
    registro_de_animales.consulta(3)->presentar_animal();
    registro_de_animales.consulta(3)->comer();
    registro_de_animales.consulta(3)->ducharse();
    registro_de_animales.consulta(3)->presentar_animal();

    return 0;
}
