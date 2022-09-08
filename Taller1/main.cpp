#include <iostream>
#include "Persona.h"
#include "Alumno.h"
#include "Profesor.h"
#include "Ramos.h"
using namespace std;

int main()
{
    Ramos* ramos[10]; // Por que cree esto como una lista de punteros se preguntaran. C++ al crear una lista no deja los espacios vacios
    Alumno* alumnos[100]; // Intenta crear objetos para rellenar estos espacios (por alguna razon) y tiraba error constantemente al crear la lista
    Profesor* profesores[5]; // Se podia crear otro constructor que al no especificarse variables cree "default", pero no lo supe hacer para los objetos con herencia  - Feli
    Alumno a1 = Alumno("Pedro", "Herrera", 4, 20);
    alumnos[0] = &a1;
    cout << "1";

    bool Go = true;

    while (Go) {

        cout << "Bienvenido al menú! seleccione una opción"<<endl<<endl<<"1) Agregar Datos"<<endl<<"2) Modificar Datos"<<endl<<"3) Mostrar Datos";
        char response;

        switch (response){
        default:
            break;
        }

    }

    return 0;
}

void addData() {



}

void modifyData() {



}

void showData() {



}

