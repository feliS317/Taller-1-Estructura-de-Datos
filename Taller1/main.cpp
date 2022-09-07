#include <iostream>
#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Ramos.h"
using namespace std;

int main()
{
    Ramos ramos[10];
    Alumno alumnos[100];
    Profesor profesores[5];
    Alumno a1 = Alumno("Pedro", "Herrera", 4, 20);
    alumnos[0] = a1;
    cout << "El codigo se ejecutó correctamente";

    return 0;
}
