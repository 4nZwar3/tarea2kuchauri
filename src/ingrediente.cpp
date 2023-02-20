#include "ingrediente.h"
Ingrediente::Ingrediente() {
}
void Ingrediente::registrarIngrediente() {
    cout << "\t-Registrar Ingrediente-\n"
         << "Nombre: ";
    getline(cin, nombre);
    do {
        cout << "En qué unidad se registrará el ingrediente?\n"
             << U_GRAMO << ") Gramos\n"
             << U_KILO << ") Kilos\n"
             << U_MILILITRO << ") Mililitro\n"
             << U_LITRO << ") Litro\n"
             << SELECT;
        cin >> tipoUnidad;
    }
    while(tipoUnidad < U_GRAMO || tipoUnidad > U_LITRO);
    switch (tipoUnidad) {
    	case U_GRAMO:
        	cout << "Gramos: ";
        	cin >> cantidad.gramos;
        	break;
    	case U_KILO:
        	cout << "Kilos: ";
        	cin >> cantidad.kilos;
        	break;
    	case U_MILILITRO:
        	cout << "Mililitros: ";
        	cin >> cantidad.mililitros;
        	break;
    	case U_LITRO:
        	cout << "Litros: ";
        	cin >> cantidad.litros;
        	break;
    	default:
        	break;
    }
}
void Ingrediente::consultarIngrediente() {
    cout << "Nombre: " << nombre << endl
         << "Cantidad: ";
    switch (tipoUnidad) {
    	case U_GRAMO:
        	cout << cantidad.gramos << " gramos" << endl;
        	break;
    	case U_KILO:
        	cout << cantidad.kilos << " kilos" << endl;
        	break;
    	case U_MILILITRO:
        	cout << cantidad.mililitros << " mililitros" << endl;
        	break;
    	case U_LITRO:
        	cout << cantidad.litros << " litros" << endl;
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
string Ingrediente::printNombre() {
    return nombre;
}