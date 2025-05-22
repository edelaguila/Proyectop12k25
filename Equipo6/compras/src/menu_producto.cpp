#include "menu_general.h"  // Para acceder a usuarioActual
#include "menu_producto.h"
#include "producto.h"
#include <iostream>
#include <limits>

using namespace std;

<<<<<<< HEAD
void MenuProducto::mostrarMenuProducto() {
=======
<<<<<<< HEAD
void mostrarMenuProducto() {
=======
void MenuProducto::mostrarMenuProducto() {
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    int opcion;
    do {
        string usuario = MenuGeneral::getUsuarioActual();
        if (usuario.empty()) {
            usuario = "Desconocido";
        }

        cout << "\n=== GESTIÓN DE PRODUCTOS ==="
             << "\nUsuario: " << usuario << "\n"
             << "1. Registrar nuevo producto"
             << "\n2. Listar productos"
             << "\n3. Modificar producto"
             << "\n4. Eliminar producto"
             << "\n5. Volver al menú principal"
             << "\nSeleccione una opción: ";

        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }
        cin.ignore();

<<<<<<< HEAD
        switch (opcion) {
            case 1:
                system("cls");
                Producto::ingresarProducto();
                break;
            case 2:
                system("cls");
                Producto::consultarProductos();
                break;
            case 3:
                system("cls");
                Producto::modificarProducto();
                break;
            case 4:
                system("cls");
                Producto::borrarProducto();
                break;
            case 5:
                system("cls");
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
=======
<<<<<<< HEAD
        switch(opcion) {
            case 1: ingresarProducto(); break;
            case 2: consultarProductos(); break;
            case 3: modificarProducto(); break;
            case 4: borrarProducto(); break;
            case 5: cout << "Volviendo...\n"; break;
            default: cerr << "Opción inválida\n";
        }
    } while(opcion != 5);
=======
        switch (opcion) {
            case 1:
                Producto::ingresarProducto();
                break;
            case 2:
                Producto::consultarProductos();
                break;
            case 3:
                Producto::modificarProducto();
                break;
            case 4:
                Producto::borrarProducto();
                break;
            case 5:
                cout << "Volviendo al menú principal...\n";
                break;
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
}
