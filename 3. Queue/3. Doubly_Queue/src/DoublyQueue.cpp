#include "iostream"
using namespace std;

#include "DoublyQueue.h"

template <class T>

DoublyQueue<T>::DoublyQueue()
{
    //ctor
}

template <class T>
 DoublyQueue<T>::DoublyQueue( T _Length)
{
    Length=_Length;
    Front=-1;
    Rear=-1;
    arr= new T[Length];
}

template <class T>
DoublyQueue<T>::~DoublyQueue()
{
   delete []arr;
}

template <class T>
void DoublyQueue<T>::EnQueue( T ele )
{
    if(!isFull())
    {
         int choice;
            cout<<"\n1. insert via front ";
            cout<<"\n2. insert via rear \n";
            cout<<"\nEnter your choice : ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    if(Front==0)
                    {
                        cout<<"cannot insert from front \n";
                        return;
                    }
                    else if(Front==-1)
                    {
                        Front++;
                        Rear++;
                    }
                    else
                    {
                         Front--;
                    }
                    arr[Front]=ele;
                }
                break;
                case 2:
                {
                    if(Rear==Length-1)
                    {
                        cout<<"Cannot insert from rear \n";
                        return;
                    }
                    else if(Front==-1)
                    {
                        Front++;
                        Rear++;
                    }
                    else
                    {
                       Rear++;
                    }
                    arr[Rear]=ele;
                }
                break;
            }
    }
    else
    {
        cout<<"array is full";
    //throw exception etc
    }
}

template <class T>
T DoublyQueue<T>::DeQueue()
{
    T temp;
     if(!isEmpty())
    {

        if(Front==Rear)
        {
            temp=arr[Front];
            Front=Rear=-1;
            cout<<"\nQueue is now empty\n";
        }
        else
        {
           int choice;
            cout<<"\n1. delete via front ";
            cout<<"\n2. delete via rear \n";
            cout<<"\nEnter your choice : ";
            cin>>choice;
            switch(choice)
            {
                case 1:
                {
                    temp=arr[Front];
                    Front++;
                }
                break;
                case 2:
                {
                    temp=arr[Rear];
                    Rear--;
                }
                break;
            }

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
void DoublyQueue<T>::Display()
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
void DoublyQueue<T>::ClearQueue()
{
Front=Rear=-1;
}

template <class T>
bool DoublyQueue<T>::isFull()
{
if((Front==0) && (Rear==Length-1))
    return true;
else
    return false;
}

template <class T>
bool DoublyQueue<T>::isEmpty()
{
    if((Front==-1)&&(Rear==-1))
        return true;
    else
        return false;
}


template class DoublyQueue<int>;
