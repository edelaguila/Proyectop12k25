#include <iostream>
#include <fstream>
#include <string>
#include "Empleados.h"
#include "Cliente.h"
#include "Proveedores.h"
#include "Contabilidad.h"
#include "Auditoria.h"
#include "Usuario.h"
#include <conio.h> //para la funci�n getch() que permite capturar teclas sin mostrarlas
#include "Nominas.h"
#include "Bitacora.h"
using namespace std;



// Pausar el programa esperando ENTER
void pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

// Mostrar el men� principal
void mostrarMenu() {
    //se crean objetos de cada clase para poder usar sus funciones
    Empleados empleados;
    Cliente cliente;
    Proveedor proveedor;
    Contabilidad contabilidad;
    Auditoria auditoria;
    Nominas nominas;
    Bitacora bitacora;

    int opcion;
    do {
        cout << "\n------------------------------------";
        cout << "\n        SISTEMA BANCARIO";
        cout << "\n------------------------------------";
        cout << "\n 1. Nominas";
        cout << "\n 2. Cliente";
        cout << "\n 3. Empleados";
        cout << "\n 4. Contabilidad";
        cout << "\n 5. Auditoria";
        cout << "\n 6. Proveedores";
        cout << "\n 7. Bitacora";
        cout << "\n 8. Salir";
        cout << "\n------------------------------------";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        // Validar entrada incorrecta
        if (cin.fail()) {
            cin.clear(); // limpiar error
            cin.ignore(10000, '\n'); // descartar entrada
            opcion = 0;
        }

        switch (opcion) {
    case 1:
        nominas.menuNominas();
        bitacora.insertar("Admin", 4000, "Nominas", "Ingres� al m�dulo de N�minas");
        break;
    case 2:
        cliente.menuCliente();
        bitacora.insertar("Admin", 4100, "Clientes", "Ingres� al m�dulo de Clientes");
        break;
    case 3:
    empleados.menuEmpleados();  // Aqu� se llama al m�todo correcto de la clase Empleados
    bitacora.insertar("Admin", 4001, "Empleados", "Ingres� al m�dulo de Empleados");
        break;

    case 4:
        contabilidad.generarReporte();
        bitacora.insertar("Admin", 4301, "Contabilidad", "Generar reporte contable");
        break;
    case 5:
        auditoria.revisarTransacciones();
        bitacora.insertar("Admin", 4401, "Auditor�a", "Revisar transacciones");
        break;
    case 6:
        proveedor.menuProveedor();
        bitacora.insertar("Admin", 4200, "Proveedores", "Ingres� al m�dulo de Proveedores");
        break;
    case 7:
        bitacora.menuBitacora();
        bitacora.insertar("Admin", 4402, "Sistema", "Usuario cerr� sesi�n");
        break;
    case 8:
    bitacora.insertar("Admin", 4901, "Sistema", "Usuario cerr� sesi�n");
    cout << "\nSaliendo del sistema... Gracias!\n";
    break;

    default:
        cout << "\nOpci�n inv�lida. Intente de nuevo.\n";
        bitacora.insertar("Admin", 4902, "Sistema", "Intento de opci�n inv�lida");
        break;
}

                pausar();


    } while (opcion != 8);
}

// Funci�n principal
int main() {
    while (true) {
        // Mostrar el men� de autenticaci�n
        if (Usuario::menuAutenticacion()) {
            // Si inicia sesi�n con �xito, mostrar men� bancario
            mostrarMenu();

            // Despu�s de salir del men� bancario:
            pausar();
            Usuario::limpiarPantalla();  // si la hiciste p�blica o moviste la funci�n
        } else {
            cout << "\nAutenticaci�n fallida o el usuario decidi� salir.\n";
            break; // salir completamente del programa
        }
    }

    return 0;
}



