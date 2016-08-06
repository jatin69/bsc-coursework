/* command line arguments counting occurences of each alphabet */
 
  #include<iostream>
#include<cstring>
using namespace std;
void disp(int []);
int a[26];
int main(int argc, char* argv[])
{ char temp;

for(int i=1; i<argc; i++)
{
	for(int j=0 ;j<strlen(argv[i]);j++)
	{ 	 temp=tolower(argv[i][j]);
	if(temp>=97 && temp<=122 )
		a[temp-97]++ ;
	}
}
cout<<"\n---------------------------------------------------------------------------\n";

disp(a);

cout<<"---------------------------------------------------------------------------\n";
return 0;
}


void disp(int a[26])
{ cout<<"\tALPHABET   |     NO. of occurences"<<endl;
for(int i=0 ; i<=26 ; i++)
if(a[i]>0)
cout<<"\t "<<char(i+97)<<"\t   |       "<<a[i]<<endl;
}
