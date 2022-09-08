#include "Ramos.h"

Ramos::Ramos(string _nombre, string _carrera, string _sala)
{
	nombre = _nombre;
	carrera = _carrera;
	sala = _sala;
}
string Ramos::getNombre()
{
	return nombre;
}
void Ramos::setNombre(string _nombre)
{
	nombre = _nombre;
}
string Ramos::getCarrera()
{
	return carrera;
}
void Ramos::setCarrera(string _carrera)
{
	carrera = _carrera;
}
string Ramos::getSala()
{
	return sala;
}
void Ramos::setSala(string _sala)
{
	sala = _sala;
}