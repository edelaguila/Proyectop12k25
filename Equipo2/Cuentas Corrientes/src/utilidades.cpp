// Archivo: utilidades.cpp
// Implementación de funciones auxiliares para validación y utilidades comunes
// Autora: Dulce Rocio Reyes Pirir

//Programación secundaria Astrid Ruíz (no toque nada de limpiar pantalla y esas cosas,
//arreglé todos los errores con las funciones de traer los datos de clientes, proveedores, acreedor.
//Tambien arreglé los errores q daba con los archivos (tuve q modificar las clases d clientes, proveedor, acreedor para q funcionara)
//- astrid

#include "utilidades.h"
#include "factura.h"
#include <fstream>
#include <sstream>
#include <limits>
#include <cctype>
#include <algorithm>

using namespace std;

// Estructuras para lectura binaria
struct ClienteBin {
    char id[15];
    char nombre[50];      // Orden igual que en clase cliente
    char telefono[15];
    char nit[15];
};

struct ProveedorBin {
    char id[15];          // Orden igual que en clase proveedor
    char nombreProveedor[50];
    char nit[15];
    char telefono[15];
    char numCuenta[20];
    char banco[30];
};

struct AcreedorBin {
    char id[15];          // Orden igual que en clase acreedor
    char nombreAcreedor[50];
    char nit[15];
    char telefono[15];
    char numCuenta[20];
    char banco[30];
};

void limpiarEntrada() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pausarPantalla() {
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get();
}

void pausar() {
    system("pause");
}

void limpiarPantalla() {
    system("cls");
}

string aMayusculas(string texto) {
    transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
    return texto;
}

bool esNumeroEntero(const string& str) {
    if (str.empty()) return false;
    return all_of(str.begin(), str.end(), ::isdigit);
}

bool esNumeroDecimal(const string& str) {
    bool punto = false;
    for (char c : str) {
        if (c == '.') {
            if (punto) return false;
            punto = true;
        } else if (!isdigit(c)) {
            return false;
        }
    }
    return !str.empty();
}

// Busca cliente por ID (binario)
bool obtenerDatosClientePorID(const string& idBuscar, string& nombre, string& nit) {
    ifstream archivo("cliente.bin", ios::binary);
    if (!archivo) return false;

    ClienteBin temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(ClienteBin))) {
        if (string(temp.id) == idBuscar) {
            nombre = string(temp.nombre);
            nit = string(temp.nit);
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

// Busca proveedor por ID (binario)
bool obtenerDatosProveedorPorID(const string& idBuscar, string& nombre, string& nit) {
    ifstream archivo("proveedor.bin", ios::binary);
    if (!archivo) return false;

    ProveedorBin temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(ProveedorBin))) {
        if (string(temp.id) == idBuscar) {
            nombre = string(temp.nombreProveedor);
            nit = string(temp.nit);
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

// Busca acreedor por ID (binario)
bool obtenerDatosAcreedorPorID(const string& idBuscar, string& nombre, string& nit) {
    ifstream archivo("acreedor.bin", ios::binary);
    if (!archivo) return false;

    AcreedorBin temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(AcreedorBin))) {
        if (string(temp.id) == idBuscar) {
            nombre = string(temp.nombreAcreedor);
            nit = string(temp.nit);
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}
