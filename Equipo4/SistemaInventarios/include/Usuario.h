//Luis Valenzuela 9959-24-12583
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

struct Usuario {
    int id;
    char nombre[30];
    char contrasena[30];
};

class usuarios {
public:
    usuarios();
    ~usuarios();
    bool loginUsuarios();
    void menuUsuarios();
    bool buscar(std::string user, std::string passw);
    std::string getNombre();
    void setNombre(std::string nombre);
    void consultarUsuarios();
    void agregarUsuarios();
    void modificarUsuarios();
    void eliminarUsuarios();
    void agregarUsuarioBinario();
    void consultarUsuariosBinario();

private:
    int id;
    std::string name;
    std::string pass;
};

#endif
