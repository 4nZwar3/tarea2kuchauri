#include "receta.h"
#include "ingrediente.h"
#include <iostream>
void Receta::agregar_receta() {
	std::cout << "\t---Agregar receta---\n"
		 << "Inserte el nombre de su receta: ";
	std::cin >> nombre;
	std::cin.ignore();
	menu_ingredientes();
}
void Receta::mostrar_receta() {
	std::cout << "\nNombre: " << nombre
	     << "\nIngredientes:\n";
	for(int j(0); j < contador; ++j) {
		std::cout << "> ";
		switch (ingredientes[j].tipoDeUnidad()) {
			case U_GRAMO:
				std::cout << ingredientes[j].printGramos() << " gramos";
				break;
			case U_KILO:
				std::cout << ingredientes[j].printKilos() << " kilos";
				break;
			case U_MILILITRO:
	            std::cout << ingredientes[j].printMililitros() << " milimetros";
	            break;
	  		case U_LITRO:
	 			std::cout << ingredientes[j].printLitros() << " litros";
				break;
		}
		std::cout << " de " << ingredientes[j].printNombre() << std::endl;
	}
	std::cout << "Pasos:\n";
	for(int j(0); j < contadorPasos; ++j) {
		std::cout << "> " << pasos[j] << std::endl;
	}
}
void Receta::menu_ingredientes() {
    int opc;
    do {
        std::cout << "\t--Ingredientes--\n"
             << OPC_REGISTRAR << ") Agregar ingrediente\n"
             << OPC_CONSULTAR << ") Consultar ingredientes\n"
             << OPC_BUSCAR << ") Buscar ingrediente\n"
             << OPC_REGISTRAR_PASO << ") Agregar paso\n"
             << OPC_CONSULTAR_PASO << ") Conultar pasos\n"
             << OPC_SALIR << ") Salir\n"
             << SELECT;
        std::cin >> opc;
        std::cin.ignore();

        switch (opc) {
        	case OPC_REGISTRAR:
            	if (contador < MAX_INGREDIENTES) {
                	ingredientes[contador].registrarIngrediente();
                	++contador;
            	}
            	else {
                	std::cout << "No hay más espacios disponibles" << std::endl;
            	}
            	break;
        	case OPC_CONSULTAR:
            	if (contador > 0) {
                	mostrarIngredientes();
            	}
            	else {
                	std::cout << "No hay ingredientes registrados" << std::endl;
            	}
            	break;
        	case OPC_BUSCAR:
            	if (contador > 0) {
                	buscarIngrediente();
            	}
            	else {
                	std::cout << "No hay ingredientes registrados" << std::endl;
            	}
            	break;
        	case OPC_SALIR:
            	std::cout << "Regresando al menu anterior" << std::endl;
            	break;
            case OPC_REGISTRAR_PASO:
            	std::cout << "Inserte paso: ";
            	std::cin >> pasos[contadorPasos];
            	std::cin.ignore();
            	++contadorPasos;
            	break;
            case OPC_CONSULTAR_PASO:
            	for(int j(0); j < contadorPasos; ++j) {
            		std::cout << " > " << pasos[j] << std::endl;
            	}
            	break;
        	default:
            	std::cout << "Opción no válida..." << std::endl;
            	break;
        }
    }
    while(opc != OPC_SALIR);
}
void Receta::mostrarIngredientes() {
    std::cout << "\t--Consultar Ingredientes--" << std::endl;
    for (int i(0); i < contador; ++i) {
        ingredientes[i].consultarIngrediente();
    }
}
void Receta::buscarIngrediente() {
    std::string patron;
    int cont(0);
    std::cout << "\t--Buscar Ingrediente\t--\n"
        << "Nombre: ";
    getline(std::cin, patron);
    for (int i(0); i < contador; ++i) {
        /*
         *  patron: ez
         *  ingredientes[i].nombre = Aceite
         * 0123456
         * Aceite
         *       ez
         */
        if (ingredientes[i].printNombre().find(patron) < ingredientes[i].printNombre().size()) {
            ingredientes[i].consultarIngrediente();
            ++cont;
        }
    }
    std::cout << "Se encontraron " << cont << " ingredientes" << std::endl;
}
std::string Receta::printNombre() {
    return nombre;
}