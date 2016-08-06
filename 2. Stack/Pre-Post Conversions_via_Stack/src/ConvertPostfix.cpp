#include "ConvertPostfix.h"
#include<iostream>
#include<cstring>
#include "Stack.h"
#include "MyException.h"


using namespace std;

ConvertPostfix::ConvertPostfix()
{
    //ctor
}

bool ConvertPostfix::is_operator(char ch)
 {
   return(ch=='+'||ch=='-'||ch=='/'||ch=='*');
 }

 bool ConvertPostfix::is_operand(char ch)
 {
   return((ch>='a'&& ch<='z')||(ch>='A' && ch<='Z'));
 }

 bool ConvertPostfix::checkPrepost(char op1, char op2)                //returns true if precedence of op1 > op2
 {
   if((op1=='*' || op1=='/') && (op2=='*'||op2=='/'))
     return false ;
   else if((op1=='+' || op1=='-') && (op2=='+'||op2=='-'))
      return false;
else if((op1=='+' || op1=='-') && (op2=='/'||op2=='*'))
      return false;
   else //if((op1=='*' || op1=='/') && (op2=='+'||op2=='-'))
      return true;

 }


 char* ConvertPostfix::infix_to_postfix(char* infix)
 {
   int length = strlen(infix);

   Stack<char> operand_stack(length);
   Stack<char> operator_stack(length/2);
   int i;

   for(i=0;i<length;i++)
   {
     if(is_operand(infix[i]))
     {
       operand_stack.push(infix[i]);
     }

     else if(is_operator(infix[i]))
     {
       if(operator_stack.isEmpty())
	 operator_stack.push(infix[i]);

     else  if(checkPrepost(infix[i],operator_stack.element_at_top()))
       {
	 operator_stack.push(infix[i]);
       }
       else
       {
	 do{
	   operand_stack.push(operator_stack.pop());
	}while(!operator_stack.isEmpty() && !checkPrepost(infix[i],operator_stack.element_at_top()) );

	 operator_stack.push(infix[i]);
       }
    }
   }

   while(!operator_stack.isEmpty())
    operand_stack.push(operator_stack.pop());


   char* prefix = new char[length];

   i=length-1;
   while(!operand_stack.isEmpty())
   {
     prefix[i]= operand_stack.pop();
     i--;
   }

   prefix[i] = '\0';

   return prefix;
 }

char* ConvertPostfix::postfix_to_infix(char* postfix)
 {

   int length = strlen(postfix);

   Stack<char> operand_stack(length);
   Stack<char> operator_stack(length/2);
   int i;

   for(i=length-1;i>=0;i--)
   {

      if(is_operator(postfix[i]))
      {
	 operator_stack.push(postfix[i]);
      }
       else if(is_operand(postfix[i]))
     {
       operand_stack.push(postfix[i]);
        if(!operator_stack.isEmpty())
	{
	  operand_stack.push(operator_stack.pop());
	}
     }
   }

   char* infix = new char[length];

   i=0;
   while(!operand_stack.isEmpty())
   {
     infix[i]= operand_stack.pop();
     i++;
   }

   infix[i] = '\0';

   return infix;
 }


 int ConvertPostfix::postfixEva(char* postfix)
 {
  int length = strlen(postfix);

   Stack<int> operand_stack(length);
   int i;

   for(i=0;i<length;i++)
   {
     if(is_operand(postfix[i]))
     {
     operand_stack.push(getvalue(postfix[i]));
     }

     else if(is_operator(postfix[i]))
     {
     operand_stack.push( performOp(operand_stack.pop(),operand_stack.pop(),postfix[i]));
     }
    }

   return operand_stack.pop();
 }


int ConvertPostfix::getvalue(char op)
{
int value;
cout<<" Enter value of "<<op<<": ";
cin>>value;
return value;
}

int ConvertPostfix::performOp( int a,int b, char Op)
{

if(Op=='+')
{
return a+b;
}

else if(Op=='-')
{
return a-b;
}
else if(Op=='/')
{
return a/b;
}
else if(Op=='*')
{
return a*b;
}
else
{
cout<<"error";
return 0;
}

}
