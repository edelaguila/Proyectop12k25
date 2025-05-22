//Clase para mantenimiento de Proveedores
//Programado por Britany Hernandez 04/05/25
//Programado por Astrid Ru�z 11/05/25 (agregu� funciones CRUD y binarios)

//Actualizacion y correcciones
//Programado por Britany Hernandez 11/05/25

//Modificaci�n para uso de archivos binarios 18/05/25 Astrid Ru�z
//Actualizado para uso correcto de estructuras binarias 21/05/25 Astrid Ru�z (por el error q daba utilidades d dulce)
//Aqu� se cambio los archivos binarios como clientes y acreedores (basicamente es el mismo flujo) Astrid Ru�z


//Modificación para uso de archivos binarios 18/05/25



#include "proveedor.h"
#include "bitacora.h"
#include "usuarios.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>
#include <cstring> // Necesario para strcpy y memset

using namespace std;

extern usuarios usuariosrRegistrado; //Objeto usuario declarado en el main

// Estructura para manejo binario - Debe coincidir con la definida en utilidades.cpp
struct ProveedorBin {
    char id[15];          // Orden igual que en clase proveedor
    char nombreProveedor[50];
    char nit[15];
    char telefono[15];
    char numCuenta[20];
    char banco[30];
};

void proveedor::menu()
{
    int choice;
    char x;
    do {
        system("cls");
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t |   SISTEMA GESTION PROVEEDORES |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t 1. Ingreso Proveedores"<<endl;
        cout<<"\t\t\t 2. Despliegue Proveedores"<<endl;
        cout<<"\t\t\t 3. Modifica Proveedores"<<endl;
        cout<<"\t\t\t 4. Busca Proveedores"<<endl;
        cout<<"\t\t\t 5. Borra Proveedores"<<endl;
        cout<<"\t\t\t 6. Reporte Proveedores"<<endl;
        cout<<"\t\t\t 7. Salida"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            do {
                insertar();
                cout<<"\n\t\t\t Agrega otro Proveedor (Y/N): ";
                cin>>x;
            } while(x=='y'||x=='Y');
            break;
        case 2:
            desplegar();
            break;
        case 3:
            modificar();
            break;
        case 4:
            buscar();
            break;
        case 5:
            borrar();
            break;
        case 6:
            reporte();
            break;
        case 7:
            break;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get();
        }
    } while(choice!= 7); // Corregido: ahora sale cuando la opci�n es 7
}

void proveedor::insertar()
{
    system("cls");
    fstream file;
    char guardar; //Variable para guardar la respuesta de la confirmacion

    cout<<"\n-----------------------------------------------------------------------------------";
    cout<<"\n-------------------------------- Agregar Proveedor --------------------------------"<<endl;
    cout << "\t\t\tIngresa ID Proveedor         : ";
    cin >> id;
    cout << "\t\t\tIngresa Nombre Proveedor     : ";
    cin >> nombreProveedor;
    cout << "\t\t\tIngresa Nit Proveedor        : ";
    cin >> nit;
    cout << "\t\t\tIngresa Telefono Proveedor   : ";
    cin >> telefono;
    cout << "\t\t\tIngresa Num.Cuenta Proveedor : ";
    cin >> numCuenta;
    cout << "\t\t\tIngresa Banco del Proveedor  : ";
    cin >> banco;


    cout << "\n\t\t\t¿Deseas guardar los datos? (s/n): ";
    cin >> guardar;

    if(guardar=='s' || guardar=='S'){

        try {
            // Guardar en archivo binario principal
            file.open("proveedor.bin", ios::binary | ios::app | ios::out);
            if (!file.is_open()) throw runtime_error("No se pudo abrir el archivo");

            // Convertir atributos de la clase a la estructura ProveedorBin
            ProveedorBin proveedorStruct;
            memset(&proveedorStruct, 0, sizeof(ProveedorBin)); // Inicializar con ceros

            // Copiar las cadenas a los campos de la estructura
            strncpy(proveedorStruct.id, id.c_str(), sizeof(proveedorStruct.id) - 1);
            strncpy(proveedorStruct.nombreProveedor, nombreProveedor.c_str(), sizeof(proveedorStruct.nombreProveedor) - 1);
            strncpy(proveedorStruct.nit, nit.c_str(), sizeof(proveedorStruct.nit) - 1);
            strncpy(proveedorStruct.telefono, telefono.c_str(), sizeof(proveedorStruct.telefono) - 1);
            strncpy(proveedorStruct.numCuenta, numCuenta.c_str(), sizeof(proveedorStruct.numCuenta) - 1);
            strncpy(proveedorStruct.banco, banco.c_str(), sizeof(proveedorStruct.banco) - 1);

            // Escribir la estructura al archivo
            file.write(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin));
            file.close();

            // Guardar en reporte de texto (opcional)
            ofstream reporteFile;
            reporteFile.open("reportesProveedores.txt", ios::app);
            reporteFile << left << setw(15) << id << left << setw(15) << nombreProveedor
                        << left << setw(15) << nit << left << setw(15) << telefono
                        << left << setw(15) << numCuenta << left << setw(15) << banco << "\n";
            reporteFile.close();

            bitacora auditoria;
            auditoria.insertar(usuariosrRegistrado.getNombre(), "8030", "INP");

            cout << "\n\t\t\t Proveedor registrado exitosamente!" << endl;
        } catch (const exception& e) {
            cout << "\n\t\t\t Error ocurrido: " << e.what() << endl;
        }

        // Guardar en archivo binario principal
        file.open("proveedor.bin", ios::binary | ios::app | ios::out);
        file.write((char*)this, sizeof(proveedor));
        file.close();

        // Guardar en reporte (opcional, puede mantenerse como texto)
        ofstream reporteFile;
        reporteFile.open("reportesProveedores.txt", ios::app);
        reporteFile << left << setw(15) << id << left << setw(15) << nombreProveedor
                    << left << setw(15) << telefono << left << setw(15) << numCuenta
                    << left << setw(15) << banco << "\n";
        reporteFile.close();

        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8030", "INP");


    cout << "\n\t\t\t¿Deseas guardar los datos? (s/n): ";
    cin >> guardar;

    if(guardar=='s' || guardar=='S'){
        file.open("proveedor.txt", ios::app | ios::out);
        file<<left<<setw(15)<< id <<left<<setw(15)<< nombreProveedor <<left<<setw(15)<<telefono <<left << setw(15)<< numCuenta <<left << setw(15) << banco << "\n";
        file.close();

        ofstream reporteFile;
        file.open("reportesProveedores.txt", ios::app | ios::out);
        file<<left<<setw(15)<< id <<left<<setw(15)<< nombreProveedor <<left<<setw(15)<<telefono <<left << setw(15)<< numCuenta <<left << setw(15) << banco << "\n";
        file.close();

        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8030", "INP"); //Ingreso a la bitacoras


        cout << "\n\t\t\t Proveedor registrado exitosamente!" << endl;

    }
    else {
        cout << "\n\t\t\t Ingreso cancelado..." << endl;
    }
    system("pause");
}

void proveedor::desplegar()
{
    system("cls");
    ifstream file;
    int total=0;
    cout<<"\n------------------------ Lista de Proveedores ------------------------"<<endl;
    file.open("proveedor.bin", ios::binary | ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion...\n";
        system("pause");
    }
    else {

        // Leer como estructura ProveedorBin
        ProveedorBin proveedorStruct;
        while(file.read(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin))) {
            total++;
            cout<<"\n\t\t\t ID proveedor        : " << proveedorStruct.id;
            cout<<"\n\t\t\t Nombre proveedor    : " << proveedorStruct.nombreProveedor;
            cout<<"\n\t\t\t Nit proveedor       : " << proveedorStruct.nit;
            cout<<"\n\t\t\t Telefono proveedor  : " << proveedorStruct.telefono;
            cout<<"\n\t\t\t Banco proveedor     : " << proveedorStruct.banco;
            cout<<"\n\t\t\t Num.Cuenta proveedor: " << proveedorStruct.numCuenta<<endl;


        while(file.read((char*)this, sizeof(proveedor))) {

        file >> id >> nombreProveedor >> telefono >> numCuenta>> banco ;
        while(!file.eof()) {

            total++;
            cout<<"\n\t\t\t ID proveedor        : "<<id;
            cout<<"\n\t\t\t Nombre proveedor    : "<<nombreProveedor;
            cout<<"\n\t\t\t Telefono proveedor  : "<<telefono;
            cout<<"\n\t\t\t Banco proveedor     : "<<banco;
            cout<<"\n\t\t\t Num.Cuenta proveedor: "<<numCuenta<<endl;


            file >> id >> nombreProveedor >> telefono >> numCuenta >> banco ;


        }
        if(total==0){
            cout<<"\n\t\t\tNo hay informacion...";
        }
        system("pause");
    }
    file.close();
    bitacora auditoria;

    auditoria.insertar(usuariosrRegistrado.getNombre(), "8031", "MP");

    auditoria.insertar(usuariosrRegistrado.getNombre(), "8031", "MP"); //Mostrar Proveedor

}

void proveedor::modificar()
{
    system("cls");
    fstream file, tempFile;
    string proveedor_id;
    int found=0;
    cout<<"\n---------------- Modificar Proveedor ----------------"<<endl;
    file.open("proveedor.bin", ios::binary | ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion...";
        system("pause");
        file.close();
    }
    else {
        cout<<"\nIngrese ID del proveedor que quiere modificar: ";
        cin>>proveedor_id;

        tempFile.open("temporal.bin", ios::binary | ios::out);


        // Leer como estructura ProveedorBin
        ProveedorBin proveedorStruct;
        while(file.read(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin))) {
            if(proveedor_id != proveedorStruct.id) {
                tempFile.write(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin));

        file1.open("temporal.txt", ios::app | ios::out);
        file >> id >> nombreProveedor >> telefono >> numCuenta>> banco ;


        while(file.read((char*)this, sizeof(proveedor))) {
            if(proveedor_id != id) {

                tempFile.write((char*)this, sizeof(proveedor));

                file1<<left<<setw(15)<< id <<left<<setw(15)<< nombreProveedor <<left<<setw(15)<< telefono <<
                left << setw(15)<< numCuenta <<left << setw(15) << banco << "\n";


            }
            else {
                cout<<"\t\t\tIngrese Id proveedor        : ";

                cin>>id;
                cout<<"\t\t\tIngrese Nombre proveedor    : ";
                cin>>nombreProveedor;
                cout<<"\t\t\tIngrese Nit proveedor       : ";
                cin>>nit;
                cout<<"\t\t\tIngrese Telefono proveedor  : ";
                cin>>telefono;
                cout<<"\t\t\tIngrese Num.Cuenta proveedor: ";
                cin>>numCuenta;
                cout<<"\t\t\tIngrese Banco proveedor     : ";
                cin>>banco;

                // Preparar la estructura actualizada
                memset(&proveedorStruct, 0, sizeof(ProveedorBin)); // Inicializar con ceros
                strncpy(proveedorStruct.id, id.c_str(), sizeof(proveedorStruct.id) - 1);
                strncpy(proveedorStruct.nombreProveedor, nombreProveedor.c_str(), sizeof(proveedorStruct.nombreProveedor) - 1);
                strncpy(proveedorStruct.nit, nit.c_str(), sizeof(proveedorStruct.nit) - 1);
                strncpy(proveedorStruct.telefono, telefono.c_str(), sizeof(proveedorStruct.telefono) - 1);
                strncpy(proveedorStruct.numCuenta, numCuenta.c_str(), sizeof(proveedorStruct.numCuenta) - 1);
                strncpy(proveedorStruct.banco, banco.c_str(), sizeof(proveedorStruct.banco) - 1);

                tempFile.write(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin));
                found++;
            }

				cin>>id;
				cout<<"\t\t\tIngrese Nombre proveedor    : ";
				cin>>nombreProveedor;
				cout<<"\t\t\tIngrese Telefono proveedor  : ";
				cin>>telefono;
				cout<<"\t\t\tIngrese Num.Cuenta proveedor: ";
				cin >>numCuenta;
				cout<<"\t\t\tIngrese Banco proveedor     : ";
				cin>>banco;


                file1<<left<<setw(15)<< id <<left<<setw(15)<< nombreProveedor <<left<<setw(15)<< telefono <<
                left << setw(15)<< numCuenta  <<left << setw(15) << banco << "\n";
                found++;
            }
            file >> id >> nombreProveedor >> telefono >> numCuenta >> banco;

        }

        file.close();
        tempFile.close();
        remove("proveedor.bin");
        rename("temporal.bin", "proveedor.bin");

        if(found==0){
            cout<<"\n\t\t\tProveedor no encontrado...";
        }
        else {
            cout<<"\n\t\t\tProveedor modificado exitosamente!";
        }
        system("pause");
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8032", "UPD");
    }
}

void proveedor::buscar()
{
    system("cls");
    ifstream file;
    int found=0;

    cout<<"\n---------------- Buscar Proveedor ----------------"<<endl;
    file.open("proveedor.bin", ios::binary | ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion...";
    }
    else {
        string proveedor_id;
        cout<<"\nIngrese ID del proveedor que quiere buscar : ";
        cin>>proveedor_id;


        // Leer como estructura ProveedorBin
        ProveedorBin proveedorStruct;
        while(file.read(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin))) {
            if(proveedor_id == proveedorStruct.id) {
                cout<<"\n\t\t\t ID Proveedor        : " << proveedorStruct.id << endl;
                cout<<"\t\t\t Nombre Proveedor    : " << proveedorStruct.nombreProveedor << endl;
                cout<<"\t\t\t Nit Proveedor       : " << proveedorStruct.nit << endl;
                cout<<"\t\t\t Telefono Proveedor  : " << proveedorStruct.telefono << endl;
                cout<<"\t\t\t Num.Cuenta Proveedor: " << proveedorStruct.numCuenta << endl;
                cout<<"\t\t\t Banco Proveedor     : " << proveedorStruct.banco << endl;

        file >> id >> nombreProveedor >> telefono >> numCuenta >> banco;


        while(file.read((char*)this, sizeof(proveedor))) {
            if(proveedor_id==id) {
                cout<<"\n\t\t\t ID Proveedor        : "<<id<<endl;
                cout<<"\t\t\t Nombre Proveedor    : "<<nombreProveedor<<endl;
                cout<<"\t\t\t Telefono Proveedor  : "<<telefono<<endl;
                cout<<"\t\t\t Num.Cuenta Proveedor: "<<numCuenta<<endl;
                cout<<"\t\t\t Banco Proveedor     : "<<banco<<endl;

                found++;
                break;
            }

            file >> id >> nombreProveedor >> telefono >> numCuenta >> banco ;


        }

        if(found==0){
            cout<<"\nProveedor no encontrado...\n";
        }
        file.close();
        system("pause");
    }
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8033", "BPR");
}

void proveedor::borrar()
{
    system("cls");
    fstream file, tempFile;
    string proveedor_id;
    int found=0;
    cout<<"\n---------------- Borrar Proveedor ----------------"<<endl;

    file.open("proveedor.bin", ios::binary | ios::in);

    if(!file)
    {
        cout<<"\n\t\t\tNo hay informacion...";
    }
    else
    {
        cout<<"\n Ingrese el Id del Proveedor que quiere borrar: ";
        cin>>proveedor_id;
        tempFile.open("temporal.bin", ios::binary | ios::out);

        // Leer como estructura ProveedorBin
        ProveedorBin proveedorStruct;
        while(file.read(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin))) {
            if(proveedor_id != proveedorStruct.id) {
                tempFile.write(reinterpret_cast<char*>(&proveedorStruct), sizeof(ProveedorBin));
            }
            else {
                found++;
                cout << "\nProveedor borrado exitosamente\n";
            }
        }

        file.close();
        tempFile.close();
        remove("proveedor.bin");
        rename("temporal.bin","proveedor.bin");

        if(found==0)
        {
            cout<<"\nProveedor no encontrado\n";
        }
        system("pause");
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8034", "DPR");
    }

    file.open("proveedor.txt", ios::in);

	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		system("pause");
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del Proveedor que quiere borrar: ";
		cin>>proveedor_id;
		file1.open("temporal.txt",ios::app | ios::out);
		file >> id >> nombreProveedor >> telefono >> numCuenta >> banco;
		while(!file.eof())
		{
			if(proveedor_id!= id)
			{
				file1<<left<<setw(15)<< id <<left<<setw(15)<< nombreProveedor <<left<<setw(15)<< telefono <<
                left << setw(15)<< numCuenta <<left << setw(15) << banco << "\n";
			}
			else
			{
				found++;
				cout << "\nProveedor borrado exitosamente\n";
				system("pause");
			}
			file >> id >> nombreProveedor >> telefono >> numCuenta >> banco;
		}
		if(found==0)
		{
			cout<<"\nProveedor no encontrado\n";
			system("pause");
		}
		file1.close();
		file.close();
		remove("proveedor.txt");
		rename("temporal.txt","proveedor.txt");
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8034", "DPR"); //Eliminar preedor de bitacora
	}

}

void proveedor::reporte() {
    system("cls");
    fstream file, reporteFile;
    int found = 0;


    cout << "\n----------------------------- Reporte de Proveedores -----------------------------\n" << endl;
    file.open("proveedor.txt", ios::in);
    reporteFile.open("reportesproveedor.txt", ios::app | ios::out); // Archivo de reporte

    cout<<"\n----------------------------- Reporte de Proveedores -----------------------------\n\n"<<endl;

    file.open("proveedor.dat", ios::in | ios::binary);


    file.open("proveedor.txt", ios::in);


    if (!file) {
        cout << "\n\t\t\tNo hay informacion ...\n";
        reporteFile << "No hay informacion en proveedor.txt\n\n";
    } else {
        cout << left << setw(15) << "ID" << setw(15) << "Nombre" << setw(15) << "Nit"
             << setw(15) << "Telefono" << setw(15) << "Num. Cuenta" << setw(15) << "Banco" << endl;
        cout << "---------------------------------------------------------------------------------------------\n";

        reporteFile << "----------------------------- REPORTE DE PROVEEDORES -----------------------------\n";
        reporteFile << left << setw(15) << "ID" << setw(15) << "Nombre" << setw(15) << "Nit"
                    << setw(15) << "Telefono" << setw(15) << "Num. Cuenta" << setw(15) << "Banco" << "\n";
        reporteFile << "---------------------------------------------------------------------------------------------\n";

        file >> id >> nombreProveedor >> nit >> telefono >> numCuenta >> banco;
        while (!file.eof()) {
            found++;
            cout << left << setw(15) << id << setw(15) << nombreProveedor << setw(15) << nit
                 << setw(15) << telefono << setw(15) << numCuenta << setw(15) << banco << endl;

            reporteFile << left << setw(15) << id << setw(15) << nombreProveedor << setw(15) << nit
                        << setw(15) << telefono << setw(15) << numCuenta << setw(15) << banco << "\n";

            file >> id >> nombreProveedor >> nit >> telefono >> numCuenta >> banco;
        }

        reporteFile << "---------------------------------------------------------------------------------------------\n\n";

        if (found == 0) {
            cout << "\n\t\t\tNo hay proveedores registrados...\n";
            reporteFile << "No hay proveedores registrados...\n\n";
        }
    }

    cout << endl;
    file.close();
    reporteFile.close();
    system("pause");



    ofstream reporteFile;

        file.open("reportesProveedores.dat", ios::app | ios::out | ios::binary);

        file.open("reportesProveedores.txt", ios::app | ios::out);

        file<<left<<setw(15)<< id <<left<<setw(15)<< nombreProveedor <<left<<setw(15)<<telefono <<left << setw(15)<< numCuenta <<left << setw(15) << banco << "\n";
        file.close();


    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8035", "RPR"); // Reporte Proveedor
}
