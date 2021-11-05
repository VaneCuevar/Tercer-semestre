#include <iostream>
#include "CFraccion.h"
#include "MatFrac.h"

int main()
{
    

    
    
    Fraccion f1(7, 8);
   

    Fraccion f2(1, 8);
    Fraccion f3;
    //Fraccion f4(3, 5);
    //Fraccion f5(1, 3);
    //Fraccion f6;
    //f6 = f4.mult(f5);

    f3 = f1 + f2;
    f3 = f1 - f2;


    std::cout << f3 ;
    //f3 = f1.suma(f2);
    //f3.imprimir();
    //std::cout << std::endl;
    //f6.imprimir();

    //MathFrac matriz("D:\\temp\\file1.txt");
    //MathFrac matriz2("D:\\temp\\file2.txt");

    //matriz.sumar(matriz2);
    //matriz.printMatriz();




}

