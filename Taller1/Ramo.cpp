#include "Ramo.h"

Ramo::Ramo(string _nombre, string _carrera, string _sala)
{
	nombre = _nombre;
	carrera = _carrera;
	sala = _sala;
}
string Ramo::getNombre()
{
	return nombre;
}
void Ramo::setNombre(string _nombre)
{
	nombre = _nombre;
}
string Ramo::getCarrera()
{
	return carrera;
}
void Ramo::setCarrera(string _carrera)
{
	carrera = _carrera;
}
string Ramo::getSala()
{
	return sala;
}
void Ramo::setSala(string _sala)
{
	sala = _sala;
}