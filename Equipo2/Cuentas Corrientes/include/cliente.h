//Clase para mantenimiento de clientes
//Programado por Dulce Mart�nez 02/05/25

#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>

using namespace std;

class cliente
{
    private:
		string id, nombre, telefono, nit;
	public:
		void menu();
		void insertar();
		void desplegar();
		void modificar();
		void buscar();
		void borrar();
		void reporte();
		bool backupClientes ();
};

#endif // CLIENTE_H
