#include "usuario.h"
#include "bitacora.h"
<<<<<<< HEAD
#include "utils.h"  // Para usar xorEncryptDecrypt
#include <fstream>
#include <iostream>
#include <conio.h>  // Para _getch()
#include <windows.h>
#include <algorithm>
#include <cctype>   // Para isprint()
=======
#include <fstream>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <algorithm>
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978

using namespace std;

const string Usuario::ARCHIVO_USUARIOS = "usuarios.dat";
<<<<<<< HEAD
=======
const char XOR_KEY = 0x55; // Clave XOR para encriptación simple
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978

bool isShiftPressed() {
    return (GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0;
}

<<<<<<< HEAD
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
=======
void aplicarXOR(string& data) {
    transform(data.begin(), data.end(), data.begin(),
        [](char c) { return c ^ XOR_KEY; });
}

string Usuario::leerContrasenaOculta(bool mostrarCaracter, char caracterOculto) {
    string contrasena;
    char ch;
    bool revelar = false;

    while ((ch = _getch()) != '\r' && ch != '\n') {
        bool shiftActual = isShiftPressed();
        if (shiftActual != revelar) {
            revelar = shiftActual;
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
            cout << string(contrasena.length(), '\b') << flush;
            cout << (revelar ? contrasena : string(contrasena.length(), caracterOculto)) << flush;
            continue;
        }

<<<<<<< HEAD
        if (ch == '\b') { // Tecla Backspace
=======
        if (ch == '\b') {
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
            if (!contrasena.empty()) {
                contrasena.pop_back();
                cout << "\b \b" << flush;
            }
        }
<<<<<<< HEAD
        else if (isprint(ch)) { // Caracter imprimible
=======
        else if (isprint(ch)) {
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
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

<<<<<<< HEAD
    string usuarioArchivo, contrasenaArchivo;
=======
    string usuarioArchivo;
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    size_t length;

    while (archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t))) {
        usuarioArchivo.resize(length);
        archivo.read(&usuarioArchivo[0], length);
<<<<<<< HEAD
        usuarioArchivo = xorEncryptDecrypt(usuarioArchivo);

        // Saltar la contraseña
        archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t));
        archivo.ignore(length);
=======
        aplicarXOR(usuarioArchivo);

        archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t));
        archivo.ignore(length); // ignorar la contraseña
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978

        if (usuarioArchivo == usuario) {
            return true;
        }
    }
    return false;
}

bool Usuario::registrarUsuario(const string& usuario, const string& contrasena) {
    if (usuarioExiste(usuario)) {
        cerr << "❌ El usuario ya existe\n";
<<<<<<< HEAD
        Bitacora::registrarAccion("Sistema", CodigosAccion::LOGIN_FALLIDO, "Intento de registrar usuario existente: " + usuario);
=======
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
        return false;
    }

    ofstream archivo(ARCHIVO_USUARIOS, ios::binary | ios::app);
    if (!archivo) {
        cerr << "❌ Error al abrir o crear el archivo de usuarios\n";
<<<<<<< HEAD
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
=======
        Bitacora::registrarAccion(usuario, CodigosAccion::ERROR_ARCHIVO, "No se pudo abrir/crear el archivo de usuarios.");
        return false;
    }

    string usuarioEncriptado = usuario;
    string contrasenaEncriptada = contrasena;
    aplicarXOR(usuarioEncriptado);
    aplicarXOR(contrasenaEncriptada);

    size_t lenUsuario = usuarioEncriptado.size();
    size_t lenContrasena = contrasenaEncriptada.size();

    archivo.write(reinterpret_cast<const char*>(&lenUsuario), sizeof(size_t));
    archivo.write(usuarioEncriptado.c_str(), lenUsuario);

    archivo.write(reinterpret_cast<const char*>(&lenContrasena), sizeof(size_t));
    archivo.write(contrasenaEncriptada.c_str(), lenContrasena);

    cout << "✔ Usuario registrado exitosamente\n";
    Bitacora::registrarAccion(usuario, CodigosAccion::CREACION_CLIENTE, "Nuevo usuario registrado.");
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    return true;
}

bool Usuario::iniciarSesion(const string& usuario, const string& contrasena) {
    ifstream archivo(ARCHIVO_USUARIOS, ios::binary);
    if (!archivo) {
<<<<<<< HEAD
        Bitacora::registrarAccion(usuario, CodigosAccion::ERROR_ARCHIVO, "Fallo al acceder a archivo de usuarios");
=======
        Bitacora::registrarAccion(usuario, CodigosAccion::ERROR_ARCHIVO, "Archivo de usuarios no accesible.");
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
        return false;
    }

    string usuarioArchivo, contrasenaArchivo;
    size_t length;

    while (archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t))) {
<<<<<<< HEAD
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
=======
        usuarioArchivo.resize(length);
        archivo.read(&usuarioArchivo[0], length);
        aplicarXOR(usuarioArchivo);

        archivo.read(reinterpret_cast<char*>(&length), sizeof(size_t));
        contrasenaArchivo.resize(length);
        archivo.read(&contrasenaArchivo[0], length);
        aplicarXOR(contrasenaArchivo);

        if (usuarioArchivo == usuario && contrasenaArchivo == contrasena) {
            Bitacora::registrarAccion(usuario, CodigosAccion::LOGIN_EXITOSO, "Inicio de sesión correcto.");
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
            return true;
        }
    }

<<<<<<< HEAD
    Bitacora::registrarAccion(usuario, CodigosAccion::LOGIN_FALLIDO, "Intento fallido de inicio de sesión");
=======
    Bitacora::registrarAccion(usuario, CodigosAccion::LOGIN_FALLIDO, "Intento fallido de inicio de sesión.");
>>>>>>> 042ee62d5f1aa9ff7462cda7db36b88e7c7bb978
    return false;
}
