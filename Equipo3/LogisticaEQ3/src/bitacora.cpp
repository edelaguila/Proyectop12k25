//LUIS ANGEL MENDEZ FUENTES 9959-24-6845
// MAYO 2025
#include "bitacora.h"  // Inclusi�n del encabezado que declara la clase bitacora
#include <iostream>    // Librer�a para entrada y salida est�ndar
#include <iomanip>     // Librer�a para manipulaci�n de formato (como setw)

using namespace std;   // Uso del espacio de nombres est�ndar para evitar el uso de std::

// M�todo para insertar un registro en la bit�cora
void bitacora::insertar(string usuario, string codigo, string accion) {
    // Abre el archivo bitacora.txt en modo de a�adir al final (append)
    ofstream file("bitacora.txt", ios::app);
    if (file.is_open()) {
        // Escribe en el archivo el usuario, el c�digo y la acci�n con formato fijo
        file << left << setw(20) << usuario    // Campo de 20 caracteres alineado a la izquierda
             << setw(10) << codigo             // Campo de 10 caracteres
             << setw(15) << accion << endl;    // Campo de 15 caracteres y salto de l�nea
        file.close();  // Cierra el archivo despu�s de escribir
    } else {
        // Mensaje de error si no se pudo abrir el archivo
        cerr << "\n\t\tError al abrir la bit�cora!";
    }
}

// M�todo para mostrar el contenido de la bit�cora en pantalla
void bitacora::desplegar() {
    system("cls");  // Limpia la pantalla (solo en sistemas Windows)

    ifstream file("bitacora.txt");  // Abre el archivo para lectura

    // Encabezado decorativo de la bit�cora
    cout << "\t\t========================================" << endl;
    cout << "\t\t| REGISTRO DE BITACORA - LOGISTICA     |" << endl;
    cout << "\t\t========================================" << endl;

    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            // Muestra cada l�nea del archivo con sangr�a
            cout << "\t\t" << linea << endl;
        }
        file.close();  // Cierra el archivo despu�s de la lectura
    } else {
        // Si el archivo no existe o no se pudo abrir, muestra este mensaje
        cout << "\t\tNo hay registros en la bit�cora." << endl;
    }

    // Pie del marco
    cout << "\t\t========================================" << endl;
    system("pause");  // Pausa la ejecuci�n hasta que el usuario presione una tecla
}

// M�todo que muestra el men� de opciones de la bit�cora
void bitacora::menuBitacora() {
    int opcion;  // Variable para almacenar la opci�n del usuario

    do {
        system("cls");  // Limpia la pantalla antes de mostrar el men�

        // Men� principal de la bit�cora
        cout << "\t\t========================================" << endl;
        cout << "\t\t| ADMINISTRACION DE BITACORA           |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Ver registros" << endl;
        cout << "\t\t 2. Exportar a archivo" << endl;
        cout << "\t\t 3. Volver" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion: ";
        cin >> opcion;  // Se lee la opci�n ingresada por el usuario

        switch(opcion) {
            case 1:
                desplegar();  // Muestra los registros
                break;
            case 2:
                // Este caso est� a�n sin implementar
                cout << "\n\t\t[Exportando bit�cora...]" << endl;
                system("pause");
                break;
            case 3:
                // Vuelve al men� anterior o finaliza el ciclo
                break;
            default:
                // Si la opci�n no es v�lida, se notifica al usuario
                cout << "\n\t\tOpcion invalida!";
                cin.get(); // Espera entrada para evitar que se salte la pausa
        }
    } while(opcion != 3);  // Repite hasta que el usuario seleccione la opci�n 3 (Volver)
}
