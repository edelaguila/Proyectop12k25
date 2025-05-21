#include "menu_cliente.h"
#include "cliente.h"
#include "bitacora.h"   // Incluye para poder obtener el usuario actual
#include <iostream>

using namespace std;

void MenuCliente::mostrarMenuCliente() {
    string usuario = Bitacora::obtenerUsuarioActual();  // Obtener usuario actual
    int opcion;
    do {
        cout << "\n=== GESTI�N DE CLIENTES ===" << endl;
        cout << "Usuario actual: " << usuario << endl;   // Mostrar usuario
        cout << "1. Registrar nuevo cliente"
             << "\n2. Listar clientes"
             << "\n3. Modificar cliente"
             << "\n4. Eliminar cliente"
             << "\n5. Volver al men� principal"
             << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: ingresarCliente(); break;
            case 2: consultarClientes(); break;
            case 3: modificarCliente(); break;
            case 4: borrarCliente(); break;
            case 5: cout << "Volviendo...\n"; break;
            default: cerr << "Opci�n inv�lida\n";
        }
    } while(opcion != 5);
}
