#include<iostream>
#include<cstring>
#include <cmath>
#include<ctime>
#include<cstdlib>

using namespace std;

void fillRandomSeq(short int *seq, int n)
{
    int i;
    for(i=0; i<n; i++)
        seq[i] = rand()%100;
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
            res[i] = (((text[i]-65)^seq[i])%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)^seq[i])%26)+97;
        }
        else
            res[i] = text[i];
    }
    res[i] = '\0';

    return res;
}


int main()
{
    srand((unsigned)time(NULL));
    char *text, *etext, *dtext;
    text = new char[500];

    int ch,n,len;
    short int *seq;

    cout<<"\n** Stream Cipher with XOR **\n";
    cout<<"\nEnter text : ";
    cin.getline(text,500);

    len = strlen(text);
    seq = new short int[len];
    etext = encrypt(text,seq);
    cout<<"\nEncrypted text: "<<etext;

    cout<<"\n\nRandom number sequence used:\n";
    for(int i=0; i<len; i++)
        cout<<seq[i]<<"  ";

    cout<<"\n\n";
    return 0;
}
