#include<iostream>
#include<stdlib.h>
using namespace std;
int * count_sort(int a[],int k,int n)
{
	int *c,*b;
	c=new int[k];
	b=new int[n];
	for (int i=0;i<k;i++)
		c[i]=0;
	for (int j=0;j<n;j++)
		c[a[j]]++;
	for (int i=1;i<k;i++)
		c[i]=c[i]+c[i-1];
	for (int j=n-1;j>=0;j--)
	{
		b[c[a[j]]-1]=a[j];
		c[a[j]]--;
	}
	return b;
}
int get_digit(int z,int d)
{
	for (int i=1;i<d;i++)
		z=z/10;
	return z%10;
}
void radix_sort(int a[],int d,int n)
{
	int *c,*b;
	c=new int[10];
	b=new int[n];
	for(int j=0;j<d;j++)
	{
		for (int i=0;i<10;i++)
			c[i]=0;
		for (int i=0;i<n;i++)
			c[get_digit(a[i],j+1)]++;;
		for (int i=1;i<10;i++)
			c[i]=c[i]+c[i-1];
		for (int i=n-1;i>=0;i--)
		{
			b[c[get_digit(a[i],j+1)]-1]=a[i];
			c[get_digit(a[i],j+1)]--;
		}
		for (int i=0;i<n;i++)
			a[i]=b[i];
	}
}
int main()
{
	int n,k,*a1,r,d,*a2;
	char ch='y';
	while(ch=='y')
	{
		cout<<"\nEnter the size  \t: ";
		cin>>n;
		cout<<"\n\t\t\t\tCOUNT SORT\n";
		cout<<"\nEnter the range \t: ";
		cin>>k;
		a1=new int[n];
		a2=new int[n];
		for(int i=0;i<n;i++)
		{
			r=rand()%k;
			a1[i]=r;
		}
		int *a=count_sort(a1,k,n);
		cout<<"Sorted Array is \t: ";
		for (int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
		cout<<"\n\n\t\t\t\tRADIX SORT\n";
		cout<<"\nEnter number of Digits  : ";
		cin>>d;
		for(int i=0;i<n;i++)
		{
			r=rand();
			int x=1;
			for(int j=0;j<d;j++)
				x=x*10;
			r=r%x;
			a2[i]=r;
		}
		radix_sort(a2,d,n);
		cout<<"Sorted Array is \t: ";
		for (int i=0;i<n;i++)
			cout<<a2[i]<<" ";
		cout<<endl;
		cout<<"\nWant to Enter More?(y/n):   ";
		cin>>ch;
		cout<<endl;
	}
	return 0;
}
