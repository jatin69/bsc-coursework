#include <iostream>
#include "stdlib.h"
#include "Recursion.h"

using namespace std;

int main()
{
    Recursion R;

    cout<<"\n\n===================== WELCOME TO RECURSIVE OPERATIONS ====================\n\n";
    do{
    cout<<"\n\t\t1. calculate factorial of a number ";
    cout<<"\n\t\t2. calculate fibonacci of a series ";
    cout<<"\n\t\t3. calculate product of two numbers ";
    cout<<"\n\t\t4. calculate GCD of two numbers ";
    cout<<"\n\t\t5. calculate X raised to the power Y ";
    cout<<"\n\t\t6. Exit";
    int choice;
    cout<<"\n\nEnter your choice : ";
    cin>>choice;
    int num1;
    int num2;

    switch(choice)
    {
    case 1:
        {
            cout<<"\n-------------------------------------------------------------------------------";
            cout<<"\nEnter the number for factorial ( upto 30 only ) : ";
            cin>>num1;
            cout<<"\nFactorial of "<<num1<<" is : "<<R.factorial(num1);
            cout<<"\n\n-------------------------------------------------------------------------------";
        }break;
    case 2:
        {
            cout<<"\n-------------------------------------------------------------------------------";
            cout<<"\nEnter no of elements: ";
            cin>>num1;
            cout<<"\nFibonacci upto "<<num1<<" elements:\n\n";
            cout<<"0  ";
            for(int i=0;i<num1-1;i++)
            cout<<R.fibo(i)<<"  ";
            cout<<"\n\n-------------------------------------------------------------------------------";

       }break;
    case 3:
        {
            cout<<"\n-------------------------------------------------------------------------------";
            cout<<"\nEnter first number : ";
            cin>>num1;
            cout<<"\nEnter second number : ";
            cin>>num2;
            cout<<"\nProduct of "<<num1<<" & "<<num2<<" is : "<<R.multiply(num1,num2);
            cout<<"\n\n-------------------------------------------------------------------------------";

        }break;
    case 4:
        {
            cout<<"\n-------------------------------------------------------------------------------";
            cout<<"\nEnter first number : ";
            cin>>num1;
            cout<<"\nEnter second number : ";
            cin>>num2;
            cout<<"\nGCD of "<<num1<<" & "<<num2<<" is : "<<R.gcd(num1,num2);
            cout<<"\n\n-------------------------------------------------------------------------------";
        }break;
    case 5:
        {
            cout<<"\n-------------------------------------------------------------------------------";
            cout<<"\nEnter X : ";
            cin>>num1;
            cout<<"\nEnter Y : ";
            cin>>num2;
            cout<<"\nResult of "<<num1<<" raised to power "<<num2<<" is : "<<R.power(num1,num2);
            cout<<"\n\n-------------------------------------------------------------------------------";
        }break;
    case 6:
        {
            cout<<"\n\t ********** User requested exit **********";
            cout<<"\n\n\tExiting ..  ..";
            cout<<"\n\n------------------------------------------------------------------------------\n";
            exit(0);
        }
    }
    }while(1);

    return 0;
}
