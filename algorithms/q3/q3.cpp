#include<iostream>
#include<stdlib.h>
using namespace std;
long cp=0,rcp=0,heapsize=0,hcp=0;
long merge(int *a,int f,int c,int l)
{
	int *b,i=f,j=c,k=0,counter=0;
	b=new int[l-f+1];
	while(i!=c && j!=l+1)
	{
		counter++;
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	while(i!=c)
	{
		counter++;
		b[k++]=a[i++];
	}
	while(j!=l+1)
	{
		b[k++]=a[j++];
		counter++;
	}
	for(i=0;i<k;i++)
		a[f+i]=b[i];
	return counter;
}
long mergesort(int a[],int f,int l)
{
	long m=0;
	if(f!=l)
	{
		int mid=(f+l)/2;
		m+=mergesort(a,f,mid);
		m+=mergesort(a,mid+1,l);
		m+=merge(a,f,mid+1,l);
	}
	return m;
}
int partition (int a[],int f,int l)
{
	int t;
	int i=f-1;
	for (int j=f;j<=l-1;)
	{	cp++;
		if(a[j]<=a[l])
		{
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			j++;
		}
		else j++;
	}
	t=a[i+1];
	a[i+1]=a[l];
	a[l]=t;
	/*for(int i=0;i<=l;i++)
		cout<<a[i]<<" ";
	cout<<endl;*/
	
	return i+1;
	
}
void quicksort(int a[],int f,int l)
{
	int j;
	if(f<l)
	{
		j=partition(a,f,l);
		quicksort(a,f,j-1);
		quicksort(a,j+1,l);
	}
}
int rand_partition (int a[],int f,int l)
{
	int r,t;
	r=(rand()%(l-f+1))+f;
	t=a[r];
	a[r]=a[l];
	a[l]=t;
	int i=f-1;
	for (int j=f;j<=l-1;)
	{	rcp++;
		if(a[j]<=a[l])
		{
			i++;
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			j++;
		}
		else j++;
	}
	t=a[i+1];
	a[i+1]=a[l];
	a[l]=t;

	return i+1;
}
void rand_quicksort(int a[],int f,int l)
{
	int j;
	if(f<l)
	{
		j=rand_partition(a,f,l);
		rand_quicksort(a,f,j-1);
		rand_quicksort(a,j+1,l);
	}
}
void swap(int &x,int &y)
{
	int t;
	t=x;
	x=y;
	y=t;
}
void max_heapify(int a[], int i)
{
	int l,r,largest;
	l=((2*i)+1);
	r=((2*i)+2); 
	hcp++; 
  	if((l<heapsize)&&(a[l]>a[i]))
  		largest=l;
  	else
 		largest=i;
	if((r<heapsize)&&(a[r]>a[largest]))
		largest=r;
	if(largest!=i)
	{
        	swap(a[i],a[largest]);
        	max_heapify(a,largest);
        }
}
void build_max_heap(int a[])
{
	for(int j=((heapsize/2)-1);j>=0;j--)
		max_heapify(a,j);
}
void heap_sort(int a[],int n)
{  
	build_max_heap(a); 
	for(int k=heapsize-1;k>0;k--)
	{
		swap(a[0],a[k]);
		heapsize--;
		max_heapify(a,0);
	}
}			
int main()
{
	srand(time(NULL));
	int n,*a1,*a2,*a3,*a4,r;
	long s1=0;
	char ch='y';
	while(ch=='y')
	{
		cp=0,rcp=0,hcp=0;
		cout<<"\nEnter the size of array : ";
		cin>>n;
		heapsize=n;
		a1=new int[n];
		a2=new int[n];
		a3=new int[n];
		a4=new int[n];
		for(int i=0;i<n;i++)
		{
			r=rand()%n;
			a1[i]=r;
			a2[i]=r;
			a3[i]=r;
			a4[i]=r;
		}
		s1=mergesort(a1,0,n-1);
		quicksort(a2,0,n-1);
		rand_quicksort(a3,0,n-1);
		heap_sort(a4,n);
		cout<<"\n\t\t\t\t\t\tNo. of comparisons";
		cout<<"\n\nMerge sort\t\t\t\t:\t\t"<<s1;
		cout<<"\n\nQuick sort(last element as pivot)\t:\t\t"<<cp;
		cout<<"\n\nRandomized Quick sort\t\t\t:\t\t"<<rcp;
		cout<<"\n\nHeap sort\t\t\t\t:\t\t"<<hcp<<endl<<endl;
		cout<<"Want to Enter More?(y/n):   ";
		cin>>ch;
		cout<<endl;
	}
	return 0;
}
