// Clase para el menu de procesos - Astrid Ru�z 9959 24 2976 Mayo 2025
#include <iostream>
#include <limits>
#include "procesos.h"
#include "transaccion.h"
#include "factura.h"  // Incluimos el encabezado de facturas - Dulce Reyes
#include "pago.h"
#include "cobros.h"
#include "usuarios.h"
using namespace std;

extern usuarios usuariosrRegistrado;

// Men� principal de procesos
void menuProcesos() {
    GestionCobros cob;
    pago pag;
    //GestionCobros cob;
    int opcion;
    do {
        system("cls");
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout << "\n\n\t\tMenu Procesos" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Facturas (Clientes/Proveedores/Acreedores)" << endl;
        cout << "\t\t2. Gestionar pagos a Proveedor o Acreedor" << endl;
        cout << "\t\t3. Gestionar cobro a Cliente" << endl;
        cout << "\t\t4. Gestionar transacciones bancarias" << endl;
        cout << "\t\t5. Volver al menu principal" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(opcion) {
            case 1:
                menuFactura(); // Submen� con 3 tipos de factura
                break;
            case 2:
                pag.menuPagos();
                system("pause");
                break;
            case 3: {
                GestionCobros gc;
                gc.menuCobros();
                break;
            }
            case 4:
                menuTransacciones();
                break;
            case 5:
                break;
            default:
                cout << "\t\tOpci�n inv�lida." << endl;
                system("pause");
        }
    } while(opcion != 5);
}

// Submen� de Facturas - Dulce Reyes Mayo 2025
void menuFactura() {
    int opcion;
    do {
        system("cls");
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout << "\n\t\tMenu de Facturas" << endl;
        cout << "\t\t-----------------------------" << endl;
        cout << "\t\t1. Factura de Cliente" << endl;
        cout << "\t\t2. Factura de Proveedor" << endl;
        cout << "\t\t3. Factura de Acreedor" << endl;
        cout << "\t\t4. Reportes Factura " << endl;
        cout << "\t\t5. Volver al menu anterior" << endl;
        cout << "\n\t\tSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (opcion) {
            case 1:
                menuFacturaCliente();
                break;
            case 2:
                menuFacturaProveedor();
                break;
            case 3:
                menuFacturaAcreedor();
                break;
            case 4:
                menuReporteFactura();
                break;
            case 5:
                break;
            default:
                cout << "\t\tOpci�n inv�lida." << endl;
                system("pause");
        }
    } while (opcion != 5);
}

// Men� de transacciones bancarias (manteniendo estructura original)
void menuTransacciones() {
    int opcion;
    transaccion t;

    do {
        system("cls");
        cout << "\n\n\t\tTransacciones Bancarias" << endl;
        cout << "\t\t1. Realizar Dep�sito" << endl;
        cout << "\t\t2. Realizar Retiro" << endl;
        cout << "\t\t3. Realizar Transferencia" << endl;
        cout << "\t\t4. Listar Transacciones" << endl;
        cout << "\t\t5. Editar Transacci�n" << endl;
        cout << "\t\t6. Eliminar Transacci�n" << endl;
        cout << "\t\t7. Volver" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string id;

        switch (opcion) {
            case 1:
                t.registrarTransaccion("Deposito");
                t.guardarEnArchivo();
                system("pause");
                break;
            case 2:
                t.registrarTransaccion("Retiro");
                t.guardarEnArchivo();
                system("pause");
                break;
            case 3:
                t.registrarTransaccion("Transferencia");
                t.guardarEnArchivo();
                system("pause");
                break;
            case 4:
                transaccion::mostrarTodasDesdeArchivo();
                system("pause");
                break;
            case 5:
                cout << "Ingrese ID de transacci�n a editar: ";
                cin >> id;
                transaccion::editarTransaccion(id);
                system("pause");
                break;
            case 6:
                cout << "Ingrese ID de transacci�n a eliminar: ";
                cin >> id;
                transaccion::eliminarTransaccion(id);
                system("pause");
                break;
            case 7:
                break;
            default:
                cout << "\n\t\tOpci�n inv�lida." << endl;
                system("pause");
        }
    } while (opcion != 7);
}
