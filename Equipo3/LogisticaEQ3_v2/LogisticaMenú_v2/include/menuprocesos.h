#ifndef MENUPROCESOS_H
#define MENUPROCESOS_H

#include <vector>

// Forward declarations
class Clientes;
class Producto;
class Almacen;
class Proveedor; // Asegúrate de incluir esta línea si usas Proveedor
class usuarios;

class MenuProcesos
{
public:
    // Declaración del método con el nuevo parámetro
    void mostrar(std::vector<Clientes>& clientes,
                 std::vector<Producto>& productos,
                 std::vector<Almacen>& almacenes,
                 std::vector<Proveedor>& proveedores); // Actualizado
};

#endif // MENUPROCESOS_H

