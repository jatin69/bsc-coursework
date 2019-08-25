#include "ConvertPrefix.h"
#include<iostream>
#include<cstring>
#include "Stack.h"
#include "MyException.h"


using namespace std;


ConvertPrefix::ConvertPrefix()
{

}

bool ConvertPrefix::is_operator(char ch)
 {
   return(ch=='+'||ch=='-'||ch=='/'||ch=='*');
 }

 bool ConvertPrefix::is_operand(char ch)
 {
   return((ch>='a'&& ch<='z')||(ch>='A' && ch<='Z'));
 }

 bool ConvertPrefix::checkPre(char op1, char op2)                //returns true if precedence of op1 > op2
 {
   if((op1=='+' || op1=='-') && (op2=='/'||op2=='*'))
     return false;
   else
     return true;
 }


 char* ConvertPrefix::infix_to_prefix(char* infix)
 {
   int length = strlen(infix);

   Stack <char> operand_stack(length);
   Stack <char> operator_stack(length/2);
   int i;

   for(i=length-1;i>=0;i--)
   {
     if(is_operand(infix[i]))
     {
       operand_stack.push(infix[i]);
     }

     else if(is_operator(infix[i]))
     {
       if(operator_stack.isEmpty())
	 operator_stack.push(infix[i]);

     else  if(checkPre(infix[i],operator_stack.element_at_top()))
       {
	 operator_stack.push(infix[i]);
       }
       else
       {
	 do{
	   operand_stack.push(operator_stack.pop());
	}while(!operator_stack.isEmpty() && !checkPre(infix[i],operator_stack.element_at_top()) );

	 operator_stack.push(infix[i]);
       }
    }
   }

   while(!operator_stack.isEmpty())
    operand_stack.push(operator_stack.pop());


   char* prefix = new char[length];

   i=0;
   while(!operand_stack.isEmpty())
   {
     prefix[i]= operand_stack.pop();
     i++;
   }

   prefix[i] = '\0';

   return prefix;
 }

char* ConvertPrefix::prefix_to_infix(char* prefix)
 {
   int length = strlen(prefix);

   Stack<char> operand_stack(length);
   Stack<char> operator_stack(length/2);
   int i;

   for(i=0;i<=length-1;i++)
   {

      if(is_operator(prefix[i]))
      {
	 operator_stack.push(prefix[i]);
      }
       else if(is_operand(prefix[i]))
     {
       operand_stack.push(prefix[i]);
        if(!operator_stack.isEmpty())
	{
	  operand_stack.push(operator_stack.pop());
	}
     }
   }

   char* infix = new char[length];

   i=length-1;
   while(!operand_stack.isEmpty())
   {
     infix[i]= operand_stack.pop();
     i--;
   }

   infix[i] = '\0';

   return infix;
 }
