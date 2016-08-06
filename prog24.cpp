
#include<iostream>
#include<cstdlib>

using namespace std;

 class Location
	{
	  int latitude;
	  int longitude;
	
	  public:
	  Location();
	  void store();
	  void show();
	  friend Location operator + (Location,int);
	  friend Location operator + (int,Location);
	  
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


  Location operator+ (Location L,int i)
{
  Location temp;
  temp.latitude = L.latitude + i;
  temp.longitude = L.longitude + i;
  return temp;
}



 Location operator+ (int i,Location L)
{
  Location temp;
  temp.latitude = L.latitude + i;
  temp.longitude = L.longitude + i;
  return temp;
}



int main()
{

   int choice,i;
   char ch;
   Location l1;
   cout<<"\n-------------------------------------------------------------------------------\n";
   cout<<"\n \t\t******** WELCOME TO LOCATION CLASS ********\n";
   
 do{
   cout<<"1. Enter  location L1\n";
   cout<<"2. Display L1\n";
   cout<<"3. L1 = L1 + integer\n";
   cout<<"4. L1 = integer + L1\n";

   cout<<"5. Exit\n";
   
int counter=-1;
do{ counter++;
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
     cout<<"\nL1:";
     l1.store();
     break;

     case 2:
     cout<<"\nL1:";
     l1.show();
     break;

    
     case 3:
     cout<<"\nEnter an integer: ";
     cin>>i;
     cout<<"L1 = L1 + "<<i<<"\n";
     l1 = l1 + i;
     break;

     case 4:
     cout<<"\nEnter an integer: ";
     cin>>i;
     cout<<"L1 = "<<i<<"+ L1\n";
     l1 = i + l1;
     break;


     case 5:   
     cout<<" \n-------------------------- EXITING --------------------------------\n";
	exit(0);
     break;

   }

   cout<<"\nDo you wish to continue?(y/n): ";
  cin>>ch;
   cout<<"\n----------------------------------------------------------------------------\n";

 }while(toupper(ch)=='Y') ;
   
return 0;

}


