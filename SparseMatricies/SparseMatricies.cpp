#include <iostream>
#include "stdlib.h"
using namespace std;

void diagonal_matrix(int n)
{
    int sizeOfArr = n;
    int* a = new int[sizeOfArr];
    int i,j;
    int ele;

    cout<<"\nEnter a diagonal matrix:\n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cin>>ele;
            if(i == j)
                a[i] = ele;
        }

    }

    cout<<"\nDiagonal matrix: \n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if(i==j)
                cout<<a[i]<<"  ";
            else
                cout<<"0  ";
        }
        cout<<endl;
    }
}


void tridiagonal_matrix(int n)
{
    int sizeOfArr = 3*n-2;
    int* a = new int[sizeOfArr];
    int i,j;
    int ele;

    cout<<"\nEnter a tri-diagonal matrix:\n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cin>>ele;
            if(i == j || i==j+1 || i+1==j)
                a[2*i + j] = ele;
        }

    }

    cout<<"\nTri-diagonal matrix: \n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if(i == j || i==j+1 || i+1==j)
                cout<<a[2*i + j]<<"  ";
            else
                cout<<"0  ";
        }
        cout<<endl;
    }
}


void upper_triangular(int n)
{
    int sizeOfArr = n*(n+1)/2;
    int* a = new int[sizeOfArr];
    int i,j,k;
    int ele;

    cout<<"\nEnter a upper triangular matrix:\n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cin>>ele;
            if(i <= j)
            {
                k= (i*n)+j - (i*(i+1))/2;
                a[k] = ele;
            }
        }
    }

    cout<<"\nUpper triangular matrix: \n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if(i <= j)
            {
                k= (i*n)+j - (i*(i+1))/2;
                cout<<a[k]<<"  ";
            }
            else
                cout<<"0  ";
        }
        cout<<endl;
    }
}

void lower_triangular(int n)
{
    int sizeOfArr = n*(n+1)/2;
    int* a = new int[sizeOfArr];
    int i,j,k;
    int ele;

    cout<<"\nEnter a lower triangular matrix:\n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cin>>ele;
            if(i >= j)
            {
                k= (i*(i+1))/2 + j;
                a[k] = ele;
            }
        }

    }

    cout<<"\nLower triangular matrix: \n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if(i >= j)
            {
                k= (i*(i+1))/2 + j;
                cout<<a[k]<<"  ";
            }
            else
                cout<<"0  ";
        }
        cout<<endl;
    }
}


void symmetric_matrix(int n)
{
    int sizeOfArr = n*(n+1)/2;
    int* a = new int[sizeOfArr];
    int i,j,k;
    int ele;

    cout<<"\nEnter a symmetric matrix:\n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            cin>>ele;
            if(i >= j)
            {
                k= (i*(i+1))/2 + j;
                a[k] = ele;
            }
        }

    }

    cout<<"\nThe symmetric matrix is : \n";
    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<n ; j++)
        {
            if(i >= j)
            {
                k= (i*(i+1))/2 + j;
                cout<<a[k]<<"  ";
            }
            else
            {
                k= (j*(j+1))/2 + i;
                cout<<a[k]<<"  ";
            }
        }
        cout<<endl;
    }
}


int main()
{

    int ch,dimension;

    do{

        cout<<"\n--------------------------------------------------------------------------\n";
        cout<<"  Which type of matrix do you wish to enter?\n";
        cout<<"1.Diagonal matrix\n";
        cout<<"2.Tri-diagonal matrix\n";
        cout<<"3.Upper triangular matrix\n";
        cout<<"4.Lower triangular matrix\n";
        cout<<"5.Symmetric matrix\n";
        cout<<"6.Exit\n";
        cout<<"\n--------------------------------------------------------------------------";
        cout<<"\nEnter choice: ";
        cin>>ch;
        cout<<"\n--------------------------------------------------------------------------";

        if(ch!=6)
        {
            cout<<"\nEnter dimension of the square matrix: ";
            cin>>dimension;
            cout<<"\n--------------------------------------------------------------------------";
        }

        switch(ch)
        {
            case 1:
            diagonal_matrix(dimension);
            break;

            case 2:
            tridiagonal_matrix(dimension);
	        break;

            case 3:
            upper_triangular(dimension);
            break;


            case 4:
            lower_triangular(dimension);
            break;


            case 5:
            symmetric_matrix(dimension);
            break;


            case 6:
            exit(0);

            default: cout<<"\nPlease enter a valid choice\n";

        }

    }while(1);

    cout<<"\n--------------------------------------------------------------------------\n";

    return 0;

}
