#include "reportes.h"
#include <iostream>
#include "usuarios.h"

//Clases con informes
#include "pago.h"
#include "factura.h"
//#include "cobros.h"
//otros

using namespace std;

extern usuarios usuariosrRegistrado;
reportes::reportes()
{
    //ctor
}

void reportes::menuInformes() {
    pago pag;
    Factura fac;

    int opcion;
    do {
        system("cls");
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t |   Menu de reportes      |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout <<"\t\t\t1. Listado de Cuentas por Pagar" << endl;
        cout <<"\t\t\t2. Listado de Cuentas por Cobrar" << endl;
        cout <<"\t\t\t3. Reporte de Pagos Realizados" << endl;
        cout <<"\t\t\t4. Reporte de Ingresos Recibidos" << endl;
        cout <<"\t\t\t5. Reporte de Facturas" << endl;
        cout <<"\t\t\t6. Volver al menú principal" << endl;
        cout <<"\n\t\tIngresa tu Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                pag.reporteCuentasPorPagar(); //Muestra todas las facturas pendientes de pago
                break;
            case 2:
                //reporte Cuentas Por Cobrar
                break;
            case 3:
                pag.reportePagos(); //Muestra todos los pagos registrados por acreedores/proveedores
                break;
            case 4:
                //reporteIngresos() ---pagos de clientes
                break;
            case 5:
                menuReporteFactura();
                break;
            case 6:
                break;
            default:
                cout << "\t\tOpción inválida..." << endl;
                system("pause");
        }
    } while (opcion != 5);
}

/*void reportes::menuFactura() {
    menuReporteFactura;

    int opcion;
    do {
        system("cls");
        cout << "\n\t\tMenu de Facturas" << endl;
        cout << "\t\t-----------------------------" << endl;
        cout << "\t\t1. Factura de Cliente" << endl;
        cout << "\t\t2. Factura de Proveedor" << endl;
        cout << "\t\t3. Factura de Acreedor" << endl;
        cout << "\t\t4. Reportes Factura " << endl;
        cout << "\t\t5. Volver al menu anterior" << endl;
        cout << "\n\t\tSeleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                menuReporteFactura();
                break;
            case 5:
                break;
            default:
                cout << "\t\tOpción inválida." << endl;
                system("pause");
        }
    } while (opcion != 5);
}*/
