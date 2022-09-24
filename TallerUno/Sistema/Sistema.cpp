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
using std::getline;
using std::isdigit;

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
	if (text != "") { // Si hay texto que imprimir
		cout << "\n" + text << endl; // Imprime el texto de alarma
	}

	cout << "Presione [Enter] para continuar..."; // Pide un input al usuario

	string placeholder; // Crea una variable para almacenar un texto arbitrario
	getline(cin, placeholder); // Espera por una entrada
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
	Devuelve los ramos que la Persona aun no ha tomado.
	@param persona La persona a chequear.
	@return Los ramos aun no tomados.
*/
Vector<Ramo*> Sistema::RamosDisponibles(Persona* persona)
{
	bool found;
	Vector<Ramo*> ramosNoTomados = Vector<Ramo*>(10);
	cout << persona->getRamos().length;
	for (int i = 0; i < ramos.length; i++)
	{
		found = false;
		for (int j = 0; j < persona->getRamos().length; j++)
		{
			cout << &ramos[i];
			cout << persona->getRamos()[j];
			if (&ramos[i] == persona->getRamos()[j])
			{
				cout << "Found";
				found = true;
				break;
			}
		}
		if (!found)
		{
			ramosNoTomados.add(&ramos[i]);
		}
	}
	return ramosNoTomados;
}

/*
	Muestra el menú de seleccion de ramos por pantalla.
	@param titulo Título del menú.
	@return Opción seleccionada por el usuario.
*/
Ramo* Sistema::MostrarMenuRamos(string titulo, Vector<Ramo*> ramosNoTomados) {
	cleanConsole(); // Limpia la consola
	print(titulo); // Imprime el título

	for (int i = 0; i < ramosNoTomados.length; i++) { // Imprime las opciones
		print("[" + std::to_string(i + 1) + "] " + ramosNoTomados[i]->getNombre() + "  Carrera: " + ramosNoTomados[i]->getCarrera() + "  Sala: " + ramosNoTomados[i]->getSala());
	}
	print("[" + std::to_string(ramosNoTomados.length + 1) + "] No tomar ninguno");

	int value = IntInput("Ingrese una opcion: "); // Toma un input

	while (value < 1 || value > ramosNoTomados.length+1) { // Validación de opción
		value = IntInput("Opcion Invalida. Ingrese otra opcion: ");
	}
	if (value == ramosNoTomados.length + 1) {
		return NULL;
	}
	return ramosNoTomados[value-1];
}

/*
	Permite la entrada de un string por consola
	@param text Texto de salida.
*/
string Sistema::StringInput(string text)
{
	string entrada; // Declara una variable de entrada
	cout << text; // Muestra un texto por pantalla
	getline(cin, entrada); // Pregunta por consola

	while (entrada == "") { // Mientras sea una entrada nula
		cout << text; // Muestra un texto por pantalla
		getline(cin, entrada); // Pregunta por consola
	}

	return entrada; // Devuelve el texto ingresado
}

/*
	Permite la entrada de un int por consola
	@param text Texto de salida.
*/
int Sistema::IntInput(string text)
{
	bool entradaEsDigito = false; // Al comienzo se toma el input invalido
	string entrada = StringInput(text); // Declara una variable de entrada
	
	while (!entradaEsDigito) { // Si no es un dato numérico
		entradaEsDigito = true; // Decimos que el input es valido

		for (char const& ch : entrada) { // Por cada caracter del string
			if (!isdigit(ch)) { // Si ese caracter no es digito
				entrada = StringInput("Valor invalido. " + text); // Pregunta otra vez
				entradaEsDigito = false; // El string no paso la prueba
				break; // Paramos el ciclo
			}
		}
	}
	
	return stoi(entrada); // Devuelve el integer ingresado
}

/*
	Permite la entrada de un string por consola y dependiendo de su resultado devuelve un bool
	@param text Titulo de Input.
	@return True o False.
*/
bool Sistema::BoolInput(string text)
{
	bool entradaValida = false; // Al comienzo se toma el input invalido
	string entrada = StringInput(text); // Declara una variable de entrada

	while (!entradaValida) { // Si la respuesta no fue ni Si ni No
		entradaValida = true; // Decimos que el input es valido
		if (entrada == "Si")
		{
			return true;
		}
		else if (entrada == "No")
		{
			return false;
		}
		else
		{   // Si no dio una de las 2 respuestas de arriba
			entrada = StringInput("Valor invalido. "); // Pregunta otra vez
			entradaValida = false; // El string no paso la prueba
		}
	}
}

void Sistema::ListaRamos(Persona* persona)
{
	cleanConsole(); // Limpia la consola
	print("== Lista de Ramos de " + persona->getNombreCompleto() + " =="); // Imprime el título

	for (int i = 0; i < persona->getRamos().length; i++) { // Imprime las opciones
		print("[" + std::to_string(i + 1) + "] " + persona->getRamos()[i]->getNombre() + "  Carrera: " + persona->getRamos()[i]->getCarrera() + "  Sala: " + persona->getRamos()[i]->getSala());
	}
	alarm("");
}

/*
	Añade ramos a Alumno o Profesor
	@param persona Alumno o Profesor a agregarle ramos.
*/
void Sistema::AgregarRamos(Persona* persona)
{
	bool end = false;
	Ramo* option;
	while (!end)
	{
		Vector<Ramo*> ramosNoTomados = RamosDisponibles(persona);
		option = MostrarMenuRamos("== Ramo a agregar ==", ramosNoTomados);
		if (option)
		{
			if (persona->addRamo(option)) {
				print("Ramo anadido correctamente");
				if (!BoolInput("Desea agregar mas ramos? Responda Si o No. ")) { end = true; }
			}
			else
			{
				alarm("No se ha podido agregar el ramo, se ha excedido el limite");
				end = true;
			}
		}
		else{	end = true;	}
	}
}

/*
	Crea un nuevo alumno y lo añade al sistema
*/
void Sistema::IngresarAlumno(string nombre, string apellido, int semestre, int edad)
{
	if (edad > 0 && edad < 120 && semestre > 0 && semestre < 31){
		Alumno alumno = Alumno(nombre, apellido, semestre, edad); // Crea un nuevo alumno
		alumnos.add(alumno); // Añade el alumno
		if (ramos.length > 0)
		{
			if (BoolInput("Desea agregar inmediatamente los ramos? Responda Si o No. ")) {
				AgregarRamos(&alumno);
			}
		}
	}
	else{
		alarm("La edad o el semestre del Alumno no es valida (la edad debe estar entre 1 y 120, y el semestre debe estar entre 1 y 30");
	}
}

/*
	Crea un nuevo profesor y lo añade al sistema
*/
void Sistema::IngresarProfesor(string nombre, string apellido)
{
	Profesor profesor = Profesor(nombre, apellido); // Crea un nuevo profesor
	profesores.add(profesor); // Añade el profesor
	if (ramos.length > 0)
	{
		if (BoolInput("Desea agregar inmediatamente los ramos? Responda Si o No. ")) {
			AgregarRamos(&profesor);
		}
	}
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

/*
	Consulta por un alumno en el sistema. En caso de no encontrarlo, devuelve la referencia a null.
	@param nombre Nombre del alumno a buscar
	@return Alumno encontrado
*/
Alumno* Sistema::ConsultarAlumno(string nombre)
{
	Alumno* alumnoEncontrado = nullptr;

	if (alumnos.cacheExists() && alumnos.getCache().getNombreCompleto() == nombre) { // Si el alumno estaba cacheado
		alumnoEncontrado = &alumnos.getCache(); // Obtenemos la referencia del cache
	}
	else { // En caso contrario
		for (int i = 0; i < alumnos.length; i++) { // Iteramos sobre la lista
			if (alumnos[i].getNombreCompleto() == nombre) { // Si coincide el nombre
				alumnoEncontrado = &alumnos[i]; // Obtenemos la referencia del elemento
				break; // Rompemos el ciclo
			}
		}
	}

	return alumnoEncontrado; // Devolvemos la referencia
}

/*
	Consulta por un profesor en el sistema. En caso de no encontrarlo, devuelve la referencia a null.
	@param nombre Nombre del profesor a buscar
	@return Profesor encontrado
*/
Profesor* Sistema::ConsultarProfesor(string nombre)
{
	Profesor* profesorEncontrado = nullptr;

	if (profesores.cacheExists() && profesores.getCache().getNombreCompleto() == nombre) { // Si el profesor estaba cacheado
		profesorEncontrado = &profesores.getCache();  // Obtenemos la referencia del cache
	} 
	else {
		for (int i = 0; i < profesores.length; i++) { // Iteramos sobre la lista
			if (profesores[i].getNombreCompleto() == nombre) { // Si coincide el nombre
				profesorEncontrado = &profesores[i]; // Obtenemos la referencia del elemento
				break; // Rompemos el ciclo
			}
		}
	}

	return profesorEncontrado; // Devolvemos la referencia
}

/*
	Consulta por un ramo en el sistema. En caso de no encontrarlo, devuelve la referencia a null.
	@param nombre Nombre del ramo a buscar
	@return Ramo encontrado
*/
Ramo* Sistema::ConsultarRamo(string nombre)
{
	Ramo* ramoEncontrado = nullptr;

	if (ramos.cacheExists() && ramos.getCache().getNombre() == nombre) { // Si el ramo estaba cacheado
		ramoEncontrado = &ramos.getCache(); // Obtenemos la referencia del cache
	}
	else {
		for (int i = 0; i < ramos.length; i++) { // Iteramos sobre la lista
			if (ramos[i].getNombre() == nombre) { // Si coincide el nombre
				ramoEncontrado = &ramos[i]; // Obtenemos la referencia del elemento
				break; // Rompemos el ciclo
			}
		}
	}

	return ramoEncontrado; // Devolvemos la referencia
}

void Sistema::ModificarAlumno(Alumno* busquedaAlumno)
{
	int option = 0;
	string nombre = "";
	string apellido = "";
	int semestre = 0;
	int edad = 0;
	while (option < 6) {
		option = MostrarMenu("== Modificar o Eliminar Alumno ( " + busquedaAlumno->getNombreCompleto() + "   Semestre: " + std::to_string(busquedaAlumno->getSemestre()) + " Edad: " + std::to_string(busquedaAlumno->getEdad()) + " ) == ", new string[7]{
			"Modificar nombre",
			"Modificar apellido",
			"Modificar semestre",
			"Modificar edad",
			"Agregar ramo",
			"Eliminar Alumno",
			"Volver al menu de Modificar elemento"
			}, 7);
		switch (option)
		{
		case 1:
			nombre = StringInput("Ingrese el nuevo nombre del Alumno: ");
			busquedaAlumno->setNombre(nombre);
			break;
		case 2:
			apellido = StringInput("Ingrese el nuevo apellido del Alumno: ");
			busquedaAlumno->setApellido(apellido);
			break;
		case 3:
			semestre = IntInput("Ingrese el nuevo semestre del Alumno: ");
			busquedaAlumno->setSemestre(semestre);
			break;
		case 4:
			edad = IntInput("Ingrese la nueva edad del Alumno: ");
			busquedaAlumno->setEdad(edad);
			break;
		case 5:
			AgregarRamos(busquedaAlumno);
			break;
		case 6:
			if (alumnos.remove(busquedaAlumno)) {
				alarm("Alumno eliminado exitosamente");
			}
			break;
		}
	}
}

void Sistema::ModificarProfesor(Profesor* busquedaProfesor)
{
	int option = 0;
	string nombre = "";
	string apellido = "";
	while (option < 4) {
		option = MostrarMenu("== Modificar o Eliminar Profesor ( " + busquedaProfesor->getNombreCompleto() + " ) == ", new string[5]{
			"Modificar nombre",
			"Modificar apellido",
			"Agregar ramo",
			"Eliminar Profesor",
			"Volver al menu de Modificar elemento"
			}, 5);
		switch (option)
		{
		case 1:
			nombre = StringInput("Ingrese el nuevo nombre del Profesor: ");
			busquedaProfesor->setNombre(nombre);
			break;
		case 2:
			apellido = StringInput("Ingrese el nuevo apellido del Profesor: ");
			busquedaProfesor->setApellido(apellido);
			break;
		case 3:
			AgregarRamos(busquedaProfesor);
			break;
		case 4:
			if (profesores.remove(busquedaProfesor)) {
				alarm("Profesor eliminado exitosamente");
			}
			
			break;
		}
	}
}

void Sistema::ModificarRamo(Ramo* busquedaRamo)
{
	int option = 0;
	string nombre = "";
	string carrera = "";
	string sala = "";
	while (option < 4) {
		option = MostrarMenu("== Modificar o Eliminar Ramo ( " + busquedaRamo->getNombre() + "   Semestre: " + busquedaRamo->getCarrera() + " Edad: " + busquedaRamo->getSala() + " ) == ", new string[5]{
			"Modificar nombre",
			"Modificar apellido",
			"Modificar sala",
			"Eliminar Ramo",
			"Volver al menu de Modificar elemento"
			}, 5);
		switch (option)
		{
		case 1:
			nombre = StringInput("Ingrese el nuevo nombre del Ramo: ");
			busquedaRamo->setNombre(nombre);
			break;
		case 2:
			carrera = StringInput("Ingrese la nueva carrera del Ramo: ");
			busquedaRamo->setCarrera(carrera);
			break;
		case 3:
			sala = StringInput("Ingrese la nueva sala del Ramo: ");
			busquedaRamo->setSala(sala);
		case 4:
			if (ramos.remove(busquedaRamo)) {
				alarm("Ramo eliminado exitosamente");
				break;
			}
			alarm("El ramo no se ha eliminado");
			break;
		}
	}
}
