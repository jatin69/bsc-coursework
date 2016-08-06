#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

/*
DATA MEMBERS    : s1,s2,s3 : numeric
MEMBER FUNCTIONS: enter,check,print,callarea
                  operator=, operator==
*/ 
 class  Triangle
	{
	  int s1;
	  int s2;
	  int s3;
	float Area;
	 
	  public:
	   Triangle();
	  void enter();
	  bool check();
	  void print();
	  float callarea();
	  Triangle& operator= (Triangle&);
	  bool operator== ( Triangle);  
  	};

 Triangle:: Triangle()
{ 
	s1=s2=s3=0;
}

/*
FORMAL PARAMETER: NULL
PURPOSE: checks whether sides form a  Triangle
RETURN: true if sides form a  Triangle
        false if sides don't form a  Triangle
*/

 bool  Triangle:: check()
{
  return((s1+s2>=s3 && s1+s3>=s2 && s2+s3>=s1)&&(s1>0 && s2>0 && s3>0));
} 


/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in s1,s2,s3
       : calls function check()
RETURN: void
*/

 void  Triangle:: enter()
{
 
  int counter=-1;
do{ counter++;
if(counter==1)
{
  cout<<"Entered Values of sides do not form a  Triangle!! please try again !!!\n\n";
  counter=0;
}
  cout<<"\nSide 1 : ";cin>>s1;
  cout<<"Side 2 : ";cin>>s2;
  cout<<"Side 3 : ";cin>>s3;
}while(!(check()));

}


/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of s1,s2,s3
RETURN: void
*/

 void  Triangle:: print()
{
  cout<<"\n\tSide 1 : "<<s1;
  cout<<"\n\tSide 2 : "<<s2;
  cout<<"\n\tSide 3 : "<<s3;
  cout<<endl;
}
 

/*
FORMAL PARAMETER: s1: integer
PURPOSE: calculates area of an equilateral  Triangle
RETURN: area of the equilateral  Triangle
*/

 float area(int s1)
{
  return((sqrt(3)*s1*s1)/4.0 );
}


/*
FORMAL PARAMETER: s1,s2,s3 : integer
PURPOSE: calculates area of a  general  Triangle
RETURN: area of the  Triangle
*/

 float area(int s1,int s2, int s3)
 {
   float s,ar1;
   s = (s1+s2+s3)/2.0;
   ar1 = s*(s-s1)*(s-s2)*(s-s3);

   return (sqrt(ar1));
 }


/*
FORMAL PARAMETER: NULL
PURPOSE: calls one of the overloaded functions area()
         as per the sides
       : prints the area
RETURN: void
*/

 float  Triangle:: callarea()
{
   if(s1==s2==s3)		// for equilateral triangle
    Area= area(s1);

   else				//for general triangle
    Area = area(s1,s2,s3);
  
 return Area;

 } 


/*
FORMAL PARAMETER: t1: reference to an object of  Triangle
PURPOSE: assigns value of one  Triangle to another
RETURN: reference to the calling object
*/
 
  Triangle&  Triangle:: operator = ( Triangle& t1)
{
   s1 = t1.s1;
   s2 = t1.s2;
   s3 = t1.s3;

   return *this;
}


/*
FORMAL PARAMETER: t1:  Triangle
PURPOSE: checks whether two triangles are congruent
RETURN: true if triangles are congruent
        false if triangles are not congruent
*/

 bool  Triangle:: operator == ( Triangle t1) 
{
   return((s1== t1.s1 && s2== t1.s2 && s3== t1.s3)||(s1== t1.s2 && s2== t1.s3 && s3==t1.s1)||(s1== t1.s3 && s2== t1.s1 && s3== t1.s2));   
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
    Triangle t1,t2,t3;
	cout<<"-------------------------------------------------------------------------------\n\n";
	cout<<" \t \t ******** WELCOME TO TRIANGLE OPERATIONS *********"<<endl;
	cout<<"\nEnter  Triangle 1 : "; 
	     t1.enter();
     	cout<<"\nEnter  Triangle 2 :"; 
     		t2.enter();
     
do{
   cout<<"-------------------------------------------------------------------------------\n\n";
   cout<<"1. Display both triangles\n";
   cout<<"2. Calculate the area of both triangles\n";
   cout<<"3. Check if the two triangles are congruent ( overloaded == operator)\n";
   cout<<"4. Assign Triangle 1 to Triangle 2 ( overloaded = operator)\n";
   cout<<"5. Exit\n"<<endl;

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
	}while(choice<1||choice>5);

   switch(choice)
   {
     case 1:
     cout<<"\nTriangle 1:";
     t1.print();
     cout<<"\nTriangle 2:";
     t2.print();
     break;

     case 2:
     cout<<"\nArea of\nTriangle 1 :  ";
     cout<<t1.callarea();
     cout<<"\nTriangle 2 :  ";
     cout<<t2.callarea()<<endl;
     break;

     case 3:
     if(t1==t2)
      cout<<"\n!!! The two triangles are congruent !!!\n";
     else 
      cout<<"\n!!! The two triangles are not congruent !!!\n";
     break;

     case 4:
     t2 = t1;
     cout<<"\n !!! Triangle 1 has been assigned to Triangle 2  !!!\n";
     break;

     case 5:
	cout<<"-------------------------- EXITING ----------------------------\n\n";
     exit(0);
     
   }
  
	cout<<"\n want more operations ( y/n ) : ";
	cin>>ch;
	cout<<"\n-------------------------------------------------------------------------------\n";
}while(toupper(ch)=='Y') ;

return 0;
}

