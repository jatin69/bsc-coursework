#include "DeQueue.h"
#include "iostream"
#include "MyException.h"

using namespace std ;


DeQueue::DeQueue()
{
    Front=0;
    Rear=0;
}

DeQueue::~DeQueue()
{
    //dtor
}

bool DeQueue::isEmpty()
{
    return Front==0;
}


void DeQueue::Display()
{
   if(isEmpty())
  {
      throw MyException("Queue is Empty");
  }

    Node *temp;
    cout<<"\t\nQueue is :\n\t";
    cout<<"\t"<<Front->data;
   for( temp=Front->next ; temp!=0 ; temp=temp->next)
    {
        cout<<"\t"<<temp->data;
    }
    cout<<endl;
}


void DeQueue::clearQueue()
{
       if(isEmpty())
  {
      throw MyException("Queue is Empty");
  }

do{
     deleteFromHead();
}while(Front!=0);

}



 void DeQueue::addToTail(int _data)
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

void DeQueue::addToHead(int _data)
 {
    Front=new Node(_data ,Front);
     if(Rear==0)
     {
         Rear=Front;
     }
 }

int DeQueue::deleteFromHead()
{
  if(isEmpty())
  {
      throw MyException(" Link List is Empty");
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

int DeQueue::deleteFromTail()
{
  if(isEmpty())
  {
      throw  MyException(" Link List is Empty");
  }
  else if(Front->next==0)
  {
      int _data=Front->data;
      delete Front;
      Front=0;
      Rear=0;
      cout<<"\nLink List has only one element , deleting  it .. .. ";
      return _data;
  }
  else
  {
    Node *temp;
    int _data=Rear->data;
    for( temp=Front; (temp->next)!=Rear ;temp=temp->next);
    delete Rear;
    Rear=temp;
    Rear->next=0;
    return _data;
  }
}


