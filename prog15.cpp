/*Create a file that contains records of 5 employees. Each record contains an employee’s
salary details. Print the information retrieved from the filw in the following format:
EId
Name
Basic
HRA
DA
Extra Allowances
*/


#include<iostream>
#include<fstream>

using namespace std;

class Employee
{ 	long int EId, Basic, HRA, DA, ExtraAllowance;
 	char Name[20];
 	public:
	 void enterdetails();
	 void dispdetails();
};

void Employee::enterdetails()
{	 cout<<"EId\t\t ";cin>>EId;
 	cout<<"Name\t \t ";cin>>Name;
	cout<<"Basic\t\t ";cin>>Basic;
	cout<<"HRA\t \t ";cin>>HRA;
	cout<<"DA\t\t ";cin>>DA;
	cout<<"Extra Allowance\t ";cin>>ExtraAllowance;
 }

void Employee::dispdetails()
{ 
cout<<EId<<" \t "<<Name<<" \t "<<Basic<<" \t "<<HRA<<" \t "<<DA<<"\t  "<<ExtraAllowance<<endl;
}

int main()
{
	fstream ob;
	Employee E;
	int i;
	ob.open("file.dat",ios::out);	
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"************************* EMPLOYEE FILE OPEN ***************************\n";
	for(i=0;i<5;i++)
	{	cout<<"\nEnter the following details respectively for employee "<<i+1<<":\n";
		 E.enterdetails();
	    ob.write((char*)&E,sizeof(E));
	}

	ob.close();

	ob.open("file.dat",ios::in);
	cout<<"\n\n************************* DISPLAYING RECORDS FROM EMPLOYEE FILE  ***************************\n";
	cout<<"EId\t Name\t Basic\t HRA\t DA\tExtraAllowance \n";
	
	for(i=0;i<5;i++)
	{	ob.read((char*)&E,sizeof(E));
		
		E.dispdetails();
	}

	ob.close();
	cout<<"\n-------------------------------------------------------------------------------\n\n";
	return 0;
}
