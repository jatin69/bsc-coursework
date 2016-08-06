#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

/*
hDATA MEMBERS    : name,addr: char[]
                : age      : integer
MEMBER FUNCTIONS: store(),display(), ~Person()
*/ 

 class Person
{
  protected:
  char name[25];
  int age;
  char addr[50];

  public:
   Person()
  {
    cout<<"\n**** CONSTRUCTOR of Person CALLED ****\n";
  }
virtual   ~Person()
  {
    cout<<"**** DESTRUCTOR of Person CALLED ****\n"; 
 }
  virtual void store();
  virtual void display() const;
};


/*
FORMAL PARAMETER: NULL
PURPOSE: enters values in name,age,addr
RETURN: void
*/

 void Person:: store()
{
  cout<<"\nEnter name       : ";
  cin.ignore();
  cin.getline(name,25);
  cout<<"Enter age        : ";
  cin>>age;
  cout<<"Enter address    : ";
  cin.ignore();
  cin.getline(addr,50);
}


/*
FORMAL PARAMETER: NULL
PURPOSE: displays values of name,age,addr
RETURN: void
*/

 void Person:: display() const
{ 
  cout<<"\nName   : ";
  cout.write(name,strlen(name));
  cout<<"\nAge    : ";
  cout<<age;
  cout<<"\nAddress: ";
  cout.write(addr,strlen(addr));
  cout<<endl;
}


/*
DATA MEMBERS    : empid      : integer
MEMBER FUNCTIONS: store(),display(), ~Teacher()
*/ 

 class Teacher : public Person
{
  protected:
  int empid;

  public:
  Teacher()
  { 
	cout<<"**** CONSTRUCTOR of Teacher CALLED ****\n";
  }
  ~Teacher()
  {
     cout<<"\n**** DESTRUCTOR of Teacher CALLED ****\n";  }
  virtual void store();
  virtual void display() const;
};


/*
FORMAL PARAMETER: NULL
PURPOSE:calls store() function of base class Person 
       :enters value in empid
RETURN: void
*/

  void Teacher:: store()
{
  Person:: store();
  cout<<"Enter employee ID: ";
  cin>>empid;
}


/*
FORMAL PARAMETER: NULL
PURPOSE:calls display() function of base class Person 
       :displays value of empid
RETURN: void
*/

  void Teacher:: display() const
{
  Person:: display();
  cout<<"EmpID  : ";
  cout<<empid<<endl;
}
       

/*
DATA MEMBERS    : rno      : integer
MEMBER FUNCTIONS: store(),display(), ~Student()
*/ 

 class Student : public Person
{
  protected:
  int rno;

  public:

  Student()
  {
   cout<<"**** CONSTRUCTOR of Student CALLED ****\n";
  }
  ~Student()
  {
    cout<<"\n**** DESTRUCTOR of Person CALLED ****\n";
  }
  virtual void store();
  virtual void display() const;
};


/*
FORMAL PARAMETER: NULL
PURPOSE:calls store() function of base class Person 
       :enters value in rno
RETURN: void
*/

  void Student:: store()
{
  Person:: store();
  cout<<"Enter roll no.   : ";
  cin>>rno;
}


/*
FORMAL PARAMETER: NULL
PURPOSE:calls display() function of base class Person 
       :displays value of rno
RETURN: void
*/

  void Student:: display() const
{ 
  Person:: display();
  cout<<"RollNo : ";
  cout<<rno<<endl;
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
	cout<<"-------------------------------------------------------------------------------\n\n";
	cout<<" \t \t ******** WELCOME TO THE PROGRAM *********"<<endl;
   
	   Person* objptr;
	cout<<"\n A pointer 'objptr'  has been created !!! \n";
	cout<<" \tThis pointer 'objptr' is able to point to an object of Person class";
 do{
	     cout<<"\n-------------------------------------------------------------------------------\n\n";
   cout<<"1. To point 'objptr' to a object of Person class \n";
   cout<<"2. To point  'objptr' to a object of Teacher class ( derived from Person )\n";
   cout<<"3. To point  'objptr' to a object of Student class ( derived from Person )\n";
   cout<<"4. Exit\n";

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
	}while(choice<1||choice>4);

   switch(choice)
   {
     case 1:
     cout<<"\n-------------------------------------------------------------------------------\n";
     objptr = new Person;
     cout<<"\nThe pointer is now POINTING to a OBJECT of 'Person'\n";
     cout<<"\nEnter data for PERSON:\n";
     objptr->store(); 
     cout<<"\nDisplaying data for Person:\n";
     objptr->display();
     cout<<"\n";
     delete objptr;
     cout<<"\n-------------------------------------------------------------------------------\n";     
     break;

     case 2:
     cout<<"\n-------------------------------------------------------------------------------\n";
     objptr = new Teacher;
     cout<<"\nThe pointer is now POINTING to a OBJECT of 'Teacher'\n";
     cout<<"\nEnter data for TEACHER:";
     objptr->store(); 
      cout<<"\nDisplaying data for Teacher:";
     objptr->display();
     delete objptr;
     cout<<"\n-------------------------------------------------------------------------------\n";     
     break;
 
     case 3:
     cout<<"\n-------------------------------------------------------------------------------\n";     
     objptr = new Student;
     cout<<"\nThe pointer is now POINTING to a OBJECT of 'Student'\n";
     cout<<"\nEnter data for STUDENT:";
     objptr->store(); 
      cout<<"\nDisplaying data for Student:";
     objptr->display();
     delete objptr;
     cout<<"\n-------------------------------------------------------------------------------\n";     
     break;

     case 4:
     cout<<"-------------------------- EXITING ----------------------------\n\n";
     exit(0);
     
   }
  
	cout<<"\n want more operations ( y/n ) : ";
	cin>>ch;
}while(toupper(ch)=='Y') ;

return 0;
}

