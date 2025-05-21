//Maria Celeste Mayen Ibarra  9959-23-3775
#include "Cliente.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

vector<Cliente> Cliente::clientes;
int Cliente::contadorClientes = 200;  // Código inicial modificado

Cliente::Cliente() {}

Cliente::Cliente(string n, string t, string nit, string cod)
    : nombre(n), telefono(t), nit(nit), codigo(cod) {}

std::vector<Cliente>& Cliente::obtenerClientes() {
    return clientes;
}

void Cliente::MenuClientes() {
    int opcion;
    do {
        system("cls");
        cout << "\t\t\t---------------------------\n";
        cout << "\t\t\t |   SISTEMA DE CLIENTES  |\n";
        cout << "\t\t\t---------------------------\n";
        cout << "\t\t\t 1. NUEVO CLIENTE\n";
        cout << "\t\t\t 2. MODIFICAR CLIENTE\n";
        cout << "\t\t\t 3. ELIMINAR CLIENTE\n";
        cout << "\t\t\t 4. SALIR\n";
        cout << "\t\t\t-------------------------------\n";
        cout << "\t\t\tIngresa tu opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                AgregarCliente();
                break;
            case 2:
                ModificarCliente();
                break;
            case 3:
                EliminarCliente();
                break;
            case 4:
                return;
            default:
                cout << "\n\t\t\t Opción inválida...Intente otra vez...\n";
                cin.ignore();
                cin.get();
        }
    } while (opcion != 4);
}

void Cliente::AgregarCliente() {
    system("cls");
    cout << "\t\t\t---------------------\n";
    cout << "\t\t\t |   NUEVO CLIENTE   |\n";
    cout << "\t\t\t----------------------\n";

    if (contadorClientes > 300) {
        cout << "\t\t\tLímite de clientes alcanzado.\n";
        return;
    }

    string nombre, telefono, nit;
    string codigo = to_string(contadorClientes++);

    cout << "\t\t\tIngrese el nombre del cliente: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "\t\t\tIngrese el número telefonico del cliente: ";
    cin >> telefono;
    cout << "\t\t\tIngrese el numero de NIT del cliente: ";
    cin >> nit;

    clientes.push_back(Cliente(nombre, telefono, nit, codigo));
    GuardarClientes();
    cout << "\t\t\tCliente agregado exitosamente.\n";

    cout << "\nPresione ENTER para regresar al menú...";
    cin.ignore();
    cin.get();
}

void Cliente::ModificarCliente() {
    system("cls");
    cout << "\t\t\t--------------------------\n";
    cout << "\t\t\t |   MODIFICAR CLIENTE   |\n";
    cout << "\t\t\t--------------------------\n";

    string codigoBuscado;
    cout << "\t\t\tIngrese el código del cliente a modificar: ";
    cin >> codigoBuscado;

    for (auto& cliente : clientes) {
        if (cliente.codigo == codigoBuscado) {
            cout << "\t\t\tCliente encontrado:\n";
            cout << "\t\t\tNombre: " << cliente.nombre << "\n";
            cout << "\t\t\tTelefono: " << cliente.telefono << "\n";
            cout << "\t\t\tNIT: " << cliente.nit << "\n";

            cout << "\t\t\t¿Que desea modificar?\n";
            cout << "\t\t\t1. Telefono\n";
            cout << "\t\t\t2. NIT\n";
            int opcion;
            cin >> opcion;

            if (opcion == 1) {
                cout << "\t\t\tIngrese nuevo número telefonico: ";
                cin >> cliente.telefono;
            } else if (opcion == 2) {
                cout << "\t\t\tIngrese nuevo NIT: ";
                cin >> cliente.nit;
            } else {
                cout << "\t\t\tOpcion inválida.\n";
            }

            GuardarClientes();
            cout << "\t\t\tCliente modificado exitosamente.\n";
            break;
        }
    }

    cout << "\t\t\tPresione ENTER para regresar al menu...";
    cin.ignore();
    cin.get();
}

void Cliente::EliminarCliente() {
    system("cls");
    cout << "\t\t\t-------------------------\n";
    cout << "\t\t\t |   ELIMINAR CLIENTE   |\n";
    cout << "\t\t\t-------------------------\n";

    string codigoBuscado;
    cout << "\t\t\tIngrese el codigo del cliente a eliminar: ";
    cin >> codigoBuscado;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->codigo == codigoBuscado) {
            clientes.erase(it);
            GuardarClientes();
            cout << "\t\t\tCliente eliminado exitosamente.\n";
            break;
        }
    }

    cout << "\t\t\tPresione ENTER para regresar al menu...";
    cin.ignore();
    cin.get();
}

void Cliente::MostrarClientes() {
    system("cls");
    cout << "\t\t\t----------------------------\n";
    cout << "\t\t\t |   REGISTRO DE CLIENTE   |\n";
    cout << "\t\t\t----------------------------\n";

    if (clientes.empty()) {
        cout << "\t\t\tNo hay clientes registrados.\n";
    } else {
        cout << left << setw(10) << "Codigo" << setw(20) << "Nombre"
             << setw(15) << "Telefono" << setw(15) << "NIT" << "\n";
        cout << "-------------------------------------------------------------\n";

        for (const auto& cliente : clientes) {
            cout << left << setw(10) << cliente.codigo
                 << setw(20) << cliente.nombre
                 << setw(15) << cliente.telefono
                 << setw(15) << cliente.nit << "\n";
        }
    }

    cout << "\t\t\tPresione ENTER para regresar al menu...";
    cin.ignore();
    cin.get();
}

void Cliente::GuardarClientes() {
    ofstream archivo("clientes.dat", ios::binary);
    if (!archivo) {
        cout << "Error al abrir el archivo.\n";
        return;
    }
    for (const auto& cliente : clientes) {
        archivo.write(reinterpret_cast<const char*>(&cliente), sizeof(Cliente));
    }
    archivo.close();
}

void Cliente::CargarClientes() {
    ifstream archivo("clientes.dat", ios::binary);
    if (!archivo) return;

    Cliente cliente;
    while (archivo.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente))) {
        clientes.push_back(cliente);
    }
    archivo.close();
}
