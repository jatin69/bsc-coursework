#include "MergeSort.h"


void MergeSort::Merge(int *arr , int lowerBound , int higherBound)
{
	int *temp=new int[higherBound-lowerBound+1];

	int mid=(lowerBound+higherBound)/2;
	int j=(mid+1);
	int i=lowerBound;
	int k=0;

	while(i<=mid && j<=higherBound)
	{

	    temp[k++]=(arr[i]<arr[j])?arr[i++]:arr[j++];
    }

	while(i<=mid)
	        temp[k++]=arr[i++];

	while(j<=higherBound)
		temp[k++]=arr[j++];

    for( i=lowerBound , j=0 ; i<=higherBound ; i++ , j++)
                arr[i]=temp[j];

    delete []temp;
}


void MergeSort:: mergesort(int *arr,int lowerBound,int higherBound)
{
	if(lowerBound<higherBound)
	{
	  	int mid=(lowerBound+higherBound)/2;

		mergesort(arr,lowerBound,mid);
		mergesort(arr,mid+1,higherBound);
		Merge(arr,lowerBound ,higherBound);
	}
}


