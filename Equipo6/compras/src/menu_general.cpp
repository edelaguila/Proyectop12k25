#include "menu_general.h"
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

    } while (true);
}
