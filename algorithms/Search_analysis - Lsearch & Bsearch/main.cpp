#include <iostream>
using namespace std;

#include "cstdlib"

int lsearch(int*, int , int );
int bsearch( int* , int, int );

void Swap(int&, int&);
void bubble_sort(int* , int);

/// global variables
int l_count=0;
int b_count=0;

int main()
{
    cout<<"========================================================================\n\n";
    cout<<"Size\t\tl_search avg\tb_search avg\n";
    for(int Size=50; Size<=500; Size=Size+50)
    {
        // allocate size
        int *arr=new int[Size];

        // fill array
        for(int i=0 ; i<Size ; i++)
            arr[i]=rand();

        // linear search avg time
        for(int i=0 ; i<Size ; i++)
        {
            lsearch(arr,Size,arr[i]);
        }
        float l_avg= l_count/float(Size);

        /// sorting , so that b_search can be applied
        bubble_sort(arr,Size);

        /// binary search avg time
        for(int i=0 ; i<Size ; i++)
        {
            bsearch(arr,Size,arr[i]);
        }
        float b_avg= b_count/float(Size);

        /// display
        cout<<"\n"<<Size<<"\t\t"<<l_avg<<"\t\t"<<b_avg;
    }

    cout<<"\n\n========================================================================\n";
    return 0;
}


int lsearch(int *arr , int Size, int ele)
{
    int index=-1;
    for(int i=0; i<Size; i++)
    {
        l_count++;
        if(arr[i]==ele)
        {
            index=i;
            break;
        }
    }
    return index;
}


int bsearch( int *arr , int Size, int ele)
{
    int beg=0;
    int End=Size-1;
    int mid = (beg+End)/2;

    while(beg<=End && arr[mid]!=ele)
    {
        b_count++;

        if(ele < arr[mid])
        {
            End=mid-1;
        }
        else
        {
            beg=mid+1;
        }

        mid=(beg+End)/2;
    }
    return mid;
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
    for(i=0; i<Size-1; i++)
    {
        for(j=0; j<Size-i-1; j++)
        {
            if(arr[j]>=arr[j+1])
                Swap(arr[j],arr[j+1]);
        }
    }
}

