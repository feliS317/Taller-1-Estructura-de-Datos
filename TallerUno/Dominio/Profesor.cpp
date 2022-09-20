#include "Profesor.h"
#include "string"

using std::string;

Profesor::Profesor(string _nombre, string _apellido) : Persona(_nombre, _apellido){}

bool Profesor::addRamo(Ramo ramo)
{
    if (ramosTomados >= ramos.length)
    {
        return false;
    }
    ramos[ramosTomados] = ramo;
    ramosTomados++;
    return true;
}
