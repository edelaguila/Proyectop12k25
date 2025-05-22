// Encabezado para funciones de manejo de facturas - Dulce Rocio Reyes Pirir

#ifndef FACTURA_H
#define FACTURA_H
#include <string>
#include <ctime>
#include <iomanip>
#include "cliente.h"

// Estructura que representa una factura
struct Factura {
    int codigo;
    cliente cliente;
    double monto;
    double saldoPendiente;
    std::string fecha;
    std::string hora;
    std::string tipo;
    std::string estado;
    std::string tipoOperacion;
};

// Prototipos de funciones relacionadas con la gestión de facturas

// Menús específicos para cada tipo de factura
void menuFacturaCliente();
void menuFacturaProveedor();
void menuFacturaAcreedor();
void menuReporteFactura();

// Funciones de operaciones CRUD sobre facturas
void registrarFacturaPorTipo(const std::string& tipo);
void mostrarFacturasPorTipo(const std::string& tipo);
void modificarFacturaPorTipo(const std::string& tipo);
void eliminarFacturaPorTipo(const std::string& tipo);

// Funciones utilitarias
std::string obtenerFechaActual();
std::string obtenerHoraActual();
std::string formatearMonto(double monto);

#endif
