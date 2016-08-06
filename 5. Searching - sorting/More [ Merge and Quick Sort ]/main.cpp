#include<iostream>
using namespace std;
#include "stdlib.h"
#include "MergeSort.h"
#include "QuickSort.h"


  int main()
{
   int choice,Size;

    cout<<"\n======================== SORTING TECHNIQUES =======================\n";
    cout<<"\nEnter Size of Array: ";
    cin>>Size;

    int *A= new int[Size];
    cout<<"\nEnter the array  : \n";
    for(int i=0;i<Size;i++)
    cin>>A[i];

 do{
        cout<<"\n\n=========================================================================\n";
        cout<<"\t1. Display Array\n\n";
        cout<<"\t2. Sort by Merge sort and display\n";
        cout<<"\t3. Sort by Quick sort and display\n";
        cout<<"\t4. Exit\n";
        cout<<"\n Enter choice: ";
        cin>>choice;
        cout<<"\n--------------------------------------------------------------------------";
    switch(choice)
   {
        case 1:
        {
            cout<<"\nThe original array is:\n";
            cout<<"\n\t\t";
            for(int i=0;i<Size;i++)
            cout<<A[i]<<"  ";
        }break;

      case 2:
      {
        int *B= new int[Size];
        for(int i=0;i<Size;i++)
        B[i]=A[i];

        MergeSort M;
        M.mergesort(B, 0 , Size-1);
        cout<<"\nThe sorted array is:\n";
        cout<<"\n\t\t";
        for(int i=0;i<Size;i++)
        cout<<B[i]<<"  ";
        }break;


      case 3:
      {
        int *B= new int[Size];
        for(int i=0;i<Size;i++)
        B[i]=A[i];

        QuickSort Q;
        Q.quickSort(B, 0 , Size-1);
        cout<<"\nThe sorted array is:\n";
        cout<<"\n\t\t";
        for(int i=0;i<Size;i++)
        cout<<B[i]<<"  ";
        }break;

      case 4:
          {
            cout<<"\n\t ********** User requested exit **********";
            cout<<"\n\n\tExiting ..  ..";
            cout<<"\n\n------------------------------------------------------------------------------\n";
            exit(0);
          }
   }

 }while(1);

  cout<<"\n--------------------------------------------------------------------------\n";
   return 0;
}
