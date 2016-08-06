#include <iostream>
using namespace std;

class selecsort
	{
		int *a;
	    int n,exchange;
	    public:
	     selecsort();
	    ~selecsort();
	    void getdata();
	    void showdata();
	    int sortLogicasc();
	    int sortLogicdes();
	};

/*
FORMAL PARAMETER: none
PURPOSE: it is a constructor to initialize values and allocate space for new array
RETURN: none ( not even void )
*/

 selecsort :: selecsort()			
{   exchange=0;
    cout<<"\nHow many ELEMENTS you require : ";
    cin>>n;
    a=new int[n];
    for(int i=0;i<n;i++)
        *(a+i)=0;
}

/*
FORMAL PARAMETER: none
PURPOSE:  destructor to deallocate space
RETURN: none ( not even void )
*/

 selecsort :: ~selecsort()			
{   
	delete []a;
}


/*
FORMAL PARAMETER: none
PURPOSE:  to take values of array from user
RETURN: void
*/
void selecsort :: getdata()
{
    cout<<"\nPlease enter "<<n<< " ELEMENTS : \n";
      for(int i=0;i<n;i++)
        cin>>*(a+i);
}

/*
FORMAL PARAMETER: none
PURPOSE:  to display values of array 
RETURN: void
*/
void selecsort :: showdata()
{
    cout<<"\n\nSORTED ARRAY is : \n";
    for(int i=0;i<n;i++)
        cout<<*(a+i)<<"\n";
}


/*
FORMAL PARAMETER: none
PURPOSE:  to sort the array in ASCENDING ORDER using selection sort logic and return the total no. of exchanges that took place
RETURN: integer
*/
int selecsort :: sortLogicasc()
{
    int i,j,temp,min_at,min;
    
	for( i=0;i<n-1;i++)
	{	
		min=*(a+i);
		min_at=i;
		
	for( j=i+1;j<n;j++)
	{
		if(*(a+j)<min)
		{
			min=*(a+j);
			min_at=j;
		}
	}
	 
		 temp = *(a+i);
		 *(a+i) = *(a+min_at);
		 *(a+min_at) = temp;
		 exchange++;
	}

return exchange;
}

/*
FORMAL PARAMETER: none
PURPOSE:  to sort the array in DESCENDING ORDER using selection sort logic and return the total no. of exchanges that took place
RETURN: integer
*/
int selecsort :: sortLogicdes()
{
    int i,j,temp,max_at,max;    

	for( i=0;i<n-1;i++)
	{	
		max=*(a+i);
		max_at=i;
		
	for( j=i+1;j<n;j++)
	{
		if(*(a+j)>max)
		{
			max=*(a+j);
			max_at=j;
		}
	}
	 
		 temp = *(a+i);
		 *(a+i) = *(a+max_at);
		 *(a+max_at) = temp;
		 exchange++;
	}

return exchange;
}

/*
FORMAL PARAMETER: none
PURPOSE:  to call all the required func. and execute the required operations
RETURN: int
*/

int main()
{  	cout<<"==============================================================================\n\n";
	cout<<"\t\t******** WELCOME TO BUBBLE SORT  *********"<<endl; 
	 selecsort ob;
	  int exchanges,choice;
	    ob.getdata();
	cout<< "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  cout<<"\n 1. Sort in ASCENDING ORDER "; 
	  cout<<"\n 2. Sort in DESCENDING ORDER \n";
	  cout<<"\n Enter ur choice : ";cin>>choice;	 
	cout<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	if(choice==1)
	{	exchanges=ob.sortLogicasc(); }
	if(choice==2)
	{	exchanges=ob.sortLogicdes(); } 
	   
	if(exchanges==0)
	    {
		 cout<<" \n\t****** ARRAY IS ALREADY IN SORTED ORDER !!! ******\n";
	    }
	    else
	    { 
		cout<<" \n\t****** ARRAY HAS BEEN SORTED !!! ******";
		cout<<"\nTotal no. of EXCHANGES that took place are : "<<exchanges;
		ob.showdata();
	    }
	cout<<"\n==============================================================================\n";
return 0;
}
