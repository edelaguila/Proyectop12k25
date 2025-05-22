//Clase para mantenimiento de Acreedores
//Programado por Britany Hernandez  04/05/25
//Programado por Astrid Ruíz - binarios y usuario
//Actualización de Astrid Ruíz (se actualizaron los archivos binarios con estructuras por el error d utilidades)
//Documentación Astrid Ruíz

#include "acreedor.h"
#include "bitacora.h"
#include "usuarios.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<cstring> // Necesario para strcpy
using namespace std;

extern usuarios usuariosrRegistrado;

// Definición de estructura para compatibilidad
struct AcreedorBin {
    char id[15];
    char nombreAcreedor[50];
    char nit[15];
    char telefono[15];
    char numCuenta[20];
    char banco[30];
};

void acreedor::menu()
{
    int choice;
    char x;
    do {
        system("cls");
        //cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t|  SISTEMA GESTION ACREEDORES |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t 1. Ingreso Acreedores"<<endl;
        cout<<"\t\t\t 2. Despliegue Acreedores"<<endl;
        cout<<"\t\t\t 3. Modifica Acreedores"<<endl;
        cout<<"\t\t\t 4. Busca Acreedores"<<endl;
        cout<<"\t\t\t 5. Borra Acreedores"<<endl;
        cout<<"\t\t\t 6. Reportes Acreedores"<<endl;
        cout<<"\t\t\t 7. Salida"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6/7]"<<endl; // Corregido para incluir 7
        cout<<"\t\t\tIngresa tu Opcion: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            do {
                insertar(); // Agregar nuevo acreedor
                cout<<"\n\t\t\t Agrega otro Acreedor (Y/N): ";
                cin>>x;
            } while(x=='y'||x=='Y');
            break;
        case 2:
            desplegar(); // Mostrar todos los acreedores
            break;
        case 3:
            modificar(); // Editar información de un acreedor
            break;
        case 4:
            buscar(); // Buscar acreedor por ID
            break;
        case 5:
            borrar(); // Eliminar acreedor por ID
            break;
        case 6:
            reporte(); // Mostrar reporte tabular de acreedores
            break;
        case 7:
            break;
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get();
        }
    } while(choice!= 7); // Corregido para salir cuando se seleccione 7
}

// Inserta un nuevo acreedor con validación y confirmación de datos
void acreedor::insertar()
{
    system("cls");
    fstream file;
    char confirmar;
    //implementación del trycatch
    try{
        do {
            cout << "\n----------------------------------------------------------------------------------";
            cout << "\n-------------------------------- Agregar Acreedor --------------------------------\n";

            cout << "\t\t\tIngresa ID Acreedor         : ";
            cin >> id;
            cout << "\t\t\tIngresa Nombre Acreedor     : ";
            cin >> nombreAcreedor;
            cout << "\t\t\tIngresa Nit Acreedor        : ";
            cin >> nit;
            cout << "\t\t\tIngresa Telefono Acreedor   : ";
            cin >> telefono;
            cout << "\t\t\tIngresa Num.Cuenta Acreedor : ";
            cin >> numCuenta;
            cout << "\t\t\tIngresa Banco del Acreedor  : ";
            cin >> banco;

            cout << "\nResumen de la información ingresada:\n";
            cout << "\t\t\tID Acreedor        : " << id << endl;
            cout << "\t\t\tNombre Acreedor    : " << nombreAcreedor << endl;
            cout << "\t\t\tNombre Nit         : " << nit << endl;
            cout << "\t\t\tTelefono Acreedor  : " << telefono << endl;
            cout << "\t\t\tNumero de Cuenta   : " << numCuenta << endl;
            cout << "\t\t\tBanco              : " << banco << endl;

            cout << "\n Esta seguro de guardar esta informacion? (S/N): ";
            cin >> confirmar;

            if (confirmar == 's' || confirmar == 'S') {
                //Abrir archivo en modo binario para agregar datos al final
                file.open("acreedor.bin", ios::binary | ios::app | ios::out);
                if (!file.is_open()) throw runtime_error("No se pudo abrir el archivo");

                // Convertir atributos de la clase a la estructura AcreedorBin
                AcreedorBin acreedorStruct;
                memset(&acreedorStruct, 0, sizeof(AcreedorBin)); // Inicializar con ceros

                // Copiar las cadenas string a los arrays de char d la estructura
                //usando strncpy para evitar lo del buffer (que se desborde)
                strncpy(acreedorStruct.id, id.c_str(), sizeof(acreedorStruct.id) - 1);
                strncpy(acreedorStruct.nombreAcreedor, nombreAcreedor.c_str(), sizeof(acreedorStruct.nombreAcreedor) - 1);
                strncpy(acreedorStruct.nit, nit.c_str(), sizeof(acreedorStruct.nit) - 1);
                strncpy(acreedorStruct.telefono, telefono.c_str(), sizeof(acreedorStruct.telefono) - 1);
                strncpy(acreedorStruct.numCuenta, numCuenta.c_str(), sizeof(acreedorStruct.numCuenta) - 1);
                strncpy(acreedorStruct.banco, banco.c_str(), sizeof(acreedorStruct.banco) - 1);

                // Escribir la estructura al archivo binario, aquí si la deje como antes
                //reinterpret_cast para convertir el puntero a la estructura en un puntero char
                file.write(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin));
                file.close();

                bitacora auditoria;
                auditoria.insertar(usuariosrRegistrado.getNombre(), "8040", "INA");
                cout << "\nAcreedor guardado correctamente.\n";
            } else {
                cout << "\nVolvamos a ingresar los datos...\n";
            }

        } while (confirmar != 's' && confirmar != 'S');
    } catch (const exception& e) {
        cout << "\n\t\t\t Error ocurrido: " << e.what() << endl;
    }
}

// Muestra todos los acreedores registrados
void acreedor::desplegar()
{
    system("cls");
    ifstream file;
    int total=0;
    cout<<"\n------------------------ Lista de Acreedores ------------------------"<<endl;
    file.open("acreedor.bin", ios::binary | ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion...\n";
    }
    else {
        //Cree la estructura temporal para almacenar cada registro leido
        //lo cambie pq si no, no iba jalar el id para lo de la factura
        AcreedorBin acreedorStruct;
        while(file.read(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin))) {
            total++;
            cout<<"\n\t\t\t ID Acreedor        : " << acreedorStruct.id << endl;
            cout<<"\t\t\t Nombre Acreedor    : " << acreedorStruct.nombreAcreedor << endl;
            cout<<"\t\t\t Nit Acreedodor     : " << acreedorStruct.nit << endl;
            cout<<"\t\t\t Telefono Acreedor  : " << acreedorStruct.telefono << endl;
            cout<<"\t\t\t Num.Cuenta Acreedor: " << acreedorStruct.numCuenta << endl;
            cout<<"\t\t\t Banco Acreedor     : " << acreedorStruct.banco << endl;
        }
        if(total==0){
            cout<<"\n\t\t\tNo hay informacion...";
        }
    }
    file.close();
    system("pause");
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8041", "MA"); //mostrar acreedor
}

// Permite modificar la información de un acreedor ya existente
void acreedor::modificar()
{
    system("cls");
    fstream file, tempFile;
    string acreedor_id;
    int found=0;
    cout<<"\n---------------- Modificar Acreedor ----------------"<<endl;
    file.open("acreedor.bin", ios::binary | ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion...";
        file.close();
    }
    else {
        cout<<"\nIngrese ID del Acreedor que quiere modificar: ";
        cin>>acreedor_id;
        tempFile.open("temporal.bin", ios::binary | ios::out);

        // Leer y escribir como estructura AcreedorBin
        AcreedorBin acreedorStruct;
        while(file.read(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin))) {
                //si el id no concide, copiar el registro sin cambios al archivo temporal
            if(acreedor_id != acreedorStruct.id) {
                tempFile.write(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin));
            }
            else {
                // si coincide, agregar los nuevos datos del usuario
                cout<<"\t\t\tIngrese Id Acreedor        : ";
                cin>>id;
                cout<<"\t\t\tIngrese Nombre Acreedor    : ";
                cin>>nombreAcreedor;
                cout<<"\t\t\tIngrese Nit de Acreedor    : ";
                cin>>nit;
                cout<<"\t\t\tIngrese Telefono Acreedor  : ";
                cin>>telefono;
                cout<<"\t\t\tIngrese Num.Cuenta Acreedor: ";
                cin>>numCuenta;
                cout<<"\t\t\tIngrese Banco Acreedor     : ";
                cin>>banco;

                // Convertir a la estructura y guardar (lo mismo de arriba) aquí utilizo strncpy para copiar un numero limitado de caracteres de una cadena a otra, lo del buffer xD
                memset(&acreedorStruct, 0, sizeof(AcreedorBin));
                strncpy(acreedorStruct.id, id.c_str(), sizeof(acreedorStruct.id) - 1);
                strncpy(acreedorStruct.nombreAcreedor, nombreAcreedor.c_str(), sizeof(acreedorStruct.nombreAcreedor) - 1);
                strncpy(acreedorStruct.nit, nit.c_str(), sizeof(acreedorStruct.nit) - 1);
                strncpy(acreedorStruct.telefono, telefono.c_str(), sizeof(acreedorStruct.telefono) - 1);
                strncpy(acreedorStruct.numCuenta, numCuenta.c_str(), sizeof(acreedorStruct.numCuenta) - 1);
                strncpy(acreedorStruct.banco, banco.c_str(), sizeof(acreedorStruct.banco) - 1);

                tempFile.write(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin)); //el reinterpret_cast lo del libro para reinterpretar un bloque de memoria de un tipo como si fuera d otro tipo (binario)
                found++;
            }
        }

        file.close();
        tempFile.close();
        remove("acreedor.bin");
        rename("temporal.bin","acreedor.bin");

        if(found==0){
            cout<<"\n\t\t\tAcreedor no encontrado...";
        }
        else {
            cout<<"\n\t\t\tAcreedor modificado exitosamente!";
        }
        system("pause");
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8042", "UAD");
    }
}

// Permite buscar un acreedor por ID y mostrar su información
void acreedor::buscar()
{
    system("cls");
    ifstream file;
    int found=0;

    cout<<"\n---------------- Buscar Acreedor ----------------"<<endl;
    file.open("acreedor.bin", ios::binary | ios::in);
    if(!file) {
        cout<<"\n\t\t\tNo hay informacion...";
    }
    else {
        string acreedor_id;
        cout<<"\nIngrese ID del Acreedor que quiere buscar : ";
        cin>>acreedor_id;

        // MODIFICADO: Leer como estructura AcreedorBin
        AcreedorBin acreedorStruct;
        while(file.read(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin))) {
            if(acreedor_id == acreedorStruct.id) {
                cout<<"\n\t\t\t ID Acreedor        : " << acreedorStruct.id << endl;
                cout<<"\t\t\t Nombre Acreedor    : " << acreedorStruct.nombreAcreedor << endl;
                cout<<"\t\t\t Nit acreedor       : " << acreedorStruct.nit << endl;
                cout<<"\t\t\t Telefono Acreedor  : " << acreedorStruct.telefono << endl;
                cout<<"\t\t\t Num.Cuenta Acreedor: " << acreedorStruct.numCuenta << endl;
                cout<<"\t\t\t Banco Acreedor     : " << acreedorStruct.banco << endl;
                found++;
                break;
            }
        }

        if(found==0){
            cout<<"\n\t\t\tAcreedor no encontrado...\n";
        }
        file.close();
    }
    system("pause");
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8043", "BAR");
}

// Elimina un acreedor según su ID
void acreedor::borrar()
{
    system("cls");
    fstream file, tempFile;
    string acreedor_id;
    int found=0;
    cout<<"\n---------------- Borrar Acreedor ----------------"<<endl;
    file.open("acreedor.bin", ios::binary | ios::in);

    if(!file) {
        cout<<"\n\t\t\tNo hay informacion...";
    }
    else {
        cout<<"\n Ingrese el Id del Acreedor que quiere borrar: ";
        cin>>acreedor_id;
        tempFile.open("temporal.bin", ios::binary | ios::out);

        // MODIFICADO: Leer como estructura AcreedorBin
        AcreedorBin acreedorStruct;
        while(file.read(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin))) {
            if(acreedor_id != acreedorStruct.id) {
                tempFile.write(reinterpret_cast<char*>(&acreedorStruct), sizeof(AcreedorBin));
            }
            else {
                found++;
                cout << "\nAcreedor borrado exitosamente\n";
            }
        }

        file.close();
        tempFile.close();
        remove("acreedor.bin");
        rename("temporal.bin","acreedor.bin");

        if(found==0) {
            cout<<"\nAcreedor no encontrado\n";
        }
        system("pause");
        bitacora auditoria;
        auditoria.insertar(usuariosrRegistrado.getNombre(), "8044", "DAR");
    }
}

// Genera un reporte tabular con todos los acreedores y guarda una copia en reportes.txt
//los reportes deben quedar .txt
void acreedor::reporte(){
    system("cls");
    fstream file, reporteFile;
    int found = 0;

    cout<<"\n----------------------------- Reporte de Acreedores -----------------------------\n"<<endl;
    file.open("acreedor.bin", ios::in);
    reporteFile.open("reportes.txt", ios::app | ios::out); // nuevo archivo

    if (!file) {
        cout << "\n\t\t\tNo hay informacion ...\n";
        reporteFile << "No hay informacion en acreedor.txt\n\n";
    }
    else {
        cout << left << setw(15) << "ID" << setw(15) << "Nombre"  << setw(15) << "Nit" << setw(15) << "Telefono"
             << setw(15) << "Num. Cuenta" << setw(15) << "Banco" << endl;
        cout << "------------------------------------------------------------------------------------------------\n";

        reporteFile << "------------------------------------- REPORTE DE ACREEDORES ---------------------------------------- \n";
        reporteFile << left << setw(15) << "ID" << setw(15) << "Nombre"  << setw(15) << "Nit" << setw(15) << "Telefono"
                    << setw(15) << "Num. Cuenta" << setw(15) << "Banco" << "\n";
        reporteFile << "-------------------------------------------------------------------------------------------\n";

        file >> id >> nombreAcreedor >> nit >> telefono >> numCuenta >> banco;
        while (!file.eof()) {
            found++;
            cout << left << setw(15) << id << setw(15) << nombreAcreedor << setw(15) << nit
            << setw(15) << telefono << setw(15) << numCuenta << setw(15) << banco << endl;

            reporteFile << left << setw(15) << id << setw(15) << nombreAcreedor << setw(15) << nit
            << setw(15) << telefono << setw(15) << numCuenta << setw(15) << banco << "\n";

            file >> id >> nombreAcreedor >> nit >> telefono >> numCuenta >> banco;
        }

        reporteFile << "----------------------------------------------------------------------------------------------\n\n";

        if(found==0){
            cout<<"\n\t\t\tNo hay Acreedores registrados...\n";
            reporteFile << "No hay Acreedores registrados...\n\n";
        }
    }

    cout << endl;
    file.close();
    reporteFile.close();
    system("pause");
    bitacora auditoria;
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8045", "REPORTEAC"); // Reporte Acreedor
}
