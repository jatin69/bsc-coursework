/*Create a structure Student containing fields for Roll No., Name, Class, Year and Total
Marks. Create 10 students and store them in a file. Write a program to retreive the student
information from file created in previous question and print it in following format.
Roll No. 
Name
Marks
*/

#include<iostream>
#include<fstream>
using namespace std;

struct student
	{
		int roll,cl,year,tot;
		 char Name[20];
	}s;

int main()
{	fstream f;
	int i;

	f.open("file.dat",ios::out);
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"************************* STUDENT FILE OPEN ***************************\n";
	for(i=0;i<10;i++)
	{	cout<<"\nEnter the following details respectively for student "<<i+1<<":\n";
		cout<<"Roll no.\t ";cin>>s.roll;
 		cout<<"Name\t \t ";cin>>s.Name;
		cout<<"class\t\t ";cin>>s.cl;
		cout<<"year\t \t ";cin>>s.year;
		cout<<"total marks\t ";cin>>s.tot;
		f.write((char*)&s,sizeof(s));
	}
	f.close();
	f.open("file.dat",ios::in);

	cout<<"\n\n************************* DISPLAYING RECORDS FROM EMPLOYEE FILE  ***************************\n";
	cout<<"Roll no.  Name\t class\t year\t total marks \n";
	
	for(i=0;i<10;i++)
	{	f.read((char*)&s,sizeof(s));
		cout<<s.roll<<"\t  "<<s.Name<<" \t "<<s.cl<<"\t  "<<s.year<<" \t "<<s.tot<<endl;
	}
	
	f.close();
	cout<<"\n-------------------------------------------------------------------------------\n\n";
	return 0;
}
