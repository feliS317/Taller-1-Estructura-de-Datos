#include <iostream>
#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Ramos.h"
#include "ListaAlumnos.h"
#include "ListaProfesores.h"
using namespace std;

int main()
{
    Ramos ramos[10];
    ListaAlumnos alumnos = ListaAlumnos();
    ListaProfesores profesores = ListaProfesores();
    Alumno a1 = Alumno("Pedro", "Herrera", 4, 20);
    if (alumnos.addAlumno(a1))
    {
        cout << "Alumno a�adido correctamente";
    }
    cout << "El codigo se ejecut� correctamente";

    return 0;
}
