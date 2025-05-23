//Documentado por Britany Hernandez 10/05/2025 9959-24-4178
//Implementacion de la bitacora para el registro y visualizacion de acciones realizadas por Britany Mishel y Astrid Ru�z
//Documentado Astrid Ru�z
//Modificaci�n archivos binarios - Astrid Ru�z 9959 24 2976
//Implementaci�n de hora y fecha a la bitacora de despliegue (mejora requerida)
#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include <ctime>
#include<iomanip>
#include<cstring> // Para strcpy

using namespace std;


bitacora::bitacora()
{
    //ctor
}

void bitacora::menu(){
    int choice;
    char x;
    do{
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

        switch (choice){
        case 1:
            desplegar();
            break;
        case 2:
            break;
        default:
            cout <<"\n\t\t\t Opcion invalida intente denuevo...";
            cin.get();
        }
    }while (choice !=2);
}

// Se encarga de llevar el registro de acciones que se realizan
void bitacora::insertar(string nombre, string aplicacion, string accion){
    system("cls");
    fstream file;
    file.open("bitacora.bin", ios::app | ios::out | ios::binary);

    // Obtener fecha y hora actual
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char fechaHora[50];
    strftime(fechaHora, sizeof(fechaHora), "%Y-%m-%d %H:%M:%S", ltm);

    // Convertimos strings a arrays de char con tama�o fijo
    char nombreArr[50], aplicacionArr[50], accionArr[50];
    strcpy(nombreArr, nombre.c_str());
    strcpy(aplicacionArr, aplicacion.c_str());
    strcpy(accionArr, accion.c_str());

    // Escribimos en el archivo binario
    file.write(nombreArr, sizeof(nombreArr));
    file.write(aplicacionArr, sizeof(aplicacionArr));
    file.write(accionArr, sizeof(accionArr));
    file.write(fechaHora, sizeof(fechaHora));

    file.close();
}

void bitacora::desplegar(){
    system("cls");
    fstream file;
    int total=0;
    cout<<"\n-------------------------Tabla de Detalles de Bitacora -------------------------"<<endl;
    file.open("bitacora.bin", ios::in | ios::binary);

    if(!file){
        cout<<"\n\t\t\tNo hay informacion..";
        file.close();
    }
    else{
        char nombreArr[50], aplicacionArr[50], accionArr[50],fechaHora[50];

        while(file.read(nombreArr, sizeof(nombreArr))){
            total++;
            file.read(aplicacionArr, sizeof(aplicacionArr));
            file.read(accionArr, sizeof(accionArr));
            file.read(fechaHora, sizeof(fechaHora));

            cout <<"\n\t\t\t Nombre Usuario: " << nombreArr << endl;
            cout <<"\t\t\t No. Aplicacion: " << aplicacionArr << endl;
            cout <<"\t\t\t Accion Realizada: "<< accionArr << endl;
            cout <<"\t\t\t Fecha-Hora: "<< fechaHora << endl;
            cout << "\t\t\t---------------------------------" << endl;
        }
        system("pause");

        file.close();

        if (total==0){
            cout <<"\n\t\t\t No hay informacion...";
        }
        system("pause");
    }
}

//agregandole backup a la bitacora - astrid
bool bitacora::backupBitacora() {
    system("cls");
    fstream file, backupFile;
    char nombreArr[50], aplicacionArr[50], accionArr[50],fechaHora[50];

    cout << "\n\t\t---------------------------------" << endl;
    cout << "\t\t  BACKUP DE BITACORA   " << endl;
    cout << "\t\t---------------------------------" << endl << endl;

    file.open("bitacora.bin", ios::in | ios::binary);
    if (!file) {
        cout << "\n\t\tNo hay informaci�n disponible para realizar el backup..." << endl;
        return false;
    }

    backupFile.open("Bitacora_Backup.bin", ios::out | ios::binary);
    if (!backupFile) {
        cout << "\n\t\tError al crear el archivo de backup." << endl;
        file.close();
        return false;
    }

    cout << "\n\t\tRealizando backup de datos..." << endl;

    // Leemos y escribimos los registros uno por uno
    while (file.read(nombreArr, sizeof(nombreArr))) {
        // Escribimos el nombre al archivo de backup
        backupFile.write(nombreArr, sizeof(nombreArr));

        // Leemos y escribimos los dem�s campos
        file.read(aplicacionArr, sizeof(aplicacionArr));
        backupFile.write(aplicacionArr, sizeof(aplicacionArr));

        file.read(accionArr, sizeof(accionArr));
        backupFile.write(accionArr, sizeof(accionArr));

        file.read(fechaHora, sizeof(fechaHora));
        backupFile.write(fechaHora, sizeof(fechaHora));
    }

    file.close();
    backupFile.close();

    cout << "\n\t\tBackup realizado con �xito en 'Bitacora_Backup.bin'" << endl;

    return true;
}
