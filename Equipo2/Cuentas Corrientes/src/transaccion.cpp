////Clase transacción - Astrid Ruíz 9959242976 Programada 5/5/25
//Esta clase fue creada para el proceso de transacciones, sin embargo fue indicado por el ingeniero ya no trabajar este proceso
//Por lo que tiene un CRUD para las transacciones, pero no sé conecta con el demás sistema
//Sigue con archivos .txt porque se indico no utilizarlos.
#include "transaccion.h"
#include "bitacora.h"
#include "usuarios.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

extern usuarios  usuariosrRegistrado;

// Constructor por defecto
transaccion::transaccion() {}

// Constructor con parámetros
transaccion::transaccion(string id, string tipo, double monto, string fecha, string banco) {
    this->idTransaccion = id;
    this->tipo = tipo;
    this->monto = monto;
    this->fecha = fecha;
    this->banco = banco;
}

// Generar nuevo ID automático leyendo el último del archivo
string transaccion::generarNuevoID() {
    ifstream archivo("transacciones.txt");
    string linea, ultimoID = "8700"; //inicié desde este para la bitacora

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            size_t pos = linea.find("|");
            if (pos != string::npos) {
                ultimoID = linea.substr(0, pos);
            }
        }
        archivo.close();
    }

    int nuevoID = stoi(ultimoID) + 1; //aumentarle 1 al id
    return to_string(nuevoID);
}

// Registrar nueva transacción
void transaccion::registrarTransaccion(string tipoOperacion) {
    idTransaccion = generarNuevoID(); //el id que se genera
    tipo = tipoOperacion; //depende si es retiro, deposito o transaccion

    cout << "Ingrese monto: ";
    cin >> monto;
    cout << "Ingrese fecha (YYYY-MM-DD): ";
    cin >> fecha;
    cout << "Ingrese banco: ";
    cin >> banco;
}

// Mostrar una sola transacción
void transaccion::mostrarTransaccion() const {
    cout << "ID: " << idTransaccion << " | "
         << "Tipo: " << tipo << " | "
         << "Monto: Q" << monto << " | "
         << "Fecha: " << fecha << " | "
         << "Banco: " << banco << endl;
}

// Guardar transacción en el archivo
void transaccion::guardarEnArchivo() const {
    ofstream archivo("transacciones.txt", ios::app);
    if (archivo.is_open()) {
        archivo << idTransaccion << "|"
                << tipo << "|"
                << monto << "|"
                << fecha << "|"
                << banco << endl;
        archivo.close();
        cout << "\nTransacción registrada correctamente.\n";

        // Registrar en bitácora
        bitacora b;
        b.insertar("usuario1", "Transacción", "Registro de nueva transacción ID: " + idTransaccion);
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

// Mostrar todas las transacciones desde archivo
void transaccion::mostrarTodasDesdeArchivo() {
    ifstream archivo("transacciones.txt");
    string linea;

    if (archivo.is_open()) {
        cout << "\n=== Listado de Transacciones Bancarias ===\n\n";
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo.\n";
    }
}

// Editar una transacción por ID
void transaccion::editarTransaccion(string id) {
    ifstream archivoOriginal("transacciones.txt");
    ofstream archivoTemp("temp.txt");
    string linea;
    bool encontrado = false;

    if (archivoOriginal.is_open() && archivoTemp.is_open()) {
        while (getline(archivoOriginal, linea)) {
            if (linea.find(id + "|") == 0) {
                encontrado = true;
                cout << "Transacción encontrada: " << linea << endl;
                transaccion nueva;
                nueva.idTransaccion = id;
                cout << "Ingrese nuevo tipo: ";
                cin >> nueva.tipo;
                cout << "Ingrese nuevo monto: ";
                cin >> nueva.monto;
                cout << "Ingrese nueva fecha: ";
                cin >> nueva.fecha;
                cout << "Ingrese nuevo banco: ";
                cin >> nueva.banco;

                archivoTemp << nueva.idTransaccion << "|"
                            << nueva.tipo << "|"
                            << nueva.monto << "|"
                            << nueva.fecha << "|"
                            << nueva.banco << endl;
            } else {
                archivoTemp << linea << endl;
            }
        }
        archivoOriginal.close();
        archivoTemp.close();
        remove("transacciones.txt");
        rename("temp.txt", "transacciones.txt");

        if (encontrado) {
            cout << "Transacción editada.\n";
            bitacora b;
            b.insertar("usuario1", "Transacción", "Edición de transacción ID: " + id);
        } else {
            cout << "No se encontró la transacción.\n";
        }
    } else {
        cout << "Error al abrir los archivos.\n";
    }
}

// Eliminar una transacción por ID
void transaccion::eliminarTransaccion(string id) {
    ifstream archivoOriginal("transacciones.txt");
    ofstream archivoTemp("temp.txt");
    string linea;
    bool encontrado = false;

    if (archivoOriginal.is_open() && archivoTemp.is_open()) {
        while (getline(archivoOriginal, linea)) {
            if (linea.find(id + "|") == 0) {
                encontrado = true;
                cout << "Transacción eliminada: " << linea << endl;
            } else {
                archivoTemp << linea << endl;
            }
        }
        archivoOriginal.close();
        archivoTemp.close();
        remove("transacciones.txt");
        rename("temp.txt", "transacciones.txt");

        if (encontrado) {
            cout << "Transacción eliminada correctamente.\n";
            bitacora b;
            b.insertar("usuario1", "Transacción", "Eliminación de transacción ID: " + id);
        } else {
            cout << "No se encontró la transacción.\n";
        }
    } else {
        cout << "Error al abrir los archivos.\n";
    }
}

//agregar un backup al archivo
//Realizando respaldo de transacciones
bool transaccion::backupTransacciones() {
    system("cls");
    fstream file, backupFile;
    string currentId, currentName, currentPass;

    cout << "\n\t\t---------------------------------" << endl;
    cout << "\t\t  BACKUP DE TRANSACCIONES  " << endl;
    cout << "\t\t---------------------------------" << endl << endl;

    file.open("transacciones.txt", ios::in);
    if (!file) {
        cout << "\n\t\tNo hay información disponible para realizar el backup..." << endl;
        return false;
    }

    backupFile.open("Transacciones_Backup.txt", ios::out);
    if (!backupFile) {
        cout << "\n\t\tError al crear el archivo de backup." << endl;
        file.close();
        return false;
    }

    cout << "\n\t\tRealizando backup de datos..." << endl;

    // Copia línea por línea del archivo original al de backup
    file >> currentId >> currentName >> currentPass;
    while (!file.eof()) {
        backupFile << currentId << "        " << currentName << "       " << currentPass << "       " << endl;
        file >> currentId >> currentName >> currentPass;
    }

    file.close();
    backupFile.close();

    cout << "\n\t\tBackup realizado con éxito" << endl;

    // Registrar en bitácora
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8100", "BACK");

    return true;
}
