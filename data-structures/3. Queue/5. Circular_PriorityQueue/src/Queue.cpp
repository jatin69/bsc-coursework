#include "iostream"
using namespace std;
#include "MyException.h"
#include "Queue.h"

template <class T>
 Queue<T>::Queue()
{

}

template <class T>
 Queue<T>::Queue( T _Length)
{
    Length=_Length;
    Front=-1;
    Rear=-1;
    arr= new T[Length];
}

template <class T>
Queue<T>::~Queue()
{
   delete []arr;
}

template <class T>
bool Queue<T>::isFull()
{
if( (Front==Rear+1) ||((Front==0)&&(Rear==Length-1)))
    return true;
else
    return false;
}

template <class T>
void Queue<T>::ClearQueue()
{
Front=Rear=-1;
}

template <class T>
bool Queue<T>::isEmpty()
{
    if((Front==-1)&&(Rear==-1))
        return true;
    else
        return false;
}

template <class T>
void Queue<T>::EnQueue( T ele )
{
    if(!isFull())
    {
       if(isEmpty())
    {
        Front=Rear=0;
    }
    else
    {
     Rear=((Rear+1) % Length);
    }
        arr[Rear]=ele;
    }
    else
    {
        throw MyException(" Queue is full ");
    }
}

template <class T>
T Queue<T>::DeQueue()
{
    T temp;
     if(!isEmpty())
    {
        temp=arr[Front];
        if(Front==Rear)
        {
        Front=Rear=-1;
        }
        else
        {
            Front=((Front+1)%Length);
        }
        return temp;
    }
    else
    {
        throw MyException("Queue is empty");
    }

}

template <class T>
void Queue<T>::Display()
{
   if(!isEmpty())
    {
        if(Front<=Rear)
        {
            for(int i=Front ; i<=Rear ; i++)
            {
                cout<<"\t"<<arr[i];
            }
        }
        else
        {

            for(int i=Front ; i<=Length-1 ; i++)
            {
                cout<<"\t"<<arr[i];
            }
            for(int i=0 ; i<=Rear ; i++)
            {
                cout<<"\t"<<arr[i];
            }
        }

    }

     else
    {
           throw MyException("Queue is empty");
    }

}



template class Queue<int>;
