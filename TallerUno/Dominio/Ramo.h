#pragma once
#include <iostream>
#include "string"

using std::string;

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