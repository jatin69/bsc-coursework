#include "priority_queue.h"
#include "iostream"
#include "stdlib.h"
using namespace std;

priority_queue::priority_queue()
{
    //ctor
}

priority_queue::priority_queue(int Size)
{
    length=Size;
    arr=new int[length];
    heapsize=-1;
}

void priority_queue:: heap_increase_key(int i, int key)
{
    if(key<arr[i])
    {
        cout<<"new key is smaller than current key";
        return;
    }
    arr[i]=key;
    int parent = (i-1)/2;
    while(i>0 && arr[parent]<arr[i])
    {
        Swap(arr[parent],arr[i]);
        i=parent;
        parent = (i-1)/2;
    }
}

int priority_queue:: heap_maximum()
{
    if(heapsize<0)
    {
        cout<<"\n\n heap underflow \n";
       return -1;
    }
    return arr[0];
}

int priority_queue:: heap_extract_max()
{
    if(heapsize<0)
    {
        cout<<"\n\n heap underflow \n";
       return -1;
    }
    int Max=arr[0];
    arr[0]=arr[heapsize];
    heapsize--;
    max_heapify(0);
    return Max;

}

void priority_queue:: max_heap_insert(int ele )
{
    if(heapsize==-1)
    {
        heapsize=0;
        arr[heapsize]=ele;
        return;
    }
    if(heapsize==length-1)
    {
        cout<<"\n Heap overflow ";
        return;
    }
    heapsize++;
    arr[heapsize]=ele;
    int i=heapsize;
    int parent = (i-1)/2;
    while(i>=1 && arr[parent]<arr[i])
    {
        Swap(arr[parent],arr[i]);
        i=parent;
        parent = (i-1)/2;
    }
}

void priority_queue:: Swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

void priority_queue:: display()
{
    if(heapsize==-1)
    {
        cout<<" heap is empty !! ";
    }
    for(int i=0 ; i<=heapsize ; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void priority_queue:: max_heapify( int parent )
{
    int left_child = (2*parent)+1;
    int right_child = (2*parent)+2;
    int largest = parent;
    if( arr[left_child]>arr[parent] && left_child<=heapsize )
    {
        largest=left_child;
    }
    if( arr[right_child]>arr[largest] && right_child<=heapsize )
    {
        largest=right_child;
    }
    if(largest!=parent)
    {
        Swap(arr[parent],arr[largest]);
        max_heapify(largest);
    }
}
