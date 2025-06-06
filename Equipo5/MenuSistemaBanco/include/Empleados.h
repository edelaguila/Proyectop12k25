//Karla Ruiz 9959-24-6859
#ifndef EMPLEADOS_H
#define EMPLEADOS_H

#include <vector>
#include <string>
#include "Bitacora.h"

using namespace std;

// Clase para representar a un empleado
class Empleado {
public:
    string nombre;      // Nombre del empleado
    string codigo;      // C�digo de identificaci�n
    string puesto;      // Puesto de trabajo
    string telefono;    // Tel�fono del empleado
};

// Clase principal para la gesti�n de empleados
class Empleados {
private:
    vector<Empleado> empleados;   // Vector que almacena la lista de empleados
    string usuario;//Bitacora
public:
    void setUsuario(const string& u);//bitacora
    // Funciones
    void limpiarPantalla();            // Limpia la pantalla seg�n el sistema operativo
    void pausar();                     // Pausa el programa hasta que se presione ENTER
    void cargarEmpleados();            // Carga los empleados desde el archivo
    void guardarEmpleados();           // Guarda todos los empleados en el archivo
    void ordenarEmpleados();           // Ordena a los empleados alfab�ticamente por nombre

    // Funciones de men�
    void menuEmpleados();              // Muestra el men� principal de empleados
    void crearEmpleado();              // Agrega un nuevo empleado
    void borrarEmpleado();             // Borra un empleado por nombre y c�digo
    void buscarEmpleado();             // Busca un empleado por nombre y c�digo
    void modificarEmpleado();          // Modifica los datos de un empleado
    void desplegarEmpleados();         // Muestra todos los empleados registrados
};

#endif // EMPLEADOS_H
