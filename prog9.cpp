/*Write a function that checks whether a given string is a Palindrome or not. Use this function
to find whether the string entered by user is Palindrome or not.*/

#include<iostream>
using namespace std;

int palindrome(char []);	

int main()
{
	char c[50]; 
	cout<<"------------------------------------------------------------------------------\n";
	cout<<" \n\t\t******** CHECKING FOR PALINDROM *******\n";
	cout<<"\nEnter the string : ";
	cin>>c;
	
	if(palindrome(c))
  	cout<<"\n !!! The entered string is a palindrome !!! ";
  	else
	cout<<"\n !!! The entered string is not a palindrome !!!";

  	cout<<"\n\n------------------------------------------------------------------------------\n";
	return 0;
}


/*
FORMAL PARAMETER: ch : char type array
PURPOSE: check if the passed string is a palindrom
RETURN TYPE: integer
*/

int palindrome(char ch[50])
{
	int i;
	
	for(i=0;ch[i]!='\0';i++);			// to calculate string length
  	i--;					// to remove the extra NULL from string 	
  						// as this NULL will create problem while comparing characters
	for(int j=0;j<=i/2;j++)
	if(ch[j]!=ch[i-j])
	return 0;
	
	else
	return 1;
}
