// Gabriela - 5 de Mayo 2025
#include <iostream>
#include "Reportes.h"
#include "Usuarios.h"
#include "Inventario.h"
#include "Facturacion.h"
#include "Bitacora.h"
#include "Envios.h"
#include "Pedidos.h"

using namespace std;

int main() {
    int opcion;
    // Crear instancias de los módulos
    Reportes reportes;
    Usuarios usuarios;
    Inventario inventario;
    Facturacion facturacion;
    Bitacora bitacora;

    do {
        // Menu principal del sistema logistico
        system("cls");
        cout << "\t\t========================================" << endl;
        cout << "\t\t| SISTEMA LOGISTICO - MENU PRINCIPAL   |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Modulo de Reportes" << endl;
        cout << "\t\t 2. Modulo de Usuarios" << endl;
        cout << "\t\t 3. Modulo de Inventario" << endl;
        cout << "\t\t 4. Modulo de Facturacion" << endl;
        cout << "\t\t 5. Modulo de Bitacora" << endl;
        cout << "\t\t 6. Modulo de Envios" << endl;
        cout << "\t\t 7. Modulo de Pedidos" << endl;
        cout << "\t\t 8. Salir" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                reportes.mostrarMenuReportes(); // Llamar al módulo de reportes
                break;
            case 2:
                usuarios.mostrarMenuUsuarios(); // Llamar al módulo de usuarios
                break;
            case 3:
                inventario.mostrarMenuInventario(); // Llamar al módulo de inventario
                break;
            case 4:
                facturacion.mostrarMenuFacturacion(); // Llamar al módulo de facturacion
                break;
            case 5:
                bitacora.mostrarMenuBitacora(); // Llamar al módulo de bitacora
                break;
            case 6:
                bitacora.mostrarMenuEnvios(); // Llamar al módulo de envios
                break;
            case 7:
                bitacora.mostrarMenuPedidos(); // Llamar al módulo de pedidos
                break;
            case 8:
                cout << "\nSaliendo del sistema... Gracias por usar el sistema logistico." << endl;
                break;
            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                system("pause");
                break;
        }

    } while(opcion != 8);

    return 0;
}
