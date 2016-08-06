//Copy the contents of one text file to another file, after removing all whitespaces.

#include<iostream>
#include<fstream>
using namespace std;

int main()
{ 	
	char st[1000];
	char ch;

	ifstream iob;
	ofstream oob;

	cout<<"\n---------------------------------------------------------------------------\n";
 	cout<<"\n\t   ***************** WELCOME TO THE PROGRAM ******************\n";
 	cout<<"\nCreating FILE 1  :\n";
	oob.open("file1.txt");
	cout<<"\nEnter the text  : \n";
	cin.getline(st,1000);
	oob<<st;
 	oob.close();
	
	iob.open("file1.txt");
	oob.open("file2.txt");
	
	while(iob)
	{ 
		iob.get(ch);
                if(iob.eof())
		break;
		if(ch!=' ')
	 	 oob<<ch;
	}

	iob.close();
	oob.close();
	
	iob.open("file2.txt");			// this code is for verification whether the file is correctly copied or not ..
	cout<<" \nFILE 2 is : \n";
	while(iob)
      {
	iob.getline(st,1000);
	cout<<st;
      }
	iob.close();

 	cout<<"\n\n--------------- Content suceessfully copied to FILE 2 !!! ------------------\n\n";
	return 0;
}
