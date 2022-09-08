#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
#include "Ramo.h"
using namespace std;

class Alumno:public Persona
{
private:
    int semestre;
    int edad;
    Ramo ramos[5];
public:
    Alumno() = default;
    Alumno(string, string, int, int);
    int getSemestre();
    void setSemestre(int);
    int getEdad();
    void setEdad(int);
};
