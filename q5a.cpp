/*
Additive cipher
Encryption - add N to plaintext
Decryption - add additiveInverse(N) to ciphertext
*/

#include<iostream>
#include<cstring>

using namespace std;

int mod(int, int);
int addinverse(int, int);
char* encrypt(char* , int );
char* decrypt(char* , int );

int main()
{
    char *text, *etext, *dtext;
    
    int ch;
    cout<<"\n ** Additive Cipher** \n";
    cout<<"\n1. Encrypt text.";
    cout<<"\n2. Decrypt text.";
    cout<<"\n\nEnter choice: ";
    cin>>ch;
    cin.ignore();

    text = new char[500];
    cout<<"\nEnter text: ";
    cin.getline(text,500);
    
    int n;
    cout<<"Enter key : ";
    cin>>n;
    switch(ch)
    {
        case 1: etext = encrypt(text,n);
                cout<<"\nEncrypted text: "<<etext<<"\n\n";
                break;
                
        case 2: dtext = decrypt(text,n);
                cout<<"\nDecrypted text: "<<dtext<<"\n\n";
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

char* encrypt(char* text, int n)
{
    int key=n;
    int len = strlen(text); 
    char *res = new char[len];
    
    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = (((text[i]-65)+key)%26)+65;            
        }
        else if(islower(text[i]))
        {
            res[i] = (((text[i]-97)+key)%26)+97;            
        }        
        else
            res[i] = text[i];
    }   
    
    res[i] = '\0';
    return res;
}

int addinverse(int n,int domain){
    // a inverse of 4 can be -4 as well as 22
    // For a inverse in positive domain
    return (domain-n);
}
char* decrypt(char* text, int n)
{
    // additive inverse of 'n' in the range 26
    int key=addinverse(n,26);

    int len = strlen(text); 
    char *res = new char[len];
    
    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = mod(((text[i]-65)+key),26)+65;            
        }
        else if(islower(text[i]))
        {
            res[i] = mod(((text[i]-97)+key),26)+97;            
        }      
        else
            res[i] = text[i];
    }    
    
    res[i] = '\0';
    return res; 
}
