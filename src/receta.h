#ifndef RECETA_H
#define RECETA_H
#include "ingrediente.h"
#include <iostream>
using namespace std;
const int MAX_INGREDIENTES(10);
const int MAX(30);
enum Opciones {
    OPC_SALIR,
    OPC_REGISTRAR,
    OPC_CONSULTAR,
    OPC_BUSCAR,
    OPC_REGISTRAR_PASO,
    OPC_CONSULTAR_PASO
};
class Receta {
    public:
        void agregar_receta();
        void mostrar_receta();
        void consultar_recetas();
        void buscar_receta();
        void menu_ingredientes();
        void mostrarIngredientes();
        void buscarIngrediente();
        string printNombre();
    private:
        string nombre;
        Ingrediente ingredientes[MAX_INGREDIENTES];
        int contador;
        int contadorPasos;
        string pasos[MAX];
};
#endif