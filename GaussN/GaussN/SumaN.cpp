#include "SumaN.h"
#include <iostream>
int main()
{
    std::cout << "Hello World!\n";
    std::cout << "Recursivo: " << SumaN::sumaR(5);
    std::cout << "Iterativo: " << SumaN::sumaI(5);
}
int SumaN::sumaI(int val)
{
    int resultado = 0;

    for (int i = 1; i <= val; i++)
        resultado += i;

    return resultado;
}

int SumaN::sumaR(int val)
{
    if (val == 1)
        return 0;
    else
        return val + SumaN::sumaR(val - 1);

}

int SumaN::sumaPF(int n)
{
    return (n + 1) * (n / 2); //aqui algo falta ya que entero / entero se trunca, qué es?

}
