#pragma once
#include "Ramos.h"

class ListaRamos
{
private:
	Ramos ramos[10];
public:
	ListaRamos();
	void addRamo();
	void deleteRamo();
	Ramos findRamo();
};