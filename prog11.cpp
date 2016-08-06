/* wap to perform all the array operations */

#include<iostream>
using namespace std;              

class Array
{    
		  int i,j,temp,SIZE, check  ;
		  float sum ,avg;
		  int *a;	
		  public:
		  Array();
		 ~Array();
		  void getsize();		  
		  void getarray();        // PROTOTYPE OF ALL FUNCTIONS
		  void printarray();
		  void printeven();
		  void printodd();
		  void printsum();
		  void removeduplicate();
		  void reversearray();
}object;

// ALL FUNCTIONS ARE BELOW

Array::Array()
{
	  i=1;
	  j=1;
	  check=0;
	  sum=0.0;
	  avg=1.0; 
}

Array::~Array()
{ delete []a; }

void Array::getsize()
{
	cout<<"\nEnter the number of elements in array : ";
	cin>>SIZE;
	a=new int[SIZE];
	for(i=0;i<SIZE;i++)
	  *(a+i)=0;

}
void Array::getarray()
{       getsize();
	cout<<"\nEnter the "<<SIZE<<"  elements : "<<endl;
	for(i=0; i<SIZE ; i++)
  	cin>>*(a+i);  
	check++;
}

void Array::printarray()
{ 
   cout<<"Now the elements of the array are :"<<endl;
   for(i=0; i<SIZE ; i++)
   cout<<*(a+i)<<endl; 
}

void Array::printeven()
{ 
	 if(check)
	{	cout<<" The even valued elements are : "<<endl;
		  for(i=0; i<SIZE ; i++)
		  { 	 if(*(a+i)%2==0)
		  	cout<<*(a+i)<<"\t";
		  }
	}
	else
	{
		cout<<"Array is empty !!! \n";
	}
}

void Array::printodd()
{       
	if(check)
	{	cout<<" The odd valued elements are : "<<endl;
	    	for(i=0; i<SIZE ; i++)
	    	{	  if(!(*(a+i)%2==0))
			  cout<<*(a+i)<<"\t";
	    	}
	}
	else
	{
		cout<<"Array is empty !!! \n";
	}
}
void Array::printsum()
{  
 	  if(check)
	{  for(i=0; i<SIZE ; i++)
      		sum+=*(a+i);
       		avg=sum/SIZE;
     
		printarray();
		cout<<" sum is : "<<sum;
		cout<<" avg is : "<<avg;
	}

	else
	{
		cout<<"Array is empty !!! \n";
	}
}

void Array::reversearray()
{ 
       if(check)
	{  cout<<"reversearrayersed array is :"<<endl;
		  for(i=0,j=SIZE-1; i<j  ; i++,j--)
		  { 
		     temp=*(a+i);
		     *(a+i)=*(a+j);
		     *(a+j)=temp;
		   }
     	printarray();
	}

	else
	{
		cout<<"Array is empty !!! \n";
	}
}


void Array::removeduplicate()
{    
  if(check)
{ 
	for( i=0; i<SIZE ; i++)
	{	
		
		for( j=i+1; j<SIZE ; j++)
		{  	
			if(*(a+i)==*(a+j))
			{  	
				temp=j;
			 	while(temp<SIZE-1)
			  	{ 
				    a[temp]=a[temp+1];
    				    temp++; 
    				}
				SIZE--;
				j--;
			}
		}
	}
	printarray();
}

   else
  {
	cout<<"Array is empty !!! \n";
  }
}

int main()
{  
	
	char ch;
	int choice;
cout<<"-------------------------------------------------------------------------------\n\n";
cout<<" \t \t ******** WELCOME TO ARRAY OPERATIONS *********"<<endl; 
do{
cout<<"\n Enter 1 to enter a new array "<<endl;
cout<<" Enter 2 to print even valued elements of array"<<endl;
cout<<" Enter 3 to print odd valued elements of array "<<endl;
cout<<" Enter 4 to print sum and average of elements of array"<<endl;
cout<<" Enter 5 to remove duplicate elements of array"<<endl;
cout<<" Enter 6 to print array in reverse order "<<endl<<endl;

int counter=-1;
do{ counter++;
if(counter==1)
{
cout<<"\tIncorrect choice !! please try again\n ";
counter=0;
}
cout<<" \nenter ur choice :   ";
cin>>choice;
}while(choice<1||choice>6);

switch(choice)
{

case 1 : 
	  object.getarray();
	  break;
case 2 :		
	  object.printeven();
	  break;
case 3:
	  object.printodd();
	  break;
case 4:  
 	  object.printsum();
	  break;
case 5: 
	 object.removeduplicate();
	 break;
case 6: 
	 object.reversearray();
	 break; 
}

cout<<"\n want more operations ( y/n ) : ";
cin>>ch;
cout<<"\n-------------------------------------------------------------------------------\n";
}while(toupper(ch)=='Y') ;
return 0;
}

