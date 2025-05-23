//Programado y documentado por Dulce Martínez
#include "Cobros.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "usuarios.h"
#include "bitacora.h"

using namespace std;

extern usuarios usuariosrRegistrado;

void GestionCobros::menuCobros() {
    GestionCobros gc;
    int opcion;

    while (true) {
        system("cls");
        cout << "\n========= MENÚ DE COBROS =========\n";
        cout << "1. Ver Cuentas por Cobrar\n";
        cout << "2. Registrar Cobro\n";
        cout << "3. Ver Historial de Cobros\n";
        cout << "4. Buscar Cobro por Factura\n";
        cout << "5. Listar Cobros por Cliente\n";
        cout << "6. Volver al Menú Principal\n";
        cout << "==================================\n";
        cout << "Ingrese una opción: ";
        cin >> opcion;

        if (opcion == 6) {
            break;
        }

        switch (opcion) {
            case 1:
                gc.listarCuentasPorCobrar();
                break;
            case 2:
                gc.registrarCobro();
                break;
            case 3:
                gc.listarHistorialCobros();
                break;
            case 4: {
                int id;
                cout << "Ingrese ID de factura: ";
                cin >> id;
                gc.buscarCobroPorFactura(id);
                break;
            }
            case 5: {
                string id;
                cout << "Ingrese ID del cliente: ";
                cin >> id;
                gc.listarCobrosPorCliente(id);
                break;
            }

            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }

        cout << "\nPresione Enter para continuar...";
        cin.get(); // Este solo espera Enter, pero no limpia buffer (y es opcional)
        cin.get(); // Lo puedes quitar si te da problemas
    }
}

void GestionCobros::listarCuentasPorCobrar() {
    ifstream fileFacturas("facturas.bin");
    if (!fileFacturas) {
        cout << "No se pudo abrir el archivo de facturas." << endl;
        system("pause");
        return;
    }

    string linea;
    string idFactura, nombre, cuenta, montoStr, fecha, hora, tipo, clasificacion, estado, saldoStr;
    float montoTotal, saldoPendiente;

    cout << "------ Listado de Cuentas por Cobrar ------\n";
    cout << "ID Factura | Cliente | Monto Total | Saldo Pendiente | Estado\n";
    cout << "-------------------------------------------------------------\n";

    while (getline(fileFacturas, linea)) {
        stringstream ss(linea);
        getline(ss, idFactura, ',');
        getline(ss, nombre, ',');
        getline(ss, cuenta, ',');
        getline(ss, montoStr, ',');
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, tipo, ',');
        getline(ss, clasificacion, ',');
        getline(ss, estado, ',');
        getline(ss, saldoStr);

        montoTotal = stof(montoStr);
        saldoPendiente = stof(saldoStr);

        // Mostrar solo si no está solvente o pagada
        if ((estado != "solvente" && estado != "pagada") && tipo=="Cliente") {
            cout << idFactura << " | " << nombre << " | Q" << fixed << setprecision(2) << montoTotal
                 << " | Q" << saldoPendiente << " | " << estado << endl;
        }
    }

    fileFacturas.close();
    system("pause");
}

void GestionCobros::registrarCobro() {
    bitacora auditoria;

    // Archivos
    fstream fileFacturas, fileCobros, fileTemporal;

    // Variables de factura
    // Variables de factura
    string lineaFactura;
    string idFactura, nombre, nitCliente, montoStr, fecha, hora, tipo, clasificacion, estado, saldoStr;
    float montoTotal, saldoPendiente;
    string idFacturaRegistrada;


    // Variables de control
    bool facturaExiste = false;
    char confirmar;

    system("cls");
    cout << "\n------------- Registrar Nuevo Cobro -------------\n";
    cout << "\n\tIngrese el ID de la factura: ";
    cin >> idFacturaRegistrada;

    fileFacturas.open("facturas.bin", ios::in);
    fileTemporal.open("facturas_temporal.bin", ios::app | ios::out);

    if (!fileFacturas) {
        cout << "No se encontró información..." << endl;
        system("pause");
        return;
    }

    while (getline(fileFacturas, lineaFactura)) {
        stringstream ss(lineaFactura);
        getline(ss, idFactura, ',');
        getline(ss, nombre, ',');
        getline(ss, nitCliente, ',');
        getline(ss, montoStr, ',');
        getline(ss, fecha, ',');
        getline(ss, hora, ',');
        getline(ss, tipo, ',');
        getline(ss, clasificacion, ',');
        getline(ss, estado, ',');
        getline(ss, saldoStr);

        montoTotal = stof(montoStr);
        saldoPendiente = stof(saldoStr);

        if (idFactura == idFacturaRegistrada && tipo == "Cliente" &&
            clasificacion == "Por cobrar" &&
            (estado == "Pendiente" || estado == "cobrado_parcial")) {

            facturaExiste = true;

            cout << "\nFactura encontrada - Saldo pendiente: Q" << fixed << setprecision(2) << saldoPendiente << endl;
            cout << "\n------------------------------------------------\n";
            cout << "Ingrese ID del cobro    : "; cin >> idCobro;
            cout << "Ingrese fecha del cobro : "; cin >> fechaCobro;
            cout << "Ingrese monto recibido  : Q "; cin >> montoCobro;
            cout << "Ingrese método de cobro : "; cin >> metodoCobro;

            system("cls");
            cout << "\n--------- Resumen de la información ingresada ---------\n";
            cout << "ID Cobro        : " << idCobro << endl;
            cout << "ID Factura      : " << idFactura << endl;
            cout << "Fecha del cobro : " << fechaCobro << endl;
            cout << "Método de cobro : " << metodoCobro << endl;
            cout << "Monto recibido  : Q" << fixed << setprecision(2) << montoCobro << endl;
            cout << "Saldo Actual    : Q" << saldoPendiente << endl;
            cout << "NIT del cliente : " << nitCliente << endl;
            cout << "Tipo Entidad    : Cliente" << endl;

            cout << "\n¿Está seguro de guardar esta información? (S/N): ";
            cin >> confirmar;

            if (confirmar == 's' || confirmar == 'S') {
                if (montoCobro > saldoPendiente) {
                    cout << "El monto ingresado excede el saldo pendiente (Q" << saldoPendiente << ")\n";
                    estadoCobro = "rechazado";
                    montoCobro = 0;
                } else if (montoCobro < 0) {
                    cout << "El monto no puede ser menor a cero.\n";
                    estadoCobro = "rechazado";
                    montoCobro = 0;
                } else {
                    saldoPendiente -= montoCobro;
                    if (saldoPendiente == 0) {
                        estado = "solvente";
                        estadoCobro = "ejecutado";
                    } else {
                        estado = "cobrado_parcial";
                        estadoCobro = "ejecutado";
                    }

                    auditoria.insertar(usuariosrRegistrado.getNombre(), "8300", "UPDF"); // Actualizar facturas
                }
            } else {
                estadoCobro = "rechazado";
                montoCobro = 0;
            }

            // Guardar factura actualizada
            fileTemporal << idFactura << "," << nombre << "," << nitCliente << ","
                         << fixed << setprecision(2) << montoTotal << "," << fecha << "," << hora << ","
                         << tipo << "," << clasificacion << "," << estado << "," << saldoPendiente << "\n";

        } else {
            // Copia la línea sin cambios
            fileTemporal << lineaFactura << endl;
        }
    }

    fileFacturas.close();
    fileTemporal.close();

    if (!facturaExiste) {
        cout << "\nFactura no válida, ya solvente o no corresponde a un cliente.\n";
        remove("facturas_temporal.bin");
        system("pause");
        return;
    }

    // Reemplaza el archivo original
    remove("facturas.bin");
    rename("facturas_temporal.bin", "facturas.bin");

    // Guardar el cobro
    fileCobros.open("cobros.bin", ios::app | ios::out);
    if (!fileCobros) {
        cout << "No se encontró información..." << endl;
        system("pause");
        return;
    }

    fileCobros << idCobro << "," << idFactura << "," << fechaCobro << ","
               << fixed << setprecision(2) << montoCobro << "," << metodoCobro << ","
               << nitCliente << "," << "Cliente" << "," << estadoCobro << endl;

    fileCobros.close();

    if (estadoCobro == "rechazado") {
        cout << "\nEl cobro fue rechazado y registrado como tal.\n";
    } else {
        cout << "\nCobro registrado exitosamente.\n";
    }

    system("pause");
    auditoria.insertar(usuariosrRegistrado.getNombre(), "8300", "AddC"); // Registrar cobro
}

void GestionCobros::listarHistorialCobros() {
    ifstream file("cobros.bin");
    string linea;

    if (!file) {
        cout << "No se encontró el archivo de cobros.\n";
        return;
    }

    cout << "\n----------- Historial de Cobros (Clientes) -----------\n";

    while (getline(file, linea)) {
        stringstream ss(linea);
        string idCobro, idFactura, fecha, monto, metodo, nit, tipo, estado;

        getline(ss, idCobro, ',');
        getline(ss, idFactura, ',');
        getline(ss, fecha, ',');
        getline(ss, monto, ',');
        getline(ss, metodo, ',');
        getline(ss, nit, ',');
        getline(ss, tipo, ',');
        getline(ss, estado);


        if (tipo == "Cliente") {
            cout << "\nID Cobro   : " << idCobro
                 << "\nFactura    : " << idFactura
                 << "\nFecha      : " << fecha
                 << "\nMonto      : Q" << monto
                 << "\nMétodo     : " << metodo
                 << "\nNIT Cliente: " << nit
                 << "\nEstado     : " << estado << endl;
        }
    }

    file.close();
    system("pause");
}

void GestionCobros::buscarCobroPorFactura(int idFactura) {
    string facturaBuscada;
    cout << "\nIngrese el ID de la factura: ";
    cin >> facturaBuscada;

    ifstream file("cobros.bin");
    string linea;
    bool encontrado = false;

    if (!file) {
        cout << "No se encontró el archivo de cobros.\n";
        return;
    }

    cout << "\n--- Cobros para Factura: " << facturaBuscada << " ---\n";

    while (getline(file, linea)) {
        stringstream ss(linea);
        string idCobro, idFactura, fecha, monto, metodo, nit, tipo, estado;

        getline(ss, idCobro, ',');
        getline(ss, idFactura, ',');
        getline(ss, fecha, ',');
        getline(ss, monto, ',');
        getline(ss, metodo, ',');
        getline(ss, nit, ',');
        getline(ss, tipo, ',');
        getline(ss, estado);

        if (tipo == "Cliente" && idFactura == facturaBuscada) {
            encontrado = true;
            cout << "\nID Cobro   : " << idCobro
                 << "\nFecha      : " << fecha
                 << "\nMonto      : Q" << monto
                 << "\nMétodo     : " << metodo
                 << "\nEstado     : " << estado << endl;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontraron cobros para esta factura.\n";
    }

    file.close();
    system("pause");
}

void GestionCobros::listarCobrosPorCliente(string nitCliente) {
    string nitBuscado;
    cout << "\nIngrese el NIT del cliente: ";
    cin >> nitBuscado;

    ifstream file("cobros.bin");
    string linea;
    bool encontrado = false;

    if (!file) {
        cout << "No se encontró el archivo de cobros.\n";
        return;
    }

    cout << "\n--- Cobros del Cliente con NIT: " << nitBuscado << " ---\n";

    while (getline(file, linea)) {
        stringstream ss(linea);
        string idCobro, idFactura, fecha, monto, metodo, nit, tipo, estado;

        getline(ss, idCobro, ',');
        getline(ss, idFactura, ',');
        getline(ss, fecha, ',');
        getline(ss, monto, ',');
        getline(ss, metodo, ',');
        getline(ss, nit, ',');
        getline(ss, tipo, ',');
        getline(ss, estado);

        if (tipo == "Cliente" && nit == nitBuscado) {
            encontrado = true;
            cout << "\nID Cobro   : " << idCobro
                 << "\nFactura    : " << idFactura
                 << "\nFecha      : " << fecha
                 << "\nMonto      : Q" << monto
                 << "\nMétodo     : " << metodo
                 << "\nEstado     : " << estado << endl;
        }
    }

    if (!encontrado) {
        cout << "\nNo se encontraron cobros para este cliente.\n";
    }

    file.close();
    system("pause");
}
