#include <iostream>
#include <limits>
#include <windows.h>
#include "usuario.h"
#include "menu_general.h"

using namespace std;

<<<<<<< HEAD
// Limpia cualquier error de entrada y descarta el resto de la línea
=======
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
void limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

<<<<<<< HEAD
// Muestra el menú de opciones iniciales (registro/login)
=======
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
void mostrarMenuLogin() {
    system("cls");
    cout << "=== SISTEMA DE GESTIÓN ===" << endl;
    cout << "1. Registrar usuario" << endl;
    cout << "2. Iniciar sesión" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opción: ";
}

<<<<<<< HEAD
// Ejecuta el proceso de registro de usuario
=======
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
void procesoRegistro() {
    string usuario, contrasena;
    cout << "\n--- REGISTRO ---" << endl;
    cout << "Usuario: ";
    getline(cin, usuario);

    cout << "Contraseña: ";
    contrasena = Usuario::leerContrasenaOculta();

    if (Usuario::registrarUsuario(usuario, contrasena)) {
<<<<<<< HEAD
        cout << "Usuario registrado exitosamente." << endl;
    } else {
        cout << "No se pudo registrar el usuario (¿ya existe?)." << endl;
    }
}

// Ejecuta el proceso de inicio de sesión
=======
        cout << "✅ Usuario registrado exitosamente." << endl;
    } else {
        cout << "❌ No se pudo registrar el usuario (¿ya existe?)." << endl;
    }
}

>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
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
<<<<<<< HEAD
            cout << "\nAcceso concedido\n";

            // Guardar el nombre del usuario actual
            MenuGeneral::setUsuarioActual(usuario);

            // Mostrar menú general
            MenuGeneral menu;
            menu.mostrar();
            return;
        }

        cout << "\nCredenciales incorrectas. ";
=======
            cout << "\n✔ Acceso concedido" << endl;
            MenuGeneral menu;
            menu.mostrar();  // Ir directamente al menú principal tras login exitoso
            return;
        }

        cout << "\n❌ Credenciales incorrectas. ";
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
        if (++intentos < MAX_INTENTOS) {
            cout << "Intentos restantes: " << MAX_INTENTOS - intentos << endl;
        }
    }
<<<<<<< HEAD
    cout << "Límite de intentos alcanzado" << endl;
}

// Función principal del programa
=======
    cout << "⛔ Límite de intentos alcanzado" << endl;
}

>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
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
<<<<<<< HEAD
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

=======
                procesoRegistro();
                break;
            case 2:
                procesoLogin();
                break;
            case 3:
                cout << "👋 Saliendo del sistema..." << endl;
                break;
            default:
                cout << "❌ Opción inválida" << endl;
        }
        if (opcion != 3) system("pause");
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    } while (opcion != 3);

    return 0;
}
