#include <iostream>
#include "FLinked.h"
using namespace std;

template<class T>
void print(FLinked<T> list){
  for(int i = 0; i < list.size ;i++){
    cout << list.get(i) << endl;
  }
}

int main(){
    FLinked<int> list;
    list.add(1); // O(1)
    list.add(23); // O(1)
    list.add(3); // O(1)
    cout<<"Lista original"<<endl;
    print(list);
    list.update(1, 50); // O(n)
    cout<<"Lista actualizada con update"<<endl;
    print(list);
    cout<<"Lista actualizada con delete"<<endl;
    list.remove(1); //O(n)
    print(list);

    return 0;
}
