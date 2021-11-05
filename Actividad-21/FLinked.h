#pragma once
#include <iostream>
using namespace std;

template<class T>
struct node {
	node<T>* next;
	T data;
};

template<class T>
class FLinked
{
public:
	node<T>* first;
	node<T>* last;
  int size = 0;
	FLinked<T>() {
		first = NULL;
		last = NULL;
	}

	void add(T data) {
		if (!first) {
			// The list is empty
			first = new node<T>;
			first->data = data;
			first->next = NULL;
			last = first;
		}
		else {
			// The list isn't empty
			if (last == first) {
				// The list has one element
				last = new node<T>;
				last->data = data;
				last->next = NULL;
				first->next = last;
			}
			else {
				// The list has more than one element
				node<T>* insdata = new node<T>;
				insdata->data = data;
				insdata->next = NULL;
				last->next = insdata;
				last = insdata;
			}
		}
    this->size++;
	}

  // O(n)
	T get(int index) { 
		if (index == 0) { // O(1)
			// Get the first element
			return this->first->data; 
		}
		else {
			// Get the index'th element
			node<T>* curr = this->first; // O(1)
			for (int i = 0; i < index; ++i) { // O(n)
				curr = curr->next; // O(1)
			}
			return curr->data;
		}
	}

  // O(n)
  void update(int index, T data){  
    if (index == 0) {
			// Set the first element
			this->first->data = data;
		} else {
			node<T>* curr = this->first; // O(1)
			for (int i = 0; i < index; ++i) {// O(n)
				curr = curr->next;
			}
      curr->data = data;
    }
		
  }
//
  void remove(int index){
    if (index == 0){
			// Delete first element
      node<T>* oldFirst = this->first;
			this->first = first->next;
      delete oldFirst;
		}
		else {
        node<T>* current=this->first;
        for(int i=1;i<index;i++) current=current->next;//O(n)
        node<T>* aux=current->next;
        current->next = current->next->next;
        delete aux;
    }
    this->size--;
		
  }

	T operator[](int index) {
		return get(index);
	}

};