#ifndef BITACORA_H
#define BITACORA_H
//LUIS ANGEL MENDEZ FUENTES.
//MAYO 2023
#include <string>
#include <unordered_map>

struct RegistroBitacora {
<<<<<<< HEAD
    int id_accion;              ///< ID único de la acción basada en el módulo
    int codigo;                 ///< Código del módulo al que pertenece la acción
    char usuario[50];           ///< Nombre del usuario que ejecutó la acción
    char modulo[30];            ///< Nombre del módulo donde se ejecutó la acción
    char descripcion[100];      ///< Descripción de la acción realizada
    char fecha_hora[20];        ///< Fecha y hora en que ocurrió la acción
=======
    int id_accion;              ///< ID ï¿½nico de la acciï¿½n basada en el mï¿½dulo
    int codigo;                 ///< Cï¿½digo del mï¿½dulo al que pertenece la acciï¿½n
    char usuario[50];           ///< Nombre del usuario que ejecutï¿½ la acciï¿½n
    char modulo[30];            ///< Nombre del mï¿½dulo donde se ejecutï¿½ la acciï¿½n
    char descripcion[100];      ///< Descripciï¿½n de la acciï¿½n realizada
    char fecha_hora[20];        ///< Fecha y hora en que ocurriï¿½ la acciï¿½n
>>>>>>> f432235ec7a7ee37d9ae0aed0a67dd2ab32ad176
};

/**
 * @class CodigosBitacora
 * @brief Administra los cï¿½digos ï¿½nicos asignados a cada mï¿½dulo para identificaciï¿½n en la bitï¿½cora.
 *
 * Esta clase permite obtener un ID especï¿½fico por mï¿½dulo, ï¿½til para clasificar
 * y rastrear acciones dentro del sistema.
 */
class CodigosBitacora {
private:
    static std::unordered_map<std::string, int> rangos;///< Mapa de modulos

public:
    /**
     * @brief Devuelve el cï¿½digo ï¿½nico asociado a un mï¿½dulo.
     * @param modulo Nombre del mï¿½dulo (ej. "Clientes", "Pedidos", etc.).
     * @return Cï¿½digo entero asociado al mï¿½dulo.
     */
    static int getCodigo(const std::string& modulo);
};

/**
 * @class bitacora
 * @brief Clase encargada de registrar y administrar las acciones del sistema en una bitï¿½cora binaria.
 *
 * Proporciona funciones para registrar eventos, generar respaldos,
 * realizar bï¿½squedas y mostrar el contenido de la bitï¿½cora.
 */
class bitacora {
public:

    /**
     * @brief Registra una acciï¿½n en la bitï¿½cora.
     * @param usuario Nombre del usuario que realizï¿½ la acciï¿½n.
     * @param modulo Nombre del mï¿½dulo donde ocurriï¿½ la acciï¿½n.
     * @param descripcion Breve descripciï¿½n de la acciï¿½n realizada.
     */
    static void registrar(const std::string& usuario, const std::string& modulo, const std::string& descripcion);

    /**
     * @brief Inserta un registro en la bitï¿½cora (alias de registrar).
     * @param usuario Nombre del usuario que realizï¿½ la acciï¿½n.
     * @param modulo Nombre del mï¿½dulo donde ocurriï¿½ la acciï¿½n.
     * @param descripcion Breve descripciï¿½n de la acciï¿½n realizada.
     */
    static void insertar(const std::string& usuario, const std::string& modulo, const std::string& descripcion);

    /**
     * @brief Muestra en consola todos los registros almacenados en la bitï¿½cora.
     */
    static void mostrarBitacora();

    /**
     * @brief Genera una copia de seguridad del archivo de la bitï¿½cora.
     */
    static void generarBackup();

    /**
     * @brief Elimina todos los registros existentes en la bitï¿½cora.
     */
    static void reiniciarBitacora();

    /**
     * @brief Permite buscar registros por nombre de usuario.
     */
    static void buscarPorNombreUsuario();

    /**
     * @brief Permite buscar registros por fecha.
     */
    static void buscarPorFecha();

    /**
     * @brief Muestra el menï¿½ interactivo de gestiï¿½n de la bitï¿½cora.
     */
    static void menuBitacora();

private:

    /**
     * @brief Obtiene la fecha y hora actual en formato de cadena.
     * @return Fecha y hora actual como string.
     */
    static std::string obtenerFechaActual();

};

#endif // BITACORA_H
