#include <iostream>
#include <cstring>
#include <time.h>
#include <stdlib.h>
using namespace std;
string gx;

void transmission();
bool validategx(int*,int);
void sender();
void medium(int*,int);
void receiver(int*,int);
void error_generator(int*,int);
int* moduloTwoDivision(int*,int,int*,int);
void flip(int*,int);

int main()
{
    // random no' generator , generating new random no's on each build
    srand(time(NULL));

    transmission();
    return 0;
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
    /*
    cout<<"\n\nremainder is : \t\t";
    for(int i=0; i<len_of_message ; i++)
        {
            cout<<remainder[i];
        }
    */
    int isError=0;
    cout<<"\n\n";
    for(int i=0; i<len_of_message ; i++)
    {
        if(remainder[i]!=0)
        {
            isError=1;
            break;
        }
    }

    if(isError==0)
    {
        cout<<"\n\nMessage successfully received !! \n\n\n";
    }
    else
    {
        cout<<"\n\nError detected !! Message NOT received successfully !!\n\n\n";
    }
}

void transmission()
{
    sender();
}

void medium(int* A,int len_of_message)
{
    int var=(rand()%2);
    // int var=0;
    if(var==0)
    {
        // generates error in A
        error_generator(A,len_of_message);
    }
    // transmits to receiver
    receiver(A,len_of_message);

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


void flip(int* A,int bitIndex)
{
    if(A[bitIndex]==0)
    {
        A[bitIndex]=1;
    }
    else
    {
        A[bitIndex]=0;
    }
}


void error_generator(int* A,int len_of_message)
{
    int r=(rand()%3) +1;
    switch(r)
    {
    case 1:
    {
        int errorBit1=(rand()%len_of_message);
        flip(A,errorBit1);
    }
    break;
    case 2:
    {
        int errorBit1=(rand()%len_of_message);
        int errorBit2=(rand()%len_of_message);
        while(errorBit1==errorBit2)
        {
            errorBit2=(rand()%len_of_message);
        }
        flip(A,errorBit1);
        flip(A,errorBit2);
    }
    break;
    case 3:
    {
        int errorBit1=(rand()%len_of_message);
        int errorBit2=(rand()%len_of_message);
        while(errorBit1==errorBit2)
        {
            errorBit2=(rand()%len_of_message);
        }
        flip(A,errorBit1);
        flip(A,errorBit2);
        int  sizeOfBurstError;
        if(errorBit1>errorBit2)
        {
            sizeOfBurstError= errorBit1 - errorBit2;
        }
        else
        {
            sizeOfBurstError= errorBit2 - errorBit1;
        }

        int noOfErrors= (rand()%sizeOfBurstError);
        for(int i=0 ; i<noOfErrors; i++)
        {
            int probOfBurstError = (rand()%10);
            if(probOfBurstError==0)
            {
                if(errorBit1<errorBit2)
                {
                    int errorBit3= errorBit1 + (rand()%errorBit2);
                    flip(A,errorBit3);
                }
                else
                {
                    int errorBit3= errorBit2 + (rand()%errorBit1);
                    flip(A,errorBit3);
                }
            }
        }

    }
    break;
    }
}
