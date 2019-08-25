#include<iostream>
#include<cstdio>
using namespace std;

int c1=0,c2=0;
int linear_search(int a[],int e,int n)
{
	int i;
	bool t=false;
	for(i=0;i<n;i++)
	{
		c1++;
		if(a[i]==e)
		{
			t=true;
			break;
		}
	}
	if (t==true)
		return i;
	else return -1;
}
int binary_search(int a[],int e,int n)
{
	int mid,f=0,l=n-1;
	bool t=false;
	while(f<=l)
	{
		c2++;
		mid=(f+l)/2;
		if(a[mid]==e)
		{
			t=true;
			break;
		}
		else if (a[mid]<e)
			f=mid+1;
		else
			l=mid-1;
	}
	if(t==true)
		return mid;
	else return -1;
}
int main()
{
	int n,*a;
	char ch='y';
	while(ch=='y')
	{
		cout<<"\nEnter size of array\t  : ";
		cin>>n;
		a=new int[n];
		for(int j=0;j<n;j++)
			a[j]=j;	
		for(int i=0;i<n;i++)
		{
			int j1=linear_search(a,a[i],n);
			int j2=binary_search(a,a[i],n);
		}
		linear_search(a,n+1,n);
		binary_search(a,n+1,n);
		cout<<"\n\t\t\tNo. of comparisons\t\tAverage no. of comparisons";
		cout<<"\nLinear Search : \t\t"<<c1<<"\t\t\t\t"<<c1/(n+1);
		cout<<"\n\nBinary Search : \t\t"<<c2<<"\t\t\t\t"<<c2/(n+1)<<endl;
		cout<<"\nWant to Enter More ?(y/n):  ";
		cin>>ch;
		c1=c2=0;
		cout<<endl;
	}
	return 0;
}
