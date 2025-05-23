//9959 24 11603 Gabriela Escobar
#ifndef MENUALMACENES_H
#define MENUALMACENES_H

#include <vector>
#include "Almacen.h"
#include "usuarios.h"

// Clase que representa el men� interactivo para gestionar almacenes
class MenuAlmacenes {
public:
    // Muestra el men� de opciones para operar sobre almacenes
    // Permite al usuario agregar, mostrar, modificar o eliminar almacenes
    static void mostrar(std::vector<Almacen>& lista, usuarios& usuario);
};

#endif
