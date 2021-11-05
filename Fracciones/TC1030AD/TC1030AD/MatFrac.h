#pragma once
#include "CFraccion.h"
#include <iostream>
#include <string>


class MathFrac
{
public:
	MathFrac(std::string);
	void printMatriz();
	void sumar(MathFrac);

private:
	Fraccion array[3][3];


};

