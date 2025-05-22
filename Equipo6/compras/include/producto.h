#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>

<<<<<<< HEAD
class Producto {
private:
=======
<<<<<<< HEAD
struct Producto {
=======
class Producto {
private:
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    std::string codigo;
    std::string nombre;
    std::string descripcion;
    double precio;
    int stock;
<<<<<<< HEAD

    // Contador estático para generar códigos únicos
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

    // Generar código único para producto (actualiza contador)
    static std::string generarCodigoProducto();

    // Ajustar contador basado en código cargado
    static void ajustarContador(const std::vector<Producto>& productos);

    // Funciones para guardar y cargar productos
    static void guardarProductos(const std::vector<Producto>& productos);
    static std::vector<Producto> cargarProductos();

    // Funciones para menú: ingresar, consultar, modificar y borrar
    static void ingresarProducto();
    static void consultarProductos();
    static void modificarProducto();
    static void borrarProducto();
};

#endif // PRODUCTO_H
=======
<<<<<<< HEAD
};

void guardarProductos(const std::vector<Producto>& productos);
std::vector<Producto> cargarProductos();
void ingresarProducto();
void consultarProductos();
void modificarProducto();
void borrarProducto();
std::string generarCodigoProducto();

#endif
=======

    // Contador estático para generar códigos únicos
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

    // Generar código único para producto (actualiza contador)
    static std::string generarCodigoProducto();

    // Ajustar contador basado en código cargado
    static void ajustarContador(const std::vector<Producto>& productos);

    // Funciones para guardar y cargar productos
    static void guardarProductos(const std::vector<Producto>& productos);
    static std::vector<Producto> cargarProductos();

    // Funciones para menú: ingresar, consultar, modificar y borrar
    static void ingresarProducto();
    static void consultarProductos();
    static void modificarProducto();
    static void borrarProducto();
};

#endif // PRODUCTO_H
>>>>>>> 41f2e196da09c1d14a34796eb802d3d5d105e72b
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
