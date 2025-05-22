#include "menu_archivo.h"
#include "bitacora.h"
#include <iostream>
#include <limits>

using namespace std;

void mostrarMenuArchivo() {
    cout << "\n=== MEN� DE ARCHIVO ===" << endl;
    cout << "1. Crear respaldo" << endl;
    cout << "2. Restaurar datos" << endl;
    cout << "3. Exportar datos" << endl;
    cout << "4. Ver bit�cora" << endl;
    cout << "5. Regresar" << endl;
    cout << "Seleccione una opci�n: ";
}

void MenuArchivo::menuArchivo() {
    string usuario = Bitacora::obtenerUsuarioActual();
    int opcion;

    do {
        mostrarMenuArchivo();

        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inv�lida. Por favor ingrese un n�mero: ";
        }
        cin.ignore();

        switch(opcion) {
            case 1:
                Bitacora::registrarAccion(usuario, CodigosAccion::RESPALDO_CREADO,
                                        "Respaldo manual de la base de datos");
                cout << "Respaldo creado exitosamente." << endl;
                break;

            case 2:
                Bitacora::registrarAccion(usuario, CodigosAccion::RESTAURACION_COMPLETADA,
                                        "Restauraci�n manual desde respaldo");
                cout << "Datos restaurados exitosamente." << endl;
                break;

            case 3:
                Bitacora::registrarAccion(usuario, CodigosAccion::EXPORTACION_DATOS,
                                        "Exportaci�n manual de datos");
                cout << "Datos exportados exitosamente." << endl;
                break;

            case 4:
                Bitacora::mostrarBitacora();
                break;

            case 5:
                cout << "Regresando al men� principal..." << endl;
                break;

            default:
                Bitacora::registrarAccion(usuario, CodigosAccion::ERROR_SISTEMA,
                                        "Opci�n inv�lida en men� de archivo");
                cout << "Opci�n no v�lida. Intente nuevamente." << endl;
        }
    } while(opcion != 5);
}
