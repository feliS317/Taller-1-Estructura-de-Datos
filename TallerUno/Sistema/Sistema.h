#pragma once
#include <iostream>
#include <string>

#include "Vector.h"
#include "../Dominio/Persona.h"
#include "../Dominio/Alumno.h"
#include "../Dominio/Profesor.h"
#include "../Dominio/Ramo.h"

using std::string;

class Sistema
{
private:
	Vector<Alumno> alumnos = Vector<Alumno>(100);
	Vector<Profesor> profesores = Vector<Profesor>(5);
	Vector<Ramo> ramos = Vector<Ramo>(10);
public:
	Sistema() = default; // Constructor

	void print(string); // Permite imprimir un texto por pantalla
	void alarm(string); // Permite alarmar con un texto por pantalla
	void cleanConsole(); // Permite limpiar la consola

	int MostrarMenu(string titulo, string opciones[], int size); // Muestra un menú por pantalla
	string StringInput(string texto); // Permite la entrada de un string por consola
	int IntInput(string); // Permite la entrada de un integer por consola
	bool BoolInput(string texto); // Permite la entrada de un string por consola y devuelve un bool

	void AgregarRamos(Persona*); // Agrega ramos a alumno o profesor

	void IngresarAlumno(string, string, int, int); // Ingresa un nuevo alumno al sistema
	void IngresarProfesor(string, string); // Ingresa un nuevo profesor al sistema
	void IngresarRamo(string, string, string); // Ingresa un nuevo ramo al sistema

	bool SePuedeIngresarAlumno(); // Pregunta si es posible añadir un nuevo alumno
	bool SePuedeIngresarProfesor(); // Pregunta si es posible añadir un nuevo profesor
	bool SePuedeIngresarRamo(); // Pregunta si es posible añadir un nuevo ramo

	Alumno* ConsultarAlumno(string); // Consulta por un alumno y devuelve su puntero
	Profesor* ConsultarProfesor(string); // Consulta por un profesor y devuelve su puntero
	Ramo* ConsultarRamo(string); // Consulta por un ramo y devuelve su puntero
};