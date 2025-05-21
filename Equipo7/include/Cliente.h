//Maria Celeste Mayen Ibarra  9959-23-3775
#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// Clase que representa un cliente en el sistema
class Cliente {
public:
    // Atributos del cliente
    std::string nombre;   // Nombre del cliente
    std::string telefono;  // Número de teléfono del cliente
    std::string nit;      // Número de NIT del cliente
    std::string codigo;   // Código único del cliente

    // Constructor por defecto
    Cliente();

    // Constructor que inicializa un cliente con los datos proporcionados
    Cliente(std::string n, std::string t, std::string nit, std::string cod);

    // Método estático que muestra el menú de opciones para gestionar clientes
    static void MenuClientes();

    // Método estático para agregar un nuevo cliente
    static void AgregarCliente();

    // Método estático para modificar un cliente existente
    static void ModificarCliente();

    // Método estático para eliminar un cliente
    static void EliminarCliente();

    // Método estático para mostrar todos los clientes registrados
    static void MostrarClientes();

    // Método estático para guardar la lista de clientes en un archivo
    static void GuardarClientes();

    // Método estático para cargar la lista de clientes desde un archivo
    static void CargarClientes();

    // Método estático para obtener la lista de clientes
    static std::vector<Cliente>& obtenerClientes();

private:
    // Vector estático que almacena todos los clientes
    static std::vector<Cliente> clientes;

    // Contador estático para generar códigos únicos de clientes
    static int contadorClientes;
};

#endif // CLIENTE_H
