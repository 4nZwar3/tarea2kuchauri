#ifndef RECETARIO_H
#define RECETARIO_H
#include "receta.h"
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
#endif