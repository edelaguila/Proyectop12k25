#include "menu_compra.h"
#include "compras.h"
#include "bitacora.h"  // Incluye bitacora para obtener usuario
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void MenuCompra::mostrarMenuCompra() {
    vector<Producto> listaCompras = Compras::cargarCompras(); // Mejor cargar las compras guardadas al iniciar
    Compras compras;  // objeto para llamar los métodos
    string usuario = Bitacora::obtenerUsuarioActual(); // Obtener usuario actual
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
                break;
            case 5:
                cout << "Volviendo...\n";
                break;
            default:
                cerr << "Opción inválida\n";
        }
    } while(opcion != 5);
}
