#include "ListaRamos.h"

ListaRamos::ListaRamos(){}

bool ListaRamos::addRamo(Ramo ramo)
{
	if (count < 10)
	{
		ramos[count] = ramo;
		count++;
		return true;
	}
	return false;
}

void ListaRamos::deleteRamo()
{
}

Ramo ListaRamos::findRamo()
{
	return Ramo();
}

