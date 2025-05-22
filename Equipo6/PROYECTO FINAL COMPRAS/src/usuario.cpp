#include "usuario.h"
#include "bitacora.h"
#include "utils.h"  // Para usar xorEncryptDecrypt
#include <fstream>
#include <iostream>
#include <conio.h>  // Para _getch()
#include <windows.h>
#include <algorithm>
#include <cctype>   // Para isprint()

using namespace std;

const string Usuario::ARCHIVO_USUARIOS = "usuarios.dat";

bool isShiftPressed() {
    return (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
}

string Usuario::leerContrasenaOculta(bool mostrarCaracter, char caracterOculto) {
    string contrasena;
    char ch;
    bool revelar = false;

    while ((ch = _getch()) != '\r' && ch != '\n') {
        bool shiftActual = isShiftPressed();

        // Si el estado de Shift cambió
        if (shiftActual != revelar) {
            revelar = shiftActual;
            // Retroceder y volver a mostrar
            cout << string(contrasena.length(), '\b') << flush;
            cout << (revelar ? contrasena : string(contrasena.length(), caracterOculto)) << flush;
            continue;
        }

        if (ch == '\b') { // Tecla Backspace
            if (!contrasena.empty()) {
                contrasena.pop_back();
                cout << "\b \b" << flush;
            }
        }
        else if (isprint(ch)) { // Caracter imprimible
            contrasena += ch;
            cout << (revelar || mostrarCaracter ? ch : caracterOculto) << flush;
        }
    }
    cout << endl;
    return contrasena;
}

bool Usuario::usuarioExiste(const string& usuario) {
    ifstream archivo(ARCHIVO_USUARIOS, ios::binary);
    if (!archivo) return false;

    string usuarioArchivo, contrasenaArchivo;
    size_t length;

    while (archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t))) {
        usuarioArchivo.resize(length);
        archivo.read(&usuarioArchivo[0], length);
        usuarioArchivo = xorEncryptDecrypt(usuarioArchivo);

        // Saltar la contraseña
        archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t));
        archivo.ignore(length);

        if (usuarioArchivo == usuario) {
            return true;
        }
    }
    return false;
}

bool Usuario::registrarUsuario(const string& usuario, const string& contrasena) {
    if (usuarioExiste(usuario)) {
        cerr << "❌ El usuario ya existe\n";
        Bitacora::registrarAccion("Sistema", CodigosAccion::LOGIN_FALLIDO, "Intento de registrar usuario existente: " + usuario);
        return false;
    }

    ofstream archivo(ARCHIVO_USUARIOS, ios::binary | ios::app);
    if (!archivo) {
        cerr << "❌ Error al abrir o crear el archivo de usuarios\n";
        Bitacora::registrarAccion("Sistema", CodigosAccion::ERROR_ARCHIVO, "Fallo al abrir archivo de usuarios");
        return false;
    }

    // Cifrar datos
    string usuarioCifrado = xorEncryptDecrypt(usuario);
    string contrasenaCifrada = xorEncryptDecrypt(contrasena);

    // Escribir usuario
    size_t len = usuarioCifrado.size();
    archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
    archivo.write(usuarioCifrado.c_str(), len);

    // Escribir contraseña
    len = contrasenaCifrada.size();
    archivo.write(reinterpret_cast<const char*>(&len), sizeof(len));
    archivo.write(contrasenaCifrada.c_str(), len);

    cout << "✔ Usuario registrado exitosamente\n";
    Bitacora::registrarAccion(usuario, CodigosAccion::CREACION_CLIENTE, "Nuevo usuario registrado");
    return true;
}

bool Usuario::iniciarSesion(const string& usuario, const string& contrasena) {
    ifstream archivo(ARCHIVO_USUARIOS, ios::binary);
    if (!archivo) {
        Bitacora::registrarAccion(usuario, CodigosAccion::ERROR_ARCHIVO, "Fallo al acceder a archivo de usuarios");
        return false;
    }

    string usuarioArchivo, contrasenaArchivo;
    size_t length;

    while (archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t))) {
        // Leer usuario
        usuarioArchivo.resize(length);
        archivo.read(&usuarioArchivo[0], length);
        usuarioArchivo = xorEncryptDecrypt(usuarioArchivo);

        // Leer contraseña
        archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t));
        contrasenaArchivo.resize(length);
        archivo.read(&contrasenaArchivo[0], length);
        contrasenaArchivo = xorEncryptDecrypt(contrasenaArchivo);

        if (usuarioArchivo == usuario && contrasenaArchivo == contrasena) {
            Bitacora::registrarAccion(usuario, CodigosAccion::LOGIN_EXITOSO, "Inicio de sesión exitoso");
            return true;
        }
    }

    Bitacora::registrarAccion(usuario, CodigosAccion::LOGIN_FALLIDO, "Intento fallido de inicio de sesión");
    return false;
}
