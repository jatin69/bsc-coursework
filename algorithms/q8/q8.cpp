#include<iostream>
using namespace std;
#define infinity 0xfffffff
typedef enum{White,Grey,Black}color;
struct node
{
	int data;
	node *next;
	node(int n,node *p=0)
	{
		data=n;
		next=p;
	}
};

class queue
{
	node *front;
	node *rear;
public:
	queue()
	{
		front=rear=0;
	}
	void enqueue(int x)
	{
		node *p=new node(x);
		if(isempty())
			front=rear=p;
		else
		{
			rear->next=p;
			rear=p;
		}
	}
	int dequeue()
	{
		if(isempty())
			throw"Queue is empty!!!!!";
		node *p=front;
		if (front==rear)
			front=rear=0;
		else
			front=front->next;
		int c=p->data;
		delete p;
		return c;
	}
	bool isempty()
	{
		return (front==0);
	}
};

class SLL
{
	node *head;
	node *tail;
public:
	SLL()
	{
		head=tail=0;
	}
	node *gethead()
	{
		return head;
	}
	void add_to_tail(int x)
	{
		node *p=new node(x,NULL);
		if(head==0)
		{
			head=tail=p;
		}
		else
		{
			tail->next=p;
			tail=p;
		}
	}
};

char yn;
class graph
{
	int v,e;
	int *parent;
	SLL *adjncy_list;
	color *c;
public:
	graph()
	{
		v=e=0;
	}
	void create_graph();
	void display();
	void BFS(int);
	void print_path(int,int);
};

void graph::create_graph()
{
	int m,n;
	cout<<"Enter the no of vertices: ";
	cin>>v;
	adjncy_list=new SLL[v];
	c=new color[v];
	parent=new int[v];
	cout<<"Enter the no of edges: ";
	cin>>e;
	cout<<"Graph is undirected (y/n)? : ";
	cin>>yn;
	for(int i=0;i<e;i++)
	{
		cout<<"Enter the edge(start_vertex  end-vertex) : ";
		cin>>m>>n;
		adjncy_list[m-1].add_to_tail(n-1);
		if(yn=='y')
			adjncy_list[n-1].add_to_tail(m-1);
	}
}

void graph::display()
{
	cout<<"\n********Adjacency List**********\n"<<endl;
	node *ptr;
	for(int i=0;i<v;i++)
	{
		ptr=adjncy_list[i].gethead();
		while(ptr!=0)
		{
			int temp=ptr->data;
			cout<<"{"<<i+1<<","<<temp+1<<"}";
			ptr=ptr->next;
		}
		cout<<"\n";
	}
	cout<<"\n";
}

void graph::print_path(int s,int f)
{
	if(f>=v)
		throw "\nInvalid destination";
	if(s==f)
		cout<<s+1;
	else if(parent[f]==-1)
		cout<<"\nNo path exist from "<<s+1<<" to "<<f+1<<endl;
	else
	{
		print_path(s,parent[f]);
		cout<<"-->"<<f+1;
	}
}

void graph::BFS(int s)
{
	int i;
	int *d=new int[v];
	for(i=0;i<v;i++)
	{
		c[i]=White;
		d[i]=infinity;
		parent[i]=-1;
	}
	c[s-1]=Grey;
	d[s-1]=0;
	parent[s-1]=-1;
	queue q;
	q.enqueue(s-1);
	while(!q.isempty())
	{
		int u=q.dequeue();
		node *p=adjncy_list[u].gethead();
		while(p!=0)
		{
			int n=p->data;
			if(c[n]==White)
			{
				c[n]=Grey;
				d[n]=d[u]+1;
				parent[n]=u;
				q.enqueue(n);
			}
			p=p->next;
		}
		c[u]=Black;
	}
	int dest;
	cout<<"\nEnter the destination vertex for path : ";
	cin>>dest;
	print_path(s-1,dest-1);
	cout<<"\nVertex\t\tParent\t\tDistance from source vertex\n";
	for(int i=0;i<v;i++)
	{
		if (d[i]==infinity)
			d[i]=-1;
		cout<<i+1<<"\t\t"<<parent[i]+1<<"\t\t"<<d[i]<<endl;
	}
}
int main()
{
	int s;
	graph g;
	g.create_graph();
	g.display();
	cout<<"Enter source vertex : ";
	cin>>s;
	g.BFS(s);
	return 0;
}
