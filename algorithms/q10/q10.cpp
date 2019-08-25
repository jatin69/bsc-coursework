#include<iostream> 
using namespace std;
struct node
{
	int data;
	int parent;
	node *next;
	node(int d,int p=0,node *n=0)
	{
		data=d;
		parent=p;
		next=n;
	}
};

class SLL
{
public:
	node *head;
	node *tail;
	SLL()
	{
		head=tail=0;
	}
	
node* add_to_tail(int x)
	{
		node *t=new node(x);
		if(head==0)
		{
			head=tail=t;
		}
		else
		{
			tail->next=t;
			tail=t;
		}
		return t;
	}
};

class disjoint_set
{
	int n;
	node **p;
	SLL *list;
public:
	disjoint_set(int no)
	{
		n=no;
		list=new SLL[n];
		p=new node *[n];
	}
	void make_set(int i)
	{
		node *ptr=list[i-1].add_to_tail(i);
		ptr->parent=i-1;
		p[i-1]=ptr;
	}
	int find_set(int i)
	{
		node *p1=p[i-1];
		return p1->parent;
	}
	void uni(int i,int j)
	{
		node *p2=list[j].head;
		while(p2!=0)
		{
			p2->parent=i;
			p2=p2->next;
		}
		(list[i].tail)->next=list[j].head;
		list[i].tail=list[j].tail;
		list[j].head=list[j].tail=0;
	}
};

class graph
{
	int no_of_vertices;
	int no_of_edges;
	int **a;
public:
	graph()
	{
		no_of_vertices=0;
		no_of_edges=0;
		a=0;
	}
	void create_graph();
	void display();
	void kruskal();
};

void graph::create_graph()
{
	cout<<"\nEnter no of vertices: ";
	cin>>no_of_vertices;
	cout<<"Enter no of edges: ";
	cin>>no_of_edges;
	a=new int*[no_of_edges];
	for(int i=0;i<no_of_edges;i++)
	{
		a[i]=new int[3];
		cout<<"Enter the edge and its weight: ";
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}
}

void graph::kruskal()
{
	int weight=0;
	for(int i=0;i<no_of_edges;i++)
	{
		int min=a[i][2];
		int min_indx=i;
		for(int j=i+1;j<no_of_edges;j++)
		{
			if(a[j][2]<min)
			{
				min=a[j][2];
				min_indx=j;
			}
		}
		if(min_indx!=i)
		{
			int *temp=a[i];
			a[i]=a[min_indx];
			a[min_indx]=temp;
		}
	}
	disjoint_set s(no_of_vertices);
	for(int i=0;i<no_of_vertices;i++)
		s.make_set(i+1);

	bool *e=new bool[no_of_edges];
	for(int j=0;j<no_of_edges;j++)
	{
		int u=a[j][0];
		int v=a[j][1];
		int s1=s.find_set(u);
		int s2=s.find_set(v);
		if(s1!=s2)
		{
			e[j]=true;
			s.uni(s1,s2);
		}
		else
			e[j]=false;
	}
	cout<<"\nSelected edges are:\n";
	for(int j=0;j<no_of_edges;j++)
	{
		if(e[j])
		{
			cout<<"("<<a[j][0]<<","<<a[j][1]<<","<<a[j][2]<<")";
			weight+=a[j][2];
		}
	}
	cout<<"\nThe Weight Of the Minimum Spanning Tree Is: "<<weight;
	cout<<"\n\n";
}
int main()
{
	graph g;
	g.create_graph();
	g.kruskal();
	return 0;
}
