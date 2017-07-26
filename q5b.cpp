/*
Multiplicative cipher
Encryption - multiply key to plaintext
Decryption - multiply multiplicativeInverse(N) to ciphertext
*/

#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>

using namespace std;

int gcd(int a, int b);
bool isValidKey(int val);
char* encrypt(char* text, int key);
int mulInverse(int x, int domain);
char* decrypt(char* text, int key);

/* For a Domain of 26, there are 12 co-primes*/
int Globalkeys[12]={1,3,5,7,9,11,15,17,19,21,23,25};

int main()
{
    // Random number generator
    srand((unsigned)time(NULL));
   
    char *text, *etext, *dtext;
    int ch,n,len,key;
    text = new char[500];

    while(1)
    {
    
        cout<<"\n ** Multiplicative Cipher ** \n";
        cout<<"\n1. Encrypt text.";
        cout<<"\n2. Decrypt text.";
        cout<<"\n3. Exit.";
        cout<<"\n\nEnter choice: ";
        cin>>ch;


        cin.ignore();
           
        switch(ch)
        {
        case 1:{
            cout<<"\nEnter text    : ";
            cin.getline(text,500);
            
            key = Globalkeys[rand()%12];

            etext = encrypt(text,key);
            cout<<"\nEncrypted text: "<<etext;
            cout<<"\nKey used      : "<<key;
            cout<<endl;
        }
        break;

        case 2:{
            cout<<"\nEnter text    : ";
            cin.getline(text,500);
            
            do
            {
                cout<<"\nEnter a key co-prime with 26   : ";
                cin>>key;
            }
            while(!isValidKey(key));

            dtext = decrypt(text,key);
            cout<<"\nDecrypted text: "<<dtext<<"\n";
        }
        break;

        case 3:{ 
            cout<<"\nUser Requested Exit.\n";
        }
            exit(0);

        default:
            cout<<"\nEnter valid choice!";
        }
        cout<<"\n----------------------------------";
    };

    return 0;
}


int gcd(int a, int b)
{
    if(a == 0)
        return b;
    else
        return gcd(b%a, a);
}

bool isValidKey(int val){
    // key is valid if co-prime with 26
    return (gcd(val,26)==1)?true:false;
}

char* encrypt(char* text, int key)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-65)*key)%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)*key)%26)+97;
        }
        else
            res[i] = text[i];
    }

    res[i] = '\0';
    return res;
}

int mulInverse(int x, int domain)
{
    for(int i=1; i<domain; i++){
        if((x*i)%domain == 1){
            return i;
        }
    }
    return 0;
 }

char* decrypt(char* text, int key)
{
    int len = strlen(text);
    char *res = new char[len];

    int i;
    int inv = mulInverse(key,26);

    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-65)*inv)%26)+65;
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)*inv)%26)+97;
        }
        else
            res[i] = text[i];
    }
    res[i] = '\0';

    return res;
}

