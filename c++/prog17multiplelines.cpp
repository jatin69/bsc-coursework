//Copy the contents of one text file to another file, after removing all whitespaces.


// the doubt is written at end of prog.

#include<iostream>
#include<fstream>
using namespace std;

int main()
{ 	
	char st[1000];
	char ch;

	ifstream iob;
	ofstream oob;

// here.. i create a file

	cout<<"\n---------------------------------------------------------------------------\n";
 	cout<<"\n\t   ***************** WELCOME TO THE PROGRAM ******************\n";
 	cout<<"\nCreating FILE 1  :\n";
	oob.open("file1.txt");
	cout<<"\nEnter the text and press '0' followed by 'enter' to exit : \n";
	cin.getline(st,1000,'0');
	oob<<st;
 	oob.close();

// file1 is created by now ..
	
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
	
// this code below is for verification whether the file is correctly copied or not ..
	
	iob.open("file2.txt");			
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

/*
sir .. here the prob. is ..
if the terminating char.( i.e 0 here ) comes just next to the last  entered char. .. then the last char. is printed twice

to solve this manually ..
a solution is to -- tap a space after the last char. then terminating char. then press enter ..

THIS SOLVES THE PROB. BUT THE USER MAY NOT BE KNOWING THIS BUG ..
SO IT IS IMP. TO REMOVE IT 

plzz .. 
provide these two inputs to see wats happening :

CASE 1: "jatin0"   ( as 0 is terminating char. here )
CASE 2: "jatin 0"  ( notice space after last char. )

*/
