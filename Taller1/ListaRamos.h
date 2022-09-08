#pragma once
#include "Ramo.h"

class ListaRamos
{
private:
	Ramo ramos[10];
	int count = 0;
public:
	ListaRamos();
	bool addRamo(Ramo);
	void deleteRamo();
	Ramo findRamo();
};