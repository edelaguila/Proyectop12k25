#ifndef BACKUP_H
#define BACKUP_H

#include <string>
#include <vector>

//JENNIFER BARRIOS FLORES COORD EQ:3

// Clase Backup que permite realizar copias de seguridad y restaurarlas
class Backup {
public:
    // Muestra el men� principal de gesti�n de backups
    static void mostrarMenuBackup();

private:
    // Muestra el men� para seleccionar una clase espec�fica
    static void menuPorClase();

    // Realiza un backup de todos los archivos del sistema
    static void crearBackupGlobal();

    // Restaura todos los archivos del sistema desde sus backups
    static void restaurarBackupGlobal();

    // Realiza un backup de un archivo espec�fico
    static void crearBackupDe(const std::string& archivoOriginal);

    // Restaura un archivo espec�fico desde su backup
    static void restaurarBackupDe(const std::string& archivoOriginal);

    // Copia un archivo origen a un destino (modo binario)
    static bool copiarArchivo(const std::string& origen, const std::string& destino);

    // Devuelve una lista con los nombres base de las clases maestras
    static std::vector<std::string> clasesMaestras();

    // Devuelve una lista con los nombres base de las clases transaccionales
    static std::vector<std::string> clasesTransaccionales();

    // Muestra cu�les backups binarios est�n disponibles
    static void mostrarBackupsDisponibles();
};

#endif
