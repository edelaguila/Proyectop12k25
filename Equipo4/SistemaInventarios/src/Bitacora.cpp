#include "Bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <cstring>


#include <ctime>
//bitacaora es un histórico
//Ferdynand Monroy 9959-24-14049 Mayo 2025

using namespace std;

void bitacora::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA GESTION BITACORA  |"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\t 1. Despliegue Bitacora"<<endl;
	cout<<"\t\t\t 2. Exit"<<endl;

	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tOpcion a escoger:[1/2]"<<endl;
	cout<<"\t\t\t-------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
  		desplegar();
		break;
	case 2:
		break;
	default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        cin.get();
	}
    }while(choice!= 2);
}
void bitacora::insertar(string nombre, int codigo, string aplicacion, string accion)
{
    fstream file;
    file.open("bitacora.txt", ios::app | ios::out);

    time_t now = time(0); // obtener la fecha y hora actual Ferdynand Monroy
    char* dt = ctime(&now);

    dt[strcspn(dt, "\n")] = 0; // salto de linea Ferdynand Monroy

    struct tm * timeinfo;
    timeinfo = localtime(&now);
    char timeBuffer[9];  // hh:mm:ss
    strftime(timeBuffer, sizeof(timeBuffer), "%H:%M:%S", timeinfo);

    // Escribir la información en el archivo
    file << std::left << std::setw(15) << nombre
         << std::left << std::setw(15) << aplicacion
         << std::left << std::setw(15) << accion
         << std::left << std::setw(25) << dt    // Fecha completa
         << std::left << std::setw(10) << timeBuffer << "\n"; // Hora exacta

    file.close();
}

void bitacora::desplegar()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Detalles de Bitacora -------------------------"<<endl;
	file.open("bitacora.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> nombre >> aplicacion >> accion;
		getline(file, fecha); // Lee la hora restante Ferdynand Monroy

		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t Nombre Usuario: "<<nombre<<endl;
			cout<<"\t\t\t No. Aplicacion: "<<aplicacion<<endl;

            cout<<"\t\t\t Fecha y hora: "<<fecha<<endl; // se muestra la fecha y hora actualizada en bitacora.txt Ferdynand Monroy


			file >> nombre >> aplicacion >> accion;
			getline(file, fecha);

		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
		system("pause");
	}
	file.close();
}


