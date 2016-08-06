#ifndef STACK_H
#define STACK_H

#include "MyException.h"
#include<iostream>
using namespace std ;

#include<cstdlib>

template <class T>
class Stack
{
private:
  T* array;
  int top;
  int length;
public:

  Stack(int);
  ~Stack();
  void push( T );
  T pop();
  T element_at_top();
  bool isEmpty();
  bool isfull();
  void display();
  void clearstack();
};


#endif // STACK_H

