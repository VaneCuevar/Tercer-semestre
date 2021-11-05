#include <iostream>
#include "Orden.h"
#include "search.h"
#include <vector>

using namespace std;


int main()
{
    
   /* int array[10] = { 2,4,5,6,7,3,2,4,5,6 };

    int array2[7] = { 29,3,42,17,30,15,8 };

    int array3[7] = { 6,9,2,0,7,5,4 }*/;

    //se puede
    vector<int> vect{ 24, 45, 12, 35, 19};
    vector<int> vect1{ 19, 24, 45, 11, 20};

    //se puede
    vector<int> unVector;
    unVector.push_back(6);
    unVector.push_back(9);
    unVector.push_back(2);
    unVector.push_back(0);
    unVector.push_back(7);
    unVector.push_back(5);
    unVector.push_back(4);

    copy(unVector.begin(), unVector.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
     int tam = (int)unVector.size();
    cout << "El ordenamiento con burbuja queda asi: " << endl;
    Orden::burbuja2(unVector);
    cout << endl;
    cout << tam << " fue el tamaño" << endl;
    cout <<"---------------------------------------------"<< endl;

    copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    int tam2 = (int)vect.size();
    cout << "El ordenamiento por intercambio  queda asi: " << endl;
    Orden::ordIntercambio(vect);
    copy(vect.begin(), vect.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << tam2 << " fue el tamaño" << endl;
    cout << "---------------------------------------------" << endl;
    
    copy(vect1.begin(), vect1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    int tam3 = (int)vect1.size();
    cout << "El ordenamiento por mergesort  queda asi: " << endl;
    Orden::mergeSort(vect1, 0, vect1.size()-1);
    copy(vect1.begin(), vect1.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << tam3 << " fue el tamaño" << endl;
    cout << "---------------------------------------------" << endl;

    // Los dejaré para en un futuro experimentar con ellos Profe
    //Orden::quickSort(unVector., 0, (sizeof(array2) / sizeof(array2[0]) - 1));

    //Orden::ordSeleccion(array2, 7);

    //Orden::ordIntercambio(array, 10);
    //Orden::burbuja(array, 10);

   // Orden::ordInsercion(array2, 7);

    //Orden::burbuja2(array2, 7);

   /* int size = sizeof(array2);
    int size2 = sizeof(int);
    int size3 = sizeof(array[0]);*/

    //std::cout << size << " " << size2 <<  " " << size3 << std::endl;


    //Orden::mergeSort(array2 , 0 ,   (sizeof(array2)/sizeof(array2[0])-1    ));

   // Orden::quickSort(array3, 0, (sizeof(array2) / sizeof(array2[0]) - 1));



   //for (int i = 0; i < 7; i++)
    //   std::cout << array3[i] << " ";
    std::cout << std::endl;
    cout << "Vector para las busquedas, buscar el #9"<< endl;
    copy(unVector.begin(), unVector.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    int a = search::busquedaBin(unVector, 9);

    std::cout << "Por Binario" << std::endl;
    if (a == 0)
        std::cout << "No";
    else
        std::cout << "Si" << " En la posicion: " << a;
    
    int b = search::busquedaSec(unVector, 9);

    std::cout << std::endl;
    std::cout << "Por Secuencial" << std::endl;

    if (b == 0)
        std::cout << "No";
    else
        std::cout << "Si" << " En la posicion: "<<b;
    


}

