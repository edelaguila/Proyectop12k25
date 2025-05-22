#include "sistema.h"
#include "Opciones.h"
#include <conio.h>
#include <limits>
//Realizado por ANGEL ROQUEL
Opciones opcion; // Se crea un objeto global de la clase Opciones

sistema::sistema()
{

}

sistema::~sistema()
{

}

// Funci�n para registrar un nuevo usuario
void sistema::registrarUsuario() {
    system("cls");       // Limpia la pantalla

    string nombre, contrasenia;  // Variables para guardar el nombre y la contrase�a del usuario
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Ingrese nombre de usuario: ";
    getline(cin,nombre);  // Captura el nombre del usuario Corregido por Isaias Cedillo para obtener nombre completo del usuario

    cout << "Ingrese contrasenia: ";
    char caracter;       // Variable para leer car�cter por car�cter la contrase�a

    // Captura la contrase�a con ocultamiento visual (solo muestra '*')
    while ((caracter = _getch()) != '\r') { // Mientras no se presione Enter
        if (caracter == '\b') {             // Si se presiona retroceso
            if (!contrasenia.empty()) {     // Si la contrase�a no est� vac�a
                cout << "\b \b";            // Borra un asterisco en pantalla
                contrasenia.pop_back();     // Elimina el �ltimo car�cter de la contrase�a
            }
        } else {
            contrasenia += caracter;        // Agrega el car�cter a la contrase�a
            cout << "*";                    // Muestra un asterisco
        }
    }
    cout << endl;  // Salto de l�nea al final de la contrase�a

    ofstream archivo(archivoUsuarios, ios::app);  // Abre archivo para agregar usuarios
    if (archivo.is_open()) {
        archivo << nombre << "," << contrasenia << endl;  // Guarda el usuario y contrase�a
        archivo.close();                                  // Cierra el archivo
        cout << "Usuario registrado con exito." << endl;  // Mensaje de �xito
    } else {
        cout << "No se pudo abrir el archivo." << endl;   // Error al abrir archivo
    }
}

// Funci�n para ingresar (iniciar sesi�n) un usuario existente
void sistema::ingresarUsuario() {
    system("cls");       // Limpia la pantalla

    string nombre, contrasenia;  // Variables para ingresar datos del usuario

    cout << "Ingrese nombre de usuario: ";
    cin >> nombre;       // Captura el nombre

    cout << "Ingrese contrasenia: ";
    char caracter;

    // Captura oculta de contrase�a
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

    ifstream archivo(archivoUsuarios);  // Abre el archivo de usuarios en modo lectura
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {      // Lee cada l�nea del archivo
            size_t coma = linea.find(",");     // Encuentra la posici�n de la coma
            string usuario = linea.substr(0, coma);             // Extrae el nombre de usuario
            string contraseniaArchivo = linea.substr(coma + 1); // Extrae la contrase�a

            // Compara los datos ingresados con los del archivo
            if (usuario == nombre && contraseniaArchivo == contrasenia) {
                usuarioActual = nombre;
                cout << "Ingreso exitoso." << endl;
                archivo.close();      // Cierra el archivo
                opcion.menu(usuario);        // Llama al men� principal del sistema
                return;               // Sale de la funci�n
            }
        }
        archivo.close();  // Cierra el archivo si no se encontr� coincidencia
        cout << "Nombre de usuario o contrasena incorrecta." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Funci�n para mostrar todos los usuarios registrados
void sistema::mostrarUsuarios() {
    system("cls");  // Limpia la pantalla

    ifstream archivo(archivoUsuarios);  // Abre el archivo en modo lectura
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {     // Lee l�nea por l�nea
            size_t coma = linea.find(",");    // Encuentra la coma
            string usuario = linea.substr(0, coma);            // Extrae el nombre de usuario
            string contrasenia = linea.substr(coma + 1);       // Extrae la contrase�a

            string asteriscos(contrasenia.length(), '*');      // Crea una cadena de asteriscos del mismo largo

            // Muestra el usuario y su contrase�a oculta
            cout << "Nombre de usuario: " << usuario << endl;
            cout << "Contrasenia: " << asteriscos << endl;
            cout << "===============================" << endl << endl;
        }
        archivo.close();  // Cierra el archivo despu�s de leer
    } else {
        cout << "No se pudo abrir el archivo." << endl;  // Mensaje si el archivo no se puede abrir
    }
}
