#include "bitacora.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <limits>

using namespace std;
//Isaias Cedillo (9959-24-1672) "IsaC8-bit"
// Muestra el men� principal del sistema de bit�cora
void bitacora::menu()
{
    int choice;
    do {
        system("cls"); // Limpia la pantalla

        // Men� de opciones
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t |   SISTEMA GESTI�N BITACORA  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Despliegue Bitacora" << endl;
        cout << "\t\t\t 2. Agregar Registro" << endl;
        cout << "\t\t\t 3. Salir" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpci�n a escoger:[1/2/3]: ";

        cin >> choice;

        // Manejo de errores si la entrada no es un n�mero v�lido
        if (cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta
            cout << "\n\t\t\tEntrada invalida. Intente de nuevo...";
            cin.get(); // Pausa
            continue;
        }

        cin.ignore(); // Limpia el salto de l�nea antes de usar getline

        switch (choice) {
            case 1:
                desplegar(); // Mostrar los registros
                break;
            case 2: {
                // Solicita los datos al usuario
                string nombre, aplicacion, accion;
                cout << "\n\t\t\tIngrese nombre del usuario: ";
                getline(cin, nombre);
                // Generar c�digo de aplicaci�n autom�ticamente (de 7000 a 7999)
                fstream readFile("bitacora.txt", ios::in);
                int codigoApp = 7000;

                    if (readFile)
                        {
                        string lastNombre, lastAplicacion, lastAccion, lastTimestamp;
                        while (readFile >> std::quoted(lastNombre))
                            {
                                readFile.ignore();
                                readFile >> std::quoted(lastAplicacion);
                                readFile.ignore();
                                readFile >> std::quoted(lastAccion);
                                readFile.ignore();
                                getline(readFile, lastTimestamp);

                                try
                                {
                                    int cod = stoi(lastAplicacion);
                                    if (cod >= 7000 && cod < 7999)
                                        {
                                            codigoApp = cod + 1;
                                        }
                                        else if (cod >= 7999)
                                        {
                                            codigoApp = 7000; // Reinicia a 7000 si supera el rango
                                        }
                                }
                                catch (...)
                                {
            // Si la aplicaci�n no es un n�mero, se ignora
                                }
                            }
                    }
readFile.close();

// Asigna el c�digo como string
aplicacion = to_string(codigoApp);

                cout << "\t\t\tIngrese accion realizada: ";
                getline(cin, accion);
                insertar(nombre, aplicacion, accion); // Agrega el registro
                break;
            }
            case 3:
                break; // Salir del programa
            default:
                cout << "\n\t\t\t Opci�n invalida...Por favor prueba otra vez..";
                cin.get();
        }
    } while (choice != 3); // Repite hasta que el usuario elija salir
}

// Agrega un nuevo registro al archivo bitacora.txt
void bitacora::insertar(string nombre, string aplicacion, string accion)
{
    system("cls"); // Limpia la pantalla
    fstream file("bitacora.txt", ios::app | ios::out); // Abre archivo para agregar contenido

    // Obtiene la fecha y hora actual
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", ltm); // Formato: a�o-mes-d�a hora:min:seg

    // Guarda los datos en el archivo con comillas para evitar errores con espacios
    file << std::quoted(nombre) << ","
         << std::quoted(aplicacion) << ","
         << std::quoted(accion) << ","
         << timestamp << "\n";

    file.close(); // Cierra el archivo

    cout << "\n\t\t\tRegistro agregado exitosamente.\n";
    system("pause"); // Pausa para que el usuario vea el mensaje
}

// Muestra los registros almacenados en bitacora.txt
void bitacora::desplegar()
{
    system("cls"); // Limpia pantalla
    fstream file("bitacora.txt", ios::in); // Abre el archivo para lectura
    int total = 0;
    string nombre, aplicacion, accion, timestamp;

    cout << "\n--------------------- Tabla de Detalles de Bitacora ---------------------" << endl;

    if (!file) {
        cout << "\n\t\t\tNo hay informaci�n disponible."; // Si el archivo no existe
    } else {
        // Lee cada l�nea del archivo usando std::quoted para manejar campos con espacios
        while (file >> std::quoted(nombre)) {
            file.ignore(); // Ignora coma
            file >> std::quoted(aplicacion);
            file.ignore();
            file >> std::quoted(accion);
            file.ignore();
            getline(file, timestamp); // El timestamp va sin comillas

            total++;
            // Muestra los datos del registro
            cout << "\n\t\t\tNombre Usuario     : " << nombre << endl;
            cout << "\t\t\tAplicaci�n         : " << aplicacion << endl;
            cout << "\t\t\tAcci�n realizada   : " << accion << endl;
            cout << "\t\t\tFecha y Hora       : " << timestamp << endl;
            cout << "\t\t\t---------------------------------------------";
        }

        if (total == 0) {
            cout << "\n\t\t\tNo hay registros a�n.";
        }
    }

    file.close(); // Cierra el archivo
    cout << "\n\n";
    system("pause"); // Pausa para que el usuario vea los resultados
}

std::string bitacora::generarCodigoAplicacion()
 {
   // Abre el archivo "bitacora.txt" en modo lectura para examinar los registros existentes
fstream readFile("bitacora.txt", ios::in);

// Inicializa la variable codigoApp con 7000, que ser� el valor base o inicial del c�digo de aplicaci�n
int codigoApp = 7000;

if (readFile) {  // Verifica si el archivo se abri� correctamente
    // Variables temporales para almacenar los datos le�dos de cada registro
    string lastNombre, lastAplicacion, lastAccion, lastTimestamp;

    // Ciclo para leer todo el archivo l�nea por l�nea, extrayendo cada campo
    // El formato esperado es: "nombre","aplicacion","accion",timestamp
    while (readFile >> std::quoted(lastNombre)) {
        // Lee el campo nombre entre comillas (std::quoted maneja espacios y comillas internas)

        readFile.ignore();  // Ignora el car�cter coma (,) despu�s del campo nombre

        readFile >> std::quoted(lastAplicacion);  // Lee el campo aplicacion entre comillas

        readFile.ignore();  // Ignora la coma despu�s del campo aplicacion

        readFile >> std::quoted(lastAccion);  // Lee el campo accion entre comillas

        readFile.ignore();  // Ignora la coma despu�s del campo accion

        getline(readFile, lastTimestamp);  // Lee el campo timestamp completo (hasta el fin de l�nea)

        try {
            // Intenta convertir el campo 'aplicacion' a entero para manejar c�digos num�ricos
            int cod = stoi(lastAplicacion);

            // Verifica si el c�digo est� dentro del rango v�lido 7000 a 7998
            if (cod >= 7000 && cod < 7999) {
                // Actualiza codigoApp para que sea el siguiente n�mero consecutivo
                codigoApp = cod + 1;
            }
            else if (cod >= 7999) {
                // Si el c�digo supera el l�mite 7999, reinicia a 7000 para evitar salirse del rango
                codigoApp = 7000;
            }
        } catch (...) {
            // Si la conversi�n a entero falla (p.ej. aplicacion no es num�rico), ignora el error
            // Esto permite que registros con valores no num�ricos en aplicacion no interrumpan el proceso
        }
    }
}

// Cierra el archivo para liberar recursos
readFile.close();
    return to_string(codigoApp);
}
