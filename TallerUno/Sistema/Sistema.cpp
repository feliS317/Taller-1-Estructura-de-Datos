#include "Sistema.h"
#include "Vector.h"
#include "../Dominio/Alumno.h"
#include "../Dominio/Profesor.h"
#include "../Dominio/Ramo.h"

#include "string"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*
	Escribe una línea por consola. El output incluye salto de línea.
	@param text Texto a escribir.
 */
void Sistema::print(string text)
{
	cout << text << endl;
}

void Sistema::alarm(string text)
{
	cout << "\n" + text << endl; // Imprime el texto de alarma
	cout << "Presione [Enter] para continuar..."; // Pide un input al usuario
	cin.get(); // Espera por una entrada
	cin.ignore(1000, '\n'); // Limpia el buffer
}

/*
	Limpia la consola. Simplemente imprimirá líneas en blanco para deshacerse de líneas antiguas.
 */
void Sistema::cleanConsole()
{
	for (int i = 0; i < 100; i++) { // Imprime líneas en blanco 100 veces
		print("");
	}
}

/*
	Muestra un menú de opciones por pantalla.
	@param titulo Título del menú.
	@param opciones[] Opciones del menú.
	@param size Cantidad de opciones del menú.
	@return Opción seleccionada por el usuario.
*/
int Sistema::MostrarMenu(string titulo, string opciones[], int size) {
	cleanConsole(); // Limpia la consola
	print(titulo); // Imprime el título

	for (int i = 0; i < size; i++) { // Imprime las opciones
		print("[" + std::to_string(i+1) + "] " + opciones[i]);
	}

	int value = IntInput("Ingrese una opcion: "); // Toma un input

	while (value < 1 || value > size) { // Validación de opción
		value = IntInput("Opcion Invalida. Ingrese otra opcion: ");
	}

	return value;
}

/*
	Permite la entrada de un string por consola
	@param text Texto de salida.
*/
string Sistema::StringInput(string text)
{
	string entrada; // Declara una variable de entrada
	cout << text; // Muestra un texto por pantalla
	cin.ignore(1000, '\n');
	cin >> entrada; // Pregunta por consola
	return entrada; // Devuelve el texto ingresado
}

/*
	Permite la entrada de un int por consola
	@param text Texto de salida.
*/
int Sistema::IntInput(string text)
{
	int entrada; // Declara una variable de entrada
	cout << text; // Muestra un texto por pantalla
	cin >> entrada; // Pregunta por consola

	while (!cin.good()) { // Si no es un dato numérico
		cin.clear(); // Limpia la entrada inicial
		cin.ignore(10000, '\n'); // Limpia restos del buffer
		cout << "Valor invalido. " + text;  // Muestra un texto por pantalla
		cin >> entrada; // Pregunta por consola
	}
	
	return entrada; // Devuelve el integer ingresado
}

/*
	Crea un nuevo alumno y lo añade al sistema
*/
void Sistema::IngresarAlumno(string nombre, string apellido, int semestre, int edad)
{
	Alumno alumno = Alumno(nombre, apellido, semestre, edad); // Crea un nuevo alumno
	alumnos.add(alumno); // Añade el alumno
}

/*
	Crea un nuevo profesor y lo añade al sistema
*/
void Sistema::IngresarProfesor(string nombre, string apellido)
{
	Profesor profesor = Profesor(nombre, apellido); // Crea un nuevo profesor
	profesores.add(profesor); // Añade el profesor
}

/*
	Crea un nuevo ramo y lo añade al sistema
*/
void Sistema::IngresarRamo(string nombre, string carrera, string sala)
{
	Ramo ramo = Ramo(nombre, carrera, sala); // Crea un nuevo ramo
	ramos.add(ramo); // Añade el ramo
}

/*
	Revisa si es posible añadir un nuevo alumno.
*/
bool Sistema::SePuedeIngresarAlumno()
{
	return !alumnos.isFull();
}

/*
	Revisa si es posible añadir un nuevo profesor.
*/
bool Sistema::SePuedeIngresarProfesor()
{
	return !profesores.isFull();
}

/*
	Revisa si es posible añadir un nuevo ramo.
*/
bool Sistema::SePuedeIngresarRamo()
{
	return !ramos.isFull();
}
