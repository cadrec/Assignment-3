#ifndef __GENSTACK_H
#define __GENSTACK_H
#include <iostream>

template <typename T>
class Genstack
{
  public:
    Genstack() {
      myArray = new T(100);
      capacity = 100;
      top = -1;
    }

    Genstack(int cap) {
      myArray = new T(cap);
      capacity = cap;
      top = -1;
    }

    bool empty() {
      return (top == -1);
    }

    void push(T element) {
      if(full())
        doubleSize();
    	myArray[++top] = element;
    }

    T peek() {
    	return myArray[top];
    }

    T pop() {
      if(empty())
        throw "Your stack is empty.";
      else
    	 return myArray[top--];
    }

    bool full() {
    	return (top == capacity - 1);
    }

    ~Genstack() {
      delete myArray;
    }

    T* myArray;

  private:
    int capacity;
    int top;

    void doubleSize() {  // found on stackoverflow for adjusting size of array
      T* arr = new T[capacity*2];
      for(int i = 0; i < capacity; i++)
      {
        arr[i] = myArray[i];
      }
      capacity *= 2;
      delete myArray;
      myArray = arr;
    }
};
#endif
