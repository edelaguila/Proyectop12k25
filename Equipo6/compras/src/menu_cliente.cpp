#include "menu_cliente.h"
#include "cliente.h"
#include "bitacora.h"   // Incluye para poder obtener el usuario actual
#include <iostream>

using namespace std;

<<<<<<< HEAD
void MenuCliente::mostrarMenuCliente() {
    string usuario = Bitacora::obtenerUsuarioActual();  // Obtener usuario actual
=======
<<<<<<< HEAD
void mostrarMenuCliente() {
=======
void MenuCliente::mostrarMenuCliente() {
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    int opcion;
    do {
        cout << "\n=== GESTIÓN DE CLIENTES ===" << endl;
        cout << "Usuario actual: " << usuario << endl;   // Mostrar usuario
        cout << "1. Registrar nuevo cliente"
             << "\n2. Listar clientes"
             << "\n3. Modificar cliente"
             << "\n4. Eliminar cliente"
             << "\n5. Volver al menú principal"
             << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: ingresarCliente(); break;
            case 2: consultarClientes(); break;
            case 3: modificarCliente(); break;
            case 4: borrarCliente(); break;
            case 5: cout << "Volviendo...\n"; break;
            default: cerr << "Opción inválida\n";
        }
    } while(opcion != 5);
}
