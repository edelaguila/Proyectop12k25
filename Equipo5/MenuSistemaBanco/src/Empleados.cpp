//Programaddo por Karla Patricia Ruiz Ordo�ez 9959-24-6859
#include "Empleados.h"      // Incluye la declaraci�n de la clase Empleados y sus m�todos
#include <iostream>         // Permite usar entradas y salidas est�ndar (cin, cout)
#include <fstream>          // Permite manejo de archivos (ifstream, ofstream)
#include <algorithm>        // Para usar funciones como sort
#include "Bitacora.h"       // Bit�cora para registrar acciones

using namespace std;

Bitacora bitacoralogEmpleados; // Instancia para registrar acciones de empleados en la bit�cora

// M�todo para limpiar pantalla seg�n el sistema operativo
void Empleados::limpiarPantalla() {
#ifdef _WIN32
    system("cls");           // En Windows limpia con cls
#else
    system("clear");         // En otros sistemas (Linux, Mac) limpia con clear
#endif
}

// M�todo para pausar la ejecuci�n del programa hasta que el usuario presione ENTER
void Empleados::pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();            // Ignora cualquier car�cter en el buffer
    cin.get();               // Espera a que el usuario presione ENTER
}

// Carga los datos de empleados desde el archivo empleados.txt
void Empleados::cargarEmpleados() {
    empleados.clear();                       // Limpia el vector antes de cargar nuevos datos
    ifstream archivo("empleados.txt");      // Abre el archivo de lectura
    Empleado e;
    string linea;

    while (getline(archivo, linea)) {       // Lee l�nea por l�nea
        size_t pos = 0;
        string datos[4];

        // Divide la l�nea por comas para separar los campos
        for (int i = 0; i < 3; ++i) {
            pos = linea.find(',');
            datos[i] = linea.substr(0, pos);
            linea.erase(0, pos + 1);
        }
        datos[3] = linea; // �ltimo campo (tel�fono)

        // Asigna los valores al objeto Empleado
        e.nombre = datos[0];
        e.codigo = datos[1];
        e.puesto = datos[2];
        e.telefono = datos[3];

        empleados.push_back(e);             // Agrega el empleado al vector
    }

    archivo.close();                        // Cierra el archivo
    ordenarEmpleados();                     // Ordena alfab�ticamente
}

// Guarda la lista de empleados actual en el archivo empleados.txt
void Empleados::guardarEmpleados() {
    ofstream archivo("empleados.txt");      // Abre el archivo para escritura
    for (const auto& e : empleados) {
        archivo << e.nombre << "," << e.codigo << "," << e.puesto << "," << e.telefono << "\n";
    }
    archivo.close();                        // Cierra el archivo
}

// Ordena alfab�ticamente el vector de empleados por nombre
void Empleados::ordenarEmpleados() {
    sort(empleados.begin(), empleados.end(), [](const Empleado& a, const Empleado& b) {
        return a.nombre < b.nombre;
    });
}

// Muestra el men� principal de empleados y gestiona las opciones del usuario
void Empleados::menuEmpleados() {
    int opcion;
    do {
        cargarEmpleados();                  // Carga datos antes de cada acci�n
        limpiarPantalla();
        cout << "\n===== MEN� DE EMPLEADOS =====";
        cout << "\n1. Crear Empleado";
        cout << "\n2. Borrar Empleado";
        cout << "\n3. Buscar Empleado";
        cout << "\n4. Modificar Empleado";
        cout << "\n5. Despliegue de Empleados";
        cout << "\n6. Salir";
        cout << "\nSeleccione una opci�n: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: crearEmpleado(); break;
            case 2: borrarEmpleado(); break;
            case 3: buscarEmpleado(); break;
            case 4: modificarEmpleado(); break;
            case 5: desplegarEmpleados(); break;
            case 6:
                limpiarPantalla(); return;  // Salir del men�
            default:
                cout << "\nOpci�n inv�lida.";
                pausar();
        }
    } while (true);
}

// Crea un nuevo empleado solicitando los datos al usuario
void Empleados::crearEmpleado() {
    limpiarPantalla();
    Empleado e;
    cout << "\n=== Crear Empleado ===";
    cout << "\nNombre: "; getline(cin, e.nombre);
    cout << "C�digo: "; getline(cin, e.codigo);
    cout << "Puesto de trabajo: "; getline(cin, e.puesto);
    cout << "Tel�fono: "; getline(cin, e.telefono);

    empleados.push_back(e);                 // Agrega al vector
    ordenarEmpleados();                     // Ordena por nombre
    guardarEmpleados();                     // Guarda en archivo
    bitacoralogEmpleados.insertar("Admin", 5001, "Empleados", "Crear");  // Registra en bit�cora

    cout << "\nEmpleado agregado correctamente.";
    pausar();
}

// Borra un empleado busc�ndolo por nombre y c�digo
void Empleados::borrarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Borrar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool eliminado = false;
    vector<Empleado> nuevaLista;

    for (const auto& e : empleados) {
        if (e.nombre != nombre || e.codigo != codigo) {
            nuevaLista.push_back(e);        // Conserva el empleado
        } else {
            eliminado = true;               // Marca como eliminado
        }
    }

    if (eliminado) {
        empleados = nuevaLista;             // Reemplaza la lista
        guardarEmpleados();                 // Guarda cambios
        bitacoralogEmpleados.insertar("Admin", 5002, "Empleados", "Borrar");
        cout << "\nEmpleado eliminado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Busca un empleado por nombre y c�digo, y muestra su informaci�n
void Empleados::buscarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Buscar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool encontrado = false;

    for (const auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nEmpleado encontrado:";
            cout << "\nNombre   : " << e.nombre;
            cout << "\nC�digo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTel�fono : " << e.telefono;
            bitacoralogEmpleados.insertar("Admin", 5003, "Empleados", "Buscar");
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Modifica la informaci�n de un empleado existente
void Empleados::modificarEmpleado() {
    limpiarPantalla();
    string nombre, codigo;
    cout << "\n=== Modificar Empleado ===";
    cout << "\nNombre: "; getline(cin, nombre);
    cout << "C�digo: "; getline(cin, codigo);

    bool modificado = false;

    for (auto& e : empleados) {
        if (e.nombre == nombre && e.codigo == codigo) {
            cout << "\nIngrese nueva informaci�n:";
            cout << "\nNuevo Nombre: "; getline(cin, e.nombre);
            cout << "Nuevo C�digo: "; getline(cin, e.codigo);
            cout << "Nuevo Puesto: "; getline(cin, e.puesto);
            cout << "Nuevo Tel�fono: "; getline(cin, e.telefono);
            modificado = true;
            break;
        }
    }

    if (modificado) {
        ordenarEmpleados();                 // Reordena por nombre
        guardarEmpleados();                 // Guarda cambios
        bitacoralogEmpleados.insertar("Admin", 5004, "Empleados", "Modificar");
        cout << "\nEmpleado modificado correctamente.";
    } else {
        cout << "\nEmpleado no encontrado.";
    }

    pausar();
}

// Despliega todos los empleados registrados
void Empleados::desplegarEmpleados() {
    limpiarPantalla();
    cout << "\n=== Empleados Registrados ===\n";

    if (empleados.empty()) {
        cout << "\nNo hay empleados registrados.";
    } else {
        for (const auto& e : empleados) {
            cout << "\n----------------------------";
            cout << "\nNombre   : " << e.nombre;
            cout << "\nC�digo   : " << e.codigo;
            cout << "\nPuesto   : " << e.puesto;
            cout << "\nTel�fono : " << e.telefono;
        }
        cout << "\n----------------------------";
        bitacoralogEmpleados.insertar("Admin", 5005, "Empleados", "Desplegar");
    }

    pausar();
}


