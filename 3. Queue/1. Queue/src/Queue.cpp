#include "iostream"
using namespace std;

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
     Rear++;
    }
        arr[Rear]=ele;
    }
    else
    {
    //throw exception etc
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
            Front++;
        }
        return temp;
    }
    else
    {
        //throw new MyException("Queue is empty")
        return 0; // change it later
    }

}

template <class T>
void Queue<T>::Display()
{
    if(!isEmpty())
    {
        for(int i=Front ; i<=Rear ; i++)
        {
            cout<<"\t"<<arr[i];
        }
    }
    else
    {
        cout<<"Queue is empty !! ";
        // exception handling
    }

}

template <class T>
void Queue<T>::ClearQueue()
{
Front=Rear=-1;
}

template <class T>
bool Queue<T>::isFull()
{
if(Rear==Length-1)
    return true;
else
    return false;
}

template <class T>
bool Queue<T>::isEmpty()
{
    if((Front==-1)&&(Rear==-1))
        return true;
    else
        return false;
}


template class Queue<int>;
