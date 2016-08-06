#include "DLL.h"
#include "MyException.h"
#include "iostream"
using namespace std;

DLL::DLL()
{
    head=0;
    tail=0;
}

DLL::~DLL()
{
    //dtor
}

bool DLL::isEmpty()
{
    return head==0;
}

bool DLL::isInList(int _data)
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


void DLL::Display()
{
   if(isEmpty())
  {
      throw MyException("Link List is Empty");
  }

    Node *temp;
    cout<<"\t\nLink list is :\n\t";

   for( temp=head ; temp!=0 ; temp=temp->next)
    {
        cout<<"\t"<<temp->data;
    }
    cout<<endl;
}

void DLL::addToTail(int ele)
{
    if(head==0)
    {
        head = new Node(ele);
        head->previous=0;
        head->next=0;
        tail=head;
    }
    else
    {
        Node *insertMe = new Node(ele);
        tail->next= insertMe;
        insertMe->previous=tail;
        insertMe->next=0;
        tail=insertMe;
    }
}

void DLL::addToHead(int ele)
{
    if(head==0)
    {
        head = new Node(ele);
        head->previous=0;
        head->next=0;
        tail=head;
    }
    else
    {
        Node *insertMe = new Node(ele);
        head->previous= insertMe;
        insertMe->next=head;
        insertMe->previous=0;
        head=insertMe;
    }
}

int DLL::deleteFromTail()
{
   if(isEmpty())
  {
      throw MyException("Link List is Empty");
  }
  else if(head->next==0)
  {
      int _data=head->data;
      delete head;
      head=0;
      tail=0;
      return _data;
  }
  else
  {
      int _data=tail->data;
      Node *deleteHold =tail->previous ;
      delete tail;
      tail=deleteHold;
      tail->next=0;
      return _data;
  }
}

int DLL::deleteFromHead()
{
   if(isEmpty())
  {
      throw MyException("Link List is Empty");
  }
  else if(head->next==0)
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
    Node *deleteMe=head;
    head=head->next;
    delete deleteMe;
    return _data;
  }
}


void DLL::addBefore(int location_data , int _data)
{
    if(isEmpty())
    {
        throw MyException(" Link List is Empty");
    }
    else if(!isInList(location_data))
    {
        throw MyException("Error !! Entered element is not in list");
    }
    else if(head->data==location_data)
    {
        addToHead(_data);
    }
    else
    {
        Node* insertMe = new Node(_data);

        Node *temp;
        for( temp=head; (temp->data!=location_data) ;temp=temp->next);
        Node* hold=temp->previous;

        hold->next=insertMe;
        insertMe->previous=hold;
        insertMe->next=temp;
        temp->previous=insertMe;
    }
}

void DLL::addAfter(int location_data , int _data)
{
    if(isEmpty())
    {
        throw MyException(" Link List is Empty");
    }
    else if(!isInList(location_data))
    {
        throw MyException("Error !! Entered element is not in list");
    }
    else  if(tail->data==location_data)
        {
            addToTail(_data);
        }
    else
    {
        Node* insertMe = new Node(_data);

        Node *hold;
        for( hold=head; (hold->data!=location_data) ;hold=hold->next);
        Node* temp=hold->next;

        hold->next=insertMe;
        insertMe->previous=hold;
        insertMe->next=temp;
        temp->previous=insertMe;
    }
}


void DLL::replaceData(int location_data , int _data)
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



int DLL::deleteBefore(int location_data)
{
    // checks if link list is empty
    if(isEmpty())
    {
        throw MyException(" Link List is Empty");
    }
    // checks if the given element is not present in the list
    else if(!isInList(location_data))
    {
        throw MyException(" The entered element is not present in the list ");
    }
    else
    {
        //checks if the location element is at head
        if(head->data==location_data)
        {
            throw MyException(" Error !! cannot delete before head element ");
        }
         //checks if the location element is after head
        if(head->next->data==location_data)
        {
            return deleteFromHead();
        }


        //checks for location element at all possible locations except head & 2nd element
        else
        {
            // this 'for loop' gives "temp" the hold of the previous element of "the element to be deleted"
            Node *temp;
            for( temp=head; (temp->data!=location_data) ;temp=temp->next);

            Node *deleteMe = temp->previous;
            int _data=deleteMe->data;

            Node* hold=deleteMe->previous;

            hold->next=temp;
            temp->previous=hold;

            delete deleteMe;
            return _data;
        }
    }
}



int DLL::deleteAfter(int location_data)
{
    // checks if link list is empty
    if(isEmpty())
    {
        throw MyException(" Link List is Empty");
    }
    // checks if the given element is not present in the list
    else if(!isInList(location_data))
    {
        throw MyException(" The entered element is not present in the list ");
    }
    else
    {
        //checks if the location element is at tail
         if(tail->data==location_data)
        {
            throw MyException(" cannot delete after the tail element ");
        }
        //checks for location element at all possible locations except tail
        else
        {
            // this 'for loop' gives "temp" the hold of the previous element of "the element to be deleted"
            Node *hold;
            for( hold=head; (hold->data!=location_data) ;hold=hold->next);

            Node *deleteMe = hold->next;
            int _data=deleteMe->data;

            Node* temp=deleteMe->next;

            hold->next=temp;
            temp->previous=hold;

            delete deleteMe;
            return _data;
        }
    }
}


int DLL::deleteData(int location_data)
{
    // checks if link list is empty
    if(isEmpty())
    {
        throw MyException(" Link List is Empty");
    }
    else if(!isInList(location_data))
    {
        throw MyException(" The entered element is not present in the list ");
    }
    else
    {
        //checks if the location element is at head
        if(head->data==location_data)
        {
            return deleteFromHead();
        }
        //checks if the location element is at tail
        else if(tail->data==location_data)
        {
            return deleteFromTail();
        }
        //checks for location element at all possible locations except head & tail
        else
        {
            Node *deleteMe;
            for( deleteMe=head; (deleteMe->data!=location_data) ;deleteMe=deleteMe->next);
            int _data=deleteMe->data;

            Node *hold = deleteMe->previous;
            Node *temp=deleteMe->next;

            hold->next=temp;
            temp->previous=hold;

            delete deleteMe;
            return _data;
        }
    }
}



bool DLL::reverse_list()
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
        Node *curr , *temp ;

        curr=head;
        temp=curr->next;

        Node* swap_pointer;
        while(temp!=0)
        {
            swap_pointer=curr->next;
            curr->next=curr->previous;
            curr->previous=swap_pointer;

          curr=temp;
          temp=temp->next;
        }
            swap_pointer=curr->next;
            curr->next=curr->previous;
            curr->previous=swap_pointer;

            tail=head;
            head=curr;
    }
    return true;
}

