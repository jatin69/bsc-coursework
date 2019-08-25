#include <iostream>
#include <cstring>
using namespace std;
string gx;

void transmission();
bool validategx(int*,int);
void sender();
void medium(int*,int);
void receiver(int*,int);
int* moduloTwoDivision(int*,int,int*,int);


int main()
{
    transmission();
    return 0;
}


void transmission()
{
    sender();
}

bool validategx(int* B, int length_of_gx)
{
    int* xplus1=new int[2];
    xplus1[0]=1;
    xplus1[1]=1;
    int length_of_xplus1=2;

    if( (B[0]==1) && (B[length_of_gx-1]==1))
    {
        int* remainder=moduloTwoDivision(B,length_of_gx,xplus1,length_of_xplus1);
        for(int i=0; i<length_of_gx ; i++)
        {
            if(remainder[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }


}

void sender()
{

    string message;

    cout << "Enter G(x) :\t";
    // gx declared globally
    cin>>gx;
    int len_of_gx=gx.length();
    int* B;
    B=new int[len_of_gx];
    for(int i=0; i<len_of_gx; i++)
    {
        if(gx[i]=='1')
        {
            B[i]=1 ;
        }
        else
        {
            B[i]=0 ;
        }
    }

    while(!validategx(B,len_of_gx))
    {
        cout<<"\nEntered G(x) is not valid. Retry !!\n";
        cout << "\nEnter G(x) :\t";
        cin>>gx;
        len_of_gx=gx.length();
        delete []B;
        B=new int[len_of_gx];

        for(int i=0; i<len_of_gx; i++)
        {
            if(gx[i]=='1')
            {
                B[i]=1 ;
            }
            else
            {
                B[i]=0 ;
            }
        }

    }

    cout << "\nEnter Message :\t";
    cin>>message;


    int degree_of_gx= len_of_gx -1;

    message.append(degree_of_gx,'0');
    int len_of_message=message.length();


    int A[len_of_message];


    for(int i=0; i<len_of_message; i++)
    {
        if(message[i]=='1')
        {
            A[i]=1 ;
        }
        else
        {
            A[i]=0 ;
        }
    }

    int* remainder=moduloTwoDivision(A,len_of_message,B,len_of_gx);

    for(int i=0; i<len_of_message ; i++)
    {
        A[i]^=remainder[i];
    }


    cout<<"\n\nSent Codeword is :";
    for(int i=0; i<len_of_message; i++)
    {
        cout<<A[i];
    }

    medium(A,len_of_message);

}

void medium(int* A,int len_of_message)
{
    /// No error in Noiseless channel
    // transmits to receiver
    receiver(A,len_of_message);
}

void receiver(int* A,int len_of_message)
{
    cout<<"\n\nReceived data is :";
    for(int i=0; i<len_of_message; i++)
    {
        cout<<A[i];
    }

    int len_of_gx=gx.length();
    int B[len_of_gx];
    for(int i=0; i<len_of_gx; i++)
    {
        if(gx[i]=='1')
        {
            B[i]=1 ;
        }
        else
        {
            B[i]=0 ;
        }
    }
    int* remainder=moduloTwoDivision(A,len_of_message,B,len_of_gx);


    for(int i=0; i<len_of_message ; i++)
    {
        if(remainder[i]!=0)
        {
            cout<<"\n\nError detected !! \n\n\n";
            return;
        }
    }

    cout<<"\n\nMessage successfully received !! \n\n\n";

}


int* moduloTwoDivision(int* dividend, int len_of_dividend, int* divisor, int len_of_divisor)
{
    int i=0,l=0;
    int* A= new int[len_of_dividend];
    for(int s=0; s<len_of_dividend; s++)
    {
        A[s]=dividend[s];
    };
    while(1)
    {
        for( ; i<len_of_dividend && A[i]==0 ; i++);
        if(i==(len_of_dividend+1))
        {
            break;
        }
        l=i+len_of_divisor-1;
        if( l>len_of_dividend-1)
        {
            break;
        }
        for(int start=i,j=0; start<=l ; start++,j++)
        {
            A[start]^=divisor[j];
        }
    }
    return A;
}
