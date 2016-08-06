#include "Recursion.h"

/// Time complexity is O(n)
long Recursion:: factorial(unsigned int n)
{
  if(n==1)
    return 1;
  else
    return n * factorial(n-1);
}

/// Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential
/// so , recursive fibonacci is avoided
int Recursion:: fibo(int n)
 {
   if(n<=1)
     return 1;
     return (fibo(n-1)+fibo(n-2));
 }

 int Recursion:: gcd(int x,int y)
 {
   if(y==0)
     return x;
   else
     return gcd(y,x%y);
 }


 long Recursion::multiply(int a, int b)
 {

   if(a==1)
     return b;

   if(b==1)
     return a;

   if(a%2==0 && b%2==0)
     return (4* multiply(a/2,b/2));

   else if(a%2==0 && b%2!=0)
     return (2* multiply(a/2,b-1)) + a ;

   else if(b%2==0 && a%2!=0)
     return (2* multiply(b/2,a-1)) + b ;

   else
     return( multiply(a-1,b-1) + a + b -1);
 }


/// time complexity :   O(log n)
long Recursion:: power(int x, unsigned int y)
{
    if(x==0)
        return 0;

    if( y == 0)
        return 1;

    long int temp;
    temp = power(x, y/2);

    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

