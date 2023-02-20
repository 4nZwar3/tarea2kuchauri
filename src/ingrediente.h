#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include <iostream>
using namespace std;
const char SELECT[]("Selecciona una opción: ");
union Unidad { //Unidad de medida para un ingrediente
    int gramos;
    float kilos;
    int mililitros;
    float litros;
};
enum TipoUnidad {
    U_GRAMO = 1,
    U_KILO,
    U_MILILITRO,
    U_LITRO
};
class Ingrediente {
    public:
        Ingrediente();
        void registrarIngrediente();
        void consultarIngrediente();
        int tipoDeUnidad();
        int printGramos();
        float printKilos();
        int printMililitros();
        float printLitros();
        string printNombre();
    private:
        string nombre;
        Unidad cantidad;
        int tipoUnidad;
};
#endif