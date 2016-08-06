#include "iostream"
using namespace std;
#include "CircularQueue.h"

template <class T>
 CircularQueue<T>::CircularQueue()
{

}

template <class T>
 CircularQueue<T>::CircularQueue( T _Length)
{
    Length=_Length;
    Front=-1;
    Rear=-1;
    arr= new T[Length];
}

template <class T>
CircularQueue<T>::~CircularQueue()
{
   delete []arr;
}

template <class T>
void CircularQueue<T>::EnQueue( T ele )
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
        cout<<"queue full";
    //throw exception etc
    }
}

template <class T>
T CircularQueue<T>::DeQueue()
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
        //throw new MyException("Queue is empty")
        return 0; // change it later
    }

}

template <class T>
void CircularQueue<T>::Display()
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
        cout<<"Queue is empty !! ";
        // exception handling
    }

}

template <class T>
void CircularQueue<T>::ClearQueue()
{
Front=Rear=-1;
}

template <class T>
bool CircularQueue<T>::isFull()
{
if( (Front==Rear+1) ||((Front==0)&&(Rear==Length-1)))
    return true;
else
    return false;
}

template <class T>
bool CircularQueue<T>::isEmpty()
{
    if((Front==-1)&&(Rear==-1))
        return true;
    else
        return false;
}


template class CircularQueue<int>;
