#include "iostream"
using namespace std;
#include "PriorityQueue.h"
#include "MyException.h"

//template <class T>
//typename Queue<T>::Front

template <class T>
 PriorityQueue<T>::PriorityQueue()
{

}

template <class T>
 PriorityQueue<T>::PriorityQueue( T _Length)
{
    Queue<T>::Length=_Length;
    Queue<T>::Front=-1;
    Queue<T>::Rear=-1;
    Queue<T>::arr= new T[Queue<T>::Length];
}
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
   delete []Queue<T>::arr;
}

template <class T>
void PriorityQueue<T>::EnQueue( T ele )
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
        if( CheckPriority( Queue<T>::arr[Queue<T>::Rear] , ele ))
        {
           int temp_index=Queue<T>::Rear;

            do{
                Queue<T>::arr[temp_index+1]=Queue<T>::arr[temp_index];
                temp_index--;
            }while( CheckPriority ( Queue<T>::arr[temp_index] , ele ));

        temp_index++;
        Queue<T>::arr[temp_index]=ele;
        Queue<T>::Rear++;
        }
        else
        {
            Queue<T>::Rear++;
            Queue<T>::arr[Queue<T>::Rear]=ele;
        }

    }
}



template <class T>
bool PriorityQueue<T>::CheckPriority( T ele1 , T ele2 )
{
 if( ele1<ele2)
        return true;
 else
    return false;
}

template class PriorityQueue<int>;
