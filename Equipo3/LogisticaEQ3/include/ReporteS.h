// Gabriela - Mayo 2025
#ifndef REPORTES_H
#define REPORTES_H
#include <string>
using namespace std;

// Clase Reportes: permite generar y mostrar distintos reportes del sistema logistico
class Reportes {
public:
    void mostrarMenuReportes();     // Muestra el menu principal de reportes
    void generarReporteVentas();    // Genera un reporte de ventas
    void generarReporteUsuarios();  // Genera un reporte de usuarios
    void exportarReporte();         // Exporta un reporte a un archivo CSV
};

#endif // REPORTES_H
