#include <iostream>
#include "SistemaVentas.h"
#include "Login.h"
#include "bitacora.h"
#include "Cliente.h"
#include "Facturacion.h"
#include "Producto.h"
#include "vendedores.h"
#include "venta.h"

using namespace std;


string usuarioActual; // Para guardar el nombre del usuario bitacora

void mostrarMenuPrincipal();
void MenuCatalogo();
void MenuProcesos();
void mostrarArchivo();  // Función para mostrar el archivo bitacora.txt

int main() {
    int opcion;
    bool accesoPermitido = false;


    do {

        system ("cls");
        cout << "\n--- Bienvenido al Sistema ---\n";
        cout << "1. Iniciar Sesion\n";
        cout << "2. Registrarse\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Para evitar errores con getline

        switch (opcion) {
            case 1:
                accesoPermitido = iniciarSesion(usuarioActual);
                break;
            case 2:
                registrarUsuario();
                break;
            case 3:
                cout << "\n\nSaliendo del sistema...\n";
                return 0;
            default:
                cout << "Opcion invalida.\n";
        }
    } while (!accesoPermitido);

    mostrarMenuPrincipal();
     registrarEvento(usuarioActual, "Cerro sesion desde menu principal");
    return 0;
}




void mostrarMenuPrincipal() {
    int opcion;
    do {
        system ("cls");
        cout << "\n\t\t\t|------------------------ \n" ;
        cout << "\t\t\t|     MENU PRINCIPAL     | \n";
        cout << "\t\t\t|------------------------- \n" ;
        cout << "\t\t\t|1. Catalogos\n";
        cout << "\t\t\t|2. Procesos\n";
        cout << "\t\t\t|3. Salir del sistema\n";
        cout << "\t\t\t|Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEvento(usuarioActual, "Entro a la opcion Catalogos 5002");
                MenuCatalogo();
                break;
            case 2:
                registrarEvento(usuarioActual, "Entro a la opcion Procesos 5002 ");
                MenuProcesos();
                break;
            case 3:
                registrarEvento(usuarioActual, "Salio del menu general 5002 ");
                cout << "Cerrando sesion...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 3);
}

void MenuProcesos() {
    SistemaVentas sistemaVentas;
    int opcion;
    do {
        system ("cls");
        cout << "n\t\t\t|------------------------- \n" ;
        cout << "\t\t\t|      MENU PROCESOS     | \n";
        cout << "\t\t\t|------------------------- \n" ;
        cout << "\t\t\t|1. CLIENTES \n";
        cout << "\t\t\t|2. VENDEDORES\n";
        cout << "\t\t\t|3. PRODUCTOS\n";
        cout << "\t\t\t|4. VENTAS\n";
        cout << "\t\t\t|5. FACTURACION\n";
        cout << "\t\t\t|6. REGRESAR AL MENU PRINCIPAL\n";
        cout << "\t\t\t| Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEvento(usuarioActual, "Entro a la opcion CLIENTES 5004 ");
                {
                    Cliente Cliente;
                    Cliente.MenuClientes();
                }
                break;
            case 2:
                registrarEvento(usuarioActual, "Entro a la opcion VENDEDORES 5002 ");
                {
                    Vendedores Vendedores;
                    Vendedores.MenuVendedores();
                }
                break;
            case 3:
                registrarEvento(usuarioActual, "Entro a la opcion PRODUCTOS 5002 ");
                {
                    Producto Producto;
                    Producto.MenuProducto();
                }
                break;
            case 4:
                registrarEvento(usuarioActual, "Entro a la opcion VENTAS 5002 ");
                {
                    SistemaVentas SistemaVentas;
                    SistemaVentas.menuVenta();
                }
                break;
            case 5:
                registrarEvento(usuarioActual, "Entro a la opcion FACTURACION 5002 ");
                {
                    Facturacion Facturacion;
                    Facturacion.menuFacturacion(sistemaVentas);
                }
                break;
            case 6:
                registrarEvento(usuarioActual, "Salio del menu de catalogos 5002 ");
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);
}

void MenuCatalogo() {
    SistemaVentas sistema;
    int opcion;
    do {
        system ("cls");
        cout << "n\t\t\t|--------------------------- \n" ;
        cout << "\t\t\t|      MENU CATALOGOS      | \n";
        cout << "\t\t\t|--------------------------- \n" ;
        cout << "\t\t\t|1. REGISTRO CLIENTES \n";
        cout << "\t\t\t|2. REGISTRO VENDEDORES\n";
        cout << "\t\t\t|3. REGISTRO PRODUCTOS\n";
        cout << "\t\t\t|4. REGRESAR AL MENU PRINCIPAL\n";
        cout << "\t\t\t| Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarEvento(usuarioActual, "Entro a la opcion REGISTRO CLIENTES 5004");
                {
                    Cliente Cliente;
                    Cliente.MostrarClientes();
                }
                break;
           case 2:
                registrarEvento(usuarioActual, "Entro a la opcion REGISTRO VENDEDORES 5002 ");
                {
                   Vendedores vendedores; // Instanciar la clase
                   vendedores.MostrarVendedores(); // Llamar la función de mostrar vendedores
                 }
    break;
            case 3:
                registrarEvento(usuarioActual, "Entro a la opcion REGISTRO PRODUCTOS 5002 ");
                {

                    Producto Producto;
                    Producto.MostrarProductos();
                }
                break;
            case 4:
                registrarEvento(usuarioActual, "Salio del menu de procesos 5002 ");
                break;
            default:
                cout << "Opcion no valida.\n";
        }
    } while (opcion != 4);
}


void mostrarArchivo() {
    system("cls");
    std::ifstream archivo("bitacora.bin", std::ios::binary);
    if (!archivo) {
        std::cout << "No se pudo abrir bitacora.bin" << std::endl;
        return;
    }

    std::cout << "=== Contenido de bitacora.bin ===" << std::endl;
    size_t longitud;
    std::string mensaje;

    while (archivo.read(reinterpret_cast<char*>(&longitud), sizeof(longitud))) {
        mensaje.resize(longitud);
        archivo.read(&mensaje[0], longitud);
        std::cout << mensaje << std::endl;
    }

    archivo.close();
}
