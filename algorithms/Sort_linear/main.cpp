#include <iostream>
#include "time.h"
#include "stdlib.h"
using namespace std;

void count_sort(int*, int, int);

int main()
{
    srand(time(NULL));
    int Size;
    cout<<"\nEnter size of array :";
    cin>>Size;
    int *A = new int[Size];
    A[0]=rand()%6;
    int Max = A[0];
    for(int i=1; i<Size; i++)
    {
        A[i]=rand()%5;
        if(A[i]>Max)
        {
            Max=A[i];
        }
    }


    for(int i=0 ; i<Size; i++)
    {
        cout<<A[i]<<" " ;
    }
    cout<<endl;



    count_sort(A,Size,Max);
    for(int i=0 ; i<Size; i++)
    {
        cout<<A[i]<<" " ;
    }

    return 0;
}


void count_sort(int *A , int Size , int Max )
{
    int Range=Max+1;
    int *B = new int[Range];          // for intermediate processing
    for(int i=0 ; i<Range; i++)
    {
        B[i]=0;
    }
    // storing the count of each element
    for(int i=0 ; i<Size ; i++ )
    {
        B[A[i]]++;
    }

    // storing the cumulative sum
    for(int i=1 ; i<Range ; i++ )
    {
        B[i]=B[i]+B[i-1];
    }


    int *C = new int[Size];         // for final sorted array

    for(int i=Size-1 ; i>=0 ; i-- )
    {
        C[B[A[i]]-1]=A[i];
        B[A[i]]--;
    }

    for(int i=0 ; i<Size ; i++ )
    {
        A[i]=C[i];
    }

    delete []B;
    delete []C;
}
