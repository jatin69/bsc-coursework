#include "quickSort.h"
#include "iostream"
using namespace std;
 void inline Swap(int &a, int &b)
 {
    int temp;

        temp = a;
        a = b;
        b = temp;
 }

int QuickSort::Partition(int *arr,int lb,int hb)
{
        int pivotIndex=(lb+hb)/2; ///choosePivot(arr,lb,hb);
        int pivotValue=arr[pivotIndex];

        Swap(arr[pivotIndex],arr[hb]);

        int storeIndex=lb;

        for(int i=lb; i<=hb-1 ;i++)
        {
		 if(arr[i]<pivotValue)
  		 {
 			Swap(arr[i],arr[storeIndex]);
  			storeIndex++;
 		 }
 	   }
        Swap(arr[storeIndex],arr[hb]);
        return storeIndex;
}
int calls=0;
void  QuickSort::quickSort(int *arr , int lowerBound , int higherBound)
{
    if(lowerBound <higherBound)
	{
	    calls++;
	 int pivot = Partition(arr,lowerBound,higherBound);
	 quickSort(arr,lowerBound,pivot-1);
 	 quickSort(arr,pivot+1,higherBound);
    }
    cout<<"\n\ncalls are : "<<calls;
}
