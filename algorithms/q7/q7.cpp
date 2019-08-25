#include<iostream>
#include<cstring>
using namespace std;
int c[20][20];
char b[20][20];	
void lcs_length(string x,string y,int m,int n)
{
	for (int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			b[i][j]='0';
	for (int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			c[i][j]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{	
			if(x[i-1]==y[j-1])
			{
				c[i][j]=(c[i-1][j-1]+1);
				b[i][j]='*';
			}
			else if (c[i-1][j]>= c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]='|';
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]='-';
			}
		}
	}
	cout<<"\nB matrix is : \n";
	for (int i=1;i<=m;i++)
	{	for(int j=1;j<=n;j++)
			cout<<b[i][j];cout<<endl;}
	cout<<endl;
	cout<<"\nC matrix is : \n";
	for (int i=0;i<=m;i++)
	{	for(int j=0;j<=n;j++)
			cout<<c[i][j];cout<<endl;}
	
	
}

int print_lcs(char b[20][20],string x,int i,int j)
{
	if (i==0 || j==0)
		return 0;
	if (b[i][j]=='*')
	{
		print_lcs(b,x,i-1,j-1);
		cout<<x[i-1]<<" ";
	}
	else if(b[i][j]=='|')
		print_lcs(b,x,i-1,j);
	else print_lcs(b,x,i,j-1);		
}

int main()
{ 
	string x,y;
	int m,n;
	cout<<"Enter 1st string : ";
	cin>>x;
	cout<<"Enter 2nd string : ";
	cin>>y;
	m=x.length();
	n=y.length();
	lcs_length(x,y,m,n);
	cout<<"\nLCS is : ";
	print_lcs(b,x,m,n);
	cout<<endl;
	return 0;
}

