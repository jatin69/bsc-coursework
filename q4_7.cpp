/*
Vigenere cipher -
each character of plaintext is added with its corresponding codeword character treated as [a->0 , b->1 , .. , z->25 ] 
plaintext length <= length of codeword

Usage -
plaintext -> jatin is a good boy
codeword  -> hello he l lohe llo


Assumption-
codeword and plain text should be in the same case.
 */

#include<iostream>
#include<cstring>

using namespace std;

int mod(int, int);
char* encrypt(char*, char*);
char* decrypt(char*, char*);


int main()
{
    char *text, *code, *etext, *dtext;

    int ch;
    cout<<"\n ** Vigenere cipher **\n";
    cout<<"\n1. Encrypt text.";
    cout<<"\n2. Decrypt text.";
    cout<<"\n\nEnter choice: ";
    cin>>ch;
    cin.ignore();

    text = new char[500];
    code = new char[500];

    cout<<"\nEnter text      : ";
    cin.getline(text,500);

    cout<<"Enter code word : ";
    cin>>code;

    switch(ch)
    {
        case 1: etext = encrypt(text,code);
                cout<<"\nEncrypted text  : "<<etext<<"\n\n";
                break;

        case 2: dtext = decrypt(text,code);
                cout<<"\nDecrypted text  : "<<dtext<<"\n\n";
                break;

        default: cout<<"\nEnter valid choice!";
    }

    return 0;
}


/* to calculate mod of negative numbers. */
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

char* encrypt(char* text, char* code)
{
    int len = strlen(text);
    int lenCode = strlen(code);

    char *res = new char[len];

    int i,j=0;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-'A')+(code[j]-'A'))%26)+'A';
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-'a')+(code[j]-'a'))%26)+'a';
        }
        else
            res[i] = text[i];

       j = (j+1)%lenCode;
    }

    res[i] = '\0';
    return res;
}

char* decrypt(char* text, char* code)
{
    int len = strlen(text);
    int lenCode = strlen(code);

    char *res = new char[len];

    int i,j=0;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = mod(((text[i]-65)-(code[j]-65)),26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = mod(((text[i]-97)-(code[j]-97)),26)+97;
        }
        else
            res[i] = text[i];

        j = (j+1)%lenCode;
    }

    res[i] = '\0';
    return res;
}
