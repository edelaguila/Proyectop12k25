#include "sistema.h"
#include "Opciones.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <limits>
#include <vector>
//Realizado por ANGEL ROQUEL y Modificado por Roli Cedillo
Opciones opcion; // Se crea un objeto global de la clase Opciones

sistema::sistema()
{

}

sistema::~sistema()
{

}

// Función para registrar un nuevo usuario
void sistema::registrarUsuario() {
    system("cls");       // Limpia la pantalla

    string nombre, contrasenia;  // Variables para guardar el nombre y la contraseña del usuario
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese nombre de usuario: ";
    getline(cin,nombre);  // Captura el nombre del usuario Corregido por Isaias Cedillo para obtener nombre completo del usuario

    cout << "Ingrese contrasenia: ";
    char caracter;       // Variable para leer carácter por carácter la contraseña

    // Captura la contraseña con ocultamiento visual (solo muestra '*')
    while ((caracter = _getch()) != '\r') { // Mientras no se presione Enter
        if (caracter == '\b') {             // Si se presiona retroceso
            if (!contrasenia.empty()) {     // Si la contraseña no está vacía
                cout << "\b \b";            // Borra un asterisco en pantalla
                contrasenia.pop_back();     // Elimina el último carácter de la contraseña
            }
        } else {
            contrasenia += caracter;        // Agrega el carácter a la contraseña
            cout << "*";                    // Muestra un asterisco
        }
    }
    cout << endl;  // Salto de línea al final de la contraseña

    ofstream archivo(archivoUsuarios, ios::binary|ios::app|ios::out);  // Abre archivo para agregar usuarios
    if (archivo.is_open()) {
        size_t nombretamano = nombre.size();
        archivo.write(reinterpret_cast<const char*>(&nombretamano), sizeof(nombretamano));  // Guarda el usuario y contraseña
        archivo.write(nombre.c_str(), nombretamano);
        size_t contratamano = contrasenia.size();
        archivo.write(reinterpret_cast<const char*>(&contratamano), sizeof(contratamano));  // Guarda el usuario y contraseña
        archivo.write(contrasenia.c_str(), contratamano);
        archivo.close();                                  // Cierra el archivo
        cout << "Usuario registrado con exito." << endl;  // Mensaje de éxito
    } else {
        cout << "No se pudo abrir el archivo." << endl;   // Error al abrir archivo
    }
}

void sistema::ingresarUsuario() {
    system("cls");       // Limpia la pantalla

    string nombre, contrasenia;  // Variables para ingresar datos del usuario

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese nombre de usuario: ";       // Captura el nombre
    getline(cin, nombre);
    cout << "Ingrese contrasenia: ";
    char caracter;

    // Captura oculta de contraseña
    while ((caracter = _getch()) != '\r') {
        if (caracter == '\b') {
            if (!contrasenia.empty()) {
                cout << "\b \b";
                contrasenia.pop_back();
            }
        } else {
            contrasenia += caracter;
            cout << "*";
        }
    }
    cout << endl;

    ifstream archivo(archivoUsuarios, ios::binary);  // Abre el archivo en modo binario
    if (archivo.is_open()) {
        bool encontrado = false;

        while (true) {
            // Leer tamaño del nombre de usuario
            size_t tamUsuario;
            archivo.read(reinterpret_cast<char*>(&tamUsuario), sizeof(tamUsuario));
            if (archivo.eof()) break;

            // Leer nombre de usuario
            vector<char> usuarioBuffer(tamUsuario);
            archivo.read(usuarioBuffer.data(), tamUsuario);
            string usuario(usuarioBuffer.data(), tamUsuario);

            // Leer tamaño de la contraseña
            size_t tamContrasenia;
            archivo.read(reinterpret_cast<char*>(&tamContrasenia), sizeof(tamContrasenia));

            // Leer contraseña
            vector<char> contraseniaBuffer(tamContrasenia);
            archivo.read(contraseniaBuffer.data(), tamContrasenia);
            string contraseniaArchivo(contraseniaBuffer.data(), tamContrasenia);

            // Comparar credenciales
            if (usuario == nombre && contraseniaArchivo == contrasenia) {
                usuarioActual = nombre;
                cout << "Ingreso exitoso." << endl;
                encontrado = true;
                archivo.close();
                opcion.menu(usuario);
                return;
            }
        }

        archivo.close();
        if (!encontrado) {
            cout << "Nombre de usuario o contrasena incorrecta." << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
void sistema::mostrarUsuarios() {
    system("cls");  // Limpiar pantalla

    // 1. Abrir archivo binario
    ifstream archivo(archivoUsuarios, ios::binary);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de usuarios." << endl;
        system("pause");
        return;
    }

    cout << "============ LISTA DE USUARIOS ============\n\n";

    // 2. Leer cada usuario del archivo
    while (true) {
        // 2.1 Leer tamaño del nombre de usuario
        size_t tamUsuario;
        archivo.read((char*)&tamUsuario, sizeof(tamUsuario));

        // Si llegamos al final del archivo, salir
        if (archivo.eof()) break;

        // 2.2 Leer el nombre de usuario
        string usuario;
        usuario.resize(tamUsuario);
        archivo.read(&usuario[0], tamUsuario);

        // 2.3 Leer tamaño de la contraseña
        size_t tamContrasenia;
        archivo.read((char*)&tamContrasenia, sizeof(tamContrasenia));

        // 2.4 Leer la contraseña (pero no la guardamos)
        archivo.seekg(tamContrasenia, ios::cur);

        // 3. Mostrar la información
        cout << "Usuario: " << usuario << endl;
        cout << "Contraseña: " << string(tamContrasenia, '*') << endl; // Mostrar asteriscos
        cout << "-----------------------------" << endl << endl;
    }

    // 4. Cerrar archivo
    archivo.close();
    system("pause");
}
