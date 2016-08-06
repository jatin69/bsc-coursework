/*Program to compute the n terms of the following series
S = 1 - 2 + 3 - 4 + ......*/

#include<iostream>
using namespace std;
int sum(int );

int main()
{  int n;
cout<<"-------------------------------------------------------------------------";
cout<<"\n\t**** Program to compute sum of series  **** \n";
cout<<"\n\t S = 1 - 2 + 3 - 4 + 5 - 6 ... + (2n) - (2n+1) \n";
cout<<" \nEnter the number of terms to be added :  ";
cin>>n;
cout<<"Sum of the series is till "<<n<<"th term is :  "<<sum(n);
cout<<"\n-------------------------------------------------------------------------\n";
 return 0;
}

/*
FORMAL PARAMETER: n : integer
PURPOSE: calculates sum of series and returns it
RETURN: integer
*/

int sum(int n)
{ int sum=0;
	for(int x=1;x<=n;x++)
	{
 	if(x%2==0)
 	sum=sum-x;
 	else
 	sum=sum+x;
	}
return sum;
}
