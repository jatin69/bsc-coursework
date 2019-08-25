#include "CircularPriority.h"
#include "MyException.h"
#include "iostream"
using namespace std;

template <class T>
CircularPriority<T>::CircularPriority()
{
    //ctor
}

template <class T>
 CircularPriority<T>::CircularPriority( T _Length)
{
    Queue<T>::Length=_Length;
    Queue<T>::Front=-1;
    Queue<T>::Rear=-1;
    Queue<T>::arr= new T[Queue<T>::Length];
}

template <class T>
CircularPriority<T>::~CircularPriority()
{
   delete []Queue<T>::arr;
}

template <class T>
bool CircularPriority<T>::CheckPriority( T ele1 , T ele2 )
{
 if( ele1>ele2)
        return true;
 else
    return false;
}

template <class T>
void CircularPriority<T>::EnQueue( T ele )
{
    if(Queue<T>::isFull())
    {
             throw MyException(" Queue is full ");
    }

    else if(Queue<T>::isEmpty())
    {
        Queue<T>::Front=Queue<T>::Rear=0;
        Queue<T>::arr[Queue<T>::Rear]=ele;
    }

    else
    {
        int x=Queue<T>::Rear;
        int len=Queue<T>::Length;
        while( CheckPriority ( Queue<T>::arr[x] , ele ))
        {
            Queue<T>::arr[(x+1)%len] = Queue<T>::arr[x%len];
            x=x-1;
            if(x==-1)
            {
                x=len-1;
            }
        }
        x=(x+1)%len;
        Queue<T>::arr[x]=ele;

        Queue<T>::Rear = ((Queue<T>::Rear+1) % Queue<T>::Length);
    }
}

template class CircularPriority<int>;
