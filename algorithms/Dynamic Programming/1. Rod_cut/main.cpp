#include <iostream>
#include <limits.h>
using namespace std;

/*
 Here, we know that printing is an optional part
 So, we take 'S' as global to be able to store and print the cuts
 But, the solution of the problem i.e. the maximum profit is compulsory
 So, we return it from the Rod-cut function
*/

int *S;
int Rod_cut(int*, int);
void print_cuts(int*,int);
int Recursive_Rod_cut(int* , int);

int main()
{
    int Size=7;
    int p[7]= {0,1,5,8,9,10,17};
    int n;
    int counter=-1;
    do
    {
        counter++;
        if(counter>0)
        {
            counter=0;
            cout<<"\nError : Out of range ";
            cout<<"\n< Only enter a positive value less than the Max length : "<<Size<<">\n";
        }
        cout<<"\nEnter the length of Rod : ";
        cin>>n;
    }
    while(n<1 || n>Size);

    cout<<"\n----------------------- ROD - CUT PROBLEM ---------------------------------\n\n";
    cout<<"1. Dynamic programming approach \n";
    cout<<"2. Recursive approach\n";
    int choice;
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
    {
        int max_profit = Rod_cut(p,n);
        cout<<"\n\nMax profit from Rod of length "<<n<<" is : "<<max_profit;
        cout<<"\n\nCuts :\t";
        print_cuts(S,n);
    }
    break;
    case 2:
    {
        int max_profit = Recursive_Rod_cut(p,n);
        cout<<"\n\nMax profit from Rod of length "<<n<<" is : "<<max_profit;
    }
    break;
    }
    cout<<"\n\n------------------------------------------------------------------------------";
    return 0;
}

int Rod_cut(int* p , int n)
{
    int *r = new int[n];
    S = new int[n];
    int i,j,q, cal_value;
    r[0]=0;
    for(j=1; j<=n ; j++)
    {
        q= -1;
        for(i=1; i<=j; i++)
        {
            cal_value = p[i]+r[j-i];
            if(cal_value > q)
            {
                q = cal_value;
                S[j] = i;           /// for standard algorithm , remove this line
            }
        }
        r[j]=q;
    }
    return r[n];
}

void print_cuts(int* S, int n)
{
    if(S[n]==n)
    {
        cout<<"\tNo cuts required ";
        return;
    }
    while(n>0)
    {
        cout<<S[n]<<"  ";
        n=n-S[n];
    }
}

int Recursive_Rod_cut(int* p ,int n)
{
    if(n==0)
    {
        return 0;
    }
    int cal_value, q=-1;
    for( int i=1; i<=n; i++)
    {
        cal_value= p[i]+ Recursive_Rod_cut(p,n-i);
        if(cal_value > q)
            q=cal_value;
    }
    return q;
}
