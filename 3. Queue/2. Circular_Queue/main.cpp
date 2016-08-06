#include <iostream>
#include "cstdlib"
#include "CircularQueue.h"
using namespace std;

int main()
{
    CircularQueue <int> queue_ob(5);
int ele,ch;
char opt;
 do{

   cout<<"\n----------------------- CIRCULAR QUEUE OPERATIONS ----------------------------\n\n";
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
     // cout<<"Element inserted !! "<<endl;
      }
        break;

	  case 2:
	  {
	      queue_ob.DeQueue();
     // cout<<"\n\nElement deleted !! "<<endl;
      }
        break;

      case 3:
      {
      cout<<"\n\nElements of Queue are : \n";
      queue_ob.Display();
	  }
        break;

	  case 4:
	  {
	      queue_ob.ClearQueue();
      cout<<"\n\nQueue cleared !! ";
      }
        break;

    case 5:
      cout<<"\n\nExit requested by user ,, Exiting .. .. \n";
      exit(100);
   }

   cout<<"\n--------------------------------------------------------------------------";
   cout<<"\nDo you wish to continue: ";
   cin>>opt;

 }while(opt=='y'||opt=='Y');

  cout<<"\n--------------------------------------------------------------------------\n";
   return 0;
}
