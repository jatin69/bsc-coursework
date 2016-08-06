#include "Circular_SLL.h"
#include "Node.h"
#include "MyException.h"
#include "iostream"

using namespace std;


Circular_SLL::Circular_SLL()
{
    head=0;
    tail=0;
}

bool Circular_SLL::isEmpty()
{
    return head==0;
}

 void Circular_SLL::addToTail(int _data)
 {
    if(tail==0)
     {
        head=new Node(_data ,head);
        head->next=head;
        tail=head;
     }
    else
    {
        tail->next= new Node(_data, head );
        tail=tail->next;
    }
}

int Circular_SLL::deleteFromHead()
{
  if(isEmpty())
  {
      throw MyException(" Link List is Empty");
  }
   else if(head->next==head)
  {
      int _data=head->data;
      delete head;
      head=0;
      tail=0;
      return _data;
  }
  else
  {
    int _data=head->data;
    Node *temp=head;
    head=head->next;
    tail->next=head;
    delete temp;
    return _data;
  }
}

bool Circular_SLL::isInList(int _data)
 {
     //checks if the element is at tail
    if(tail->data==_data)
    {
        return true;
    }

    // loop runs from "head" to (n-1) as the Nth element i.e. tail has already been checked
    Node *temp;
    for( temp=head; (temp!=tail) ;temp=temp->next)
    {
        if(temp->data==_data)
            return true;
    }
    return false;
 }


void Circular_SLL::Display()
{
   if(isEmpty())
  {
      throw MyException("Link List is Empty");
  }

    Node *temp;
    cout<<"\t\nLink list is :\n\t";
    cout<<"\t"<<head->data;

   for( temp=head->next ; temp!=head ; temp=temp->next)
    {
        cout<<"\t"<<temp->data;
    }
    cout<<endl;
}

bool Circular_SLL::reverse_list()
{
    if(isEmpty())
    {
        throw MyException(" Link List is Empty");
    }
    else if(head==tail)
    {
        throw MyException("Only one element in link list , already reversed ");
    }
    else
    {
        Node *prev , *curr , *temp ;

        prev=head;
        curr=head->next;
        temp=curr->next;
        head->next=tail; ///

        while(temp!=head) ///
        {
            curr->next=prev;
            // shifting backward all three pointers one step
            prev=curr;
            curr=temp;
            temp=temp->next;
        }
            curr->next=prev;
            tail=head;
            head=curr;
    }
    return true;
}



void Circular_SLL::clearQueue()
{
       if(isEmpty())
  {
      throw MyException("Queue is Empty");
  }

    Node *temp;
    tail->next=0;

    do{
        temp=head;
        head=head->next;
        delete temp;
    }while(head!=0);

}
