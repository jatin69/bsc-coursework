
#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

 class strng
	{
	  char str[100];
	
	  public:
	  void enter();
	  void print();
	  void concte(strng);
	  void compare(strng);
	  int len();
	  void uplower();
	  void loupper();
	  void cvowel();
	  void substr();
	}s1,s2;
  

/*
FORMAL PARAMETER:  none
PURPOSE: Enters string in str[100]
RETURN TYPE: void
*/

   void strng:: enter()            
 {
  
   cout<<"\nEnter a string:\n";
   cin.getline(str,50);
   
 }

  
/*
FORMAL PARAMETER:  none
PURPOSE: calculates and Returns length of string
RETURN TYPE: int
*/
  int strng:: len()                
 {
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
 }


/*
FORMAL PARAMETER:  none
PURPOSE: Prints the string
RETURN TYPE: void
*/

  void strng:: print()
 {
   cout.write(str,len());
   cout<<"\n";
   
 }

/*
FORMAL PARAMETER:  s2 : string type
PURPOSE: Concatenates 2 strings and prints the concatenated string
RETURN TYPE: void
*/

 void strng:: concte(strng s2)
{
  int i,j,length;
  char concstr[100];
  
    
  for(i=0;i<len();i++)                   //copying characters from 1st string
  concstr[i]=str[i];
  for(j=0;j<s2.len();j++)                //copying characters from 2nd string
  concstr[i+j]=s2.str[j];
 
  length= len()+ s2.len();
  concstr[length]='\0'; 

  cout<<"\nConcatenated string\n";
  cout.write(concstr,length);
  cout<<endl; 
}


/*
FORMAL PARAMETER:  s2 : string type
PURPOSE: compares two strings and prints whether they are equal or not 
RETURN TYPE: void
*/

 void strng:: compare(strng s2)
{

  int i,flag=0;

  if(len()==s2.len())
 {
      for(i=0;str[i]!='\0';i++)
       {
          if(str[i]!=s2.str[i])
           {
             cout<<"\nThe entered strings are Unequal !!!\n"; 
             return;
            }
     	}
   
	cout<<"\nThe entered strings are Equal !!!\n"; 
   }

  else
 	cout<<"\nThe entered strings are Unequal !!!\n"; 
  
   
}


/*
FORMAL PARAMETER:  none
PURPOSE: converts upper case characters to lower case
RETURN TYPE: void
*/

  void strng:: uplower()
{
  int i;

  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]>=65 && str[i]<=90)            //ascii values for A-Z is 65-90
    str[i]=str[i]+32;
  }
}


/*
FORMAL PARAMETER:  none
PURPOSE: converts lower case characters to upper case
RETURN TYPE: void
*/
  void strng:: loupper()
{
  int i;

  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]>=97 && str[i]<=122)            //ascii values for a-z is 97-122
    str[i]=str[i]-32;
  }
}


/*
FORMAL PARAMETER:  none
PURPOSE: count the no. of vowels in the text
RETURN TYPE: void
*/

 void strng:: cvowel()
{
   int i,count=0;
   
   uplower();

    for(i=0;str[i]!='\0';i++)
    {
      if(str[i]=='a'|| str[i]=='e'|| str[i]=='i'|| str[i]=='o' || str[i]=='u')   
         count++;
     }

   cout<<"\nNo. of vowels: "<<count<<endl;

}

/*
FORMAL PARAMETER:  none
PURPOSE: finds the substring and prints the starting location, if present
RETURN TYPE: void
*/

  void strng:: substr()
{
   char sub[100];
int i,j,k; 
   cout<<"\nEnter a substring : \n";
   cin.getline(sub,100);
  
 for(k=0;sub[k]!='\0';k++);       //to find out length of substring

 
  for(i=0,j=0;((str[i]!='\0')&&(sub[j]!='\0'));i++)
   { 
      if(str[i]==sub[j])                                    //if found increment to the next element.  
         j++;
      else
         j=0;                                                     //if not found reintialise with zero           
   }
   
     if(j==k)		//  condition to check if the found characters are actually equal to string length of substring 
	{
		cout<<"\nSubstring found at position "<<i-j+1<<"\n";  // (i-j+1) is done to find the starting point .. 
	}
     else
	cout<<"\nSubstring not found\n";

}


/*
INPUT PARAMETER: ch: integer
PURPOSE: calls different functions for different options
*/

  int main()
{
  int choice,len;
  char ch; 
cout<<"-------------------------------------------------------------------------------\n\n";
cout<<" \t \t ******** WELCOME TO STRING OPERATIONS *********"<<endl; 

do{

  cout<<"\n1. Concatenate 2 strings\n";
  cout<<"2. Compare 2 strings\n";
  cout<<"3. Calculate length of string\n";
  cout<<"4. Convert upper case characters to lower case\n";
  cout<<"5. Convert lower case characters to upper case\n";
  cout<<"6. Calculate no. of vowels in the string\n";
  cout<<"7. Find a substring\n";
  cout<<"8. Exit\n";
 

	int counter=-1;
	do{ counter++;
	if(counter==1)
	{
	cout<<"\tIncorrect choice !! please try again\n ";
	counter=0;
	}
	cout<<" \nenter ur choice :   ";
	cin>>choice;
	}while(choice<1||choice>8);
	
  cin.ignore();

  switch(choice)
	 {
   
	   case 1: 
	   cout<<" \nPlease enter two strings : \n";
	   s1.enter();
	   s2.enter();
	   s1.concte(s2);
	   break;
	
	  case 2:
	  cout<<" \nPlease enter two strings : \n";
	  s1.enter();
	  s2.enter();
	  s1.compare(s2);
	  break;
	
	  case 3:
	  s1.enter();
	  len= s1.len();
	  cout<<"\nLength of string = "<<len<<endl;
	  break;
	
	  case 4:
	  s1.enter();
	  s1.uplower();
	  cout<<"\nResultant string is:\n";
	  s1.print();
	  break;
	  
	  case 5:
	  s1.enter();
	  s1.loupper();
	  cout<<"\nResultant string is:\n";
	  s1.print();
	  break;
	
	  case 6:
	  s1.enter();
	  s1.cvowel();
	  break;
	
	  case 7:
	  s1.enter();
	  s1.substr();
	  break;
	
	  case 8:
		cout<<"-------------------------- EXITING ----------------------------\n\n";
	     	exit(0);
	
	   }

cout<<"\nwant more operations ( y/n ) : ";
cin>>ch;
cout<<"\n-------------------------------------------------------------------------------\n";
}while(toupper(ch)=='Y') ;

return 0;
}

