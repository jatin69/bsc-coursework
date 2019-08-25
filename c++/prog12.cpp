#include<iostream>
#include<cstdlib>

using namespace std;

 class MATRIX
	{ 
	  int a[10][10];
	  int i,j,k;
	  int rows,columns;
	  int addcheck(MATRIX);
	  int mulcheck(MATRIX);
	
	  public:
	  MATRIX();
	  MATRIX add(MATRIX);
	  MATRIX subtract(MATRIX);
	  MATRIX multiply(MATRIX);
	  MATRIX trans();
	  void print();
	  void enter();
	
	}ob1,ob2;                     //objects of class MATRIX

  MATRIX :: MATRIX()
 {
   rows=0;
   columns=0;
 }



//Matrix is entered
  void MATRIX:: enter()
  {
    cout<<"\nEnter dimensions: ";
    cout<<"\nRows    : ";cin>>rows;
    cout<<"Columns : ";cin>>columns;
    cout<<"\nOrder of MATRIX is : "<<rows<<" X "<<columns; 
    cout<<" \nNOW .. \nEnter MATRIX : ("<<(rows*columns)<<" elements) \n\n";
 
    for(i=0;i<rows;i++)
    {
      for(j=0;j<columns;j++)
       cin>>a[i][j];
    }
  }


//Matrix is printed
   void MATRIX:: print()
{
  for(i=0;i<rows;i++)
  {
    for(j=0;j<columns;j++)
     cout<<"\t"<<a[i][j];

   cout<<endl;
  }
}


/*
FORMAL PARAMETER: object of class MATRIX
PURPOSE: check whether matricies can be added
RETURN: 1 if matricies can be added
        0 if cannot be added
*/

  int MATRIX:: addcheck(MATRIX ob2)
  {
    return(rows==ob2.rows && columns==ob2.columns);
  }


/*
FORMAL PARAMETER: object of class MATRIX
PURPOSE: check whether matricies can be multiplied
RETURN: 1 if matricies can be multiplied
        0 if cannot be multiplied
*/
   int MATRIX:: mulcheck(MATRIX ob2)
  {
     return(columns==ob2.rows);
  }


/*
FORMAL PARAMETER: object of class MATRIX
PURPOSE: adds two matricies
RETURN: resultant addition MATRIX
*/
   MATRIX MATRIX:: add(MATRIX ob2)
  {  
	MATRIX ob3;

    if(addcheck(ob2))
   {
     	for(i=0;i<rows;i++)
      	{
       		for(j=0;j<columns;j++)
       		 ob3.a[i][j]=a[i][j]+ob2.a[i][j];
        }
    cout<<"\nA+B :\n";
    
    ob3.rows=rows;              
    ob3.columns=columns;

   return ob3;
 
  }
    else
    { 
       cout<<"\nAddition not possible!!\n";
       exit(100);
    }
 } 


/*
FORMAL PARAMETER: object of class MATRIX
PURPOSE: subtracts two matricies
RETURN: resultant subtraction MATRIX
*/  
  MATRIX MATRIX:: subtract(MATRIX ob2)
{  
	MATRIX ob3;
    if(addcheck(ob2))
   {
     	for(i=0;i<rows;i++)
      	{
       		for(j=0;j<columns;j++)
       		 ob3.a[i][j]=a[i][j]-ob2.a[i][j];
        }
    cout<<"\nA-B :\n";
    
    ob3.rows=rows;              
    ob3.columns=columns;

   return ob3;
 
  }
    else
   {
     cout<<"\nSubtraction not possible!!\n";
     exit(100);
   }
    
 } 


/*
FORMAL PARAMETER: object of class MATRIX
PURPOSE: multiplies two matricies
RETURN: resultant multiplication MATRIX
*/
   MATRIX MATRIX:: multiply(MATRIX ob2)
{  
	MATRIX ob3;
  if(mulcheck(ob2))
 {
   
   for(i=0;i<rows;i++)
    {
     for(j=0;j<ob2.columns;j++)
     {
       ob3.a[i][j]=0;
       for(k=0;k<columns;k++)
        ob3.a[i][j]+=a[i][k]*ob2.a[k][j];
     }
    }
   cout<<"\nA X B\n";
   
    ob3.rows=rows;
    ob3.columns=ob2.columns;

   return ob3;
    
 }
 else
  {
   cout<<"Matrix multiplication not possible!\n";
   exit(100);
  }
 
}

/*
INPUT PARAMETER: NULL
PURPOSE: calculates transpose of MATRIX
RETURN: transposed MATRIX
*/
  MATRIX MATRIX:: trans()
 {
	MATRIX ob3;
  cout<<"\nTRANSPOSED MATRIX :\n";
 
   
 for(i=0;i<rows;i++)
  {
    for(j=0;j<columns;j++)
     ob3.a[j][i]=a[i][j];
  }
  
  ob3.rows=columns;
  ob3.columns=rows;
  

 return ob3;
}


/*
INPUT PARAMETER: ch: integer
PURPOSE: calls functions as per requirement
*/

  int main()
{
 char ch;
  int choice;
  MATRIX ob;

  cout<<"-------------------------------------------------------------------------------\n\n";
cout<<" \t \t ******** WELCOME TO MATRIX OPERATIONS *********\n"<<endl; 
do{
  cout<<"1. Enter FIRST MATRIX\n";
  cout<<"2. Enter SECOND MATRIX\n";
  cout<<"3. Display both matrices\n";
  cout<<"4. Add the matrices\n";
  cout<<"5. Subtract the matricies\n";
  cout<<"6. Multiply the matricies\n";
  cout<<"7. Transpose FIRST MATRIX\n";
  cout<<"8. Transpose SECOND MATRIX\n"<<endl;

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


 switch(choice)
 {

  case 1:
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\nEntering A :	\n";
    ob1.enter();
    cout<<"-------------------------------------------------------------------------------\n";
    break;
  
 case 2:
    cout<<"\n-------------------------------------------------------------------------------";
    cout<<"\nEntering B :	\n";
    ob2.enter();
    cout<<"-------------------------------------------------------------------------------\n";
	break;
   
 case 3:
    cout<<"\nA:\n";
    ob1.print();
    cout<<"\nB:\n";
    ob2.print();
    break;
 
 case 4:
   
   ob=ob1.add(ob2);                     
   ob.print();
   break;
 
 case 5:
  
   ob=ob1.subtract(ob2);                
   ob.print();
   break;

 case 6:

   ob= ob1.multiply(ob2);               
   ob.print();
   break;

 case 7:
  
    ob1=ob1.trans();                  
    ob1.print();
    break;

 case 8:
 
    ob2= ob2.trans();                 
    ob2.print();
    break;
 
 } 

cout<<"\n want more operations ( y/n ) : ";
cin>>ch;
cout<<"\n-------------------------------------------------------------------------------\n";
}while(toupper(ch)=='Y') ;

return 0;
}
