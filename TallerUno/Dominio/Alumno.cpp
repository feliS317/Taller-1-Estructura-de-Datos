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

bool Alumno::addRamo(Ramo ramo)
{
    if (ramosTomados >= ramos.length)
    {
        return false;
    }
    ramos[ramosTomados] = ramo;
    ramosTomados++;
    return true;
}
