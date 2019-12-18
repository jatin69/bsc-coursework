#include <iostream>
using namespace std;

#include "stdlib.h"
#include "time.h"

void inline Swap(int&, int&);

void mergesort( int* , int , int  );
void merging(int* , int , int , int ) ;

int part( int* ,int,int);
void quicksort(int* ,int ,int );

void max_heapify(int* ,  int );
void build_max_heap(int* );
void heapsort(int* );


/// global variables
int quick_count;
int merge_count;
int heap_count;
int heapsize;
int arraylength;

int main()
{
    /*
    random no' generator
    in this program , it works in following places :
    1. at the time of filling the array at the beginning
    2. at the time of selecting a random pivot_index in the partition() function
    */
    srand(time(NULL));

    cout<<"========================================================================\n\n";
    cout<<"Size\t\tmerge_sort\tquick_sort\theap_sort\t\n";

    for(int Size=50; Size<=500; Size=Size+50)
    {
        /// Re-initialization of global variables
        quick_count=0;
        merge_count=0;
        heap_count=0;

        // allocate size for original array
        int *myarr=new int[Size];

        // fill original array
        for(int i=0 ; i<Size ; i++)
            myarr[i]=rand();

        //create a copy of original array
        int *arr=new int[Size];

        //copy contents from original to this array
        for(int i=0; i<Size; i++)
            arr[i]=myarr[i];
        // merge sort avg comparisons
        mergesort(arr,0,Size-1);

        //copy contents from original to this array
        for(int i=0; i<Size; i++)
            arr[i]=myarr[i];
        // quick sort avg comparisons
        quicksort(arr,0,Size-1);

        //copy contents from original to this array
        for(int i=0; i<Size; i++)
            arr[i]=myarr[i];
        // quick sort avg no of comparisons
        heapsize=0;         /// global variable
        arraylength=Size;   /// global variable
        heapsort(arr);

        // display
        cout<<"\n"<<Size<<"\t\t"<<merge_count<<"\t\t"<<quick_count<<"\t\t"<<heap_count;
    }

    cout<<"\n\n========================================================================\n";
    return 0;
}


void mergesort( int* arr , int lower, int higher )
{
    if(lower<higher)
    {
        int mid=(lower+higher)/2;
        mergesort(arr,lower,mid);
        mergesort(arr,mid+1,higher);
        merging(arr,lower,mid,higher);
    }

}

void merging(int* arr , int l, int mid , int h)
{
    int i=l;
    int j=mid+1;
    int k=0;

    int Size=(h-l+1);
    int *C=new int[Size];

    while( i<=mid && j<=h)
    {
        merge_count++;
        if(arr[i]<arr[j])
        {
            C[k++]=arr[i++];
        }
        else
        {
            C[k++]=arr[j++];
        }
    }

    while(i<=mid)
    {
        C[k++]=arr[i++];
    }

    while(j<=h)
    {
        C[k++]=arr[j++];
    }

    for(k=0,i=l ; i<=h ; i++ ,k++)
        arr[i]= C[k];
}

void quicksort(int* arr , int lower , int higher)
{
    if(lower<higher)
    {
        int pivot = part(arr , lower , higher) ;
        quicksort(arr,lower , pivot);
        quicksort(arr,pivot+1,higher);
    }
}


void inline Swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}

int part( int* arr , int l , int h )
{
    int pivot_index = (rand()%(h-l+1))+l; // choosing a random value between l & h
    Swap(arr[pivot_index],arr[l]);

    int pivot_value=arr[l];
    int i=l;
    int j=l+1;
    /// the variable "i" always remains at an index whose (element < pivot_value)

    while(j<=h)
    {
        quick_count++;
        if(arr[j]<pivot_value)
        {
            i++;
            Swap(arr[i],arr[j]);
        }
        j++;
    }
    Swap(arr[l],arr[i]);
    return i;
}



void heapsort(int* arr)
{
    build_max_heap(arr);
    for(int i=arraylength; i>=1 ; i--)
    {
        Swap(arr[0],arr[i]);
        heapsize--;
        max_heapify(arr,0);
    }
}

void build_max_heap(int* arr)
{
    heapsize=arraylength;
    int leafnode=arraylength;
    int parent_of_leaf_node= (leafnode-1)/2;
    for(int i=parent_of_leaf_node ; i>=0; i--)
    {
        max_heapify(arr, i);
    }
}

void max_heapify(int* arr ,  int parent )
{
    int left_child = (2*parent)+1;
    int right_child = (2*parent)+2;
    int largest = parent;
    heap_count++;
    if( arr[left_child]>arr[parent] && left_child<=heapsize )
    {
        largest=left_child;
    }
    heap_count++;
    if( arr[right_child]>arr[largest] && right_child<=heapsize )
    {
        largest=right_child;
    }
    if(largest!=parent)
    {
        Swap(arr[parent],arr[largest]);
        max_heapify(arr , largest);
    }
}
