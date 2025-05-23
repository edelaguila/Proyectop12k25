//Definicion de la clase
//Programada por Astrid Ruíz

#include "catalogos.h"
#include "cliente.h"
#include "proveedor.h"
#include "acreedor.h"
#include "usuarios.h"

#include <iostream>
using namespace std;

extern usuarios usuariosrRegistrado;

//Declaracion de objetos
cliente clientes;
proveedor proveedores;
acreedor acreedores;

Catalogos::Catalogos()
{
    //ctor
}

void Catalogos::menuCatalogos(){
    int opciones;
    do{
        system("cls"); // Limpia la pantalla
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t |   Menu de catalogos        |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout <<"\t\t\t1. Catalogo de Clientes" << endl;
        cout <<"\t\t\t2. Catalogo de Proveedores" << endl;
        cout <<"\t\t\t3. Catalogo de Acreedores" << endl;
        cout <<"\t\t\t4. Volver al menu principal" << endl;

        cout<<"\t\t Opcion a escoger:[1/2/3/4]"<<endl;
        cout << "\n\t\t Ingrese una opcion: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                clientes.menu();
                break;
            case 2:
                proveedores.menu();
                break;
            case 3:
                acreedores.menu();
                break;
            case 4:
                break;
            default:
                cout << "n\t\tOpción no válida. Intente de nuevo" << endl;
                system("pause");
        }
    } while (opciones != 4); // Repite el menú hasta que el usuario quiera salir
}
