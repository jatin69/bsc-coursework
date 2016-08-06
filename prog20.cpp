#include<iostream>
#include<cstdlib>

using namespace std;

/*
DATA MEMBERS    : feet,inch : numeric
MEMBER FUNCTIONS: Constructors: Length()
                : input(),display(),check()
                : operator+ ,operator-
*/ 

 class Length
{
  int feet;
  int inch;

  public:
  Length();
  void input();
  void display();
  void check();
  void operator + (Length);
  void operator - (Length);
};


/*
FORMAL PARAMETER: NULL
PURPOSE: initialises data members with ZERO
*/

 Length:: Length()
{
  feet = 0;
  inch = 0;
}

/*
FORMAL PARAMETER: NULL
PURPOSE: checks whether the values are valid
       : makes the class Length invariant
RETURN: void
*/

 void Length:: check()
{
  if(feet< 0 || inch < 0)
  {
    cout<<"\n\tVALUES INVALID!!\t\tTERMINATING!!";
    cout<<"\n----------------------------------------------------------------------------\n";
    exit(100);
  }

  feet = feet+ (inch/12); 
  inch = inch % 12;
 }


/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in feet,inch
       : calls check() function
RETURN: void
*/

 void Length:: input()
{
  cout<<"\n\tEnter feet  : ";
  cin>>feet;
  cout<<"\tEnter inches: ";
  cin>>inch;

  check();
}


/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of feet,inch
RETURN: void
*/

 void Length:: display()
{
  cout<<"\n\t\t"<<feet<<" feet  "<<inch<<" inches\n\n";
}


/*
FORMAL PARAMETER: L1: Length
PURPOSE: to add corresponding latitudes and longitudes of 2 objects
RETURN: temp: Length
*/

 void Length:: operator + (Length L2)
{
  Length temp;
  temp.inch = (inch + 12*feet) + (L2.inch + 12*L2.feet);
  temp.check();
  cout<<"\nLENGTH 1 + LENGTH 2:";
  temp.display();
}


/*
FORMAL PARAMETER: L1: Length
PURPOSE: to subtract corresponding latitudes and longitudes of 2 objects
RETURN: temp: Length
*/

 void Length:: operator - (Length L2)
{
  Length temp;
  temp.inch = (inch + 12*feet) - (L2.inch + 12*L2.feet);
 if(temp.inch<0)
 {
  cout<<" \nHERE .. L1<L2 .. subtraction is not possible !!! \n";
  return;
 }
  temp.check();
    cout<<"\nLENGTH 1 - LENGTH 2:";
  temp.display();
}


/*
INPUT PARAMETER: ch: integer
                opt: char                 
PURPOSE: calls functions as per requirement
*/
  
 int main()
{
   int choice;
   char ch;
   Length L1,L2,L3;
	cout<<"-------------------------------------------------------------------------------\n\n";
	cout<<" \t ************* WELCOME TO LENGTH OPERATIONS *************"<<endl;
   cout<<"\nEnter LENGTH 1: \n";
     L1.input();
	cout<<"\nENTER LENGTH L2 : \n";
  	  	   L2.input();
	cout<<"\n-------------------------------------------------------------------------------\n";
		
 do{	
   cout<<"\n1. Display the lengths\n";
   cout<<"2. Add two lengths\n";
   cout<<"3. Subtract two lengths\n";
   cout<<"4. Modify length L1\n";
   cout<<"5. Modify length L2\n";
   cout<<"6. Exit\n";
  
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
	}while(choice<1||choice>6);
cout<<"\n-------------------------------------------------------------------------------\n";
	
switch(choice)
   {
     case 1:
     cout<<"\nLENGTH 1 : ";
     L1.display();
     cout<<"\nLENGTH 2 : ";
     L2.display();
     break;

     case 2:
     L1 + L2;
     break;

    case 3:
     L1 - L2 ;
    break;
     
     case 4:  
	cout<<"\nEnter NEW LENGTH 1: \n";
     L1.input();
     break;

     case 5:
	cout<<"\nENTER NEW LENGTH L2 : \n";
  	  	   L2.input();
     break;

    case 6:
     cout<<"-------------------------------- EXITING ---------------------------------------\n\n";
     exit(0);
     
   }
  
	cout<<"\n want more operations ( y/n ) : ";
	cin>>ch;
	cout<<"\n-------------------------------------------------------------------------------\n";
}while(toupper(ch)=='Y') ;

return 0;
}

