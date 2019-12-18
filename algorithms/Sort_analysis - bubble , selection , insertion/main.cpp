#include <iostream>
using namespace std;

#include "stdlib.h"
#include "time.h"

void Swap(int&, int&);
void bubble_sort(int* , int);
void sel_sort(int* , int);
void ins_sort(int* , int);

/// global variables
int bubble_count;
int sel_count;
int ins_count;

int main()
{
    cout<<"========================================================================\n\n";
    cout<<"Size\t\tbubble_sort\tselection_sort\tinsertion_sort\t\n";

    /// random no' generator , generating new random no's on each build
    srand(time(NULL));

    for(int Size=50; Size<=500; Size=Size+50)
    {
        /// Re-initialization of global variables
        bubble_count=0;
        sel_count=0;
        ins_count=0;

        // allocate size for original array
        int *myarr=new int[Size];
        // fill original array

        for(int i=0 ; i<Size ; i++)
            myarr[i]=(rand()%100);

        //create a copy of original array
        int *arr=new int[Size];

        //copy contents from original to this array
        for(int i=0; i<Size; i++)
            arr[i]=myarr[i];
        // bubble sort avg comparisons
        bubble_sort(arr,Size);

        //copy contents from original to this array
        for(int i=0; i<Size; i++)
            arr[i]=myarr[i];
        // selection  sort avg comparisons
        sel_sort(arr,Size);

        //copy contents from original to this array
        for(int i=0; i<Size; i++)
            arr[i]=myarr[i];
        // insertion sort avg comparisons
        ins_sort(arr,Size);

        // display
        cout<<"\n"<<Size<<"\t\t"<<bubble_count<<"\t\t"<<sel_count<<"\t\t"<<ins_count;
    }

    cout<<"\n\n========================================================================\n";
    return 0;
}


void Swap(int &a, int &b)
{
    int temp;

    temp = a;
    a = b;
    b = temp;
}


void bubble_sort(int *arr,int Size)
{
    int i,j;
    for(i=0; i<Size; i++)
    {
        for(j=0; j<Size-i-1; j++)
        {
            bubble_count++;
            if(arr[j]>=arr[j+1])
                Swap(arr[j],arr[j+1]);
        }
    }
}


void sel_sort(int *arr,int Size)
{
    int i,j;
    for(i=0; i<Size; i++)
    {
        int minLoc =i;

        for(j=i+1; j<Size; j++)
        {
            sel_count++;
            if(arr[j] < arr[minLoc])
                minLoc = j;
        }

        Swap(arr[i],arr[minLoc]);
    }
}

void ins_sort(int *arr,int Size)
{
    int i,j;
    for(i=1; i<Size; i++)
    {
        int temp = arr[i];
        j = i;

        while(j>0 && temp < arr[j-1] )
        {
            ins_count++;
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}
