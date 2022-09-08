#include <iostream>
#include <limits>
#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Ramo.h"
#include "ListaAlumnos.h"
#include "ListaProfesores.h"
#include "ListaRamos.h"
using namespace std;

ListaAlumnos alumnos = ListaAlumnos();
ListaProfesores profesores = ListaProfesores();
ListaRamos ramos = ListaRamos();

bool createNewAlumno()
{
    string nombre;
    string apellido;
    int semestre;
    int edad;

    cout << "Ingrese el nombre del estudiante\n";
    cin >> nombre;
    cout << "Ingrese el apellido del estudiante\n";
    cin >> apellido;
    cout << "Ingrese el semestre del estudiante\n";
    cin >> semestre;
    while (!cin.good() || semestre < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido, ingrese un numero\n";
        cin >> semestre;
    }
    cout << "Ingrese la edad del estudiante\n";
    cin >> edad;
    while (!cin.good() || edad < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido, ingrese un numero\n";
        cin >> edad;
    }
    if (alumnos.addAlumno(Alumno(nombre, apellido, semestre, edad)))
    {
        return true;
    }
    return false;
}

bool createNewProfesor()
{
    string nombre;
    string apellido;

    cout << "Ingrese el nombre del profesor\n";
    cin >> nombre;
    cout << "Ingrese el apellido del profesor\n";
    cin >> apellido;
    if (profesores.addProfesor(Profesor(nombre, apellido)))
    {
        return true;
    }
    return false;
}

bool createNewRamo()
{
    string nombre;
    string carrera;
    string sala;

    cout << "Ingrese el nombre del ramo\n";
    cin >> nombre;
    cout << "Ingrese la carrera a la que pertenece este ramo";
    cin >> carrera;
    cout << "Ingrese en que sala se imparte este ramo (puede ser nombre de sala, numero de sala)";
    cin >> sala;
    if (ramos.addRamo(Ramo(nombre, carrera, sala)))
    {
        return true;
    }
    return false;
}

bool addData()
{
    int option;
    cout << "\nQue desea agregar?\n"
        "1. Un alumno\n"
        "2. Un profesor\n"
        "3. Un ramo\n";
    cin >> option;
    while (!cin.good() || option > 3)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valor invalido, ingrese otro valor\n";
        cin >> option;
    }
    switch (option)
    {
    case 1:
        if (createNewAlumno()) { return true; }
        break;
    case 2:
        if (createNewProfesor()) { return true; }
        break;
    case 3:
        if (createNewRamo()) { return true; }
        break;
    }
    return false;
}

int main()
{
    bool go = true;
    while (go)
    {
        int option;
        cout << "Buen dia usuario, que accion desea realizar?\n";
        cout << "Escriba el numero que se indica al principio de la linea sin el . (punto) para realizar esa acción\n"
            "1. Realizar una consulta\n"
            "2. Agregar un alumno/profesor/ramo\n"
            "3. Modificar/Eliminar dato especifico ya existente\n"
            "4. Salir del programa\n";
        cin >> option;
        while (!cin.good() || option > 4)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Valor invalido, ingrese otro valor\n";
            cin >> option;
        }
        switch (option)
        {
        case 1:
            break;
        case 2:
            if (addData())
            {
                cout << "Anadido correctamente\n\n";
            }
            else
            {
                cout << "No se ha podido anadir esta informacion, se ha llegado al limite de datos de esta caracteristica\n\n";
            }
            break;
        case 3:
            break;
        case 4:
            go = false;
            break;
        }
    }
    return 0;
}