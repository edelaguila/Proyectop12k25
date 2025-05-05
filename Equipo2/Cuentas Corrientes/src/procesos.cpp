//Clase para el menu d procesos - Astrid Ru�z 9959 24 2976 Mayo 2025
#include <iostream>
#include "procesos.h"
#include "transaccion.h"

using namespace std;

void menuProcesos() {
    int opcion;
    do {
        system("cls");
        cout << "\n\n\t\tMenu Procesos" << endl;
        cout << "\t\t------------------------" << endl;
        cout << "\t\t1. Registro de Factura" << endl;
        cout << "\t\t2. Gestionar pagos a Proveedor o Acreedor" << endl;
        cout << "\t\t3. Gestionar cobro a Cliente" << endl;
        cout << "\t\t4. Gestionar transacciones bancarias" << endl;
        cout << "\t\t5. Volver al menu principal" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            //menuFactura
            break;
        case 2:
            //menuGestionarPagos
            break;
        case 3:
            //menuGestionarCobro
            break;
        case 4:
            menuTransacciones();
            break;
        case 5:
            //
            break;
        default:
            cout << "\t\tOpci�n inv�lida." << endl;
        }
    } while(opcion != 5);
}

void menuTransacciones() { //Menu d transacciones por Astrid Ru�z
    int opcion;
    transaccion t;

    do {
        system("cls");
        cout << "\n\n\t\tTransacciones Bancarias" << endl;
        cout << "\t\t1. Realizar Dep�sito" << endl;
        cout << "\t\t2. Realizar Retiro" << endl;
        cout << "\t\t3. Realizar Transferencia" << endl;
        cout << "\t\t4. Listar Transacciones" << endl; //CRUD
        cout << "\t\t5. Editar Transacci�n" << endl;
        cout << "\t\t6. Eliminar Transacci�n" << endl;
        cout << "\t\t7. Volver" << endl;
        cout << "\n\t\tIngrese una opci�n: ";
        cin >> opcion;

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
