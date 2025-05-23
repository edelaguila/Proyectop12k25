// Archivo: utilidades.h
// Declaraci�n de funciones auxiliares
// Elaborado por: Dulce Rocio Reyes Pirir

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <string>

using namespace std;

// Funciones comunes
void limpiarEntrada();
void pausarPantalla();
void pausar();
void limpiarPantalla();
string aMayusculas(string texto);
bool esNumeroEntero(const string& str);
bool esNumeroDecimal(const string& str);

// Facturaci�n
void registrarFacturaPorTipo(const string& tipo);

// B�squeda de datos
bool obtenerDatosClientePorID(const string& idBuscar, string& nombre, string& nit);
bool obtenerDatosAcreedorPorID(const string& idBuscar, string& nombre, string& nit);
bool obtenerDatosProveedorPorID(const string& idBuscar, string& nombre, string& nit);
#endif // UTILIDADES_H
