#pragma once
#include "Utilities.h"
#include <iostream>

class Fraccion
{
public:
	Fraccion();
	Fraccion(int, int);
	void imprimir();
	Fraccion suma(Fraccion);
	Fraccion mult(Fraccion);
	int getNum();
	int getDen();
	void setNum(int);
	void setDen(int);
	Fraccion operator+(const Fraccion& val)
	{
		Fraccion temp;
		temp.num = (num* val.den) + (val.num* den);
		temp.den = den * val.den;
		return temp;
	}
	Fraccion operator-(const Fraccion& val)
	{
		Fraccion temp;
		temp.num = (num * val.den) - (val.num * den);
		temp.den = den * val.den;
		return temp;
	}

	friend std::ostream& operator<<(std::ostream & os , const Fraccion &val)
	{
		os << val.num << " / " << val.den;
		return os;
	}


private:
	int num;
	int den;

};

