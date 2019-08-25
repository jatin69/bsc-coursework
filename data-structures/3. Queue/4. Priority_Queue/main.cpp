#include <iostream>
#include "cstdlib"
#include "PriorityQueue.h"
#include "MyException.h"
using namespace std;

int main()
{
    //Queue <int> queue_ob(3);
    PriorityQueue <int> queue_ob(5);
int ele,ch;
 do{

   cout<<"\n----------------------- PRIORITY QUEUE OPERATIONS ----------------------------------\n\n";
   cout<<"1. Insert an element in Queue \n";
   cout<<"2. delete an element from Queue \n";

   cout<<"3. Display all elements of Queue\n";
   cout<<"4. Clear Queue\n";

   cout<<"5. Exit\n";
   cout<<"\nEnter choice: ";
   cin>>ch;
   cout<<"--------------------------------------------------------------------------";
   switch(ch)
   {
      case 1:
      {
      cout<<"\n\nEnter the element  : ";
      cin>>ele;
      queue_ob.EnQueue(ele);
      //cout<<"Element inserted !! "<<endl;
      }
        break;

	  case 2:
	  {
	     try{
	          queue_ob.DeQueue();
      //cout<<"\n\nElement deleted !! "<<endl;
        }
        catch(MyException ob)
        {
            cout<<"\n";
            ob.printerror();
        }
      }
        break;

      case 3:
      {
          try{
                cout<<"\n";
                queue_ob.Display();
                cout<<"\n";
          }

        catch(MyException ob)
        {
            ob.printerror();
        }
	  }
        break;

	  case 4:
	  {
	      try{
	      queue_ob.ClearQueue();
      cout<<"\n\nQueue cleared !! ";
	      }

        catch(MyException ob)
        {
            ob.printerror();
        }
      }
        break;

    case 5:
      cout<<"\n\nExit requested by user ,, Exiting .. .. \n";
      exit(0);
   }

 }while(1);

  cout<<"\n--------------------------------------------------------------------------\n";
   return 0;
}
