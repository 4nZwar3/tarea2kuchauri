#ifndef INGREDIENTE_H
#define INGREDIENTE_H
#include <string>
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
        std::string printNombre();
    private:
        std::string nombre;
        Unidad cantidad;
        int tipoUnidad;
};
#endif