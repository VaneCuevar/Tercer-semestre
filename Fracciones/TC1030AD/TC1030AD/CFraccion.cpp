#include "CFraccion.h"


Fraccion::Fraccion()
{
	num = 0;
	den = 1;

}

Fraccion::Fraccion(int numerador, int denominador)
{

	int gdc = Utilities::GCD(numerador, denominador);

	num = Utilities::reduce(numerador, gdc);
	den = Utilities::reduce(denominador, gdc);

	if (numerador < 0 || denominador < 0)
		den *= -1;
}

void Fraccion::imprimir()
{
	std::cout << num << "/" << den ;
}

Fraccion Fraccion::suma(Fraccion frac)
{
	int num1 = 0;
	int num2 = 0;
	int denComun = 0;

	denComun = frac.getDen() * den;

	num1 = num * frac.getDen();
	num2 = frac.getNum() * den;

	int numComun = num1 + num2;

	return Fraccion(numComun, denComun);
	
}

Fraccion Fraccion::mult(Fraccion frac)
{
	int numComun = 0;
	int denComun = 0;

	numComun = num * frac.getNum();
	denComun = den * frac.getDen();

	return Fraccion(numComun, denComun);
	
}

int Fraccion::getDen()
{
	return den;
}

void Fraccion::setNum(int num1)
{
	num = num1;
}

void Fraccion::setDen(int den1)
{
	den = den1;
}

int Fraccion::getNum()
{
	return num;
}


