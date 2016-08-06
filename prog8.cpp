/*WAP to print the triangle of stars as follows (take number of lines from user)

	  	  *
	 	 ***	
	 	*****
	       *******
*/

#include<iostream>
using namespace std;

void printstar(int);

int main () 
{  
	int rows;
	cout<<"------------------------------------------------------------------------------\n";
	cout<<"\n\t **** Program to print the equilateral triangle of stars **** \n\n";
	cout<<" Enter no. of rows of equilateral triangle : ";
	cin>>rows;  
	cout<<endl;

	printstar(rows);
	cout<<"\n------------------------------------------------------------------------------\n";
	return 0;
}


/*
FORMAL PARAMETER: rows : integer
PURPOSE: display the equilateral triangle of stars
RETURN TYPE: void
*/

 void printstar(int rows)
{
	int spaces=rows-1;
	
	for(int i=1;i<=rows;i++,spaces--)
	{ 	 
		cout<<"\t\t";
		for(int j=1;j<=spaces;j++)
		cout<<" ";
		
 		for(int k=1; k<=2*i-1; k++)
	  	cout<<"*";

 	  	cout<<"\n";
	} 
}
	
