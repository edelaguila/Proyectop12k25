#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>

class Producto {
private:
    std::string codigo;
    std::string nombre;
    std::string descripcion;
    double precio;
    int stock;

    // Contador est�tico para generar c�digos �nicos
    static int contadorCodigo;

public:
    Producto();
    Producto(const std::string& codigo, const std::string& nombre,
             const std::string& descripcion, double precio, int stock);

    // Getters
    std::string getCodigo() const;
    std::string getNombre() const;
    std::string getDescripcion() const;
    double getPrecio() const;
    int getStock() const;

    // Setters
    void setCodigo(const std::string& c);
    void setNombre(const std::string& n);
    void setDescripcion(const std::string& d);
    void setPrecio(double p);
    void setStock(int s);

    // Generar c�digo �nico para producto (actualiza contador)
    static std::string generarCodigoProducto();

    // Ajustar contador basado en c�digo cargado
    static void ajustarContador(const std::vector<Producto>& productos);

    // Funciones para guardar y cargar productos
    static void guardarProductos(const std::vector<Producto>& productos);
    static std::vector<Producto> cargarProductos();

    // Funciones para men�: ingresar, consultar, modificar y borrar
    static void ingresarProducto();
    static void consultarProductos();
    static void modificarProducto();
    static void borrarProducto();
};

#endif // PRODUCTO_H
