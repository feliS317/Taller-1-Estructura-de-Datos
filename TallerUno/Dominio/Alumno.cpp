#include "Alumno.h"
#include "string"

using std::string;

Alumno::Alumno(string _nombre, string _apellido, int _semestre, int _edad) : Persona(_nombre, _apellido)
{
    semestre = _semestre;
    edad = _edad;
}

int Alumno::getSemestre()
{
    return semestre;
}

void Alumno::setSemestre(int _semestre)
{
    semestre = _semestre;
}

int Alumno::getEdad()
{
    return edad;
}

void Alumno::setEdad(int _edad)
{
    edad = _edad;
}

Vector<Ramo*> Alumno::getRamos()
{
    return ramos;
}

bool Alumno::addRamo(Ramo* ramo)
{
    if (ramos.isFull())
    {
        return false;
    }
    ramos.add(ramo);
    return true;
}

bool Alumno::removeRamo(Ramo* ramo)
{
    for (int i = 0; i < ramos.length; i++)
    {
        if (ramos.remove(&ramo))
        {
            return true;
        }
    }
    return false;
}
