#include <iostream>
#include <limits>
#include <windows.h>
#include "usuario.h"
#include "menu_general.h"

using namespace std;

// Limpia cualquier error de entrada y descarta el resto de la línea
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Muestra el menú de opciones iniciales (registro/login)
void mostrarMenuLogin() {
    system("cls");
    cout << "=== SISTEMA DE GESTIÓN ===" << endl;
    cout << "1. Registrar usuario" << endl;
    cout << "2. Iniciar sesión" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opción: ";
}

// Ejecuta el proceso de registro de usuario
void procesoRegistro() {
    string usuario, contrasena;
    cout << "\n--- REGISTRO ---" << endl;
    cout << "Usuario: ";
    getline(cin, usuario);

    cout << "Contraseña: ";
    contrasena = Usuario::leerContrasenaOculta();

    if (Usuario::registrarUsuario(usuario, contrasena)) {
        cout << "Usuario registrado exitosamente." << endl;
    } else {
        cout << "No se pudo registrar el usuario (¿ya existe?)." << endl;
    }
}

// Ejecuta el proceso de inicio de sesión
void procesoLogin() {
    string usuario, contrasena;
    int intentos = 0;
    const int MAX_INTENTOS = 3;

    while (intentos < MAX_INTENTOS) {
        cout << "\n--- INICIO DE SESIÓN ---" << endl;
        cout << "Usuario: ";
        getline(cin, usuario);

        cout << "Contraseña: ";
        contrasena = Usuario::leerContrasenaOculta();

        if (Usuario::iniciarSesion(usuario, contrasena)) {
            cout << "\nAcceso concedido\n";

            // Guardar el nombre del usuario actual
            MenuGeneral::setUsuarioActual(usuario);

            // Mostrar menú general
            MenuGeneral menu;
            menu.mostrar();
            return;
        }

        cout << "\nCredenciales incorrectas. ";
        if (++intentos < MAX_INTENTOS) {
            cout << "Intentos restantes: " << MAX_INTENTOS - intentos << endl;
        }
    }
    cout << "Límite de intentos alcanzado" << endl;
}

// Función principal del programa
int main() {
    // Configuración para mostrar caracteres especiales correctamente en consola
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcion;
    do {
        mostrarMenuLogin();
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1:
                system("cls");
                procesoRegistro();
                break;
            case 2:
                system("cls");
                procesoLogin();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }

        if (opcion != 3) system("pause");

    } while (opcion != 3);

    return 0;
}
