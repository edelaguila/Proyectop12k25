#include "menu_compra.h"
#include "compras.h"
#include "bitacora.h"  // Incluye bitacora para obtener usuario
#include <iostream>
#include <iomanip>
<<<<<<< HEAD
#include <vector>

using namespace std;

void MenuCompra::mostrarMenuCompra() {
    vector<Producto> listaCompras = Compras::cargarCompras(); // Mejor cargar las compras guardadas al iniciar
    Compras compras;  // objeto para llamar los métodos
    string usuario = Bitacora::obtenerUsuarioActual(); // Obtener usuario actual
=======
<<<<<<< HEAD

using namespace std;

void mostrarMenuCompra() {
    vector<Producto> listaCompras;
=======
#include <vector>

using namespace std;

void MenuCompra::mostrarMenuCompra() {
    vector<Producto> listaCompras;
    Compras compras;  // objeto para llamar los métodos
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    int opcion;

    do {
        cout << "\n=== MENÚ DE COMPRAS ===" << endl;
        cout << "Usuario actual: " << usuario << endl;  // Mostrar usuario
        cout << "1. Registrar nueva compra"
             << "\n2. Ver historial de compras"
             << "\n3. Buscar por proveedor"
             << "\n4. Ver total gastado"
             << "\n5. Volver al menú principal"
             << "\nSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
<<<<<<< HEAD
                compras.registrarCompra(listaCompras);
=======
<<<<<<< HEAD
                registrarCompra(listaCompras);
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
                break;
            case 2:
                compras.mostrarHistorial(listaCompras);
                break;
            case 3:
                compras.buscarPorProveedor(listaCompras);
                break;
            case 4:
<<<<<<< HEAD
                cout << "\nTotal gastado: $" << fixed << setprecision(2)
                     << compras.calcularTotalGastado(listaCompras) << endl;
=======
                cout << "\n💰 Total gastado: $" << fixed << setprecision(2)
                     << calcularTotalGastado(listaCompras) << endl;
=======
                compras.registrarCompra(listaCompras);
                break;
            case 2:
                compras.mostrarHistorial(listaCompras);
                break;
            case 3:
                compras.buscarPorProveedor(listaCompras);
                break;
            case 4:
                cout << "\nTotal gastado: $" << fixed << setprecision(2)
                     << compras.calcularTotalGastado(listaCompras) << endl;
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
                break;
            case 5:
                cout << "Volviendo...\n";
                break;
            default:
                cerr << "Opción inválida\n";
        }
    } while(opcion != 5);
}
