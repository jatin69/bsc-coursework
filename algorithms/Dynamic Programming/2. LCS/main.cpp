#include <iostream>
#include <limits.h>
#include <cstring>
using namespace std;

/*
 Here, we know that printing is an optional part
 So, we take 'S' as global to be able to store and print the cuts
 But, the solution of the problem i.e. the maximum profit is compulsory
 So, we return it from the Rod-cut function
*/

// global 2D array 'B' , for storing the "direction symbol"
char **B;

int LCS(char*, char*);
void print_LCS(char*,char**,int,int);

int main()
{
    cout<<"\n--------------------- LONGEST COMMON SUBSEQUENCE --------------------\n";
    char* str1=new char[100];
    char* str2=new char[100];
    cout<<"\nEnter str1 : ";
    cin>>str1;
    cout<<"\nEnter str2 : ";
    cin>>str2;
    int Result = LCS(str1,str2);
    cout<<"\nLongest common subsequence is of length: "<<Result;
    cout<<"\n\n--------------------------------------------------------------------\n";


    return 0;
}

void print_LCS(char* str1, char** B,int i ,int j)
{
    if(i==0 || j==0)
    {
        return;
    }
    if(B[i][j]=='!')
    {
        print_LCS(str1,B,i-1,j-1);
        cout<<str1[i-1];
    }
    /*
       ABOVE,,  str1[i-1] is being displayed instead of str1[i]
        this is because, string starts from 0, whereas our loop works with a start point of 1
    */

    else if(B[i][j]=='^')
    {
        print_LCS(str1,B,i-1,j);
    }
    else
    {
        print_LCS(str1,B,i,j-1);
    }
}

int LCS(char* str1, char* str2)
{
    int n= strlen(str1);        // for Rows - n
    int m= strlen(str2);        // for columns - m

    int i,j;    // local variables

    // allocating the required memory to global B
    // the size has been incremented by 1 so as to accommodate the exact length of string as well as index 0
    B=new char*[n+1];
    for(i=0; i<=n; i++)     // i.e. from 0 to size-1
    {
        B[i]=new char[m+1];
    }

    /* we take:
     ROWS till 'n' which is still (size-1) i.e. (n+1)-1
     COLUMNS till 'm' which is still (size-1) i.e. (m+1)-1
    */

    // Initializing the 0th row and column with blank symbols
    for(i=0; i<=n; i++)
    {
        B[i][0]=' ';
    }
    for(i=0; i<=m; i++)
    {
        B[0][i]=' ';
    }

    // making new 2D array C for storing the solution of LCS
    // the size has been incremented by 1 so as to accommodate the exact length of string as well as index 0
    int **C=new int*[n+1];
    for(i=0; i<=n; i++)
    {
        C[i]=new int[m+1];
    }

    /* we take:
     ROWS till 'n' which is still (size-1) i.e. (n+1)-1
     COLUMNS till 'm' which is still (size-1) i.e. (m+1)-1
    */

    // Initializing the 0th row and column with 0
    for(i=0; i<=n; i++)
    {
        C[i][0]=0;
    }
    for(i=0; i<=m; i++)
    {
        C[0][i]=0;
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            /* BELOW HERE, in IF,
             str1[i-1]==str2[j-1] is done, instead of normal
             str1[i]==str2[j] as stated in algo.
             This is because, string starts from 0, whereas our loop works with a start point of 1
            */
            if(str1[i-1]==str2[j-1])
            {
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]='!';        // ! for equal
            }
            else
            {
                if(C[i-1][j]>=C[i][j-1])
                {
                    C[i][j]=C[i-1][j];
                    B[i][j]='^';        // ^ for up
                }
                else
                {
                    C[i][j]=C[i][j-1];
                    B[i][j]='<';        // < for left
                }
            }
        }
    }

    /*  code for printing matrix

        for(i=0; i<=n; ++i)
        {
            for(j=0; j<=m; ++j)
                cout<<" "<<C[i][j]<<B[i][j];
            cout<<endl;
        }
    */

    // calling print_LCS() to display the found LCS
    cout<<"\nLCS is : ";
    print_LCS(str1,B,n,m);
    cout<<endl;

    return C[n][m];
}

