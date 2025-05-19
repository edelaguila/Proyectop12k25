#include <iostream>
#include "SistemaVentas.h"
#include "Login.h"
#include "bitacora.h"
<<<<<<< HEAD
=======
#include <fstream>
#include <string>

>>>>>>> origin

using namespace std;


string usuarioActual; // Para guardar el nombre del usuario bitacora

void mostrarMenuPrincipal();
<<<<<<< HEAD

=======
void mostrarArchivo();  // Función para mostrar el archivo bitacora.txt
>>>>>>> origin
int main() {
    int opcion;
    bool accesoPermitido = false;

<<<<<<< HEAD
=======

>>>>>>> origin
    do {

        system ("cls");
        cout << "\n--- Bienvenido al Sistema ---\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Registrarse\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Para evitar errores con getline

        switch (opcion) {
            case 1:
                accesoPermitido = iniciarSesion(usuarioActual);
                break;
            case 2:
                registrarUsuario();
                break;
            case 3:
                cout << "\n\nSaliendo del sistema...\n";
                return 0;
            default:
<<<<<<< HEAD
                cout << "Opción invalida.\n";
=======
                cout << "Opcion invalida.\n";
>>>>>>> origin
        }
    } while (!accesoPermitido);

    mostrarMenuPrincipal();
<<<<<<< HEAD
     registrarEvento(usuarioActual, "Cerró sesión desde menú principal");
=======
     registrarEvento(usuarioActual, "Cerro sesion desde menu principal");
>>>>>>> origin
    return 0;
}




void mostrarMenuPrincipal() {
    SistemaVentas sistema;
    int opcion;
    do {
        system ("cls");
        cout << "\n--- Menu General ---\n";
        cout << "1. Archivo\n";
        cout << "2. Catalogos\n";
        cout << "3. Procesos\n";
        cout << "4. Informes\n";
        cout << "5. Salir del sistema\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
<<<<<<< HEAD
                registrarEvento(usuarioActual, "Entró a la opción Archivo");
                cout << "Archivo (sin funciones aun).\n";
                break;
            case 2:
                registrarEvento(usuarioActual, "Entró a la opción Catálogos");
                sistema.mostrarMenu();
                break;
            case 3:
                registrarEvento(usuarioActual, "Entró a la opción Procesos");
                sistema.realizarVenta();
                break;
            case 4:
                registrarEvento(usuarioActual, "Entró a la opción Informes");
                sistema.mostrarVentas();
                break;
            case 5:
                registrarEvento(usuarioActual, "Salió del menú general");
=======
                registrarEvento(usuarioActual, "Entro a la opción Archivo");
                cout<< "sin funcion\n";
                system("pause");
                break;
            case 2:
                registrarEvento(usuarioActual, "Entro a la opción Catálogos");
                sistema.mostrarMenu();
                break;
            case 3:
                registrarEvento(usuarioActual, "Entro a la opción Procesos");
                sistema.realizarVenta();
                break;
            case 4:
                registrarEvento(usuarioActual, "Entro a la opción Informes");
                mostrarArchivo(); // Mostrar contenido de bitacora.txt
                system ("pause");
                break;
            case 5:
                registrarEvento(usuarioActual, "Salio del menú general");
>>>>>>> origin
                cout << "Cerrando sesion...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 5);
}
<<<<<<< HEAD
=======



void mostrarArchivo() {
    system("cls");
    std::ifstream archivo("bitacora.bin", std::ios::binary);
    if (!archivo) {
        std::cout << "No se pudo abrir bitacora.bin" << std::endl;
        return;
    }

    std::cout << "=== Contenido de bitacora.bin ===" << std::endl;
    size_t longitud;
    std::string mensaje;

    while (archivo.read(reinterpret_cast<char*>(&longitud), sizeof(longitud))) {
        mensaje.resize(longitud);
        archivo.read(&mensaje[0], longitud);
        std::cout << mensaje << std::endl;
    }

    archivo.close();
}
>>>>>>> origin
