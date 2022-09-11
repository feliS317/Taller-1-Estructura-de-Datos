#include <iostream>
#include "Sistema/Sistema.h"

using namespace std;

Sistema sistema = Sistema();

void modificarEliminarAlumno() {
	sistema.alarm("Esta opcion aun no esta implementada");
}

void modificarEliminarProfesor() {
	sistema.alarm("Esta opcion aun no esta implementada");
}

void modificarEliminarRamo() {
	sistema.alarm("Esta opcion aun no esta implementada");
}

void modificarEliminarDato() {
	int option = 0;

	while (option != 4) {
		option = sistema.MostrarMenu("== Modificar o Elimiar Elemento ==", new string[4]{
			"Alumno",
			"Profesor",
			"Ramo",
			"Volver al menu principal"
			}, 4);

		if (option == 1) {
			modificarEliminarAlumno();
		}
		else if (option == 2) {
			modificarEliminarProfesor();
		}
		else if (option == 3) {
			modificarEliminarRamo();
		}
	}
}

void agregarAlumno()
{
	if (!sistema.SePuedeIngresarAlumno()) {
		sistema.alarm("No se puede ingresar mas alumnos.");
		return;
	}

	string nombre = sistema.StringInput("Ingrese el nombre del estudiante: ");
	string apellido = sistema.StringInput("Ingrese el apellido del estudiante: ");
	int semestre = sistema.IntInput("Ingrese el semestre del estudiante: ");
	int edad = sistema.IntInput("Ingrese la edad del estudiante: ");

	sistema.IngresarAlumno(nombre, apellido, semestre, edad);
}

void agregarProfesor()
{
	if (!sistema.SePuedeIngresarProfesor()) {
		sistema.alarm("No se puede ingresar mas profesores.");
		return;
	}

	string nombre = sistema.StringInput("Ingrese el nombre del profesor: ");
	string apellido = sistema.StringInput("Ingrese el apellido del profesor: ");

	sistema.IngresarProfesor(nombre, apellido);
}

void agregarRamo()
{
	if (!sistema.SePuedeIngresarRamo()) {
		sistema.alarm("No se puede ingresar mas salas.");
		return;
	}

	string nombre = sistema.StringInput("Ingrese el nombre del ramo: ");
	string carrera = sistema.StringInput("Ingrese la carrera del ramo: ");
	string sala = sistema.StringInput("Ingrese la sala del ramo: ");

	sistema.IngresarRamo(nombre, carrera, sala);
}

void agregarDato()
{
	int option = 0;

	while (option != 4) {
		option = sistema.MostrarMenu("== Agregar Elemento ==", new string[4]{
			"Alumno",
			"Profesor",
			"Ramo",
			"Volver al menu principal"
			}, 4);

		if (option == 1) {
			agregarAlumno();
		}
		else if (option == 2) {
			agregarProfesor();
		}
		else if (option == 3) {
			agregarRamo();
		}
	}
}

void consultarAlumno() {
	sistema.alarm("Esta opcion aun no esta implementada");
}

void consultarProfesor() {
	sistema.alarm("Esta opcion aun no esta implementada");
}

void consultarRamo() {
	sistema.alarm("Esta opcion aun no esta implementada");
}

void realizarConsulta()
{
	int option = 0;

	while (option != 4) {
		option = sistema.MostrarMenu("== Realizar una Consulta ==", new string[4]{
			"Alumno",
			"Profesor",
			"Ramo",
			"Volver al menu principal"
			}, 4);

		if (option == 1) {
			consultarAlumno();
		}
		else if (option == 2) {
			consultarProfesor();
		}
		else if (option == 3) {
			consultarRamo();
		}
	}
}

int main()
{
	int option = 0;

	while (option != 4)
	{
		option = sistema.MostrarMenu("== Sistema de Gestion Academico ==", new string[4]{
			"Realizar una consulta",
			"Agregar un alumno, profesor o ramo",
			"Modificar o eliminar dato",
			"Salir del programa"
			}, 4);

		if (option == 1) {
			realizarConsulta();
		}
		else if (option == 2) {
			agregarDato();
		}
		else if (option == 3) {
			modificarEliminarDato();
		}
	}

	return 0;
}