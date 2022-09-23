#include <iostream>
#include "Sistema/Sistema.h"

using namespace std;

Sistema sistema = Sistema();

void modificarEliminarAlumno() {
	string queryBusqueda = sistema.StringInput("Ingrese el nombre completo del alumno a modificar o eliminar: ");
	Alumno* busquedaAlumno = sistema.ConsultarAlumno(queryBusqueda);

	sistema.cleanConsole();

	if (!busquedaAlumno) {
		sistema.alarm("No se ha encontrado al alumno especificado.");
	}
	else {
		sistema.ModificarAlumno(busquedaAlumno);
	}
}

void modificarEliminarProfesor() {
	string queryBusqueda = sistema.StringInput("Ingrese el nombre completo del profesor a modificar o eliminar: ");
	Profesor* busquedaProfesor = sistema.ConsultarProfesor(queryBusqueda);

	sistema.cleanConsole();

	if (!busquedaProfesor) {
		sistema.alarm("No se ha encontrado al profesor especificado.");
	}
	else {
		sistema.ModificarProfesor(busquedaProfesor);
	}
}

void modificarEliminarRamo() {
	string queryBusqueda = sistema.StringInput("Ingrese el nombre del ramo a modificar o eliminar: ");
	Ramo* busquedaRamo = sistema.ConsultarRamo(queryBusqueda);

	sistema.cleanConsole();

	if (!busquedaRamo) {
		sistema.alarm("No se ha encontrado el ramo especificado.");
	}
	else {
		sistema.ModificarRamo(busquedaRamo);
	}
}

void modificarEliminarDato() {
	int option = 0;

	while (option != 4) {
		option = sistema.MostrarMenu("== Modificar o Eliminar Elemento ==", new string[4]{
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
	string queryBusqueda = sistema.StringInput("Ingrese el nombre completo del alumno a buscar: ");
	Alumno* busquedaAlumno = sistema.ConsultarAlumno(queryBusqueda);

	sistema.cleanConsole();

	if (!busquedaAlumno) {
		sistema.alarm("No se ha encontrado al alumno especificado.");
	}
	else {
		Alumno alumnoEncontrado = *busquedaAlumno;

		sistema.print("== Mostrando Datos del Alumno ==");
		sistema.print("Nombre: " + alumnoEncontrado.getNombreCompleto());
		sistema.print("Edad: " + std::to_string(alumnoEncontrado.getEdad()));
		sistema.print("Semestre: " + std::to_string(alumnoEncontrado.getSemestre()));

		sistema.alarm("");
	}
}

void consultarProfesor() {
	string queryBusqueda = sistema.StringInput("Ingrese el nombre completo del profesor a buscar: ");
	Profesor* busquedaProfesor = sistema.ConsultarProfesor(queryBusqueda);

	sistema.cleanConsole();

	if (!busquedaProfesor) {
		sistema.alarm("No se ha encontrado al profesor especificado.");
	}
	else {
		Profesor profesorEncontrado = *busquedaProfesor;

		sistema.print("== Mostrando Datos del Profesor ==");
		sistema.print("Nombre: " + profesorEncontrado.getNombreCompleto());

		sistema.alarm("");
	}
}

void consultarRamo() {
	string queryBusqueda = sistema.StringInput("Ingrese el nombre del ramo a buscar: ");
	Ramo* busquedaRamo = sistema.ConsultarRamo(queryBusqueda);

	sistema.cleanConsole();

	if (!busquedaRamo) {
		sistema.alarm("No se ha encontrado el ramo especificado.");
	}
	else {
		Ramo ramoEncontrado = *busquedaRamo;

		sistema.print("== Mostrando Datos del Ramo ==");
		sistema.print("Nombre: " + ramoEncontrado.getNombre());
		sistema.print("Carrera: " + ramoEncontrado.getCarrera());
		sistema.print("Sala: " + ramoEncontrado.getSala());

		sistema.alarm("");
	}
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
;
	sistema.IngresarAlumno("Cesar", "Munoz", 4, 20);
	sistema.IngresarAlumno("Hariette", "Diaz", 2, 19);
	sistema.IngresarRamo("Estructura de Datos", "ICCI", "Sala Y-103");
	sistema.IngresarRamo("Estadistica", "ICI", "Sala X-104");
	sistema.IngresarRamo("Dinamica", "ICCI", "Sala X1-30");

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