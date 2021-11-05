#include "BST.h"
/*
* Se baso en el siguiente codico para la recaudaci'on de datos
* C++ - Arboles Binaros de busqueda -Recorridos por amplitud
* Site: martincruz.me
*/

#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

//Constructor:
//Complegidad constante O(1)
struct nodo {
    int nro;
    struct nodo* izq, * der;
};

typedef struct nodo* ABB;
/* es un puntero de tipo nodo que hemos llamado ABB, que ulitizaremos
   para mayor facilidad de creacion de variables */

ABB crearNodo(int x)
{
    ABB nuevoNodo = new(struct nodo);
    nuevoNodo->nro = x;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}
/*
    insert:
        Determina, de forma recursiva, si un numero se encuentra dentro del arbol
        En caso de no estar lo inserta como hoja
    Input:
        int value: El entero que se desea insertar en el arbol
        pointer a ABB: El nodo que se analiza en cada nivel de recursión (potencial padre)
    Returno:
        Bool, True en caso de incertatr el valor por primera vez
            False en caso de ya haber teido el valor en el arbol
    Compelgidad:
        Best Case - O(1)
        Average Case - O(log(N))
        Worst Case - O(N)
*/
void insertar(ABB& arbol, int x)
{
    if (arbol == NULL)
    {
        arbol = crearNodo(x);
    }
    else if (x < arbol->nro)
        insertar(arbol->izq, x);
    else if (x > arbol->nro)
        insertar(arbol->der, x);
}
/*
    preorder:
        De forma recursiva, recorre todas las posiciones del arbol
        comienza por el nodo, hijo izquierdo, hijo derecho
    Input: ABB
    Compelgidad lineal O(N)
*/
void preOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        cout << arbol->nro << " ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
/*
    inorder:
        De forma recursiva, recorre todas las posiciones del arbol
        comienza por el hijo izquierdo, el nodo, hijo derecho
    Input:
        pointer a ABB: El nodo a imprimir (puede ser nullptr)
    Compelgidad lineal O(N)
*/
void enOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        enOrden(arbol->izq);
        cout << arbol->nro << " ";
        enOrden(arbol->der);
    }
}

/*
    postorder:
        De forma recursiva, recorre todas las posiciones del arbol
        comienza por el hijo izquierdo, hijo derecho, el nodo
    Input:
        pointer a ABB: El nodo a imprimir (puede ser nullptr)
    Compelgidad lineal O(N)
*/
void postOrden(ABB arbol)
{
    if (arbol != NULL)
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->nro << " ";
    }
}


//void verArbol(ABB arbol, int n)
//{
//    if (arbol == NULL)
//        return;
//    verArbol(arbol->der, n + 1);
//
//    for (int i = 0; i < n; i++)
//        cout << "   ";
//
//    cout << arbol->nro << endl;
//
//    verArbol(arbol->izq, n + 1);
//}
/*
    height:
        De forma recursiva, recorre todas los elementos del arbol
        Encuentra al altura de cada nodo en el arbol
            La determina en base a la altura maxima de sus hijos
    Input:
        pointer a ABB: El nodo que se analiza en cada nivel de recursión (potencial padre)
    Retorno:
        Int: La altura del arbol
    Compelgidad lineal O(N)
*/

int height(ABB arbol) {
    if (arbol) {
        int left = height(arbol->izq);
        int right = height(arbol->der);
        return max(left, right) +1;
    }
    return 0;
}
/*
    ancestors:
        Busca el elemento solicitado
            Si lo encuentra imprime todos los valores desde la raiz hasta el nodo pedido
            En caso contrario no hace nada
    Input:
        int value: el valor del que se quiere saber los ancestros
    Compelgidad:
        Best Case - O(1)
        Average Case - O(log(N))
        Worst Case - O(N)
*/
void ancestors(ABB arbol, int value) {
    queue <int> ancestors;
    while (arbol) {
        ancestors.push(arbol->nro);
        if (arbol->nro == value) {
            while (!ancestors.empty()) {
                cout << ancestors.front() << " ";
                ancestors.pop();
            }
            cout << '\n';
            return;
        }
        if (arbol->nro < value)
            arbol = arbol->der;
        else
            arbol = arbol->izq;
    }
    cout << '\n';
}

/*
    whatLevelAmI:
        Busca el elemento solicitado
    Input:
        int value: el valor del que se quiere saber el nivel
    Retorno:
        int: el nivel donde se encuentra el nodo (raiz = 1)
            Si no encuentra el elemento retorna -1
    Compelgidad:
        Best Case - O(1)
        Average Case - O(log(N))
        Worst Case - O(N)
*/
int whatlevelamI(ABB arbol, int value) {
    int lvl = 0;
    while (arbol) {
        lvl++;
        if (arbol->nro == value) {
            return lvl;
        }
        if (arbol->nro < value)
            arbol = arbol->der;
        else
            arbol = arbol->izq;
    }
    return -1;
}

int main()
{
    ABB arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo
    int h, a, l, l2; //altura, ancestros, y nivel auxiliares

    cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << " Numero del nodo " << i + 1 << ": ";
        cin >> x;
        insertar(arbol, x);
    }

    /*cout << "\n Mostrando ABB \n\n";
    verArbol(arbol, 0);*/

    cout << "\n Recorridos del ABB";

    cout << "\n\n En orden   :  ";   enOrden(arbol);
    cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
    cout << "\n\n Post Orden :  ";   postOrden(arbol);

    cout << endl << endl;

    h = height(arbol);
    cout << "La altura del arbol es " <<h<< endl;

    cout << "Dame el numero del cual quieres los ancestros, los ancestros son los que estan despues del numero indicado"  << endl;
    cin >> a;
    ancestors(arbol, a);

    cout << "Dame el numero para buscar su alturs " << endl;
    cin >> l;
    l2=whatlevelamI(arbol, l);
    cout << "La altura del numero es " << l2 << endl;


    system("pause");
    return 0;
}
	