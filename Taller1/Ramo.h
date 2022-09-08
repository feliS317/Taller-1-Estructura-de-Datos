#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

class Ramo
{
private:
    string nombre;
    string carrera;
    string sala;
public:
    Ramo() = default;
    Ramo(string, string, string);
    string getNombre();
    void setNombre(string);
    string getCarrera();
    void setCarrera(string);
    string getSala();
    void setSala(string);
};