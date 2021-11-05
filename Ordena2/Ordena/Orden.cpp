#include "Orden.h"
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void Orden::ordIntercambio(std::vector<int>& theV)
{
	int i, j, aux; /* se realizan n-1 pasadas, a[o] ... a[n-2] */
	for (i = 0; i <= theV.size() - 2; i++) {/* coloca mínimo de a[i+1]...a[n-1] en a[i] */
		for (j = i + 1; j <= theV.size()-1; j++)
			if (theV[i] > theV[j])
			{
				aux = theV[i];
				theV[i] = theV[j];
				theV[j] = aux;
			}
	}
}
//https://www.youtube.com/watch?v=Vgd_aZT_BWA
void Orden::burbuja(int a[], int n) {
	bool interruptor = true;
	int tmp = 0;
	for (int pasada = 0; pasada < n - 1 && interruptor; pasada++) {
		interruptor = false; // no se han hecho intercambios
		for (int j = 0; j < n - 1 - pasada; j++) {
			if (a[j + 1] < a[j]) {
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				interruptor = true;
			}
		}
	}
}

void Orden::burbuja2(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
	
}

void Orden::burbuja2(std::vector<int> &theV)
{
	int i, j;
	for (i = 0; i < theV.size(); i++) {

		// Last i elements are already in place  
		for (j = i + 1; j < theV.size(); j++)
			if (theV[i] > theV[j])
				swap(&theV[i], &theV[j]);

		std::cout << theV[i] << " " ;
	}
}

void Orden::swap(int* val1, int* val2)
{
	int temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}





//https://www.youtube.com/watch?v=wnKQsow7ERI
void Orden::ordSeleccion(int a[], int n)
{
	int indiceMenor, i, j;
	int aux;
	for (i = 0; i < n - 1; i++) // ordenar a[0]..a[n-2] y a[n-1] en cada pasada
	{
		indiceMenor = i; // comienzo de la exploración en índice i
		for (j = i + 1; j < n; j++) // j explora la sublista a[i+1]..a[n-1]
			if (a[j] < a[indiceMenor])
				indiceMenor = j;
		if (i != indiceMenor) // sitúa el elemento mas pequeño en a[i]
		{
			aux = a[i];
			a[i] = a[indiceMenor];
			a[indiceMenor] = aux;
		}
	}
}


//https://www.youtube.com/watch?v=8oJS1BMKE64
void Orden::ordInsercion(int a[], int n)
{
	int i, j, aux;
	for (i = 1; i < n; i++) // El índice j explora sublista a[i-1]..a[0] buscando posición correcta del elemento destino, para asignarlo en a[j]
	{
		j = i;
		aux = a[i]; // se localiza el punto de inserción explorando hacia abajo
		while (j > 0 && aux < a[j - 1]) // desplazar elementos hacia arriba para hacer espacio
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = aux;
	}
}

void Orden::mergeSort(std::vector<int>& vector, int start, int end) {
	if (start < end) {
		int mid = (start + (end - 1)) / 2;

		mergeSort(vector, start, mid);
		mergeSort(vector, mid + 1, end);

		merge(vector, start, mid, end);
	}
	/*copy(vector.begin(), vector.end(), ostream_iterator<int>(cout, "; "));
	cout << endl;*/
}

void Orden::merge(std::vector<int>& vector, int start, int mid, int end) {
	int start2 = mid + 1;

	if (vector[mid] <= vector[start2]) {
		return;
	}

	while (start <= mid && start2 <= end) {
		if (vector[start] <= vector[start2]) {
			start++;
		}
		else {
			int value = vector[start2];
			int index = start2;

			while (index != start) {
				vector[index] = vector[index - 1];
				index--;
			}
			vector[start] = value;

			start++;
			mid++;
			start2++;
		}
	}
}


//https://www.youtube.com/watch?v=i8g5dj6CrxU
void Orden::quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


int Orden::partition(int arr[], int low, int high)
{
	int pivot = arr[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
