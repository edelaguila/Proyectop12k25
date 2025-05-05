// Gabriela Escobar - 5 de Mayo 2025
// Implementaci�n del m�dulo de reportes

#include "Reportes.h"
#include <iostream>
#include <fstream> // Para exportar reportes
#include <vector>  // Para trabajar con colecciones dinamicas

using namespace std;

void Reportes::mostrarMenuReportes() {
    int opcion;

    do {
        cout << "\t\t========================================" << endl;
        cout << "\t\t| MODULO DE REPORTES - LOGISTICA       |" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t 1. Reporte de Ventas" << endl;
        cout << "\t\t 2. Reporte de Usuarios" << endl;
        cout << "\t\t 3. Exportar Reporte" << endl;
        cout << "\t\t 4. Volver al men� principal" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\tSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                generarReporteVentas();
                break;
            case 2:
                generarReporteUsuarios();
                break;
            case 3:
                exportarReporte();
                break;
            case 4:
                break;
            default:
                cout << "\n\t\t�Opcion invalida!" << endl;
                break;
        }

    } while (opcion != 4);
}

void Reportes::generarReporteVentas() {
    // Simula reporte de ventas
    // Aqu� podr�as reemplazarlo con datos dinamicos de una base de datos o archivo.
    cout << "\n\t\t[Mostrando reporte de ventas...]" << endl;
    cout << "\t\tTotal ventas abril 2025: L. 120,000.00" << endl;
    system("pause");
}

void Reportes::generarReporteUsuarios() {
    // Simula reporte de usuarios
    // Aqu� podrias consultar la base de datos o archivo de usuarios.
    cout << "\n\t\t[Mostrando reporte de usuarios activos...]" << endl;
    cout << "\t\tUsuarios activos: 25" << endl;
    system("pause");
}

void Reportes::exportarReporte() {
    // Guardar el reporte de ventas y usuarios en un archivo CSV
    ofstream file("reporte_generado.csv");
    if (file.is_open()) {
        file << "Tipo de Reporte,Valor\n";
        file << "Ventas abril 2025,L. 120,000.00\n";
        file << "Usuarios activos,25\n";
        file.close();
        cout << "\n\t\t[Reporte exportado como 'reporte_generado.csv']" << endl;
    } else {
        cerr << "\n\t\tError al exportar el archivo." << endl;
    }
    system("pause");
}
