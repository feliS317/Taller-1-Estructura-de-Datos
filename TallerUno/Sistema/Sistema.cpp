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
	Escribe una l�nea por consola. El output incluye salto de l�nea.
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
	Limpia la consola. Simplemente imprimir� l�neas en blanco para deshacerse de l�neas antiguas.
 */
void Sistema::cleanConsole()
{
	for (int i = 0; i < 100; i++) { // Imprime l�neas en blanco 100 veces
		print("");
	}
}

/*
	Muestra un men� de opciones por pantalla.
	@param titulo T�tulo del men�.
	@param opciones[] Opciones del men�.
	@param size Cantidad de opciones del men�.
	@return Opci�n seleccionada por el usuario.
*/
int Sistema::MostrarMenu(string titulo, string opciones[], int size) {
	cleanConsole(); // Limpia la consola
	print(titulo); // Imprime el t�tulo

	for (int i = 0; i < size; i++) { // Imprime las opciones
		print("[" + std::to_string(i+1) + "] " + opciones[i]);
	}

	int value = IntInput("Ingrese una opcion: "); // Toma un input

	while (value < 1 || value > size) { // Validaci�n de opci�n
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

	while (!cin.good()) { // Si no es un dato num�rico
		cin.clear(); // Limpia la entrada inicial
		cin.ignore(10000, '\n'); // Limpia restos del buffer
		cout << "Valor invalido. " + text;  // Muestra un texto por pantalla
		cin >> entrada; // Pregunta por consola
	}
	
	return entrada; // Devuelve el integer ingresado
}

/*
	Crea un nuevo alumno y lo a�ade al sistema
*/
void Sistema::IngresarAlumno(string nombre, string apellido, int semestre, int edad)
{
	Alumno alumno = Alumno(nombre, apellido, semestre, edad); // Crea un nuevo alumno
	alumnos.add(alumno); // A�ade el alumno
}

/*
	Crea un nuevo profesor y lo a�ade al sistema
*/
void Sistema::IngresarProfesor(string nombre, string apellido)
{
	Profesor profesor = Profesor(nombre, apellido); // Crea un nuevo profesor
	profesores.add(profesor); // A�ade el profesor
}

/*
	Crea un nuevo ramo y lo a�ade al sistema
*/
void Sistema::IngresarRamo(string nombre, string carrera, string sala)
{
	Ramo ramo = Ramo(nombre, carrera, sala); // Crea un nuevo ramo
	ramos.add(ramo); // A�ade el ramo
}

/*
	Revisa si es posible a�adir un nuevo alumno.
*/
bool Sistema::SePuedeIngresarAlumno()
{
	return !alumnos.isFull();
}

/*
	Revisa si es posible a�adir un nuevo profesor.
*/
bool Sistema::SePuedeIngresarProfesor()
{
	return !profesores.isFull();
}

/*
	Revisa si es posible a�adir un nuevo ramo.
*/
bool Sistema::SePuedeIngresarRamo()
{
	return !ramos.isFull();
}
