#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;

 long int one_comp(long int a)
{
   long int res=0;
   int d,i=0;

   while(a!=0)
   {
     d = a%10;
     a = a/10;

     if(d==0)
     res+= pow(10,i);
     
     i++;
   }

   return res;
}


long int add(long int a, long int b, char mode='A')
{
  int d1,d2,carry=0,n=0,sum[10];
  long int res=0;  

   while(a!=0 || b!=0)
    {
       d1 = a%10;
       a = a/10;

       d2 = b%10;
       b = b/10;
      
       if(carry==0)
        {
           if(d1==0 && d2==0)
            {
              sum[n] = 0;
              carry = 0;
            }
           else if((d1==0 && d2==1) || (d1==1 && d2==0))
            {
              sum[n] = 1;
              carry = 0;
            }
           else
            {
              sum[n] = 0;
              carry = 1;
            }
         }
        else
         {
           if(d1==0 && d2==0)
            {
              sum[n] = 1;
              carry = 0;
            }
           else if((d1==0 && d2==1) || (d1==1 && d2==0))
            {
              sum[n] = 0;
              carry = 1;
            }
           else
            {
              sum[n] = 1;
              carry = 1;
            }
         }
         n++;        
      }

        if(carry==1 && mode=='A') // in 2's complement subtraction, carry is to be ignored
          sum[n] = 1;
        else
          sum[n] = 0;           // the array sum stores the result in reverse order
      
      
        for(int i=0;i<=n;i++)       
       res = res+ pow(10,i)*sum[i];        //since the array is reverse order
   
      return res;
}


 long int subtract(long int a,long int b)
{
   long c;
   c = one_comp(b);
   c = add(c,1);
   long res = add(a,c,'S');
   return res;
}



 int main()
{
  long int a,b;
  int ch;
  char opt;
    
  cout<<"\n";

 do{
  cout<<"Operations on binary numbers\n";
  cout<<"1.Enter two numbers\n";
  cout<<"2.Add the numbers\n";
  cout<<"3.Subtract the numbers\n";
  cout<<"4.Exit\n";
  cout<<"\nEnter ur choice: ";
  cin>>ch;
  
 

  switch(ch)
{
  
   case 1:
   cout<<"Enter A: ";
   cin>>a;
   cout<<"Enter B: ";
   cin>>b;
   break;

   case 2:
   cout<<"\nA + B: "<<add(a,b)<<endl;
   break;

   case 3:  
   cout<<"\nA - B: "<<subtract(a,b)<<endl;
   break;

   case 4: exit(0);
   break;

   default: cout<<"Please enter a valid choice\n";

 }
  cout<<"\nDo you wish to continue(Y/N): ";
  cin>>opt;

 }while(opt=='y'|| opt=='Y'); 


return 0;

}

