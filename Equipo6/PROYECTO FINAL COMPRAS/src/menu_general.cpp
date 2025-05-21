#include "menu_general.h"
#include "usuario.h"
#include "menu_producto.h"
#include <iostream>
#include <string>

using namespace std;

// Definici�n de la variable est�tica
string MenuGeneral::usuarioActual = "";

// Getter est�tico
string MenuGeneral::getUsuarioActual() {
    return usuarioActual;
}

// Setter est�tico
void MenuGeneral::setUsuarioActual(const string& usuario) {
    usuarioActual = usuario;
}

void MenuGeneral::mostrar() {
    string usuario, contrasena;
    int opcion;

    cout << "=== SISTEMA DE GESTI�N ===\n";

    // Login o registro simple
    do {
        cout << "1. Iniciar sesi�n\n2. Registrar usuario\nSeleccione opci�n: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "Usuario: ";
            getline(cin, usuario);
            cout << "Contrase�a: ";
            getline(cin, contrasena);

            if (Usuario::iniciarSesion(usuario, contrasena)) {
                cout << "Sesi�n iniciada correctamente.\n";
                setUsuarioActual(usuario);  // Guardamos usuario actual
                break;
            } else {
                cout << "Usuario o contrase�a incorrectos.\n";
            }
        } else if (opcion == 2) {
            cout << "Nuevo usuario: ";
            getline(cin, usuario);
            cout << "Nueva contrase�a: ";
            getline(cin, contrasena);
            Usuario::registrarUsuario(usuario, contrasena);
        } else {
            cout << "Opci�n inv�lida.\n";
        }
    } while (true);

    // Men� principal
    do {
        cout << "\n=== MEN� PRINCIPAL ===" << endl;
        cout << "Usuario actual: " << getUsuarioActual() << endl;  // Mostrar usuario
        cout << "1. Gesti�n de productos\n"
             << "2. Salir\n"
             << "Seleccione opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                MenuProducto::mostrarMenuProducto();
                break;
            case 2:
                cout << "Saliendo del sistema...\n";
                return;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (true);
}
