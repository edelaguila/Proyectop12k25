#include "utils.h"

// Implementación de la función
std::string xorEncryptDecrypt(const std::string& texto, char clave) {
    std::string resultado = texto;
    for (char& c : resultado) {
        c ^= clave;
    }
    return resultado;
}
