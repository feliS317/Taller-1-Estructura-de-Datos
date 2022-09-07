#include <iostream>
#include <limits>
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
    cout << "Buen dia usuario, que accion desea realizar?\n";
    
    return 0;
}

void mainMenu()
{
    int option;
    cout << "Escriba el numero que se indica al principio de la linea sin el . (punto) para realizar esa acción\n"
        "1. Realizar una consulta\n"
        "2. Agregar un alumno/profesor/ramo\n"
        "3. Modificar/Eliminar dato especifico ya existente\n"
        "4. Salir del programa";
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
            cout << "Anadido correctamente";
        }
        else
        {
            cout << "No se ha podido anadir esta informacion";
        }
        break;
    case 3:
        break;
    case 4:
        break;
    }

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

    }
}
