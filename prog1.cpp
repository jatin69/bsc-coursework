//Program to calculate and display sum of digits and product of digits

#include<iostream>
using namespace std;

void sumpro(int);   // prototype of the function   

int main()
{  int num;
cout<<"-------------------------------------------------------------------------\n";
cout<<"\n**** Program to calculate  sum and product of digits of a number **** \n";
cout<<" \nEnter a number :  ";
cin>>num;
sumpro(num);
cout<<"-------------------------------------------------------------------------\n";
 return 0;
}

/*
FORMAL PARAMETER: num : integer
PURPOSE: calculates sum and product of the number and display them
RETURN: void
*/

void sumpro( int num)
{  int sum=0,product=1,dig;
  while(num>0)
      {
 	dig=num%10;
  	sum=sum+dig;
  	product=product*dig;
  	num/=10;
      }
cout<<"\nSum of digits     : "<<sum;
cout<<"\nProduct of digits : "<<product<<endl;
}
