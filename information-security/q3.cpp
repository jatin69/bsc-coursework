/*
Vernam cipher - 
each character of plaintext is added with a random number
plaintext length = length of key of random numbers

here, Addition with 2 digit random numbers.

*/

#include<iostream>
#include<cstring>
#include <cmath>
#include<ctime>
#include<cstdlib>

using namespace std;


int mod(int, int);
void fillRandomSeq(short int*, int);
char* encrypt(char*, short int*);
char* decrypt(char*, short int*);

int main()
{
    srand((unsigned)time(NULL));
    char *text, *etext, *dtext;
    text = new char[500];

    while(1)
    {
        int ch,n,len;
        short int *seq;

        cout<<"\n ** Vernam Cipher ** \n";
        cout<<"\n1. Encrypt text.";
        cout<<"\n2. Decrypt text.";
        cout<<"\n3. Exit.";
        cout<<"\n\nEnter choice: ";
        cin>>ch;

        cin.ignore();

        if(ch!=3)
        {
            cout<<"\nEnter text : ";
            cin.getline(text,500);

            len = strlen(text);
            seq = new short int[len];
        }

        switch(ch)
        {
        case 1:
        {
            etext = encrypt(text,seq);
            cout<<"\nEncrypted text: "<<etext;

            cout<<"\n\nRandom number sequence used:\n";
            for(int i=0; i<len; i++)
                cout<<seq[i]<<"  ";

            cout<<endl;
        }
        break;

        case 2:
        {
            cout<<"\nEnter number sequence :\n";
            for(int i=0; i<len; i++)
                cin>>seq[i];

            dtext = decrypt(text,seq);
            cout<<"\nDecrypted text: "<<dtext<<"\n\n";
        }
        break;

            case 3:{
                cout<<"User Requested Exit.";
            } exit(0);

            default:
                cout<<"\nEnter valid choice !! \n";
        }
        cout<<"-------------------------------";

    };
    return 0;
}

int mod(int x, int y)
{
    if(x%y==0){
        return 0;
    }
    if(x < 0)
    {
        x= x *-1;
        return y-(x%y);
    }
    else
        return x%y;
}

void fillRandomSeq(short int *seq, int n)
{
    int i;
    for(i=0; i<n; i++)
        seq[i] = rand()%26;
}

char* encrypt(char* text, short int* seq)
{
    int len = strlen(text);
    char *res = new char[len];

    fillRandomSeq(seq,len);

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-'A')+seq[i])%26)+'A';
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-'a')+seq[i])%26)+'a';
        }
        else
            res[i] = text[i];
    }
    res[i] = '\0';

    return res;
}

char* decrypt(char* text, short int* seq)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = mod(((text[i]-'A')-seq[i]),26)+'A';
        }
        else if(islower(text[i]))
        {
            res[i] = mod(((text[i]-'a')-seq[i]),26)+'a';
        }
        else
            res[i] = text[i];
    }
    res[i] = '\0';

    return res;
}
