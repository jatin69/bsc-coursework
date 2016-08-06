//WAP that swaps two numbers using pointers.

#include<iostream>
using namespace std;
void swap(int *x,int *y);
int main()
{ 
	int a,b;
	cout<<"\n---------------------------------------------------------------------------\n";
	cout<<"Enter the two numbers to be swapped : \n";
	cin>>a>>b;
	cout<<"\nNo. before swapping are \n"<<"a="<<a<<"\t b="<<b<<"\n";
	swap(&a,&b);
	cout<<"\nNo. after swapping are \n"<<"a="<<a<<"\t b="<<b<<"\n";
	cout<<"\n---------------------------------------------------------------------------\n";
	return 0;
}  

void swap(int *x,int *y)
{ 
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

