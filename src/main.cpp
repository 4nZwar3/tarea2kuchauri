#include <iostream>
#include "receta.h"
using namespace std;
enum Menu {
    SALIR = 0,
    AGREGAR_RECETA,
    CONSULTAR_RECETAS,
    BUSCAR_RECETA
};
Receta recetas[MAX];
int cont_recetas = 0;
void menu();
void consultar_recetas();
void buscar_receta();
int main() {
    menu();
    return 0;
}
void menu() {
	int opt;
	do {
		cout << "\t----Recetas----\n"
		     << AGREGAR_RECETA << ") Agregar receta\n"
		     << CONSULTAR_RECETAS << ") Consultar recetas\n"
		     << BUSCAR_RECETA << ") Buscar receta\n"
		     << SALIR << ") Salir\n"
		     << SELECT;
		cin >> opt;
		cin.ignore();
		switch (opt) {
			case AGREGAR_RECETA:
				recetas[cont_recetas].agregar_receta();
                ++cont_recetas;
				break;
			case CONSULTAR_RECETAS:
				consultar_recetas();
				break;
			case BUSCAR_RECETA:
			    buscar_receta();
				break;
			case SALIR:
				cout << "Y no' fuimo'\n";
				break;
			default:
				cout << "Opción inválida\n";
				break;
		}
	} while (opt != SALIR);
}
void consultar_recetas() {
	for(int i(0); i < cont_recetas; ++i) {
		recetas[i].mostrar_receta();
	}
}
void buscar_receta() {
    string busca;
	cout << "Inserte el nombre de la receta a buscar: ";
	getline(cin, busca);
	for(int i(0); i < cont_recetas; ++i) {
		if(recetas[i].printNombre().find(busca) < recetas[i].printNombre().size()) {
			recetas[i].mostrar_receta();
			return;
		}
	}
	cout << "No se encontro un resultado.\n";
}