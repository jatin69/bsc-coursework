#include<iostream>
#include<cstdlib>

using namespace std;

 class Location
	{
	  int latitude;
	  int longitude;
	
	  public:
	  void store();
	  void show();
	  Location();
	  Location operator ++();
	  const Location operator ++(int);
	  Location operator --();
	  const Location operator --(int);
	};


 Location:: Location()
{
  latitude = 0;
  longitude = 0;
}


 void Location:: store()
{
  cout<<"\nEnter latitude : ";
  cin>>latitude;
  cout<<"Enter longitude: ";
  cin>>longitude;
}

 
 void Location:: show()
{
  cout<<"\nLatitude : "<<latitude;
  cout<<"\nLongitude: "<<longitude<<endl;
} 


/*
FORMAL PARAMETER: NULL
PURPOSE: to pre-increment the values of the calling object
RETURN: reference to the calling object
*/

  Location Location:: operator ++()
{
  ++longitude;
  ++latitude;
  return *this;
}


/*
FORMAL PARAMETER: NULL
PURPOSE: to pre-decrement the values of the calling object
RETURN: reference to the calling object
*/

  Location Location:: operator --()
{
  --longitude;
  --latitude;
  return *this;
}


/*
FORMAL PARAMETER: int (CONVENTION)
PURPOSE: to post-increment the values of the calling object
APPROACH: original object copied and returned
        : values of calling object incremented
RETURN: saved object: Location 
*/

  const Location Location:: operator ++ (int)
{
  const Location saveob=(*this);          // copying current object by operator=
  latitude++;
  longitude++;
  return saveob;
}


/*
FORMAL PARAMETER: int (CONVENTION)
PURPOSE: to post-decrement the values of the calling object
APPROACH: original object copied and returned
        : values of calling object decremented
RETURN: saved object: Location 
*/

  const Location Location:: operator -- (int)
{
  const Location saveob(*this);       // copying current object by copy constructor
  latitude--;
  longitude--;
  return saveob;
}


int main()
{

   int choice;
   char ch;
   Location l1,l2;
	cout<<"\n------------------------------------------------------------------------\n";
	cout<<"\n \t\t******** WELCOME TO LOCATION CLASS ********\n";
      
 do{
   cout<<"1. Enter location L1\n";
   cout<<"2. Display L1 and L2\n";
   
   cout<<"3. L2 = ++L1     (pre increment)\n";
   cout<<"4. L2 = --L1     (pre decrement)\n";
   cout<<"5. L2 = L1++     (post increment)\n";
   cout<<"6. L2 = L1--     (post decrement)\n";
   cout<<"7. Exit\n";
      
int counter=-1;
do{ counter++;
if(counter==1)
{
cout<<"\tIncorrect choice !! please try again\n ";
counter=0;
}
cout<<" \nenter ur choice :   ";
cin>>choice;
}while(choice<1||choice>7);

switch(choice)
   {
     case 1:
     cout<<"\nL1:";
     l1.store();
     break;

     case 2:
     cout<<"\nL1:";
     l1.show();
     cout<<"\nL2:";
     l2.show();
     break;

     case 3:
     cout<<"L2 = ++L1\n";
     l2 = ++l1;
     break;

     case 4:
     cout<<"L2 = --L1\n";
     l2 = --l1;
     break; 
          
     case 5:
     cout<<"L2 = L1++\n";
     l2 = l1++;
     break;


     case 6:
     cout<<"L2 = L1--\n";
     l2 = l1--;
     break;
 
     

     case 7:   
     cout<<" \n-------------------------- EXITING --------------------------------\n";
     exit(0);
     
   }

   cout<<"\nDo you wish to continue?(y/n): ";
  cin>>ch;
   cout<<"\n----------------------------------------------------------------------------\n";

 }while(toupper(ch)=='Y') ;
   
return 0;

}


