#include "iostream"
using namespace std;
#include "Array.h"



  Array:: Array(int n)
{
   Size = n;
   arr = new int[Size];
   int i;
   for(i=0;i<Size;i++)
    arr[i] = -1;
}


Array::~Array()
{
    delete []arr;
}



  Array:: Array (const Array& ob)
{
   int i;

   Size = ob.Size;
   arr = new int[Size];
   for(i=0;i<Size;i++)
     arr[i] = ob.arr[i];
}


  void Array:: fillarray()
{
   int i;
   cout<<"\nEnter elements:\n";

   for(i=0 ; i<Size ; i++)
    {
        cout<<"Element["<<i<<"] : ";
        cin>>arr[i];
    }

}


  void Array::display()
{
  int i;

   for(i=0 ; i<Size ; i++)
    {
        cout<<"\nElement["<<i<<"] : ";
        cout<<arr[i];
    }

  cout<<endl;
}





  int Array:: lsearch( int ele)
{
   for(int i=0;i<Size;i++)
   {
      if(arr[i]==ele)
        return i;
   }

   return -1;
}


 int Array:: bsearch( int ele)
 {
    int beg,End,mid;

    for(beg=0,End=Size-1; beg<=End && arr[mid]!=ele; )
    {
       mid = (beg+End)/2;

        if(arr[mid]>=ele)
         End = mid -1;
        else
         beg = mid +1;
    }

   if(ele==arr[mid])
    return mid;
   else
    return -1;
}



 void inline Swap(int &a, int &b)
 {
    int temp;

        temp = a;
        a = b;
        b = temp;
 }


  Array& Array::bubble_sort()
{
   Array* b = new Array(Size);
   int i,j;

   for(i=0;i<Size;i++)
    b->arr[i] = arr[i];

   for(i=0;i<Size-1;i++)
    {
      for(j=0;j<Size-i-1;j++)
       {
          if(b->arr[j]>=b->arr[j+1])
            Swap(b->arr[j],b->arr[j+1]);
       }
    }

     return *b;
}


 Array& Array:: sel_sort()
{
   Array* b = new Array(Size);
   int i,j;

   for(i=0;i<Size;i++)
    b->arr[i] = arr[i];

   for(i=0;i<Size-1;i++)
    {
       int minLoc =i;

      for(j=i+1;j<Size;j++)
       {
          if(b->arr[j] < b->arr[minLoc])
            minLoc = j;
        }

      Swap(b->arr[i],b->arr[minLoc]);
     }

   return *b;
}




  Array& Array:: ins_sort()
{
    Array* b = new Array(Size);
   int i,j;

   for(i=0;i<Size;i++)
    b->arr[i] = arr[i];

   for(i=1;i<Size;i++)
    {
      int temp = b->arr[i];
      j = i;

        while(temp < b->arr[j-1] && j>0)
         {
            b->arr[j] = b->arr[j-1];
            j--;
         }

      b->arr[j] = temp;

    }

   return *b;
}
