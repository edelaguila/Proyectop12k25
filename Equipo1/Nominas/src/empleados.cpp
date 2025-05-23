// Incluye el archivo de encabezado para la clase Empleados
#include "Empleados.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include <string>
#include <sstream>
#include <chrono>
#include <ctime>
#include <filesystem>
#include "bitacora.h"
// Objeto creado de la clase Empleados
Empleados empleados;
bitacora bitacoraempleado;
// Creado y documentado Por Isaias Cedillo (9959-24-1672) "IsaC8-bit y Xander reyes(prestaciones)"
// Constructor de la clase Empleados. Actualmente no realiza ninguna acción específica.
Empleados::Empleados()
{
}
// Metodo que muestra el menú de nómina
void Empleados::mostrarMenuNomina(const std::string& usuarioRegistrante)
{
    // Inicia un bucle que se ejecuta hasta que la opción sea 3.
    do{
        // Limpia la pantalla de la consola.
        system ("cls");
        // Muestra el encabezado del menú.
        cout << "\n -----MENU DE PRESTACIONES LABORALES -----\n";
        cout << "\n -----------------------------------------\n";
        cout << "1. Mostrar nomina general"<<endl;
        cout << "2. Mostrar nomina en especifico"<<endl<<endl;
        cout << "3. Regresar\n";
        cout << "\n -----------------------------------------\n";
        cout << "\n -----------------NOMIREG-----------------\n";
        // Solicita al usuario que seleccione una opción y la lee.
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        // Inicia una estructura switch para ejecutar diferentes acciones según la opción.
        switch (opcion)
        {
        // Mostrar nómina general.
        case 1:
            //mensaje indicando que la función está en desarrollo.
            cout<<"EN DESAROLLO...."<<endl;
            break;
        // Mostrar nómina específica.
        case 2:
            // Llama a la función buscarEmpleado del objeto empleados.
            buscarEmpleado(usuarioRegistrante);
            break;
        // Opción no válida.
        default:
            cout<<"Saliendo del sistema..."<<endl;
            break;
        }
        system("pause");
    // Continúa el bucle mientras la opción no sea 3.
    }while (opcion!=3);
}

// Muestra el menú principal para la gestión de empleados.
void Empleados::menuEmpleados(const std::string& usuarioRegistrante)
{
    // Inicializa la variable para la elección del usuario.
    int eleccion = 0;
    // Inicializa la variable para la confirmación del usuario.
    char x;
    // Inicia un bucle que se ejecuta hasta que la elección sea 5.
    do
    {
        // Limpia la pantalla de la consola.
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t |     Registro de empleados   |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Ingreso de Empleados" << endl;
        cout << "\t\t\t 2. Despliegue de Empleados" << endl;
        cout << "\t\t\t 3. Modificar Empleados" << endl;
        cout << "\t\t\t 4. Borrar Empleados" << endl;
        cout << "\t\t\t 5. Regresar" << endl<<endl;
        // Solicita al usuario que ingrese el número de la opción.
        cout << "\t\t Ingrese numero de opcion: ";
        // Lee la elección del usuario.
        cin >> eleccion;
        // Inicia una estructura switch.
        switch(eleccion)
        {
            // Ingreso de empleados.
            case 1:
                cout << "Opcion escogida... \n";
                // Llama a la función registroEmpleados para ingresar un nuevo empleado.
                registroEmpleados(usuarioRegistrante);
                // Pregunta si hay más empleados para añadir.
                cout << "Hay más empleados por añadir? Y/N \n";
                cin >> x;
                // Inicia un bucle para permitir el ingreso de múltiples empleados.
                while (x == 'y' || x == 'Y') {
                    // Llama a la función registroEmpleados para ingresar otro empleado.
                    registroEmpleados(usuarioRegistrante);
                    cout << "¿Desea ingresar otro empleado? Y/N \n";
                    cin >> x;
                }
                break;
            //Despliegue de empleados.
            case 2:
                cout << "Opcion escogida...\n";
                // Llama a la función listaEmpleados para mostrar la lista de empleados.
                listaEmpleados(usuarioRegistrante);
                break;
            //Modificar empleados.
            case 3:
                cout << "Opcion escogida \n";
                // Llama a la función cambioEmpleados para modificar la información de un empleado.
                cambioEmpleados(usuarioRegistrante);
                break;
            //Borrar empleados.
            case 4:
                cout << "Opcion escogida \n";
                // Llama a la función borrarEmpleados para eliminar un empleado.
                borrarEmpleados(usuarioRegistrante);
                break;
            // Regresar.
            case 5:
                cout <<"Regresando...."<<endl;
                break;
            // Opción no válida.
            default:
                // Muestra un mensaje indicando que la opción no es válida.
                cout << "Opcion no valida" << endl;
                break;
        }
        // Pausa la consola para que el usuario pueda ver la salida.
        system("pause");
    // Continúa el bucle mientras la elección no sea 5.
    } while(eleccion != 5);
}

void Empleados::registroEmpleados(const std::string& usuarioRegistrante) {
    system("cls");
    ofstream file;
    cout << "\n--------------------- Agregar Empleado ---------------------" << endl;

    // Limpieza de buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Lectura del nombre con validación de tamaño
    cout << "Nombre completo: ";
    getline(cin, Nombre);
    if (Nombre.empty()) {
        cout << "Error: El nombre no puede estar vacío.\n";
        return;
    }
    if (Nombre.size() > 500) { // Límite razonable de caracteres
        cout << "Error: El nombre es demasiado largo (máx 500 caracteres).\n";
        return;
    }

    // Lectura del sueldo
    cout << "Sueldo: Q";
    cin >> sueldo;
    if (sueldo < 4000) {
        cout << "Error: El sueldo mínimo es Q4000.\n";
        return;
    }

    // Inicializar tipoEmpleado (ejemplo con valor por defecto)
    tipoEmpleado = 1; // 1 = empleado regular (ajustar según necesidades)

    // Apertura del archivo con más modos de protección
    file.open("Empleados.bin", ios::binary|ios::app|ios::out);
    if (!file.is_open()) {
        cerr << "Error crítico: No se pudo abrir el archivo para escritura.\n";
        return;
    }

    try {
        // Escritura de datos con verificación
        size_t nombreSize = Nombre.size();
        file.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
        file.write(Nombre.c_str(), nombreSize);
        file.write(reinterpret_cast<const char*>(&sueldo), sizeof(sueldo));
        file.write(reinterpret_cast<const char*>(&tipoEmpleado), sizeof(tipoEmpleado));

        if (file.fail()) {
            throw runtime_error("Fallo al escribir en el archivo");
        }
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        file.close();
        remove("Empleados.bin");
        return;
    }

    file.close();
    bitacoraempleado.insertar(usuarioRegistrante, 7001, "REG_EMP");
}
void Empleados::listaEmpleados(const std::string& usuarioRegistrante) {
    system("cls");
    ifstream file("Empleados.bin", ios::binary);
    int total = 0;

    cout << "\n==================== LISTA DE EMPLEADOS ====================" << endl;

    if (!file) {
        cout << "\nNo hay empleados registrados o el archivo no existe.\n";
        system("pause");
        return;
    }

    try {
        while (true) {
            size_t nombreSize;
            // Leer tamaño del nombre
            file.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
            if (file.eof()) break;

            // Validar tamaño del nombre (evitar valores absurdamente grandes)
            if (nombreSize > 1000) { // 1000 caracteres como máximo razonable
                cerr << "Error: Tamaño de nombre inválido en archivo." << endl;
                break;
            }

            // Leer nombre
            vector<char> nombreBuffer(nombreSize + 1); // +1 para carácter nulo
            file.read(nombreBuffer.data(), nombreSize);
            if (file.gcount() != static_cast<std::streamsize>(nombreSize)) {
                cerr << "Error leyendo nombre del archivo." << endl;
                break;
            }
            nombreBuffer[nombreSize] = '\0'; // Asegurar terminación nula
            Nombre = nombreBuffer.data();

            // Leer sueldo
            file.read(reinterpret_cast<char*>(&sueldo), sizeof(sueldo));
            if (file.gcount() != sizeof(sueldo)) {
                cerr << "Error leyendo sueldo del archivo." << endl;
                break;
            }

            // Leer tipo de empleado
            file.read(reinterpret_cast<char*>(&tipoEmpleado), sizeof(tipoEmpleado));
            if (file.gcount() != sizeof(tipoEmpleado)) {
                cerr << "Error leyendo tipo de empleado del archivo." << endl;
                break;
            }

            // Mostrar información
            cout << "-----------------------------" << endl;
            cout << "Nombre: " << Nombre << endl;
            cout << "Sueldo: Q" << fixed << setprecision(2) << sueldo << endl;
            total++;
        }
    } catch (const std::bad_alloc& e) {
        cerr << "Error de memoria: " << e.what() << endl;
        file.close();
        system("pause");
        return;
    } catch (...) {
        cerr << "Error desconocido al leer archivo." << endl;
        file.close();
        system("pause");
        return;
    }

    if (total == 0) {
        cout << "\nNo hay empleados registrados.\n";
    } else {
        cout << "\nTotal de empleados: " << total << endl;
    }

    file.close();
    system("pause");

    bitacoraempleado.insertar(usuarioRegistrante, 7002, "REV_EMP");
}
void Empleados::cambioEmpleados(const std::string& usuarioRegistrante) {
    system("cls");
    fstream file, file1;
    string NombreCambio;
    float sueldoCambio;
    int found = 0;

    cout << "\n-------------------------Cambios laborales (no despidos)-------------------------" << endl;
    cout << "\n Ingrese el nombre de la persona a modificar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, NombreCambio);

    // Verificar si el empleado existe
    file.open("Empleados.bin", ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "\n\t\t\tNo hay información o no se pudo abrir el archivo..." << endl;
        return;
    }

    while (true) {
        size_t nombreSize;
        file.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
        if (file.eof()) break;

        Nombre.resize(nombreSize);
        file.read(&Nombre[0], nombreSize);
        file.read(reinterpret_cast<char*>(&sueldo), sizeof(sueldo));
        file.read(reinterpret_cast<char*>(&tipoEmpleado), sizeof(tipoEmpleado));

        if (Nombre == NombreCambio) {
            found++;
            break;
        }
    }
    file.close();

    if (found == 0) {
        cout << "\n\t\t\tUsuario no encontrado..." << endl;
        return;
    }

    cout << "\n Ingrese el nuevo sueldo: ";
    cin >> sueldoCambio;
    if (sueldoCambio < 4000) {
        cout << "Ingrese un sueldo valido segun ley.." << endl;
        system("pause");
    } else {
        file.open("Empleados.bin", ios::in | ios::binary);
        file1.open("Record.txt", ios::out | ios::binary);
        if (!file1.is_open()) {
            cout << "\n\t\t\tError al crear archivo temporal." << endl;
            file.close();
            return;
        }

        while (true) {
            size_t nombreSize;
            file.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
            if (file.eof()) break;

            Nombre.resize(nombreSize);
            file.read(&Nombre[0], nombreSize);
            file.read(reinterpret_cast<char*>(&sueldo), sizeof(sueldo));
            file.read(reinterpret_cast<char*>(&tipoEmpleado), sizeof(tipoEmpleado));

            if (Nombre == NombreCambio) {
                file1.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
                file1.write(Nombre.c_str(), nombreSize);
                file1.write(reinterpret_cast<const char*>(&sueldoCambio), sizeof(sueldoCambio));
                file1.write(reinterpret_cast<const char*>(&tipoEmpleado), sizeof(tipoEmpleado));
            } else {
                file1.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
                file1.write(Nombre.c_str(), nombreSize);
                file1.write(reinterpret_cast<const char*>(&sueldo), sizeof(sueldo));
                file1.write(reinterpret_cast<const char*>(&tipoEmpleado), sizeof(tipoEmpleado));
            }
        }

        file.close();
        file1.close();
        remove("Empleados.bin");
        rename("Record.txt", "Empleados.bin");
        cout << "\n\t\t\tRegistro modificado exitosamente..." << endl;
    }

    bitacoraempleado.insertar(usuarioRegistrante, 7003, "CAM_EMP");
}

double Empleados::calcularIndemnizacion(double sueldo, int anios) {
    return sueldo * anios;
}

void Empleados::borrarEmpleados(const std::string& usuarioRegistrante) {
    system("cls");
    fstream file, file1;
    string CambioNombreBorrar;
    int found = 0;

    cout << "\n-------------------------Detalles Persona a Borrar-------------------------" << endl;
    file.open("Empleados.bin", ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "\n\t\t\tNo hay información o no se pudo abrir el archivo..." << endl;
        return;
    }

    cout << "\n Ingrese el nombre de la Persona que quiere borrar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, CambioNombreBorrar);

    file1.open("Record.txt", ios::out | ios::binary);
    if (!file1.is_open()) {
        cout << "\n\t\t\tError al crear archivo temporal." << endl;
        file.close();
        return;
    }

    while (true) {
        size_t nombreSize;
        file.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
        if (file.eof()) break;

        Nombre.resize(nombreSize);
        file.read(&Nombre[0], nombreSize);
        file.read(reinterpret_cast<char*>(&sueldo), sizeof(sueldo));
        file.read(reinterpret_cast<char*>(&tipoEmpleado), sizeof(tipoEmpleado));

        if (CambioNombreBorrar != Nombre) {
            file1.write(reinterpret_cast<const char*>(&nombreSize), sizeof(nombreSize));
            file1.write(Nombre.c_str(), nombreSize);
            file1.write(reinterpret_cast<const char*>(&sueldo), sizeof(sueldo));
            file1.write(reinterpret_cast<const char*>(&tipoEmpleado), sizeof(tipoEmpleado));
        } else {
            found++;
            cout << "\nEmpleado encontrado. Procediendo con su despido..." << endl;
            int anios;
            cout << "Ingrese los anios trabajados del empleado: ";
            cin >> anios;
            double indemnizacion = calcularIndemnizacion(sueldo, anios);

            cout << "\n----- Detalles del Despido -----" << endl;
            cout << "Empleado despedido: " << Nombre << endl;
            cout << "Sueldo base: Q" << fixed << setprecision(2) << sueldo << endl;
            cout << "Anios trabajados: " << anios << endl;
            cout << "Indemnizacion a pagar: Q" << fixed << setprecision(2) << indemnizacion << endl;
            cout << "--------------------------------" << endl;

            cout << "\n\t\tBorrado exitosamente!" << endl;
            system("pause");
            cin.ignore();
        }
    }

    file.close();
    file1.close();

    if (found == 0) {
        cout << "\n\t\t\tEmpleado no encontrado..." << endl;
        remove("Record.txt");
    } else {
        remove("Empleados.bin");
        rename("Record.txt", "Empleados.bin");
    }

  bitacoraempleado.insertar(usuarioRegistrante, 7004, "DEL_EMP");
}

void Empleados::buscarEmpleado(const std::string& usuarioRegistrante) {
    system("cls");
    fstream file;
    string nombreBuscar;

    cout << "\n==================== BUSCAR EMPLEADO ====================" << endl;
    cout << "Ingrese el nombre del empleado: ";
    cin.ignore();
    getline(cin, nombreBuscar);

    file.open("Empleados.bin", ios::in | ios::binary);
    if (!file.is_open()) {
        cout << "\nNo hay empleados registrados o el archivo no existe.\n";
        return;
    }

    bool encontrado = false;
    while (true) {
        size_t nombreSize;
        file.read(reinterpret_cast<char*>(&nombreSize), sizeof(nombreSize));
        if (file.eof()) break;

        Nombre.resize(nombreSize);
        file.read(&Nombre[0], nombreSize);
        file.read(reinterpret_cast<char*>(&sueldo), sizeof(sueldo));
        file.read(reinterpret_cast<char*>(&tipoEmpleado), sizeof(tipoEmpleado));

        if (Nombre == nombreBuscar) {
            cout << "\nEmpleado encontrado:\n";
            cout << "Nombre: " << Nombre << endl;
            cout << "Sueldo: Q" << fixed << setprecision(2) << sueldo << endl;
            salarioBruto = sueldo;
            salarioNeto = sueldo;

            int nomina;
            cout << "Desea mostrar: " << endl;
            cout << "1. Nomina anual de a o anterior" << endl;
            cout << "2. Nomina mensual del a o actual" << endl;
            cin >> nomina;

            switch (nomina) {
                case 1:
                    calcularNominaAnual();
                    break;
                case 2:
                    calcularNominaMensual();
                    break;
            }

            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEmpleado no encontrado.\n";
    } else {
        cout << "" << endl;
    }

    file.close();

    bitacoraempleado.insertar(usuarioRegistrante, 7005, "BUS_EMP");
}
//Realizado por XANDER REYES
void Empleados::calcularNominaMensual() {
    // Declaración de variable para almacenar el mes ingresado por el usuario
    int mesActual;

    // Solicita al usuario que ingrese el número del mes (del 1 al 12)
    cout << "Ingrese el numero del mes (1-12): ";
    cin >> mesActual;

    // Verifica si el mes ingresado está dentro del rango válido
    if (mesActual < 1 || mesActual > 12) {
        // Muestra un mensaje de error si el mes no es válido
        cout << "Mes invalido. Debe estar entre 1 y 12." << endl;
        return; // Sale de la función sin hacer más cálculos
    }

    // Calcula el descuento por ISR (Impuesto Sobre la Renta)
    salarioSinISR = salarioBruto * ISR;

    // Calcula el descuento por IRTRA (Instituto de Recreación de los Trabajadores)
    salarioSinIRTRA = salarioBruto * IRTRA;

    // Calcula el descuento por IGSS (Instituto Guatemalteco de Seguridad Social)
    salarioSinIGSS = salarioBruto * IGSS;

    // Si el mes es junio (6), se asigna el Bono 14 igual al salario bruto, si no, se asigna 0
    bono14 = (mesActual == 6) ? salarioBruto : 0.0;

    // Si el mes es diciembre (12), se asigna el Aguinaldo igual al salario bruto, si no, se asigna 0
    aguinaldo = (mesActual == 12) ? salarioBruto : 0.0;

    // Calcula el salario neto: salario bruto menos descuentos, más bono incentivo y posibles bonos adicionales
    salarioNeto = salarioBruto - salarioSinISR - salarioSinIRTRA - salarioSinIGSS + bonoIncentivo + bono14 + aguinaldo;

    // Arreglo con los nombres de los meses del año
    const string meses[12] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"
    };

    // Muestra el nombre del mes correspondiente
    cout << "Nomina mes de " << meses[mesActual - 1] << endl;

    // Muestra el monto descontado por IGSS
    cout << "Descuento del IGSS: Q" << salarioSinIGSS << endl;

    // Muestra el monto descontado por IRTRA
    cout << "Descuento del IRTRA: Q" << salarioSinIRTRA << endl;

    // Muestra el monto descontado por ISR
    cout << "Descuento del ISR: Q" << salarioSinISR << endl;

    // Muestra el bono incentivo sumado al salario
    cout << "Bono incentivo: +Q" << bonoIncentivo << endl;

    // Si se aplica Bono 14, lo muestra en pantalla
    if (bono14 > 0) cout << "Bono 14: +Q" << bono14 << endl;

    // Si se aplica Aguinaldo, lo muestra en pantalla
    if (aguinaldo > 0) cout << "Aguinaldo: +Q" << aguinaldo << endl;

    // Muestra el salario neto final que recibirá el empleado
    cout << "Salario neto a recibir: Q" << salarioNeto << endl;
    system("pause");
}
// Calcula la nómina anual de un empleado
void Empleados::calcularNominaAnual() {
    double totalIGSS = 0.0;
    double totalIRTRA = 0.0;
    double totalISR = 0.0;
    double totalBonos = 0.0;
    double totalsalarioNeto = 0.0;

    // Itera por los 12 meses del a o
    for (int mes = 1; mes <= 12; ++mes) {
        // Calcula descuentos mensuales
        double descuentoIGSS = salarioBruto * IGSS;
        double descuentoIRTRA = salarioBruto * IRTRA;
        double descuentoISR = salarioBruto * ISR;

        // Bonos especiales
        double bono14Mes = (mes == 6) ? salarioBruto : 0.0;
        double aguinaldoMes = (mes == 12) ? salarioBruto : 0.0;

        // Salario neto del mes
        double salarioNetoMes = salarioBruto - descuentoISR - descuentoIRTRA - descuentoIGSS + bonoIncentivo + bono14Mes + aguinaldoMes;

        // Acumula totales
        totalIGSS += descuentoIGSS;
        totalIRTRA += descuentoIRTRA;
        totalISR += descuentoISR;
        totalBonos += bono14Mes + aguinaldoMes;
        totalsalarioNeto += salarioNetoMes;
    }

    // Mostrar resumen anual
    cout << "\nResumen de Nomina Anual" << endl;
    cout << "-------------------------" << endl;
    cout << "Total descuento IGSS: Q" << totalIGSS << endl;
    cout << "Total descuento IRTRA: Q" << totalIRTRA << endl;
    cout << "Total descuento ISR: Q" << totalISR << endl;
    cout << "Total bonos (Bono 14 + Aguinaldo): Q" << totalBonos << endl;
    cout << "Total salario neto anual: Q" << totalsalarioNeto << endl;
    system("pause");
}
