//Maria Celeste Mayen Ibarra  9959-23-3775
#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Cliente {
public:
    std::string nombre;
    std::string telefono;
    std::string nit;
    std::string codigo;

    Cliente();
    Cliente(std::string n, std::string t, std::string nit, std::string cod);

    static void MenuClientes();
    static void AgregarCliente();
    static void ModificarCliente();
    static void EliminarCliente();
    static void MostrarClientes();
    static void GuardarClientes();
    static void CargarClientes();
    static std::vector<Cliente>& obtenerClientes();

private:
    static std::vector<Cliente> clientes;
    static int contadorClientes;
};

#endif // CLIENTE_H
