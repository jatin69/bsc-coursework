
#include<iostream>
using namespace std;

void GCD();			// prototypes of used functions
void fact();
void fibonacci();

int main()
{  
	char ch;
	int choice;
	cout<<"\n------------------------------------------------------------------------\n";
	cout<<" \n\t \t ******** WELCOME TO NUMERIC OPERATIONS *********"<<endl; 
 do{
	cout<<" \n enter 1 for GCD"<<endl;
	cout<<" enter 2 for FACTORIAL"<<endl;
	cout<<" enter 3 for FIBONACCI SERIES"<<endl;

	int counter=-1;
	do{ 
		counter++;
		if(counter==1)
		{
		cout<<"\tIncorrect choice !! please try again\n ";
		counter=0;
		}
		cout<<" \nenter ur choice :   ";
		cin>>choice;
	}while(choice<1||choice>3);

	switch(choice)
	{
	
	case 1 : 
		  GCD();
		  break;
	case 2 :		
		  fact();
		  break;
	case 3:
		  fibonacci();
		  break;
	}

	cout<<"\n want more operations : Y/N ";
	cin>>ch;
  }while(toupper(ch)=='Y') ;
	return 0;
}



/*
FORMAL PARAMETER:  none
PURPOSE: calculates the fibonacci series
RETURN: void
*/
void fibonacci()
{	int n,first=0,second=1,third;
	cout<<"-------------------------------------------------------------------------";
	cout<<"\nEnter number of elements : ";
	cin>>n;
	cout<<"\nFibbonacci series is : \n";

	if(n==0)
	cout<<"Zero terms\n";
	else if(n==1)
	cout<<first;
	else if(n>=2)
	{ cout<<first<<","<<second;
		for(int x=3;x<=n;x++)
		{ 	
		  third=first+second;
		  first=second;
		  second=third;
		  cout<<","<<third; 
	 	}
	cout<<"\n-------------------------------------------------------------------------\n";
	 }
}


/*
FORMAL PARAMETER:  none
PURPOSE: calculates the factorial of a number
RETURN: void
*/

void fact()
{	unsigned long long int fact=1,num;
	cout<<"-------------------------------------------------------------------------";
	 cout<<"\nEnter the number  :  ";
	 cin>>num;
 	for(int x=num;x>=1;x--)
	  fact=fact*x;
	cout<<"factorial of "<<num<<" is : "<<fact;
	cout<<"\n-------------------------------------------------------------------------\n";
}


/*
FORMAL PARAMETER:  none
PURPOSE: calculates the GCD of two numbers
RETURN: void
*/
void GCD()
{
	int num1,num2,gcd;
	cout<<"\n-------------------------------------------------------------------------\n";
	cout<<"Enter the first number: ";
	cin>>num1;
	cout<<"Enter the second number:";
	cin>>num2;
	for(int i=1;(i<=num1)&&(i<=num2);i++)
	{
	 	if(num1%i==0 && num2%i == 0 )
	 	gcd=i;
	}
	cout<<"\nGreatest Common Divison (GCD) is :  "<<gcd;
	 cout<<"\n-------------------------------------------------------------------------\n";
 }
