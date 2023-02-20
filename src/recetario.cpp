#include "recetario.h"
#include <iostream>
Recetario::Recetario() {
}
void Recetario::menu() {
	int opt;
	do {
		std::cout << "\t----Recetas----\n"
		     << AGREGAR_RECETA << ") Agregar receta\n"
		     << CONSULTAR_RECETAS << ") Consultar recetas\n"
		     << BUSCAR_RECETA << ") Buscar receta\n"
		     << SALIR << ") Salir\n"
		     << SELECT;
		std::cin >> opt;
		std::cin.ignore();
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
				std::cout << "Y no' fuimo'\n";
				break;
			default:
				std::cout << "Opción inválida\n";
				break;
		}
	} while (opt != SALIR);
}
void Recetario::consultar_recetas() {
	for(int i(0); i < cont_recetas; ++i) {
		recetas[i].mostrar_receta();
	}
}
void Recetario::buscar_receta() {
    std::string busca;
	std::cout << "Inserte el nombre de la receta a buscar: ";
	getline(std::cin, busca);
	for(int i(0); i < cont_recetas; ++i) {
		if(recetas[i].printNombre().find(busca) < recetas[i].printNombre().size()) {
			recetas[i].mostrar_receta();
			return;
		}
	}
	std::cout << "No se encontro un resultado.\n";
}