<<<<<<< HEAD
#include "menu_general.h"
=======
<<<<<<< HEAD
 #include "menu_general.h"
#include "menu_cliente.h"
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
#include "menu_producto.h"
#include "menu_archivo.h"
#include "menu_cliente.h"
#include "menu_compra.h"
#include <iostream>

using namespace std;

// Definición de la variable estática
string MenuGeneral::usuarioActual = "Desconocido";

// Getter para obtener el usuario actual
string MenuGeneral::getUsuarioActual() {
    return usuarioActual;
}

// Setter para establecer el usuario actual
void MenuGeneral::setUsuarioActual(const string& usuario) {
    usuarioActual = usuario;
}

// Muestra el menú principal del sistema después de iniciar sesión correctamente
void MenuGeneral::mostrar() {
    int opcion;

    do {
        system("cls"); // Limpia pantalla antes de mostrar el menú

        cout << "\n=== MENÚ PRINCIPAL ===\n"
             << "Usuario: " << usuarioActual << "\n"
             << "1. Gestión de productos\n"
             << "2. Archivo\n"
             << "3. Cliente\n"
             << "4. Compras\n"
             << "5. Salir\n"
             << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                system("cls");
                MenuProducto::mostrarMenuProducto();
                break;
            case 2:
                system("cls");
                MenuArchivo::menuArchivo();
                break;
            case 3:
                system("cls");
                MenuCliente::mostrarMenuCliente();
                break;
            case 4:
                system("cls");
                MenuCompra::mostrarMenuCompra();  // Aquí llamamos al menú compras
                break;
            case 5:
                cout << "Saliendo del sistema...\n";
                return;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                system("pause");
        }
<<<<<<< HEAD

    } while (true);
=======
    } while(opcion != 5);
=======
#include "menu_general.h"
#include "usuario.h"
#include "menu_producto.h"
#include <iostream>
#include <string>

using namespace std;

void MenuGeneral::mostrar() {
    string usuario, contrasena;
    int opcion;

    cout << "=== SISTEMA DE GESTIÓN ===\n";

    // Login o registro simple
    do {
        cout << "1. Iniciar sesión\n2. Registrar usuario\nSeleccione opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) {
            cout << "Usuario: ";
            getline(cin, usuario);
            cout << "Contraseña: ";
            getline(cin, contrasena);

            if (Usuario::iniciarSesion(usuario, contrasena)) {
                cout << "Sesión iniciada correctamente.\n";
                break;
            } else {
                cout << "Usuario o contraseña incorrectos.\n";
            }
        } else if (opcion == 2) {
            cout << "Nuevo usuario: ";
            getline(cin, usuario);
            cout << "Nueva contraseña: ";
            getline(cin, contrasena);
            Usuario::registrarUsuario(usuario, contrasena);
        } else {
            cout << "Opción inválida.\n";
        }
    } while (true);

    // Menú principal
    do {
        cout << "\n=== MENÚ PRINCIPAL ===\n"
             << "1. Gestión de productos\n"
             << "2. Salir\n"
             << "Seleccione opción: ";
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
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (true);
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
}
