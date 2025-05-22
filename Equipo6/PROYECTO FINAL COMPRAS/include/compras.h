#ifndef COMPRAS_H
#define COMPRAS_H

#include <vector>
#include <string>
#include "producto.h"

class Compras {
public:
    // Métodos públicos
    static void registrarCompra(std::vector<Producto>& listaCompras);
    static void mostrarHistorial(const std::vector<Producto>& listaCompras);
    static void buscarPorProveedor(const std::vector<Producto>& listaCompras);
    static double calcularTotalGastado(const std::vector<Producto>& listaCompras);
    static void guardarCompras(const std::vector<Producto>& listaCompras);
    static std::vector<Producto> cargarCompras();

private:
    // Métodos auxiliares para serialización
    static void escribirString(std::ofstream& archivo, const std::string& str);
    static bool leerString(std::ifstream& archivo, std::string& str);
};

#endif
