// Jonathan Samuel Gonzalez Ixpata 9959-23-3184

#ifndef AUDITORIA_H
#define AUDITORIA_H

#include <string>
#include <vector>
#include "Bitacora.h"

using namespace std;

// Estructura que almacena informaci�n b�sica de los auditores
struct Auditores {
    char nombre[50];     // Nombre completo del auditor (50 caracteres)
    char codigo[20];     // Identificador �nico del auditor (20 caracteres)
};

// Clase principal para gesti�n del m�dulo de auditor�a
class Auditoria {
private:
    string usuario;              // Usuario actual del sistema
    vector<Auditores> auditores; // Almacenamiento temporal de auditores

public:
    // Establece el usuario activo para registro en bit�cora
    void setUsuario(const string& u);

    // Gesti�n principal del m�dulo
    void menuAuditoria();       // Men� principal de auditor�a

    // Utilidades de sistema
    void limpiarPantalla();     // Limpia consola seg�n SO
    void pausar();              // Pausa ejecuci�n hasta entrada

    // Funcionalidades de gesti�n de auditores
    void submenuAuditor();      // Submen� de operaciones
    void registrarAuditor();    // Registra nuevos auditores
    void borrarAuditor();       // Elimina auditores por c�digo
    void despliegueAuditores(); // Muestra lista completa de auditores
};

#endif

