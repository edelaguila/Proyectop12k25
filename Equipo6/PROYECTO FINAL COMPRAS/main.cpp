#include <iostream>
#include <limits>
#include <windows.h>
#include "usuario.h"
#include "menu_general.h"

using namespace std;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void mostrarMenuLogin() {
    system("cls");
    cout << "=== SISTEMA DE GESTIÓN ===" << endl;
    cout << "1. Registrar usuario" << endl;
    cout << "2. Iniciar sesión" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opción: ";
}

void procesoRegistro() {
    string usuario, contrasena;
    cout << "\n--- REGISTRO ---" << endl;
    cout << "Usuario: ";
    getline(cin, usuario);

    cout << "Contraseña: ";
    contrasena = Usuario::leerContrasenaOculta();

    if (Usuario::registrarUsuario(usuario, contrasena)) {
        cout << "✅ Usuario registrado exitosamente." << endl;
    } else {
        cout << "❌ No se pudo registrar el usuario (¿ya existe?)." << endl;
    }
}

// Ahora devuelve bool para indicar si el login fue exitoso
bool procesoLogin() {
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
            cout << "\n✔ Acceso concedido" << endl;
            return true;  // Login exitoso
        }

        cout << "\n❌ Credenciales incorrectas. ";
        if (++intentos < MAX_INTENTOS) {
            cout << "Intentos restantes: " << MAX_INTENTOS - intentos << endl;
        }
    }
    cout << "⛔ Límite de intentos alcanzado" << endl;
    return false; // Falló el login
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int opcion;
    bool logueado = false;

    do {
        mostrarMenuLogin();
        cin >> opcion;
        limpiarBuffer();

        switch (opcion) {
            case 1:
                procesoRegistro();
                break;

            case 2:
                logueado = procesoLogin();
                if (logueado) {
                    MenuGeneral menu;
                    menu.mostrar();  // Mostrar menú general solo si login fue exitoso

                    // Salir del programa después de cerrar menú general
                    opcion = 3;
                }
                break;

            case 3:
                cout << "👋 Saliendo del sistema..." << endl;
                break;

            default:
                cout << "❌ Opción inválida" << endl;
        }
        if (opcion != 3) system("pause");
    } while (opcion != 3);

    return 0;
}
