#include "menu_producto.h"
#include "producto.h"
#include <iostream>

using namespace std;

void MenuProducto::mostrarMenuProducto() {
    int opcion;
    do {
        cout << "\n=== GESTI�N DE PRODUCTOS ==="
             << "\n1. Registrar nuevo producto"
             << "\n2. Listar productos"
             << "\n3. Modificar producto"
             << "\n4. Eliminar producto"
             << "\n5. Volver al men� principal"
             << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

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
                cout << "Volviendo al men� principal...\n";
                break;
            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
        }
    } while (opcion != 5);
}
