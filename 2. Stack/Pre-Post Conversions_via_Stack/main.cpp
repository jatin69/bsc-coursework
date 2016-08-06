#include<iostream>
#include<cstring>
#include<cstdlib>
#include "Stack.h"
#include "ConvertPostfix.h"
#include "ConvertPrefix.h"
using namespace std;



 int main()
 {
   char* exp = new char[20];
   char opt;
   int ch;
   ConvertPostfix ob_post;
   ConvertPrefix ob_pre;

 do{

   cout<<"\n----------------------- STACK IMPLEMENTATIONS ----------------------------------\n\n";
   cout<<"1. infix to prefix.\n";
   cout<<"2. prefix to infix.\n";

   cout<<"3. infix to postfix.\n";
   cout<<"4. postfix to infix.\n";
   cout<<"5. postfix evaluation \n";

   cout<<"6. Exit\n";
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"--------------------------------------------------------------------------";
   switch(ch)
   {
      case 1:
      {
      cout<<"\n\nInfix  : ";
      cin>>exp;
      cout<<"Prefix : "<<ob_pre.infix_to_prefix(exp)<<endl;
      }
        break;

	  case 2:
	  {
      cout<<"\n\nPrefix  : ";
      cin>>exp;
      cout<<"Infix : "<<ob_pre.prefix_to_infix(exp)<<endl;
      }
        break;

      case 3:
      {
      cout<<"\n\nInfix  : ";
      cin>>exp;
      cout<<"Postfix : "<<ob_post.infix_to_postfix(exp)<<endl;
	  }
        break;

	  case 4:
	  {
      cout<<"\n\nPostfix  : ";
      cin>>exp;
      cout<<"Infix : "<<ob_post.postfix_to_infix(exp)<<endl;
      }
        break;

 	 case 5:
	 {
     cout<<"\n\nPostfix Evaluation  : ";
     cin>>exp;
     cout<<"Evaluation result : "<<ob_post.postfixEva(exp)<<endl;
 	 }
       break;

      case 6:
      cout<<"\n\nExit requested by user ,, Exiting .. .. \n";
      exit(100);
   }

/*
    //using exception handling
      try{
	cout<<"Prefix : "<<infix_to_prefix(infix);
      }
       catch( Myexception* ob)
      {
	ob->printerror();
      }

*/

   cout<<"\n--------------------------------------------------------------------------";
   cout<<"\nDo you wish to continue: ";
   cin>>opt;

 }while(opt=='y'||opt=='Y');

  cout<<"\n--------------------------------------------------------------------------\n";
   return 0;

 }

