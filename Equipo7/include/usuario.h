#ifndef USUARIO_H
#define USUARIO_H

<<<<<<< HEAD

class usuario
{
    public:
        usuario();
        virtual ~usuario();

    protected:

    private:
=======
#include <string>

class Usuario {
public:
    std::string username;
    std::string password;

    Usuario(std::string u, std::string p);
>>>>>>> origin
};

#endif // USUARIO_H
