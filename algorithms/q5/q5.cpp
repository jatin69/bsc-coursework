#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	float data;
	node *next;
	node(float d,node* z)
	{
		data=d;
		next=z;
	}
};
class sll
{
public:
	node *head,*tail;
	sll()
	{
		head=tail=NULL;
	}
	~sll()
   	{
   		while(head!=NULL)
           	{
           		node *p=head;
               		head=head->next;
               		delete p;
           	}
	   	head=tail=0;
   	}
	void insert(float);
};

void sll:: insert(float d)
{
	node *p=new node(d,NULL);
	if(head==NULL)
	{
		head=tail=p;
	}
	else if(p->data<head->data)
	{
		p->next=head;
		head=p;
	}
	else if(p->data>tail->data)
	{
		tail->next=p;
		tail=p;
	}
	else
	{
		node *y=head;
		node *a=NULL;
		while(y->data<p->data)
		{
			a=y;
			y=y->next;
		}
		a->next=p;
		p->next=y;
	}
}
void bucketsort(float *a,int n)
{
	sll *bucket=new sll[n];
	for(int i=0;i<n;i++)
	{
		int j=(int)(n*a[i]);
		bucket[j].insert(a[i]);
	}
	int i=0;
	for(int k=0;k<n;k++)
	{
		node *p=bucket[k].head;
		while(p!=0)
		{
			a[i]=p->data;
			i++;
			p=p->next;
		}
	}
}
int main()
{
	int n,r;
	cout<<"\nEnter size of array : ";
	cin>>n;
	srand(time(NULL));
	float *a=new float[n];
	for (int i=0;i<n;i++)
	{
		int r=rand()%1000000;
		a[i]=(float)r/1000000;
	}
	cout <<"\nUnsorted array is :\n";
    	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	bucketsort(a,n);
	cout<<"\n\nSorted array is :\n";
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout <<"\n\n";
	return 0;
}
