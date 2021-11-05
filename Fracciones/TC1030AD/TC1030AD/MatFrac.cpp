#include "MatFrac.h"
#include <fstream>


MathFrac::MathFrac(std::string name)
{
		int num = 0;
		int den = 0;
		std::ifstream inFile;
		inFile.open(name);

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				inFile >> num >> den;
				
					array[i][j].setNum(num);
					array[i][j].setDen(den);
				
			}
	
}

void MathFrac::printMatriz()
{

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << array[i][j].getNum() << "/" << array[i][j].getDen() << " ";
		}
		std::cout << std::endl;
	}

}

void MathFrac::sumar(MathFrac matriz)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			array[i][j] = array[i][j].suma(matriz.array[i][j]);
		}
		
	}


}
