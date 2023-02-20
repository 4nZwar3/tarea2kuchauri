#include <iostream>
#include "receta.h"
using namespace std;
enum Menu {
    SALIR,
    AGREGAR_RECETA,
    CONSULTAR_RECETAS,
    BUSCAR_RECETA
};
class Recetario {
    public:
        Recetario();
        void menu();
        void consultar_recetas();
        void buscar_receta();
    private:
        Receta recetas[MAX];
        int cont_recetas;
};