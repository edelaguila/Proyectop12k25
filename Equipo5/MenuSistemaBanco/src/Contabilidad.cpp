//Jonathan Samuel Gonzalez Ixpata 9959-23-3184
#include "Contabilidad.h"   // Declaraciones de la clase Contabilidad
#include <vector>           // Contenedor din�mico para listas
#include <sstream>          // Flujo de strings (no usado aqu�, pero �til para formateo)
#include <map>              // Para usar std::map
#include <iomanip>          // Manipuladores para formatear salida (setw, etc.)
#include <algorithm>        // Funciones como find()
#include <cstring>          // Funciones de C para manipular cadenas (strncpy, etc.)
#include "Bitacora.h"       // Registro de acciones (bit�cora)
#include "Moneda.h"         // Conversi�n y formato de moneda (GTQ a otras divisas)

#ifdef _WIN32
#include <cstdlib>          // Para usar system("cls") en Windows
#endif

// Instancia global del sistema de bit�cora para registrar las acciones hechas en este m�dulo
Bitacora bitacoralogContabilidad;

using namespace std;


// M�TODOS UTILITARIOS

// Limpia la consola dependiendo del sistema operativo
void Contabilidad::limpiarPantalla() {
#ifdef _WIN32
    system("cls");  // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}

// Pausa el programa hasta que el usuario presione ENTER
void Contabilidad::pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(); // Limpia el buffer
    cin.get();    // Espera que el usuario presione una tecla
}

// Establece el nombre de usuario activo (para bit�cora y visualizaci�n)
void Contabilidad::setUsuario(const string& u) {
    usuario = u;
}

// MEN� PRINCIPAL DEL M�DULO

void Contabilidad::menuContabilidad() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nUsuario: " << usuario << endl;
        cout << "\n===== MENU CONTABILIDAD =====";
        cout << "\n1. Registrar Pago de Nomina";
        cout << "\n2. Desplegar Registro de Salarios";
        cout << "\n3. Volver al Menu Anterior";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpia el buffer despu�s de leer la opci�n

        switch (opcion) {
            case 1: registroNomina(); break;               // Ir a registro de pagos
            case 2: desplegarRegistroSalarios(); break;    // Ver lista de salarios
            case 3: limpiarPantalla(); return;             // Salir del men�
            default:
                cout << "\n�Opcion invalida!";
                pausar(); // Espera antes de volver a mostrar el men�
        }
    } while (true);
}

// REGISTRO DE PAGO DE N�MINA

void Contabilidad::registroNomina() {
    limpiarPantalla();
    string codigo;

    cout << "\nUsuario: " << usuario << endl;
    cout << "\n=== REGISTRO DE PAGO ===";
    cout << "\nIngrese el codigo del empleado: ";
    getline(cin, codigo); // Lee el c�digo ingresado por el usuario

    // Abrimos archivo binario que contiene datos de empleados
    ifstream archivo("nominas.dat", ios::binary);
    if (!archivo.is_open()) {
        cout << "\nNo se pudo abrir el archivo nominas.dat";
        pausar();
        return;
    }

    bool encontrado = false; // Flag para saber si el empleado fue hallado

    // Leemos el archivo hasta el final
    while (archivo.peek() != EOF) {
        size_t len;
        string nombre, telefono, codigoArchivo, direccion;
        double salario;

        // Lectura de campos serializados (longitud + contenido)
        archivo.read(reinterpret_cast<char*>(&len), sizeof(len)); // Leer cu�ntos caracteres tiene el nombre
        nombre.resize(len);                                       //Ajustar el tama�o del string 'nombre' para que tenga exactamente esa longitud
        archivo.read(&nombre[0], len);                            //Leer los caracteres del nombre directamente desde el archivo binario
                                                                  // y colocarlos en la memoria del string (usando &nombre[0] como puntero al buffer interno)

        archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
        telefono.resize(len);
        archivo.read(&telefono[0], len);

        archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
        codigoArchivo.resize(len);
        archivo.read(&codigoArchivo[0], len);

        archivo.read(reinterpret_cast<char*>(&len), sizeof(len));
        direccion.resize(len);
        archivo.read(&direccion[0], len);

        archivo.read(reinterpret_cast<char*>(&salario), sizeof(salario));

        // Verificamos si el c�digo coincide con el buscado
        if (codigoArchivo == codigo) {
            encontrado = true;

            // Mostramos los datos del empleado
            cout << "\nEmpleado encontrado:";
            cout << "\nNombre: " << nombre;
            cout << "\nCodigo: " << codigoArchivo;
            cout << "\nSalario: " << Moneda::getSimbolo()
                 << Moneda::convertirDesdeGtq(salario);

            // Pregunta si se realiz� el pago
            char respuesta;
            cout << "\n�Se ha realizado el pago? (Y/N): ";
            cin >> respuesta;
            cin.ignore();

            // Creamos un nuevo registro de pago
            RegistroPago pago;
            strncpy(pago.codigo, codigoArchivo.c_str(), sizeof(pago.codigo));
            pago.codigo[sizeof(pago.codigo)-1] = '\0'; // Asegura el fin de cadena

            // Guardamos "S�" o "No" en el campo `pagado`
            strncpy(pago.pagado, (toupper(respuesta) == 'Y' ? "S�" : "No"), sizeof(pago.pagado));
            pago.pagado[sizeof(pago.pagado)-1] = '\0';

            // Guardamos en el archivo de pagos
            ofstream archivoPagos("pagos.dat", ios::binary | ios::app);
            archivoPagos.write(reinterpret_cast<char*>(&pago), sizeof(RegistroPago));
            archivoPagos.close();

            cout << "\n�Registro guardado!";
            break;
        }
    }

    // Si no se encontr� el empleado
    if (!encontrado) {
        cout << "\n�Empleado no encontrado!";
    }

    // Registro en bit�cora (c�digo 4401 = operaci�n de registrar n�mina)
    bitacoralogContabilidad.insertar(usuario, 4401, "Contabilidad", "Registro Nomina");
    pausar();
}

// DESPLIEGUE DE REGISTRO DE SALARIOS

void Contabilidad::desplegarRegistroSalarios() {
    limpiarPantalla();

    // Abrimos ambos archivos binarios
    ifstream empleados("nominas.dat", ios::binary);
    ifstream pagos("pagos.dat", ios::binary);

    if (!empleados.is_open()) {
        cout << "\nNo se pudo abrir el archivo nominas.dat";
        pausar();
        return;
    }

    // Creamos un mapa que asocia el c�digo del empleado con su estado de pago ("S�" o "No")
    map<string, string> estadoPagos;
    RegistroPago pago;

    // Leemos todos los registros de pagos desde el archivo binario
    while (pagos.read(reinterpret_cast<char*>(&pago), sizeof(RegistroPago))) {
    // Almacenamos en el mapa: clave = c�digo, valor = "S�" o "No"
    estadoPagos[string(pago.codigo)] = string(pago.pagado);
   }

    // Encabezado de la tabla
    cout << "\n=== REGISTRO DE SALARIOS ===\n";
    cout << left << setw(30) << "NOMBRE"
         << setw(15) << "CODIGO"
         << setw(10) << "PAGADO" << "\n";

    // Recorremos todos los empleados registrados
    while (empleados.peek() != EOF) {
        size_t len;
        string nombre, telefono, codigo, direccion;
        double salario;

        // Paso 1: Leer desde el archivo binario la longitud (en bytes) del campo 'nombre'.
        // La longitud fue guardada previamente como un valor tipo size_t.
        empleados.read(reinterpret_cast<char*>(&len), sizeof(len));

       // Paso 2: Ajustar el tama�o del string 'nombre' para que tenga espacio suficiente
       // para almacenar la cantidad de caracteres le�da en 'len'.
        nombre.resize(len);

       // Paso 3: Leer 'len' bytes del archivo (el contenido del nombre) y escribirlos directamente
       // en el espacio interno del string 'nombre'. &nombre[0] apunta al buffer del string.
        empleados.read(&nombre[0], len);

        empleados.read(reinterpret_cast<char*>(&len), sizeof(len));
        telefono.resize(len);
        empleados.read(&telefono[0], len);

        empleados.read(reinterpret_cast<char*>(&len), sizeof(len));
        codigo.resize(len);
        empleados.read(&codigo[0], len);

        empleados.read(reinterpret_cast<char*>(&len), sizeof(len));
        direccion.resize(len);
        empleados.read(&direccion[0], len);

        empleados.read(reinterpret_cast<char*>(&salario), sizeof(salario));

        // Verificamos si el empleado fue pagado
        // Estado por defecto: "No"
        string estado = "No";

        // Si el c�digo existe en el mapa y su estado es exactamente "S�", lo mostramos como pagado
        if (estadoPagos.count(codigo) > 0 && estadoPagos[codigo] == "S�") {
        estado = "S�";
}

        // Imprimimos la informaci�n del empleado y su estado de pago
        cout << left << setw(30) << nombre
             << setw(15) << codigo
             << setw(10) << estado << "\n";
    }

    pausar();

    // Registro en bit�cora (c�digo 4402 = ver n�mina)
    bitacoralogContabilidad.insertar(usuario, 4402, "Contabilidad", "Desplegar registro nomina");
}
