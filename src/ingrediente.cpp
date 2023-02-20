#include "ingrediente.h"
#include <iostream>
Ingrediente::Ingrediente() {
}
void Ingrediente::registrarIngrediente() {
    std::cout << "\t-Registrar Ingrediente-\n"
         << "Nombre: ";
    getline(std::cin, nombre);
    do {
        std::cout << "En qué unidad se registrará el ingrediente?\n"
             << U_GRAMO << ") Gramos\n"
             << U_KILO << ") Kilos\n"
             << U_MILILITRO << ") Mililitro\n"
             << U_LITRO << ") Litro\n"
             << SELECT;
        std::cin >> tipoUnidad;
    }
    while(tipoUnidad < U_GRAMO || tipoUnidad > U_LITRO);
    switch (tipoUnidad) {
    	case U_GRAMO:
        	std::cout << "Gramos: ";
        	std::cin >> cantidad.gramos;
        	break;
    	case U_KILO:
        	std::cout << "Kilos: ";
        	std::cin >> cantidad.kilos;
        	break;
    	case U_MILILITRO:
        	std::cout << "Mililitros: ";
        	std::cin >> cantidad.mililitros;
        	break;
    	case U_LITRO:
        	std::cout << "Litros: ";
        	std::cin >> cantidad.litros;
        	break;
    	default:
        	break;
    }
}
void Ingrediente::consultarIngrediente() {
    std::cout << "Nombre: " << nombre << std::endl
         << "Cantidad: ";
    switch (tipoUnidad) {
    	case U_GRAMO:
        	std::cout << cantidad.gramos << " gramos" << std::endl;
        	break;
    	case U_KILO:
        	std::cout << cantidad.kilos << " kilos" << std::endl;
        	break;
    	case U_MILILITRO:
        	std::cout << cantidad.mililitros << " mililitros" << std::endl;
        	break;
    	case U_LITRO:
        	std::cout << cantidad.litros << " litros" << std::endl;
        	break;
    	default:
        	break;
    }
}
int Ingrediente::tipoDeUnidad() {
    return tipoUnidad;
}
int Ingrediente::printGramos() {
    return cantidad.gramos;
}
float Ingrediente::printKilos() {
    return cantidad.kilos;
}
int Ingrediente::printMililitros() {
    return cantidad.mililitros;
}
float Ingrediente::printLitros() {
    return cantidad.litros;
}
std::string Ingrediente::printNombre() {
    return nombre;
}