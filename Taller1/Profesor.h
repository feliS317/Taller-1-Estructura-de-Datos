#pragma once
#include <iostream>
#include <string>
#include "Persona.h"
#include "Ramos.h"
using namespace std;

class Profesor:public Persona
{
private:
  Ramos ramos[3];
public:
  Profesor(string, string);

};
