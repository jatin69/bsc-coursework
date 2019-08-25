#include<iostream>
using namespace std;
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
			throw"queue is empty!!!!!!";
		node *p=front;
		if(front==rear)
			front =rear=0;
		else
			front=front->next;
		int c=p->data;
		delete p;
		return c;
	}
	bool isempty()
	{
		return(front==0);
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
		node *p=new node(x);
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
	int *parent,*s,*f;
	color *c;
	SLL *adjncy_list;
public:
	graph()
	{
		v=e=0;
	}
	void create_graph();
	void display();
	void DFS();
	void DFS_Visit(int,int &);
};

void graph::create_graph()
{
	int m,n;
	cout<<"Enter the no of vertices : ";
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
		cout<<"Enter the edge(start_vertex  end_vertex) : ";
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

void graph::DFS()
{
	int i,time=0;
	for(i=0;i<v;i++)
	{
		c[i]=White;
		parent[i]=-1;
	}
	s=new int[v];
	f=new int[v];
	for(i=0;i<v;i++)
	{
		if(c[i]==White)
			DFS_Visit(i,time);
	}
	cout<<"Vertex\t\tParent\t\tDiscovery time\t\tFinish time\n";
	for(int i=0;i<v;i++)
		cout<<i+1<<"\t\t"<<parent[i]+1<<"\t\t"<<s[i]<<"\t\t\t"<<f[i]<<endl;
}

void graph::DFS_Visit(int i,int &time)
{
	c[i]=Grey;
	time++;
	s[i]=time;
	node *ptr=adjncy_list[i].gethead();
	while(ptr!=0)
	{
		int n=ptr->data;
		if(c[n]==White)
		{
			parent[n]=i;
			DFS_Visit(n,time);
		}
		ptr=ptr->next;
	}
	c[i]=Black;
	time++;
	f[i]=time;
}

int main()
{
	graph g;
	g.create_graph();
	g.display();
	g.DFS();
	cout<<endl;
	return 0;
}
