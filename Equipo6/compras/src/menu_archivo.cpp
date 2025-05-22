#include "menu_archivo.h"
#include "bitacora.h"
#include "menu_general.h"
#include <iostream>
#include <limits>

using namespace std;

// Modificamos la función para recibir el usuario y mostrarlo
void mostrarMenuArchivo(const string& usuario) {

    cout << "\n=== MENÚ DE ARCHIVO ===" << endl;
    cout << "Usuario actual: " << usuario << endl;   // <-- Aquí mostramos el usuario
    cout << "1. Crear respaldo" << endl;
    cout << "2. Restaurar datos" << endl;
    cout << "3. Exportar datos" << endl;
    cout << "4. Ver bitácora" << endl;
    cout << "5. Regresar" << endl;
    cout << "Seleccione una opción: ";
}

<<<<<<< HEAD
void MenuArchivo::menuArchivo() {
=======
<<<<<<< HEAD
void menuArchivo() {
=======
void MenuArchivo::menuArchivo() {
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    string usuario = Bitacora::obtenerUsuarioActual();
    int opcion;

    do {
        mostrarMenuArchivo(usuario);

        while (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Por favor ingrese un número: ";
        }
<<<<<<< HEAD
        cin.ignore();
=======
<<<<<<< HEAD
=======
        cin.ignore();
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978

        switch(opcion) {
            case 1:
                Bitacora::registrarAccion(usuario, CodigosAccion::RESPALDO_CREADO,
                                        "Respaldo manual de la base de datos");
                cout << "Respaldo creado exitosamente." << endl;
                break;

            case 2:
                Bitacora::registrarAccion(usuario, CodigosAccion::RESTAURACION_COMPLETADA,
                                        "Restauración manual desde respaldo");
                cout << "Datos restaurados exitosamente." << endl;
                break;

            case 3:
                Bitacora::registrarAccion(usuario, CodigosAccion::EXPORTACION_DATOS,
                                        "Exportación manual de datos");
                cout << "Datos exportados exitosamente." << endl;
                break;

            case 4:
                Bitacora::mostrarBitacora();
                break;

            case 5:
                cout << "Regresando al menú principal..." << endl;
                break;

            default:
                Bitacora::registrarAccion(usuario, CodigosAccion::ERROR_SISTEMA,
                                        "Opción inválida en menú de archivo");
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    } while(opcion != 5);
}
