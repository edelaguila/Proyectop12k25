// Angoly Araujo Mayo 2025
#include "facturacion.h" // Inclusi�n del encabezado donde est�n declaradas las funciones de la clase Facturacion
#include <iostream> // Inclusi�n de la biblioteca est�ndar para entrada/salida
using namespace std;

// Variables externas definidas en otro lugar del programa
extern usuarios usuarioRegistrado; // Objeto global para el usuario registrado
extern bitacora auditoria;         // Objeto global para el registro de auditor�as

// M�todo principal que gestiona el men� de facturaci�n
void Facturacion::gestionFacturacion() {
    int opcion; // Variable para almacenar la opci�n seleccionada por el usuario
    do {
        system("cls"); // Limpia la pantalla
        cout << "\t\t========================================" << endl;
        cout << "\t\t| FACTURACION Y ANALISIS - LOGISTICA    |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Generar factura" << endl;
        cout << "\t\t 2. Consultar estado de pago" << endl;
        cout << "\t\t 3. Registrar pago" << endl;
        cout << "\t\t 4. Reportes financieros" << endl;
        cout << "\t\t 5. Volver al menu anterior" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tOpcion a escoger: ";
        cin >> opcion; // Captura la opci�n del usuario

        // Evaluaci�n de la opci�n usando switch
        switch(opcion) {
            case 1: generarFactura(); break;              // Opci�n 1: Generar factura
            case 2: consultarEstadoPago(); break;         // Opci�n 2: Consultar estado de pago
            case 3: registrarPago(); break;               // Opci�n 3: Registrar pago
            case 4: verReportesFinancieros(); break;      // Opci�n 4: Ver reportes financieros
            case 5: break;                                // Opci�n 5: Salir del men�
            default:
                cout << "\n\t\tOpcion invalida!"; // Mensaje de error para opci�n no v�lida
                cin.get();
        }
    } while(opcion != 5); // El men� se repite hasta que el usuario elija salir
}

// Funci�n que simula la generaci�n de una factura
void Facturacion::generarFactura() {
    cout << "\n\t\t[Generando factura...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "400", "FACT"); // Registro en la bit�cora
    system("pause"); // Pausa para visualizar el mensaje
}

// Funci�n que simula la consulta del estado de pago
void Facturacion::consultarEstadoPago() {
    cout << "\n\t\t[Consultando estado de pago...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "400", "CONSPAG"); // Registro en la bit�cora
    system("pause");
}

// Funci�n que simula el registro de un pago
void Facturacion::registrarPago() {
    cout << "\n\t\t[Registrando pago...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "400", "REGPAG"); // Registro en la bit�cora
    system("pause");
}

// Funci�n que simula la visualizaci�n de reportes financieros
void Facturacion::verReportesFinancieros() {
    cout << "\n\t\t[Mostrando reportes financieros...]" << endl;
    auditoria.insertar(usuarioRegistrado.getNombre(), "400", "REPFIN"); // Registro en la bit�cora
    system("pause");
}

