#include "Queue_SLL.h"
#include "iostream"
#include "MyException.h"

using namespace std ;

Queue_SLL::Queue_SLL()
{
    //ctor
    Front=0;
    Rear=0;
}

Queue_SLL::~Queue_SLL()
{
    //dtor
}

int Queue_SLL::DeQueue()
{
  if(isEmpty())
  {
      throw new MyException(" Queue is Empty");
  }
   else if(Front->next==0)
  {
      int _data=Front->data;
      delete Front;
      Front=0;
      Rear=0;
      return _data;
  }
  else
  {
    int _data=Front->data;
    Node *temp=Front;
    Front=Front->next;
    delete temp;
    return _data;
  }
}
void Queue_SLL::EnQueue(int _data)
 {
    if(Rear==0)
     {
        Front=new Node(_data ,Front);
        Rear=Front;
     }
    else
    {
        Rear->next= new Node(_data);
        Rear=Rear->next;
    }
}

bool Queue_SLL::isEmpty()
{
    return Front==0;
}


void Queue_SLL::Display()
{
   if(isEmpty())
  {
      throw new MyException("Queue is Empty");
  }

    Node *temp;
    cout<<"\t\nQueue is :\n\t";

   for( temp=Front ; temp!=0 ; temp=temp->next)
    {
        cout<<"\t"<<temp->data;
    }
    cout<<endl;
}


void Queue_SLL::clearQueue()
{
       if(isEmpty())
  {
      throw new MyException("Queue is Empty");
  }

do{
    DeQueue();
}while(Front!=0);

}
