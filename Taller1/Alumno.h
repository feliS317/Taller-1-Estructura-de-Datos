#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
#include "Ramos.h"
using namespace std;

class Alumno:public Persona
{
private:
  int semestre;
  int edad;
    Ramos ramos[5];
public:
  Alumno(string, string, int, int);
  int getSemestre();
  void setSemestre();
  int getEdad();
  void setEdad();
};
