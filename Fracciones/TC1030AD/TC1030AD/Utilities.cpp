#include "Utilities.h"

#include <cmath>


int Utilities::GCD(int a, int b)
{
	a = abs(a);
	b = abs(b);

	do
	{
		int n = a % b;
		a = b;
		b = n;
	} while (b > 0);

	
	return a;
}

int Utilities::reduce(int val, int gcd)
{
	return val / gcd;
}


