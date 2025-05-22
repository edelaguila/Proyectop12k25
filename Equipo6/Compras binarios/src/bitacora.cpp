#include "bitacora.h"
#include <map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

const string Bitacora::ARCHIVO_BITACORA = "bitacora.txt";
string Bitacora::usuarioActual = "";

// Mapa completo de descripciones de c�digos de acci�n
const map<int, string> DESCRIPCIONES_CODIGOS = {
    // Autenticaci�n
    {CodigosAccion::LOGIN_EXITOSO, "Inicio de sesi�n exitoso"},
    {CodigosAccion::LOGIN_FALLIDO, "Intento fallido de inicio de sesi�n"},
    {CodigosAccion::LOGOUT, "Cierre de sesi�n"},
    {CodigosAccion::BLOQUEO_USUARIO, "Usuario bloqueado"},
    {CodigosAccion::CAMBIO_CONTRASENA, "Cambio de contrase�a"},

    // Accesos
    {CodigosAccion::ACCESO_MENU_PRINCIPAL, "Acceso al men� principal"},
    {CodigosAccion::ACCESO_TUTORIAL, "Acceso al tutorial"},
    {CodigosAccion::ACCESO_BUSQUEDA, "Acceso a b�squeda"},
    {CodigosAccion::ACCESO_CONTRAVERSIA, "Acceso al m�dulo Contraversia"},
    {CodigosAccion::ACCESO_CENTRO_VENERA, "Acceso al Centro Venera"},
    {CodigosAccion::ACCESO_HERRAMIENTAS_ARCHIVO, "Acceso a herramientas de archivo"},

    // CRUD de clientes y productos
    {CodigosAccion::CREACION_CLIENTE, "Creaci�n de nuevo cliente"},
    {CodigosAccion::LECTURA_CLIENTE, "Consulta de cliente"},
    {CodigosAccion::ACTUALIZACION_CLIENTE, "Actualizaci�n de cliente"},
    {CodigosAccion::ELIMINACION_CLIENTE, "Eliminaci�n de cliente"},
    {CodigosAccion::CREACION_PRODUCTO, "Creaci�n de producto"},
    {CodigosAccion::LECTURA_PRODUCTO, "Consulta de producto"},
    {CodigosAccion::ACTUALIZACION_PRODUCTO, "Actualizaci�n de producto"},
    {CodigosAccion::ELIMINACION_PRODUCTO, "Eliminaci�n de producto"},

    // Compras
    {CodigosAccion::CREACION_COMPRA, "Creaci�n de compra"},
    {CodigosAccion::LECTURA_COMPRA, "Consulta de compra"},
    {CodigosAccion::CANCELACION_COMPRA, "Cancelaci�n de compra"},

    // Selecciones (Contraversia)
    {CodigosAccion::SELECCION_FACUNDO, "Selecci�n de Facundo"},
    {CodigosAccion::SELECCION_TURQUE_SALUD, "Selecci�n de Turque Salud"},
    {CodigosAccion::SELECCION_CERCLESALUD, "Selecci�n de CercleSalud"},
    {CodigosAccion::SELECCION_BANCOLAPACO, "Selecci�n de BancoLapaco"},
    {CodigosAccion::SELECCION_MANOCORPORAL, "Selecci�n de ManoCorporal"},
    {CodigosAccion::SELECCION_CLICATES, "Selecci�n de Clicates"},
    {CodigosAccion::SELECCION_VENCENTES, "Selecci�n de Vencentes"},
    {CodigosAccion::SELECCION_MANTENUTA, "Selecci�n de Mantenuta"},
    {CodigosAccion::SELECCION_KISSES, "Selecci�n de Kisses"},
    {CodigosAccion::SELECCION_COCONA, "Selecci�n de Cocona"},
    {CodigosAccion::SELECCION_NOORREALIZA, "Selecci�n de NoorRealiza"},
    {CodigosAccion::SELECCION_DORECA, "Selecci�n de Doreca"},

    // Gesti�n de archivos
    {CodigosAccion::RESPALDO_CREADO, "Respaldo de datos creado"},
    {CodigosAccion::RESTAURACION_COMPLETADA, "Restauraci�n completada"},
    {CodigosAccion::EXPORTACION_DATOS, "Exportaci�n de datos"},
    {CodigosAccion::IMPORTACION_DATOS, "Importaci�n de datos"},
    {CodigosAccion::LIMPIEZA_REGISTROS, "Limpieza de registros"},

    // Consultas y reportes
    {CodigosAccion::GENERACION_REPORTE, "Generaci�n de reporte"},
    {CodigosAccion::CONSULTA_HISTORICO, "Consulta del historial"},
    {CodigosAccion::BUSQUEDA_AVANZADA, "B�squeda avanzada"},

    // Configuraciones
    {CodigosAccion::CAMBIO_CONFIGURACION, "Cambio de configuraci�n"},
    {CodigosAccion::ACTUALIZACION_SISTEMA, "Actualizaci�n del sistema"},
    {CodigosAccion::RESPALDO_CONFIGURACION, "Respaldo de configuraci�n"},

    // Errores y advertencias
    {CodigosAccion::ERROR_SISTEMA, "Error del sistema"},
    {CodigosAccion::ERROR_PERMISOS, "Error de permisos"},
    {CodigosAccion::ERROR_ARCHIVO, "Error al acceder al archivo"},
    {CodigosAccion::ERROR_CONEXION, "Error de conexi�n"},
    {CodigosAccion::ADVERTENCIA_SISTEMA, "Advertencia del sistema"},
    {CodigosAccion::ADVERTENCIA_SEGURIDAD, "Advertencia de seguridad"}
};

string Bitacora::obtenerDescripcionCodigo(int codigo) {
    auto it = DESCRIPCIONES_CODIGOS.find(codigo);
    return (it != DESCRIPCIONES_CODIGOS.end()) ? it->second : "C�digo no reconocido";
}

void Bitacora::registrarAccion(const string& usuario, int codigoAccion, const string& descripcion) {
    usuarioActual = usuario;
    ofstream archivo(ARCHIVO_BITACORA, ios::app);
    if (archivo.is_open()) {
        archivo << obtenerFechaHoraActual() << " | "
                << "Usuario: " << usuario << " | "
                << "C�digo: " << codigoAccion << " (" << obtenerDescripcionCodigo(codigoAccion) << ") | "
                << "Detalles: " << descripcion << endl;
        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo de bit�cora para escritura." << endl;
    }
}

void Bitacora::mostrarBitacora() {
    ifstream archivo(ARCHIVO_BITACORA);
    if (archivo.is_open()) {
        cout << "\n=== CONTENIDO DE LA BIT�CORA ===" << endl;
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        cout << "=== FIN DE LA BIT�CORA ===" << endl;
        archivo.close();
    } else {
        cerr << "Error: No se pudo abrir el archivo de bit�cora para lectura." << endl;
    }
}

string Bitacora::obtenerFechaHoraActual() {
    time_t ahora = time(nullptr);
    tm* tiempo = localtime(&ahora);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tiempo);
    return string(buffer);
}

string Bitacora::obtenerUsuarioActual() {
    return usuarioActual;
}
