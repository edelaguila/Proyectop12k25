#include "utils.h"

// Implementaci�n de la funci�n
std::string xorEncryptDecrypt(const std::string& texto, char clave) {
    std::string resultado = texto;
    for (char& c : resultado) {
        c ^= clave;
    }
    return resultado;
}
