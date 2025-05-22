#ifndef BITACORA_H
#define BITACORA_H

#include <string>
using namespace std;

// Clase que maneja el sistema de bit�cora
class bitacora {// Registro de bitacora - Isaias Cedillo (9959-24-1672) "IsaC8-bit"
private:
    // Variables para almacenar informaci�n de cada registro
    string nombre, aplicacion, accion;

public:
    // Muestra el men� principal al usuario
    void menu();

    // Inserta un nuevo registro en la bit�cora
    void insertar(string nombre, std::string aplicacion, string accion);

    // Muestra todos los registros almacenados
    void desplegar();
    // Aplicacion para registros
     string generarCodigoAplicacion();
};

#endif
