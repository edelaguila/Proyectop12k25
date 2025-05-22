#ifndef MENU_GENERAL_H
#define MENU_GENERAL_H

#include <string>

class MenuGeneral {
public:
    void mostrar();
    static std::string getUsuarioActual();
    static void setUsuarioActual(const std::string& usuario);

private:
    static std::string usuarioActual;
};

#endif
