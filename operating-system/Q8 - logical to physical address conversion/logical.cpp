#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

struct memory_frame{
    int page_no;
};

struct page_table{
    int frame_no;
};

int main(){
    srand((unsigned)time(NULL));
    cout<<"\n ********* Logical to Physical Memory Address Conversion ********\n";
    // Input memory size and the size of page table
    int memory_size, page_size;
    cout<<"\nEnter the size of Main Memory : ";
    cin>>memory_size;
    cout<<"\nEnter the size of Page        : ";
    cin>>page_size;
    
    // assuming -> we map the whole memory to page table
    int total_pages= memory_size/page_size ;
    
    // allocating page table
    page_table my_table[total_pages];
    
    // Dividing Main memory to Frames
    memory_frame my_frame[total_pages];
    
    int arr[total_pages]={0};
    int r,random_page_no;
    for(int i=0; i<total_pages ;i++)
    {
        random_page_no = rand()%total_pages;
        
        r=random_page_no;
        if(arr[r] == 1)
        {
            i--;
            continue;
        }
        arr[r]=1;
        
        my_frame[i].page_no  = r;
        my_table[r].frame_no = i;
    }
    
    cout<<"\n********* The Structure of Main Memory **************** \n";
    cout<<"\n\tPage No'\tFrame No'\n";
    for(int r=0; r<total_pages ;r++)
    {
        cout<<"\t   "<<r<<"\t\t  "<<my_table[r].frame_no<<"\n";
    }
    
    int pg_no,offset;
    cout<<"\n\nEnter the Logical address : \n";
    cout<<"\nPage No' : ";cin>>pg_no;
    cout<<"Offset   : ";cin>>offset;
    
    if(pg_no >= total_pages || offset > page_size)
    {
        cout<<"\nInvalid Input\n\n";
        return 1;
    }
    
    int physical_add = ( my_table[pg_no].frame_no * page_size ) + offset ;
    cout<<"\nThe Physical Address is : ";cout<<physical_add;
    cout<<"\n\n";
    return 0;
}