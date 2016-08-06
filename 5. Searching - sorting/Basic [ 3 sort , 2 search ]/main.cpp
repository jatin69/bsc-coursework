#include <iostream>
#include "Array.h"
#include "stdlib.h"

using namespace std;

  int main()
{
   int choice,Size,ele,index;

    cout<<"\n======================== WELCOME TO ARRAY OPERATIONS =======================\n";
    cout<<"\nEnter Size of Array: ";
    cin>>Size;
    Array A(Size);
    A.fillarray();

char ch;
 do{
        cout<<"\n=========================================================================\n";
        cout<<"\t1. Display Array\n\n";
        cout<<"\t2. Find an element by linear search \n";
        cout<<"\t3. Find an element by binary search \n\n";
        cout<<"\t4. Sort by bubble sort and display\n";
        cout<<"\t5. Sort by selection sort and display\n";
        cout<<"\t6. Sort by insertion sort and display\n\n";
        cout<<"\t7. Exit\n";
        cout<<"\n Enter choice: ";
        cin>>choice;
        cout<<"\n--------------------------------------------------------------------------";

    switch(choice)
   {
        case 1:
        {
            cout<<"\nArray:";
            A.display();
        }break;
        case 2:
            {
               cout<<"\nEnter element to be searched: ";
                cin>>ele;
                index = A.lsearch(ele);
                if(index!=-1)
                cout<<"\nElement found.";
                else
                cout<<"\nElement not found.";

            }break;

        case 3:
            {
                 cout<<"\nEnter element to be searched: ";
                cin>>ele;
            Array B = A.ins_sort();
            index = B.bsearch(ele);
            if(index!=-1)
            cout<<"\nElement found.";
            else
            cout<<"\nElement not found.";
            }break;

      case 4:
      { Array B = A.bubble_sort();
      cout<<"\nSorted Array:";
      B.display();
      }break;

      case 5:
      { Array B = A.sel_sort();
      cout<<"\nSorted Array:";
      B.display();
      }break;

      case 6:
          {
      Array B = A.ins_sort();
      cout<<"\nSorted Array:";
      B.display();
     } break;

      case 7:
          {     cout<<"\n\t ********** User requested exit **********";
                cout<<"\n\n\tExiting ..  ..";
                cout<<"\n\n------------------------------------------------------------------------------\n";
                exit(0);
          }
   }


cout<<"\n\nwanna continue ??";
cin>>ch;
 }while(ch!='n');

  cout<<"\n--------------------------------------------------------------------------\n";
   return 0;
}


