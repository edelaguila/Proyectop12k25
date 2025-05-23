//Clase para mantenimiento de Acreedores
//Programado por Britany Hernandez  04/05/25

#ifndef ACREEDOR_H
#define ACREEDOR_H

#include<iostream>
using namespace std;

class acreedor
{
private:
    string id, nombreAcreedor, nit, telefono, numCuenta, banco;
public:
    void menu();
    void insertar();
    void desplegar();
    void modificar();
    void buscar();
    void reporte();
    void borrar();
    bool backupAcreedores();
};

#endif // ACREEDOR_H
