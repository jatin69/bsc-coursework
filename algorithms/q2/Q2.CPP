
#include<iostream>
#include<stdlib.h>
using namespace std;
int bubble_sort(int a[],int n)
{
	int i,j,t,counter=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			counter++;
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	return counter;
}
int selection_sort(int a[],int n)
{
	int i,min,j,t,counter=0;
	for(i=0;i<n;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			counter++;
			if(a[min]>a[j])
				min=j;
		}
		t=a[min];
		a[min]=a[i];
		a[i]=t;	
	}
	return counter;
}
int insertion_sort(int a[],int n)
{
	int i,j,t,counter=0;
	for (i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		while(j>=0 && t<a[j])
		{
			counter++;
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}	
	return counter;
}

int main()
{
	srand(time(NULL));
	int n,*a1,*a2,*a3,r;
	long s1=0,s2=0,s3=0;
	char ch='y';
	while(ch=='y')
	{
		s1=0,s2=0,s3=0;
		cout<<"Enter the size of array  :  ";
		cin>>n;
		a1=new int[n];
		a2=new int[n];
		a3=new int[n];
		for(int i=0;i<n;i++)
		{
			r=rand()%1000;
			a1[i]=r;
			a2[i]=r;
			a3[i]=r;
		}
		s1=bubble_sort(a1,n);
		s2=selection_sort(a2,n);
		s3=insertion_sort(a3,n);
		cout<<"\n\t\t\tNo. of comparisons";
		cout<<"\nBubble sort : \t\t\t"<<s1;
		cout<<"\n\nSelection sort : \t\t"<<s2;
		cout<<"\n\nInsertion sort : \t\t"<<s3;
		cout<<"\n\nWant to Enter More ?(y/n):   ";
		cin>>ch;
		cout<<endl;
	}
	return 0;
}
