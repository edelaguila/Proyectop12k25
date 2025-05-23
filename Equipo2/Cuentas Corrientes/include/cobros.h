#ifndef COBRO_H
#define COBRO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class GestionCobros {

private:
    // Atributos
    string idCobro;
    string idFactura;
    string fechaCobro;
    float montoCobro;
    string metodoCobro;
    string nitCliente;
    string estadoCobro;

public:

    cobro();

    // Métodos
    void menuCobros();
    void registrarCobro();
    void listarCuentasPorCobrar();
    void listarHistorialCobros();
    void buscarCobroPorFactura(int idFactura);
    void listarCobrosPorCliente(string nitCliente);
};

#endif
