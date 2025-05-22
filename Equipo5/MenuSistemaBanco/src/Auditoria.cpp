//Jonathan Samuel Gonzalez Ixpata 9959-23-3184
#include "Auditoria.h"      // Declaraci�n de la clase Auditoria
#include <iostream>         // Entrada y salida est�ndar
#include <fstream>          // Manejo de archivos binarios
#include <cstring>          // Para usar strncpy
#include "Bitacora.h"       // Para registrar acciones en la bit�cora

#ifdef _WIN32
#include <cstdlib>          // Para usar system("cls") en Windows
#endif

Bitacora bitacoralogAuditoria; // Bit�cora para registrar acciones en Auditoria
using namespace std;           // Evita usar std:: en todo el c�digo

// Limpia la pantalla seg�n el sistema operativo
void Auditoria::limpiarPantalla() {
    #ifdef _WIN32
        system("cls");     // Comando para limpiar pantalla en Windows
    #else
        system("clear");   // Comando para limpiar pantalla en otros sistemas
    #endif
}

// Pausa la ejecuci�n hasta que el usuario presione ENTER
void Auditoria::pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();          // Limpia el buffer del teclado
    cin.get();             // Espera a que se presione ENTER
}

// Asigna el nombre del usuario actual a la clase
void Auditoria::setUsuario(const string& u) {
    usuario = u;
}

// Muestra el men� principal de Auditor�a
void Auditoria::menuAuditoria() {
    int opcion;
    do {
        limpiarPantalla();                     // Limpia pantalla antes de mostrar men�
        cout << "\nUsuario: " << usuario << endl;
        cout << "\n===== MENU DE AUDITORIA =====";
        cout << "\n1. Gestion de Auditores";
        cout << "\n2. Volver al menu anterior";
        cout << "\nSeleccione una opcion: ";
        cin >> opcion;                         // Lee opci�n del usuario
        cin.ignore();                          // Elimina salto de l�nea pendiente

        switch (opcion) {
            case 1: submenuAuditor(); break;   // Muestra submen� para gestionar auditores
            case 2: limpiarPantalla(); return; // Sale del men�
            default:
                cout << "\nOpcion invalida!";
                pausar();                      // Espera a que el usuario contin�e
        }
    } while (true);
}

// Submen� para registrar, borrar y mostrar auditores
void Auditoria::submenuAuditor() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "\nUsuario: " << usuario << endl;
        cout << "\n===== GESTION DE AUDITORES =====";
        cout << "\n1. Registrar Auditor";
        cout << "\n2. Borrar Auditor";
        cout << "\n3. Desplegar Auditores";
        cout << "\n4. Volver";
        cout << "\nSeleccione: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: registrarAuditor(); break;     // Llama a la funci�n para registrar auditor
            case 2: borrarAuditor(); break;        // Llama a la funci�n para borrar auditor
            case 3: despliegueAuditores(); break;  // Muestra lista de auditores
            case 4: limpiarPantalla(); return;     // Regresa al men� anterior
            default:
                cout << "\nOpcion invalida!";
                pausar();
        }
    } while (true);
}

// Registra un nuevo auditor en memoria y archivo binario
void Auditoria::registrarAuditor() {
    limpiarPantalla();
    Auditores a;

    cout << "\nUsuario: " << usuario << endl;
    cout << "\n=== REGISTRAR AUDITOR ===";
    cout << "\nNombre: ";
    string nombreInput;
    getline(cin, nombreInput);                                    // Lee nombre
    strncpy(a.nombre, nombreInput.c_str(), sizeof(a.nombre));     // Copia nombre a estructura
    a.nombre[sizeof(a.nombre) - 1] = '\0';                         // Asegura terminaci�n nula

    cout << "Codigo: ";
    string codigoInput;
    getline(cin, codigoInput);                                    // Lee c�digo
    strncpy(a.codigo, codigoInput.c_str(), sizeof(a.codigo));     // Copia c�digo
    a.codigo[sizeof(a.codigo) - 1] = '\0';                         // Asegura terminaci�n nula

    auditores.push_back(a);                                       // Agrega a vector en memoria

    ofstream archivo("auditores.dat", ios::binary | ios::app);    // Abre archivo en modo binario
    archivo.write(reinterpret_cast<char*>(&a), sizeof(Auditores));// Escribe datos del auditor
    archivo.close();                                              // Cierra archivo

    cout << "\nAuditor registrado!";
    bitacoralogAuditoria.insertar(usuario, 4301, "Auditoria", "Registrar"); // Registra en bit�cora
    pausar();
}

// Elimina un auditor del archivo binario seg�n c�digo
void Auditoria::borrarAuditor() {
    limpiarPantalla();
    string codigo;
    cout << "\n=== BORRAR AUDITOR ===";
    cout << "\nCodigo del auditor: ";
    getline(cin, codigo);                                    // Lee c�digo a eliminar

    ifstream archivoLectura("auditores.dat", ios::binary);   // Abre archivo para leer
    vector<Auditores> nuevaLista;                            // Lista temporal sin el eliminado
    Auditores a;
    bool eliminado = false;

    while (archivoLectura.read(reinterpret_cast<char*>(&a), sizeof(Auditores))) {
        if (codigo != a.codigo) {
            nuevaLista.push_back(a);                         // Agrega solo si no coincide
        } else {
            eliminado = true;                                // Marca que s� encontr� y elimin�
        }
    }
    archivoLectura.close();

    if (eliminado) {
        ofstream archivoEscritura("auditores.dat", ios::binary | ios::trunc); // Sobrescribe archivo
        for (const auto& auditor : nuevaLista) {
            archivoEscritura.write(reinterpret_cast<const char*>(&auditor), sizeof(Auditores));
        }
        archivoEscritura.close();
        auditores = nuevaLista;                              // Actualiza vector en memoria
        cout << "\nAuditor eliminado!";
    } else {
        cout << "\nCodigo no encontrado!";
    }

    bitacoralogAuditoria.insertar(usuario, 4302, "Auditoria", "Borrar"); // Registra en bit�cora
    pausar();
}

// Muestra todos los auditores guardados en el archivo
void Auditoria::despliegueAuditores() {
    limpiarPantalla();
    ifstream archivo("auditores.dat", ios::binary);   // Abre archivo binario para lectura
    Auditores a;

    cout << "\n=== LISTA DE AUDITORES ===";
    cout << "\nNombre\t\tCodigo\t\tAccion realizada\n";
    cout << "------------------------------------------------\n";

    while (archivo.read(reinterpret_cast<char*>(&a), sizeof(Auditores))) {
        cout << a.nombre << "\t\t" << a.codigo << "\t\tRevision realizada\n";
    }

    archivo.close();
    bitacoralogAuditoria.insertar(usuario, 4303, "Auditoria", "Desplegar"); // Bit�cora
    pausar();
}
