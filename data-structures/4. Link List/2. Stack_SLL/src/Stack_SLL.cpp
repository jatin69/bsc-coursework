#include "Stack_SLL.h"
#include "MyException.h"
#include "iostream"
using namespace std;

Stack_SLL::Stack_SLL()
{
    top=0;
}

Stack_SLL::~Stack_SLL()
{
    //dtor
}


bool Stack_SLL::isEmpty()
{
    return top==0;
}


void Stack_SLL::Display()
{
   if(isEmpty())
  {
      throw new MyException("Stack is Empty");
  }

    Node *temp;
    cout<<"\t\nStack is :\n\t";

   for( temp=top ; temp!=0 ; temp=temp->next)
    {
        cout<<"\t"<<temp->data;
    }
    cout<<endl;
}

void Stack_SLL::push(int _data)
 {
    top=new Node(_data ,top);
 }

int Stack_SLL::pop()
{
  if(isEmpty())
  {
      throw new MyException(" Stack is Empty");
  }
   else if(top->next==0)
  {
      int _data=top->data;
      delete top;
      top=0;
      return _data;
  }
  else
  {
    int _data=top->data;
    Node *temp=top;
    top=top->next;
    delete temp;
    return _data;
  }
}


int Stack_SLL::element_at_top()
{
   if(isEmpty())
  {
      throw new MyException("Stack is Empty");
  }
  return top->data;
}


void Stack_SLL::clearStack()
{
       if(isEmpty())
  {
      throw new MyException("Stack is Empty");
  }

do{
    pop();
}while(top!=0);

}
