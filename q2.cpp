/*
Columnar cipher - 
to encrypt - arrange in row major - read in column major
to decrypt - arrange in column major - read in row major

bugs- does not handle spaces 
add file support
*/

#include<iostream>
#include<cstring>
#include <cmath>
#include<cstdlib>

using namespace std;

char* encrypt(char* , int );
char* decrypt(char* , int );

int main()
{
    char *text, *etext, *dtext;

    text = new char[500];

    while(1){
        int ch,n;

        cout<<"\n ** Columnar Transposition Cipher ** \n";
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

            cout<<"Column size: ";
            cin>>n;
        }

        switch(ch)
        {
            case 1:{
                etext = encrypt(text,n);
                cout<<"\nEncrypted text: "<<etext<<"\n\n";
            }break;

            case 2:{
                dtext = decrypt(text,n);
                cout<<"\nDecrypted text: "<<dtext<<"\n\n";
            }break;

            case 3:{
                cout<<"User Requested Exit.";
            } exit(0);

            default:
                cout<<"\nEnter valid choice !! \n";
        }
    };
    return 0;
}


char* encrypt(char* text, int col)
{
    int len = strlen(text);     // length of plaintext
    int rows = ceil((float)len/col); // no of rows required = len/col

    int i,j,k;
    int sparecolumns= col - (len%col);  // spare columns in last row
   
    // allocating space for 2D matrix
    char **mat = new char*[rows];
    i=0;
    for(; i<rows-1; i++){
        mat[i] = new char[col];
    }
    mat[i]=new char[col-sparecolumns];

    /* text <TO> 2D matrix -> arrange Row-majorly*/
    k=-1;
    // fill n-1 rows normally
    for(i=0; i<rows-1; i++){
        for(j=0; j<col; j++){
            mat[i][j] = text[++k];
        }
    }  
    // fill last row carefully     
    for(j=0;j<col-sparecolumns;j++){
        mat[i][j]= text[++k];
    }

   /* displaying matrix 
    *
        for(i=0;i<rows-1;i++){ for(j=0;j<col;j++){ cout<<mat[i][j]<<" "; } cout<<"\n"; }
        for(j=0;j<col-sparecolumns;j++){ cout<<mat[i][j]<<" ";  }
    /* */
 
    // res string for encrypted message
    char *res = new char[len];

    /* 2D matrix <TO> text -> read column-majorly */
    k=-1; 
    // fill non-disturbed columns normally
    for(j=0; j<col-sparecolumns; j++){
        for(i=0; i<rows; i++){
            res[++k] = mat[i][j];
        }
    }
    // fill rest of the columns carefully
    for(;j<col;j++){
        for(i=0; i<rows-1; i++){
            res[++k] = mat[i][j];
        }
    }
    res[++k] = '\0';

    return res;
}

char* decrypt(char* text, int col)
{
    int len = strlen(text);     // length of ciphertext
    int rows = ceil((float)len/col); // no of rows required = len/col

    int i,j,k;
    int sparecolumns= col - (len%col);  // spare columns in last row
   
    // allocating space for 2D matrix
    char **mat = new char*[rows];
    i=0;
    for(; i<rows-1; i++){
        mat[i] = new char[col];
    }
    mat[i]=new char[col-sparecolumns];

    /* text <TO> 2D matrix -> arrange column-majorly*/
    k=-1;
    // read un-disturbed columnns normally
    for(j=0; j<col-sparecolumns; j++){
        for(i=0; i<rows; i++){
            mat[i][j]= text[++k]; 
        }
    }
    // read rest of the columnns carefully
    for(;j<col;j++){
        for(i=0; i<rows-1; i++){
            mat[i][j]=text[++k]; 
        }
    }
   
    /* resultant decrypted msg*/
    char *res = new char[len];
    
    /* 2D matrix <TO> text -> read row-majorly*/
    k=-1;
    // read n-1 rows normally
    for(i=0; i<rows-1; i++){
        for(j=0; j<col; j++){
            res[++k]= mat[i][j] ;
        }
    }       
    // read last row carefully
    for(j=0;j<col-sparecolumns;j++){
        res[++k]=mat[i][j];
    }
    res[++k] = '\0';

    return res;
}

