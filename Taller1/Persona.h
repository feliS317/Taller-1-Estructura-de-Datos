#pragma once
#include <iostream>
#include <string>
using namespace std;

class Persona
{
protected:
  string nombre;
  string apellido;
public:
  Persona(string, string);
  string getNombre();
  void setNombre(string);
  string getApellido();
  void setApellido(string);
};