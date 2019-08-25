/*Program to compute the n terms of the following series
S = 1/1 + 1/2 + 1/3 + 1/4 + ........ + 1/n */

#include<iostream>
using namespace std;
float sum(int);

int main()
{  int n;
cout<<"-------------------------------------------------------------------------";
cout<<"\n\t**** Program to compute sum of series  **** \n";
cout<<"\n\t S = 1/1 + 1/2 + 1/3 + 1/4 + ........ + 1/n \n";
cout<<" \nEnter the number of terms to be added :  ";
cin>>n;
cout<<"Sum of the series is till "<<n<<"th term is :  "<<sum(n);
cout<<"\n-------------------------------------------------------------------------\n";
 return 0;
}

/*
FORMAL PARAMETER: n : integer
PURPOSE: calculates sum of series and returns it
RETURN: float
*/

float sum(int n)
{ float sum=0.0;
for(int x=0 ;x<=n ;x++)
sum=sum+1/(float) x;
return sum;
}
