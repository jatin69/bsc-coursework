#include "Stack.h"


template <class T>
Stack<T>::Stack(int LENGTH=0)
{
  length=LENGTH;
  array = new T[length];
  top=-1;
 }

template <class T>
Stack<T>::~Stack()
{
  delete []array;
}

template <class T>
bool Stack<T>::isEmpty()
{
  if(top==-1)
    return true;
  else
    return false;
}

template <class T>
bool Stack<T>::isfull()
{
  if(top==length-1)
    return true;
  else
    return false;
}

template <class T>
void Stack<T>::push(T element)
{

   if(isfull())
  {
    throw MyException("Stack overflow , can't push element");
  }
  else
  {
    top++;
    array[top]=element;
  }

}


template <class T>
T Stack<T>::pop()
{
  int temp;

if(isEmpty())
 {
    throw MyException("Stack underflow , cant pop element");
  }
else
  { temp=top;
    top--;
    return array[temp];
  }

}

template <class T>
void Stack<T>::clearstack()
{
  if(top==-1)
  {
      throw new MyException("Stack is already empty !!");
  }
  else
  {
    top=-1;
  }
}

template <class T>
T Stack<T>::element_at_top()
{
  if(top==-1)
  {
      throw new MyException("Stack is empty !!");
  }
  else
  {
    return array[top];
  }
}

template <class T>
void Stack<T>::display()
{
    if(top==-1)
  {
      throw new MyException("Stack is  empty , nothing to display !!");
  }
  else
  {
    for(int i=top; i>=0; i--)
  {
    cout<<"\t"<<array[i];
  }
  }
}
   template class Stack<char>;
   template class Stack<int>;
