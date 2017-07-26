/*
Caesar cipher- 
linear shift by 3
*/

#include<iostream>
#include<cstring>

using namespace std;

#define caesarKey 3

int mod(int, int);
char* encrypt(char* );
char* decrypt(char* );

int main()
{
    char *text, *etext, *dtext;
    
    cout<<"\n ** Caesar Cipher ** \n";
    cout<<"\n1. Encrypt text.";
    cout<<"\n2. Decrypt text.";
    cout<<"\n\nEnter choice: ";
    int ch;
    cin>>ch;
    cin.ignore();

    text = new char[500];
    
    switch(ch)
    {
        case 1:{
                cout<<"\nEnter text     : ";
                cin.getline(text,500);
                etext = encrypt(text);
                cout<<"Encrypted text : "<<etext<<"\n\n";
            }break;
                
        case 2:{
                cout<<"\nEnter text     : ";
                cin.getline(text,500);
                dtext = decrypt(text);
                cout<<"Decrypted text : "<<dtext<<"\n\n";
            }break;
                
        default: cout<<"\nEnter valid choice !! \n\n";        
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

char* encrypt(char* text)
{
    int len = strlen(text); 
    char *res = new char[len];
    
    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = ((text[i]-'A'+caesarKey)%26)+'A';            
        }
        else if(islower(text[i]))
        {
            res[i] = ((text[i]-'a'+caesarKey)%26)+'a';            
        }        
        else
            res[i] = text[i];
    }   
    
    res[i] = '\0';
    return res;
}

char* decrypt(char* text)
{
    int len = strlen(text); 
    char *res = new char[len];
    
    int i;
    for(i=0; i<len; i++)
    {
        if(isupper(text[i]))
        {
            res[i] = mod((text[i]-'A'-caesarKey),26)+'A';            
        }
        else if(islower(text[i]))
        {
            res[i] = mod((text[i]-'a'-caesarKey),26)+'a';            
        }      
        else
            res[i] = text[i];
    }    
    
    res[i] = '\0';
    return res; 
}
