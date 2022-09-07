#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

class Ramos
{
private:
    string nombre;
    string carrera;
    string sala;
public:
    Ramos() = default;
    Ramos(string, string, string);
    string getNombre();
    void setNombre(string);
    string getCarrera();
    void setCarrera(string);
    string getSala();
    void setSala(string);
};