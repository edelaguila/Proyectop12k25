//Clase para mantenimiento de clientes
//Programado por Dulce Martìnez 02/05/25

//Actualizaciones y correcciiones
//Programado por Dulce Martìnez 11/05/25

//Actualizaci�n de Astrid Ru�z
//Mishel me ayud� a agregar las funciones de los binarios a este
//basicamente para este se utiliz� lo mismo que acreedores y proveedores, porque debemos traernos las estructuras y ya ah� para que las lea en binario enn el orden q pide utilidades

#include "cliente.h"
#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<cstring> // Necesario para strcpy
#include<iomanip>
#include "usuarios.h"

using namespace std;

extern usuarios usuariosrRegistrado;

struct ClienteBin {
    char id[15];
    char nombre[50];      // Orden igual que en clase cliente
    char telefono[15];
    char nit[15];
};

void cliente::menu()
{
    int choice;
	char x;

	do
    {
	system("cls");
	cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION CLIENTES |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Clientes"<<endl;
	cout<<"\t\t\t 2. Despliegue Clientes"<<endl;
	cout<<"\t\t\t 3. Modifica Clientes"<<endl;
	cout<<"\t\t\t 4. Busca Clientes"<<endl;
	cout<<"\t\t\t 5. Borra Clientes"<<endl;
	cout<<"\t\t\t 6. Reportes Clientes" << endl;
	cout<<"\t\t\t 7. Salida"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
    cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insertar();
    		cout<<"\n\t\t\t Agrega otro Clientes(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
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
  }while(choice!= 7);
}
void cliente::insertar()
{

    system("cls");
    fstream file;
    char confirmar;

    cout << "\n------------------------------------------------------------------------------------------------------------------------";

	system("cls");
	fstream file;
	char confirmar; //Variable para guardar la respuesta de la confirmacion

	cout << "\n------------------------------------------------------------------------------------------------------------------------";

    cout << "\n-------------------------------------------------Agregar detalles Cliente ---------------------------------------------" << endl;

    cout << "\t\t\tIngresa Id Cliente         : ";
    cin >> id;

    cin.ignore(); // Limpiar buffer
    cout << "\t\t\tIngresa Nombre Cliente     : ";
    getline(cin, nombre);

    cout << "\t\t\tIngresa Telefono Cliente   : ";
    cin >> telefono;

    cout << "\t\t\tIngresa Nit Cliente        : ";
    cin >> nit;

    cout << "\n\t\t\t¿Deseas guardar los datos? (s/n): ";
    cin >> confirmar;

    if (confirmar == 's' || confirmar == 'S') {
        file.open("cliente.bin", ios::binary | ios::app | ios::out);
        if (!file) {
            cerr << "\n\t\t\tError al abrir el archivo 'cliente.bin'.\n";
            return;
        }

        ClienteBin clienteStruct;

        memset(&clienteStruct, 0, sizeof(ClienteBin)); // Inicializar con ceros

        strncpy(clienteStruct.id, id.c_str(), sizeof(clienteStruct.id) - 1);
        strncpy(clienteStruct.nombre, nombre.c_str(), sizeof(clienteStruct.nombre) - 1);
        strncpy(clienteStruct.telefono, telefono.c_str(), sizeof(clienteStruct.telefono) - 1);
        strncpy(clienteStruct.nit, nit.c_str(), sizeof(clienteStruct.nit) - 1);

        file.write(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin));
        file.close();

        ofstream reporteFile("reportesClientes.txt", ios::app);
        if (!reporteFile) {
            cerr << "\n\t\t\tError al abrir el archivo de reporte.\n";
            return;
        }

        reporteFile << left << setw(15) << id << left << setw(15) << nombre
                    << left << setw(15) << telefono << left << setw(15) << nit << "\n";
        reporteFile.close();

        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "INS");

        cout << "\n\t\t\tDatos guardados exitosamente.\n";
    } else {
        cout << "\n\t\t\tOperaci�n cancelada.\n";
    }

	cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n-------------------------------------------------Agregar detalles Cliente ---------------------------------------------"<<endl;
	cout<<"\t\t\tIngresa Id Cliente         : ";
	cin>>id;
	cout<<"\t\t\tIngresa Nombre Cliente     : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Telefono Cliente   : ";
	cin>>telefono;
	cout<<"\t\t\tIngresa Nit Cliente   : ";
	cin>>nit;

	cout << "\n\t\t\t¿Deseas guardar los datos? (s/n): ";
    cin >> confirmar;

    if (confirmar == 's' || confirmar == 'S')

	file.open("cliente.txt", ios::app | ios::out);
	file<<left<<setw(15)<< id <<left<<setw(15)<< nombre <<left<<setw(15)<< telefono <<left<< setw(15) << nit <<"\n";
	file.close();

	// Guardar en reportes.txt
	ofstream reporteFile;
    reporteFile.open("reportesClientes.txt", ios::app | ios::out);
    reporteFile << left << setw(15) << id << left << setw(15) << nombre<< left << setw(15) << telefono << left << setw(15) << nit << "\n";
    reporteFile.close();

    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "INS"); //ingreso a las bitácoras

}


void cliente::desplegar() {
    system("cls");
    ifstream file;
    cout << "\n-------------------------Tabla de Detalles de Cliente -------------------------" << endl;
    file.open("cliente.bin", ios::binary | ios::in);
    if (!file) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
    } else {
        ClienteBin clienteStruct;
        while (file.read(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin))) {
            cout << "\n\n\t\t\t Id Cliente: " << clienteStruct.id << endl;
            cout << "\t\t\t Nombre Cliente: " << clienteStruct.nombre << endl;
            cout << "\t\t\t Telefono Cliente: " << clienteStruct.telefono << endl;
            cout << "\t\t\t Nit Cliente: " << clienteStruct.nit << endl;
        }
        file.close();
    }
    system("pause");
    bitacora auditoria;

    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "MC");

    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "MC");//Muestra el cliente de la bitacora

}

void cliente::modificar() {
    system("cls");
    fstream file, tempFile;
    string participant_id;
    int found = 0;
    cout << "\n-------------------------Modificacion Detalles Cliente-------------------------" << endl;
    file.open("cliente.bin", ios::binary | ios::in);
    if (!file) {
        cout << "\n\t\t\tNo hay informacion..." << endl;

    } else {
        cout << "\n Ingrese Id del cliente que quiere modificar: ";
        cin >> participant_id;
        tempFile.open("temporal.bin", ios::binary | ios::out);

        ClienteBin clienteStruct;
        while (file.read(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin))) {
            if (participant_id != clienteStruct.id) {
                tempFile.write(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin));
            } else {
                cout << "\t\t\tIngrese Id Cliente: ";
                cin >> id;
                cout << "\t\t\tIngrese Nombre Cliente: ";
                cin >> nombre;
                cout << "\t\t\tIngrese Telefono Cliente: ";
                cin >> telefono;
                cout << "\t\t\tIngrese Nit Cliente: ";
                cin >> nit;
                tempFile.write(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin));

                found++;

                memset (&clienteStruct, 0, sizeof(ClienteBin));
                strncpy(clienteStruct.id, id.c_str(), sizeof(clienteStruct.id) - 1);
                strncpy(clienteStruct.nombre, nombre.c_str(), sizeof(clienteStruct.nombre) - 1);
                strncpy(clienteStruct.telefono, telefono.c_str(), sizeof(clienteStruct.telefono) - 1);
                strncpy(clienteStruct.nit, nit.c_str(), sizeof(clienteStruct.nit) - 1);

                // Escribir la estructura al archivo
                file.write(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin));

            }
        }
        file.close();
        tempFile.close();
        remove("cliente.bin");
        rename("temporal.bin", "cliente.bin");
        bitacora auditoria;

        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "UPD");
    }
}

void cliente::buscar() {
    system("cls");
    ifstream file;
    int found = 0;
    cout << "\n-------------------------Datos del Cliente Buscado------------------------" << endl;
    file.open("cliente.bin", ios::binary | ios::in);
    if (!file) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
    } else {
        string participant_id;
        cout << "\nIngrese Id del cliente que quiere buscar: ";
        cin >> participant_id;

        ClienteBin clienteStruct;
        while (file.read(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin))) {
            if (participant_id == clienteStruct.id) {
                cout << "\n\n\t\t\t Id Cliente: " << clienteStruct.id << endl;
                cout << "\t\t\t Nombre Cliente: " << clienteStruct.nombre << endl;
                cout << "\t\t\t Telefono Cliente: " << clienteStruct.telefono << endl;
                cout << "\t\t\t Nit Cliente: " << clienteStruct.nit << endl;
                found++;
            }
        }
        if (found == 0) {
            cout << "\n\t\t\t Cliente no encontrado..." << endl;
        }
        file.close();
    }
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "BC");

        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "UPD"); //Actualizacion datos cliente
	}
}
void cliente::buscar()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("cliente.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Cliente Buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
		cout<<"\n-------------------------Datos del Cliente Buscado------------------------"<<endl;
		cout<<"\nIngrese Id del cliente que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono >> nit;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id Cliente: "<<id<<endl;
				cout<<"\t\t\t Nombre Cliente: "<<nombre<<endl;
				cout<<"\t\t\t Telefono Cliente: "<<telefono<<endl;
				cout<<"\t\t\t Nit Cliente: "<<nit<<endl;
				found++;
			}
			file >> id >> nombre >> telefono >> nit;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "BC"); //Busqueda cliente en bitacora
	}

}

void cliente::borrar() {
    system("cls");
    fstream file, tempFile;
    string participant_id;
    int found = 0;
    cout << "\n-------------------------Detalles Cliente a Borrar-------------------------" << endl;
    file.open("cliente.bin", ios::binary | ios::in);
    if (!file) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
    } else {
        cout << "\n Ingrese el Id del cliente que quiere borrar: ";
        cin >> participant_id;

        tempFile.open("temporal.bin", ios::binary | ios::out);

        ClienteBin clienteStruct;
        while (file.read(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin))) {
            if (participant_id != clienteStruct.id) {
                tempFile.write(reinterpret_cast<char*>(&clienteStruct), sizeof(ClienteBin));
            } else {
                found++;
                cout << "\n\t\t\tBorrado exitoso." << endl;
            }
        }
        file.close();
        tempFile.close();
        remove("cliente.bin");
        rename("temporal.bin", "cliente.bin");
        bitacora auditoria;

        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "DEL");
    }

        auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "DEL"); //Eliminar cliente de bitacora
	}

}

void cliente::reporte(){
    system("cls");
    fstream file;
    int found = 0;

    cout << "\n----------------------------- Reporte de Clientes -----------------------------\n\n" << endl;
    file.open("cliente.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay información...\n";
    }
    else {
        // Encabezado del reporte
        cout << left << setw(15) << "ID" << setw(30) << "Nombre" << setw(15) << "Telefono"
             << setw(15) << "NIT" << endl;
        cout << "-------------------------------------------------------------------------------\n";

        // Leer datos del archivo
        while (file >> id) {
            // Usamos getline para leer nombres con espacios
            file.ignore();  // Ignorar el salto de línea después del ID
            getline(file, nombre);
            file >> telefono >> nit;

            found++;

            // Imprimir los datos del cliente
            cout << left << setw(15) << id << setw(30) << nombre << setw(15)
                 << telefono << setw(15) << nit << endl;
        }

        if (found == 0) {
            cout << "\n\t\t\tNo hay clientes registrados...\n";
        }
    }
    cout << endl;
    file.close();
    system("pause");

    // Guardar todos los clientes en el archivo de reporte
    ofstream reporteFile;
    reporteFile.open("reportesClientes.txt", ios::app);

    // Reabrimos el archivo para escribir todos los clientes
    file.open("cliente.txt", ios::in);
    while (file >> id) {
        file.ignore(); // Ignorar salto de línea después del ID
        getline(file, nombre);
        file >> telefono >> nit;

        // Escribir cada cliente en el reporte
        reporteFile << left << setw(15) << id << setw(30) << nombre
                    << setw(15) << telefono << setw(15) << nit << "\n";
    }
    reporteFile.close();

    // Bitácora
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8011", "RPC"); // Reporte Cliente
}

//Realizando respaldo de cliente - Astrid Ru�z
//Se copia todo el contenido de cliente.bin a BackupCliente.bin
bool cliente::backupClientes() {
    system("cls");
    ifstream file;
    ofstream backupFile;
    cout << "\n\t\t---------------------------------" << endl;
    cout << "\t\t  BACKUP DE CLIENTES   " << endl;
    cout << "\t\t---------------------------------" << endl << endl;

    file.open("cliente.bin", ios::binary | ios::in);
    if (!file) {
        cout << "\n\t\tNo hay informaci�n disponible para realizar el backup..." << endl;
        return false;
    }

    backupFile.open("BackupClientes.bin", ios::binary | ios::out);
    if (!backupFile) {
        cout << "\n\t\tError al crear el archivo de backup." << endl;
        file.close();
        return false;
    }

    cout << "\n\t\tRealizando backup de datos..." << endl;

    // Copia binaria directa
    backupFile << file.rdbuf();

    file.close();
    backupFile.close();

    cout << "\n\t\tBackup realizado con �xito'" << endl;

    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8012", "BKP");
    return true;
}
