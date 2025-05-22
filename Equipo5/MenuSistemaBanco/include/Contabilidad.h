//Jonathan Samuel Gonzalez Ixpata 9959-23-3184
#ifndef CONTABILIDAD_H
#define CONTABILIDAD_H

#include <iostream>
#include <fstream>
#include <string>
#include "Bitacora.h"

// Estructura para representar el estado de pago de un empleado
struct RegistroPago {
    char codigo[20];  // C�digo del empleado
    char pagado[5];   // "S�" o "No"
};

class Contabilidad {
public:
    void setUsuario(const std::string& u);     // bit�cora
    void menuContabilidad();                   // Men� principal
    void registroNomina();                     // Registrar pago
    void desplegarRegistroSalarios();          // Mostrar registros
    void limpiarPantalla();                    // Limpiar pantalla
    void pausar();                             // Pausar ejecuci�n

private:
    std::string usuario;                       // Usuario actual para bit�cora
};

#endif
