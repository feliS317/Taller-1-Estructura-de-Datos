#include "Profesor.h"
#include "string"

using std::string;

Profesor::Profesor(string _nombre, string _apellido) : Persona(_nombre, _apellido){}

Vector<Ramo*> Profesor::getRamos()
{
    return ramos;
}

bool Profesor::addRamo(Ramo* ramo)
{
    if (ramos.isFull())
    {
        return false;
    }
    ramos.add(ramo);
    return true;
}
