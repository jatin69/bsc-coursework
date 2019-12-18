#include <iostream>
#include "priority_queue.h"
#include "cstdlib"

using namespace std;

int main()
{
    int choice,Size;

    cout<<"\n\t\t\tPRIORITY QUEUE\t\t\t\t \n";
    cout<<"\nEnter Size of Array: ";
    cin>>Size;

    priority_queue Q1(Size);
    do
    {
        cout<<"\n---------------------------------------------------------------------\n\n";
        cout<<"\t1. Insert element\n";
        cout<<"\t2. Display MAX\n";
        cout<<"\t3. Extract MAX\n";
        cout<<"\t4. Display array\n";
        cout<<"\t5. Exit\n";
        cout<<"\n Enter choice: ";
        cin>>choice;
        cout<<"\n--------------------------------------------------------------------------";
        switch(choice)
        {
        case 1:
        {
            int element;
            cout<<"\n Enter the element :";
            cin>>element;
            Q1.max_heap_insert(element);
        }
        break;

        case 2:
        {
            cout<<"\n Max element is :";
            int result= Q1.heap_maximum();
            if(result!=-1)
            {
                cout<<result;
            }

        }
        break;


        case 3:
        {
            cout<<"\n Extracted Max element is :";
            int result= Q1.heap_extract_max();
            if(result!=-1)
            {
                cout<<result;
            }
        }
        break;

        case 4:
        {
            cout<<"\nHeap in the Array form is : ";
            Q1.display();
        }
        break;

        case 5:
        {
            cout<<"\n\t ********** User requested exit **********";
            cout<<"\n\n\tExiting ..  ..";
            cout<<"\n\n------------------------------------------------------------------------------\n";
            exit(0);
        }
        }

    }
    while(1);

    cout<<"\n--------------------------------------------------------------------------\n";
    return 0;

    return 0;
}
