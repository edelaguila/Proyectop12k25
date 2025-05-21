///MEILYN JULEISY GARCIA LIMA 9959-23-17838
#ifndef BITACORA_H
#define BITACORA_H
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Bitacora {
private:
    //VARIABLE
    char usuario[50];//NOMBRE DE USUARIO QUE EJECUTA LA ACCION
    char accion[100];//DESCIPCION DE LA ACCION REALIZADA
    char fechaHora[25];//FECHA Y HORA DEL EVENTO

public:
    Bitacora() = default;//constructor por defecto
    Bitacora(string user, string acc);

    void guardarEnArchivo();
    static void mostrarBitacora();
};

void registrarEvento(const string& usuario, const string& accion);

#endif
/**Clase que representa un registro de bitácora.
 * Esta clase se encarga de almacenar eventos importantes del sistema,
 * tales como inicios de sesión, accesos a menús, y otras actividades
 * del usuario. Cada registro incluye: usuario, acción y fecha/hora.
 */
