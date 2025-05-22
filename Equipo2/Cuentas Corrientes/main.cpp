//Main iniciado a programar por Astrid Ruíz (Agregué el menu general, el d inicio, todo el de usuarios para asegurarme d que inicie sesión antes d modficar un usuasio)
////Menu modificado por Astrid Ruíz 9959 24 2976 - Agregué menu de seguridad para usuarios y agregué backup
//Astrid Ruíz - Terminé de agregar todos los backups wuuuuu

//El día de la exposición se requirio como mejora integrar el nombre del usuario que está en el programa (el usuario en línea) se realizó en todos los menus
//Mejora implementada por Astrid Ruíz
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "usuarios.h"
#include "catalogos.h"
#include "procesos.h"
#include "bitacora.h"
#include "proveedor.h"
#include "reportes.h"
#include "acreedor.h"
#include "cliente.h"
#include "pago.h"
#include "transaccion.h"
#include <limits>
#include "factura.h"

using namespace std;

extern cliente clientes;

void menuGeneral ();
void menuInicio();
void menuUsuarios();
void menuBackup();

//Objetos
usuarios usuariosrRegistrado;
Catalogos catalogo;
bitacora auditorias;
proveedor proveedoress;
reportes reporte;
acreedor acreedoress;
pago pagos;
transaccion transa;
//GestionCobros cobro;


int main()
{
    try {
        menuInicio();
    } catch (exception &e){
        cout << "\n\t\t Error ocurrido: " << e.what() << endl; //En caso de un erro en medio de la ejecucion
    }

    system("cls");
    cout << "\n\t\tSALIENDO DEL SISTEMA...\n";
    return 0;
}

void menuInicio() {
    int opcion;
    bool accesoUsuarios;

    do {
        system("cls");
        cout << "\n\t\t--------------------------------------" << endl;
        cout << "\t\t   SISTEMA DE USUARIOS - MENU ARCHIVOS  " << endl;
        cout << "\t\t--------------------------------------" << endl << endl;
        cout << "\t\t1. Iniciar Sesion" << endl;
        cout << "\t\t2. Registrarse" << endl; //para que el usuario tenga oportunidad de registrarse si no tiene user
        cout << "\t\t3. Gestion de Usuarios" << endl; //CRUD USUARIOS
        cout << "\t\t4. Backup y Respaldo" << endl;
        cout << "\t\t5. Salir" << endl;
        cout << "\t\tSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                system("cls");
                accesoUsuarios = usuariosrRegistrado.loginUsuarios();
                if (accesoUsuarios) {
                    menuGeneral();
                    return;
                }
                break;
            case 2:
                system ("cls");
                usuariosrRegistrado.registrarUsuario();
                 break;
            case 3: //Se requiere que el usuario inicie sesión antes por seguridad
                system("cls");
                if (usuariosrRegistrado.getNombre().empty()) {
                    cout << "\n\t\tDebe iniciar sesión para acceder a esta función." << endl;
                     system("pause"); // <-- Pausa para que se lean los mensajes
                    if (!usuariosrRegistrado.loginUsuarios()) {
                        cout << "\n\t\tInicio de sesión fallido. No se puede acceder a Gestión de Usuarios." << endl;
                        system("pause"); // <-- Pausa para que se lean los mensajes
                        break;
                    }
                }
                menuUsuarios(); // ya está autenticado aquí
                break;
            case 4: //Se requiere que el usuario inicie sesión antes por seguridad
                system("cls");
                if (usuariosrRegistrado.getNombre().empty()) {
                    cout << "\n\t\tDebe iniciar sesión para acceder a esta función." << endl;
                    system("pause"); // <-- Pausa para que se lean los mensajes
                    if (!usuariosrRegistrado.loginUsuarios()) {
                        cout << "\n\t\tInicio de sesión fallido. No se puede acceder a Backup." << endl;
                        system("pause"); // <-- Pausa para que se lean los mensajes
                        break;
                    }
                }
                menuBackup();
                break;
            case 5:
                return; // Salir del programa
            default:
                cout << "\n\t\tOpción inválida. Intente de nuevo." << endl;
                system("pause");
        }
    } while (opcion != 5);
}

void menuUsuarios() {
    int choice;
    do {
        system("cls");
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\t | SISTEMA GESTION DE SEGURIDAD - Usuarios |" << endl;
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\t 1. Ingreso Usuarios" << endl;
        cout << "\t\t\t 2. Consulta Usuarios" << endl;
        cout << "\t\t\t 3. Modificación Usuarios" << endl;
        cout << "\t\t\t 4. Eliminación Usuarios" << endl;
        cout << "\t\t\t 5. Retornar al menú anterior" << endl;
        cout << "\t\t\t-------------------------------------------------------" << endl;
        cout << "\t\t\tIngrese una opción: ";
        cin >> choice;

        switch (choice) {
        case 1:
            usuariosrRegistrado.registrarUsuario();
            break;
        case 2:
            usuariosrRegistrado.consultarUsuarios();
            system("pause"); // <-- Pausa para que se lean los mensajes
            break;
        case 3:
            usuariosrRegistrado.modificarUsuario();
            system("pause");
            break;
        case 4:
            usuariosrRegistrado.eliminarUsuario();
            system("pause");
            break;
        case 5:
            break;
        default:
            cout << "n\t\tOpción no válida. Intente de nuevo" << endl;
        }

    } while (choice != 5);
}


void menuBackup() {
    int opcion;
    do {
        system("cls");
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout << "\n\t\t---------------------------------" << endl;
        cout << "\t\t  MENÚ DE BACKUP Y RESPALDO     " << endl;
        cout << "\t\t-----------------------------------" << endl << endl;
        cout << "\t\t1. Realizar backup de usuarios" << endl;
        cout << "\t\t2. Restaurar backup de usuarios" << endl;
        cout << "\t\t3. Realizar backup de bitacora" << endl;
        cout << "\t\t4. Realizar backup de proveedores" << endl;
        cout << "\t\t5. Realizar backup de acreedores" << endl;
        cout << "\t\t6. Realizar backup de clientes" << endl;
        cout << "\t\t7. Realizar backup de gestión de pagos" << endl;
        cout << "\t\t8. Realizar backup de gestión de cobros" << endl;
        cout << "\t\t9. Realizar backup de transacciones" << endl;
        cout << "\t\t10. Retornar al menú anterior" << endl;
        cout << "\t\tSeleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                usuariosrRegistrado.backupUsuarios();
                break;
            case 2:
                usuariosrRegistrado.restaurarBackup();
                break;
            case 3:
               auditorias.backupBitacora();
                break;
            case 4:
                proveedoress.backupProveedores();
                break;
            case 5:
                acreedoress.backupAcreedores();
                break;
            case 6:
                clientes.backupClientes();
                break;
            case 7:
                pagos.backupPagos();
                break;
            case 8:
                //cobro.backupCobros();
                break;
            case 9:
                transa.backupTransacciones();
                break;
            case 10:
               return;
            default:
                cout << "\n\t\tOpción inválida. Intente de nuevo." << endl;
                system("pause");
        }

        if (opcion != 11) {
            cout << "\n\t\tPresione Enter para continuar...";
            cin.get();
        }
    } while (opcion != 3);
}

void menuGeneral(){
    int opciones;
    do{
        system("cls"); // Limpia la pantalla
        cout << "\t\t\tUsuario en linea: " << usuariosrRegistrado.getNombre() << "\n" << endl;
        cout << "\t\t\t---------------------- " << endl;
        cout << "\t\t\t | CUENTAS POR COBRAR |" << endl;
        cout << "\t\t\t-----------------------" << endl;
        cout << "\t\t\t1. Menu de Catalogos" << endl;
        cout << "\t\t\t2. Menu de Procesos" << endl;
        cout << "\t\t\t3. Menu de Reportes" << endl;
        cout << "\t\t\t4. Menu de Configuracion" << endl;
        cout << "\t\t\t5. Menu de Bitacora" << endl;
        cout << "\t\t\t6. Menu de Archivos (Usuarios)" << endl; //Astrid agregó menú para los archivos
        cout << "\t\t\t7. Salir" << endl;
        cout << "\n\t\tIngrese una opcion: ";
        cin >> opciones;

        switch (opciones) {
            case 1:
                catalogo.menuCatalogos();
                break;
            case 2:
                menuProcesos();
                break;
            case 3:
                reporte.menuInformes();
                break;
            case 4:
                //menuConfiguracion();
                break;
            case 5:
                auditorias.menu();
                break;
            case 6:
                menuInicio();
                break;
            case 7:
                cout << "\n\n\t\tSaliendo del sistema...\n" << endl;
                break;
            default:
                cout << "n\t\tOpción no válida. Intente de nuevo" << endl;
        }
    } while (opciones != 7); // Repite el menú hasta que el usuario quiera salir

}
