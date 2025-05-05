//LUIS ANGEL MENDEZ FUENTES 9959-24-6845
// MAYO 2025
#ifndef BITACORA_H
#define BITACORA_H

// Inclusi�n de bibliotecas necesarias
#include <string>
#include <fstream> // Para manejo de archivos

using namespace std;

// Clase bitacora: permite registrar y visualizar acciones realizadas por usuarios
class bitacora {
private:
    // Atributos que pueden utilizarse para representar una entrada de bit�cora
    string nombreUsuario;   // Nombre del usuario que realiz� la acci�n
    string codigoAccion;    // C�digo asociado a la acci�n realizada
    string descripcion;     // Descripci�n textual de la acci�n

public:
    // Inserta un nuevo registro en el archivo de bit�cora
    void insertar(string usuario, string codigo, string accion);

    // Muestra en pantalla los registros actuales de la bit�cora
    void desplegar();

    // Muestra el men� interactivo para gestionar la bit�cora
    void menuBitacora();
};

#endif // BITACORA_H
