#include<iostream>
using namespace std;

 int checkp(int);

 int main()
{
  int num,opt;
  char ch;
 cout<<"\n------------------------------------------------------------------------\n";
 cout<<"\n \t\t****** PRIME NUMBER OPERATIONS *******\n";
 do{
 cout<<"\nEnter 1 to generate prime numbers ";
 cout<<"\nEnter 2 to Check if the number is prime\n ";
 cout<<"\nEnter your choice :  ";
 cin>>opt;

 switch(opt)
{
 case 1:
          cout<<"--------------------------------------------------------------------------\n";
	cout<<"enter a number to Generate prime numbers upto :  ";
	 cin>>num;
	cout<<"Prime numbers upto "<<num<<"  are :- \n";
	  for(int i=2;i<=num;i++)
	     {
	       if(checkp(i))
	       cout<<i<<" ";
	     } 
	cout<<"\n-------------------------------------------------------------------------\n";
	break;

 case 2:
      cout<<"------------------------------------------------------------------------\n";
	cout<<"Enter number to be checked : ";
	 cin>>num;
   if(checkp(num))
  cout<<" The entered number is prime ";
   else
  cout<<" The entered number is not prime ";
   cout<<"\n----------------------------------------------------------------------\n";
	break;

 default: cout<<"\nPlease enter a valid choice\n";
 }
cout<<"\nwant more operations : Y/N ";
	cin>>ch;
   cout<<"\n----------------------------------------------------------------------\n";
  }while(toupper(ch)=='Y') ;

 return 0;
}


/*
FORMAL PARAMETER: num : integer
PURPOSE: checks if the passed number is prime
RETURN: integer
*/
 int checkp(int num)
{
   for(int i=2;i<=num/2;i++)
  {   if(num%i==0)
      return 0;
   }
    return 1;
}


