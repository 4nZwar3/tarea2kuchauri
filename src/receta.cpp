#include "receta.h"
#include "ingrediente.h"
void Receta::agregar_receta() {
	cout << "\t---Agregar receta---\n"
		 << "Inserte el nombre de su receta: ";
	cin >> nombre;
	cin.ignore();
	menu_ingredientes();
}
void Receta::mostrar_receta() {
	cout << "\nNombre: " << nombre
	     << "\nIngredientes:\n";
	for(int j(0); j < contador; ++j) {
		cout << "> ";
		switch (ingredientes[j].tipoDeUnidad()) {
			case U_GRAMO:
				cout << ingredientes[j].printGramos() << " gramos";
				break;
			case U_KILO:
				cout << ingredientes[j].printKilos() << " kilos";
				break;
			case U_MILILITRO:
	            cout << ingredientes[j].printMililitros() << " milimetros";
	            break;
	  		case U_LITRO:
	 			cout << ingredientes[j].printLitros() << " litros";
				break;
		}
		cout << " de " << ingredientes[j].printNombre() << endl;
	}
	cout << "Pasos:\n";
	for(int j(0); j < contadorPasos; ++j) {
		cout << "> " << pasos[j] << endl;
	}
}
void Receta::menu_ingredientes() {
    int opc;
    do {
        cout << "\t--Ingredientes--\n"
             << OPC_REGISTRAR << ") Agregar ingrediente\n"
             << OPC_CONSULTAR << ") Consultar ingredientes\n"
             << OPC_BUSCAR << ") Buscar ingrediente\n"
             << OPC_REGISTRAR_PASO << ") Agregar paso\n"
             << OPC_CONSULTAR_PASO << ") Conultar pasos\n"
             << OPC_SALIR << ") Salir\n"
             << SELECT;
        cin >> opc;
        cin.ignore();

        switch (opc) {
        	case OPC_REGISTRAR:
            	if (contador < MAX_INGREDIENTES) {
                	ingredientes[contador].registrarIngrediente();
                	++contador;
            	}
            	else {
                	cout << "No hay más espacios disponibles" << endl;
            	}
            	break;
        	case OPC_CONSULTAR:
            	if (contador > 0) {
                	mostrarIngredientes();
            	}
            	else {
                	cout << "No hay ingredientes registrados" << endl;
            	}
            	break;
        	case OPC_BUSCAR:
            	if (contador > 0) {
                	buscarIngrediente();
            	}
            	else {
                	cout << "No hay ingredientes registrados" << endl;
            	}
            	break;
        	case OPC_SALIR:
            	cout << "Regresando al menu anterior" << endl;
            	break;
            case OPC_REGISTRAR_PASO:
            	cout << "Inserte paso: ";
            	cin >> pasos[contadorPasos];
            	cin.ignore();
            	++contadorPasos;
            	break;
            case OPC_CONSULTAR_PASO:
            	for(int j(0); j < contadorPasos; ++j) {
            		cout << " > " << pasos[j] << endl;
            	}
            	break;
        	default:
            	cout << "Opción no válida..." << endl;
            	break;
        }
    }
    while(opc != OPC_SALIR);
}
void Receta::mostrarIngredientes() {
    cout << "\t--Consultar Ingredientes--" << endl;
    for (int i(0); i < contador; ++i) {
        ingredientes[i].consultarIngrediente();
    }
}
void Receta::buscarIngrediente() {
    string patron;
    int cont(0);
    cout << "\t--Buscar Ingrediente\t--\n"
        << "Nombre: ";
    getline(cin, patron);
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
    cout << "Se encontraron " << cont << " ingredientes" << endl;
}
string Receta::printNombre() {
    return nombre;
}