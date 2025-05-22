#ifndef COMPRAS_H
#define COMPRAS_H

#include <vector>
<<<<<<< HEAD
#include <string>
=======
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
#include "producto.h"

class Compras {
public:
<<<<<<< HEAD
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
=======
    void registrarCompra(std::vector<Producto>& listaCompras);
    void mostrarHistorial(const std::vector<Producto>& listaCompras);
    void buscarPorProveedor(const std::vector<Producto>& listaCompras);
    double calcularTotalGastado(const std::vector<Producto>& listaCompras);
    void guardarCompras(const std::vector<Producto>& listaCompras);
    std::vector<Producto> cargarCompras();
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
};

#endif
