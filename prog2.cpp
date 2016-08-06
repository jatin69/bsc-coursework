//Program to reverse a number.

#include<iostream>
using namespace std;
int reverse(int );
int main()
{  int num;
cout<<"-------------------------------------------------------------------------";
cout<<"\n\n\t\t**** Program to reverse a number **** \n";
cout<<" \nEnter a number  : ";
cin>>num;
cout<<"Reversed no. is : "<<reverse(num);
cout<<"\n-------------------------------------------------------------------------\n";
 return 0;
}

/*
FORMAL PARAMETER: num : integer
PURPOSE: reverses the number and returns it
RETURN TYPE: integer
*/


int reverse(int num)
{  int dig,rev=0;
 while(num>0)
 { dig=num%10;
  rev=(rev*10)+dig;
  num/=10;
 }
return rev;
} 












