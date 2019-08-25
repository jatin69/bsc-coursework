#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int choice;
	char ch;
	
	do
	{	
                cout<<"\n===================================================================\n";
		cout<<"\n\t\tMENU\t\t\n";
		cout<<"1. Cpu version\n2. Cpu info\n3. Memory info\n4. Exit\n";
		cout<<"\nEnter your choice: ";cin>>choice;
                cout<<"\n\n";
		
		switch(choice)
		{ 	
	
		case 1:	system("awk '{print $1 $2 $3}' /proc/version");
			break;
	
		case 2: system("awk NR==4,NR==5'{print $0}' /proc/cpuinfo");
			break;
		
		case 3:	system("awk NR==2,NR==4'{print $0}' /proc/meminfo");
			break;

                case 4: cout<<"User Requested Exit . . . . \n\n";
                        exit(0);
			break;

		}
	
	}while(1);

			
	return 0;
}
