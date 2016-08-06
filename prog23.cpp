// operations on box class

#include <iostream>
#include<cstdio>                 
using namespace std; 

class BOX {
	        double length,breadth,height;
		    public:
 		 void getdata();
		 friend bool operator==(BOX& , BOX& );
		 double calcvolume();
		 void operator+( BOX&);
		 void operator=(BOX&);
		 void iscube();
		 void show();

		BOX() 
	   	{
			length=0;breadth=0;height=0;
	   	}

		BOX( BOX &ob1)
		{  cout<<"The copy constructor is being called !!!  ";
		  length = ob1.length;
		  breadth = ob1.breadth;
		  height = ob1.height;
		}
			

		
	 };

	void BOX::getdata()
	 {
	 	cout<<"\nENTER THE length :  ";
	 	cin>>length;
	 	cout<<"ENTER THE breadth :  ";
		cin>>breadth;
	 	cout<<"ENTER THE height :  ";
	 	cin>>height;
	 }

          	
	void BOX::show()
	 {
  		cout<<"\nDIMENSIONS OF BOX ARE";
		cout <<"\n length :  "<<length ;
		cout <<"\n breadth :  "<<breadth;
	        cout <<"\n height :  "<<height<<endl ;
	}

    	double BOX::calcvolume()
    	{
    		return(length*breadth*height);
    	}

	void BOX::operator+(BOX &ob2)
 	{
	         
 		 BOX temp;
  		temp.length = length + ob2.length;
  		temp.breadth = breadth + ob2.breadth;
  		temp.height = height + ob2.height;
   		temp.show();
	}
	
	bool operator==(BOX&  ob1 , BOX& ob2)
 		{
		   return((ob1.length==ob2.length)&&(ob2.breadth==ob1.breadth)&&(ob2.height==ob1.height));
               	}

	void BOX::operator=(BOX& ob2)
 		{ 
		  length = ob2.length;
		  breadth= ob2.breadth;
		  height = ob2.height;
		  
		}

	void BOX::iscube()
	{
		if(length==breadth==height)
		  cout<<"\nBOX WITH THESE DIMENSIONS IS CUBE\n";
		else
		  cout<<"\nBOX WITH THESE DIMENSIONS IS  CUBOID\n";	
	}
	
	void copycall(BOX& ob1)
	{ 	
		BOX ob3(ob1);
	}
		
BOX ob2,ob1;

int main()
{  
	

	char ch;
	int choice;
	cout<<"-------------------------------------------------------------------------------\n\n";
	cout<<" \t \t ******** WELCOME TO BOX OPERATIONS *********"<<endl;

	 cout<<"\nENTER DATA FOR FIRST BOX :\n";
	 ob1.getdata();
         
do{
	 	
	cout<<"-------------------------------------------------------------------------------\n\n";
	cout<<" 1:CALCULATE THE VOLUME OF A BOX"<<endl;
	cout<<" 2:CHECK THE BOX FOR CUBE & CUBOID"<<endl;
	cout<<" 3:ADDITION OF TWO BOXES  "<<endl;
	cout<<" 4:CHECK EQUALITY OF BOXES "<<endl;
	cout<<" 5:ASSIGNMENT OF ONE BOX TO OTHER"<<endl;
	cout<<" 6:CREATION OF A NEW BOX  BY COPYING BOX 1 ( by using copy constructor  )"<<endl<<endl;
	
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

	if((choice>=3)&&(choice<=5))
	{	cout<<"\nENTER DATA FOR SECOND OBJECT \n";
  	  	ob2.getdata();
	}

	switch(choice)
	{	
	
	case 1 : 
		 cout<<"\n volume: "<<ob1.calcvolume();
		  break;
	case 2 :			
		  ob1.iscube();
		  break;
	case 3:	
		cout<<"\nADDITION TAKING PLACE !!! \n";
		ob1.operator+(ob2);
       		 break;
	case 4: 	 
 		 if(operator==(ob1,ob2))
		     cout<<"\n BOXES ARE EQUAL !!!\n ";
		 else 
			 cout<<"\n BOXES ARE NOT EQUAL !!!\n";	
		 break;
	case 5: 	
		ob1.operator=(ob2);
		cout<<"\nObject successfully copied !!! \n";
		cout<<"\nNOW , ";
		ob1.show();
		 break;
	
	case 6: 
		copycall(ob1);
		cout<<"\nNew Box  created !!!\n";
		break;
	
	
	}	
	
	cout<<"\n want more operations ( y/n ) : ";
	cin>>ch;
	cout<<"\n-------------------------------------------------------------------------------\n";
}while(toupper(ch)=='Y') ;

return 0;
}

