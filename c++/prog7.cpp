//WAP to compute the factors of a given number.

#include<iostream>
using namespace std;
void factors(int );

int main()
{	int num;
 	cout<<"------------------------------------------------------------------------------\n";
	cout<<"\n\n\t**** Program to compute the factors of a number **** \n";
	cout<<"Enter a no. : \n";
	cin>>num;
	cout<<"\nThe Factors of "<<num<<" are \n";
	factors(num);
	cout<<"------------------------------------------------------------------------------\n";
 return 0;
}


/*
FORMAL PARAMETER: num : integer
PURPOSE: compute the factors of the passed number
RETURN TYPE: integer
*/


void factors(int num)
{		
	 for(int c=1;c<=num/2;c++)
		 if(num%c==0)
		 cout<<c<<"\n";
		cout<<num<<"\n";
}
