#include "SLL.h"
#include "Node.h"
#include "MyException.h"
#include "iostream"

using namespace std;

SLL::SLL()
{
    head=0;
    tail=0;
}

SLL::~SLL( )
{

}

bool SLL::isEmpty()
{
    return head==0;
}

 void SLL::addToTail(int _data)
 {
    if(tail==0)
     {
        head=new Node(_data ,head);
        tail=head;
     }
    else
    {
        tail->next= new Node(_data);
        tail=tail->next;
    }
}

void SLL::addToHead(int _data)
 {
    head=new Node(_data ,head);
     if(tail==0)
     {
         tail=head;
     }
 }

int SLL::deleteFromHead()
{
  if(isEmpty())
  {
      throw new MyException(" Link List is Empty");
  }
   else if(head->next==0)
  {
      int _data=head->data;
      delete head;
      head=0;
      tail=0;
      //cout<<"\nLink List has only one element , deleting  it .. .. ";
      return _data;
  }
  else
  {
    int _data=head->data;
    Node *temp=head;
    head=head->next;
    delete temp;
    return _data;
  }
}

int SLL::deleteFromTail()
{
  if(isEmpty())
  {
      throw new MyException(" Link List is Empty");
  }
  else if(head->next==0)
  {
      int _data=head->data;
      delete head;
      head=0;
      tail=0;
      //cout<<"\nLink List has only one element , deleting  it .. .. ";
      return _data;
  }
  /*
    **** if u want to prevent creation of "temp" for when not necessary
    we can handle the case of 2 elements separately ,  ****

  else if(temp->next==tail)
  {
       int _data=tail->data;
       delete tail;
       tail=head;
       tail->next=0;
  }
  */
  else
  {
    Node *temp;
    int _data=tail->data;
    for( temp=head; (temp->next)!=tail ;temp=temp->next);
    delete tail;
    tail=temp;
    tail->next=0;
    return _data;
  }
}



void SLL::addBefore(int location_data , int _data)
{
    if(isEmpty())
    {
        throw new MyException(" Link List is Empty");
    }
    else if(!isInList(location_data))
    {
        throw new MyException("Error !! Entered element is not in list");
    }
    else if(head->data==location_data)
    {
        addToHead(_data);
    }
    else
    {
        Node *temp;
        for( temp=head; (temp->next->data!=location_data) ;temp=temp->next);
        temp->next= new Node(_data , temp->next);
    }
}
void SLL::addAfter(int location_data , int _data)
{
    if(isEmpty())
    {
        throw new MyException(" Link List is Empty");
    }
    else if(!isInList(location_data))
    {
        throw new MyException("Error !! Entered element is not in list");
    }
    else
    {
        if(tail->data==location_data)
        {
            addToTail(_data);
        }
        else
        {
            Node *temp;
            for( temp=head; (temp->data!=location_data) ;temp=temp->next);
            temp->next= new Node(_data , temp->next);
        }
    }
}

void SLL::replaceData(int location_data , int _data)
{
    if(isEmpty())
    {
        throw new MyException(" Link List is Empty");
    }
    else if(!isInList(location_data))
    {
        throw new MyException("Error !! Entered element is not in list");
    }
    else
    {
        if(tail->data==location_data)
        {
            tail->data=_data;
        }
        else
        {
            Node *temp;
            for( temp=head; (temp->data!=location_data) ;temp=temp->next);
            temp->data=_data;
        }
    }
}

bool SLL::isInList(int _data)
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


void SLL::Display()
{
   if(isEmpty())
  {
      throw new MyException("Link List is Empty");
  }

    Node *temp;
    cout<<"\t\nLink list is :\n\t";

   for( temp=head ; temp!=0 ; temp=temp->next)
    {
        cout<<"\t"<<temp->data;
    }
    cout<<endl;
}

int SLL::deleteBefore(int location_data)
{
    // checks if link list is empty
    if(isEmpty())
    {
        throw new MyException(" Link List is Empty");
    }
    // checks if the given element is not present in the list
    else if(!isInList(location_data))
    {
        throw new MyException(" The entered element is not present in the list ");
    }
    else
    {
        //checks if the location element is at head
        if(head->data==location_data)
        {
            throw new MyException(" Error !! cannot delete before head element ");
        }
         //checks if the location element is after head
        if(head->next->data==location_data)
        {
            return deleteFromHead();
        }


        //checks for location element at all possible locations except head & 2nd element
        else
        {
            Node *temp;
            // this 'for loop' gives "temp" the hold of the previous element of "the element to be deleted"
            for( temp=head; (temp->next->next->data!=location_data) ;temp=temp->next);
            Node *deleteMe = temp->next;
            int _data=deleteMe->data;
            temp->next=temp->next->next;
            delete deleteMe;
            return _data;
        }
    }
}

int SLL::deleteAfter(int location_data)
{
    // checks if link list is empty
    if(isEmpty())
    {
        throw new MyException(" Link List is Empty");
    }
    // checks if the given element is not present in the list
    else if(!isInList(location_data))
    {
        throw new MyException(" The entered element is not present in the list ");
    }
    else
    {
        //checks if the location element is at tail
         if(tail->data==location_data)
        {
            throw new MyException(" cannot delete after the tail element ");
        }
        //checks for location element at all possible locations except tail
        else
        {
            Node *temp;
            // this 'for loop' gives "temp" the hold of the previous element of "the element to be deleted"
            for( temp=head; (temp->data!=location_data) ;temp=temp->next);
            Node *deleteMe = temp->next;
            int _data=deleteMe->data;
            temp->next=temp->next->next;
            delete deleteMe;
            return _data;
        }
    }
}

int SLL::deleteData(int location_data)
{
    // checks if link list is empty
    if(isEmpty())
    {
        throw new MyException(" Link List is Empty");
    }
    // checks if the given element is not present in the list
     /// the use of isinlist is not suitable here as it is nothing but , an extra use of resource , extra loop traversal
    else if(!isInList(location_data))
    {
        throw new MyException(" The entered element is not present in the list ");
    }
    else
    {
        //checks if the location element is at head
        if(head->data==location_data)
        {
            ///its illogical to call a function deleteFromHead() here ,
            /// as there also isEmpty() would be checked , & thats something we have already checked
            /// so , we can just copy required lines of code from deleteFromHead() & use them here
            return deleteFromHead();
        }
        //checks if the location element is at tail
        else if(tail->data==location_data)
        {
            /// here also , same logic as deleteFromHead() applies
            /// Further , if IsInList() is avoided , then this scenario also becomes useless
            /// & can be checked in loop only
            return deleteFromTail();
        }
        //checks for location element at all possible locations except head & tail
        else
        {
            Node *temp;
            // this 'for loop' gives "temp" the hold of the previous element of "the element to be deleted"
            for( temp=head; (temp->next->data!=location_data) ;temp=temp->next);
            Node *deleteMe = temp->next;
            int _data=deleteMe->data;
            temp->next=temp->next->next;
            delete deleteMe;
            return _data;
        }
    }
}

bool SLL::reverse_list()
{
   // cout<<" Reversing the link list now ";
     // checks if link list is empty
    if(isEmpty())
    {
        throw new MyException(" Link List is Empty");
    }
    else if(head==tail)
    {
        throw new MyException("Only one element in link list , already reversed ");
    }
    else
    {
        Node *prev , *curr , *temp ;

        prev=head;
        curr=head->next;
        temp=curr->next;
        head->next=0;

        while(temp!=0)
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

