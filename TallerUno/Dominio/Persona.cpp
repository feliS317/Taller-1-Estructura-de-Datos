#include "Persona.h"
#include "../Sistema/Vector.h"
#include "string"

using std::string;

Persona::Persona(string _nombre, string _apellido)
{
    nombre = _nombre;
    apellido = _apellido;
}
string Persona::getNombre()
{
    return nombre;
}
void Persona::setNombre(string _nombre)
{
    nombre = _nombre;
}
string Persona::getApellido()
{
    return apellido;
}
void Persona::setApellido(string _apellido)
{
    apellido = _apellido;
}

string Persona::getNombreCompleto()
{
    return nombre + " " + apellido;
}

Vector<Ramo*> Persona::getRamos()
{
    return Vector<Ramo*>(0);
}

bool Persona::addRamo(Ramo*)
{
    return false;
}

bool Persona::removeRamo(Ramo*)
{
    return false;
}
