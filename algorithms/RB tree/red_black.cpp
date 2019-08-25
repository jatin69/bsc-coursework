#include<iostream>
using namespace std;

enum node_color{red,black};

struct rb_node
{
	int data;
	node_color color;
	rb_node* left;
	rb_node* right;
	rb_node* parent;
	rb_node(int x,rb_node* l=0,rb_node* r=0,rb_node * p=0,node_color c=red)
	{
		data=x;
		left=l;
		right=r;
		parent=p;
		color=c;  
    }
};

class rbtree
{
	rb_node* nil;
	rb_node* root;
  public:
  	
	
  	rbtree()
    {
    	nil= new rb_node(0,0,0,0,black);
    	root=nil;
        
  	}
  	
  	void Left_Rotate(rb_node*);
  	void Right_Rotate(rb_node*);
  	void insert(int x);
  	void rb_insert_fixup(rb_node* np);
  	void delete_n(int x);
  	void delete_fixup(rb_node* x);
  	rb_node* successor(rb_node* x);
  	rb_node* ret_root();
  	rb_node* search(int s);
  	void inorder(rb_node*);
	void inorder();
  	
};
void rbtree::Right_Rotate(rb_node* y)
{
  rb_node* x;
  x=y->left;
  rb_node* b=x->right;
  x->right=y;
  y->left=b;
  b->parent=y;
  x->parent=y->parent;
  y->parent=x;
  
  if(x->parent!=nil)
  {
  	if(x->parent->left==y)
  	 {
  	 	x->parent->left=x;
  	 	
  	 }
  	 else
  	 {
  	 	x->parent->right=x;
  	 }
  }
  else
     root=x;
}
void rbtree::  Left_Rotate(rb_node* x)
{
	rb_node* y;
	y= x->right;
	rb_node* b=y->left;
	y->left=x;
	x->right = b;
	b->parent=x;
	y->parent=x->parent;
	x->parent=y;
	
	if(y->parent!=nil)
	{
		if(y->parent->left==x)
		 {
		 	y->parent->right=y;
		 }
		 else
		 {
		 	y->parent->left=y;
		 	
		 }
    }
	else
	    root =y;
	   

}
void rbtree:: insert(int x)
{
	rb_node *np=new rb_node(x);
	rb_node *fp=nil;
	rb_node *p=root;
	while(p!=nil)
	{
		fp=p;
		if(x<p->data)
		{
			p=p->left;
		}
		else
		{
			p=p->right;
		}
	}
	np->parent=fp;
	if(fp==nil)
	{
		root=np;
	}
	else if(x<fp->data)
	{
		fp->left=np;
	}
	else
		fp->right=np;
	np->left=nil;
	np->right=nil;
	np->color=red;
	rb_insert_fixup(np);
}/*
void rbtree:: insert(int x)
{
	rb_node* tmp=new rb_node(x,0,0,0,red);
	rb_node* p= root,*prev=nil;
	while(p!=nil)
	{
		prev=p;
		if(p->data<x)
		  p=p->right;
		else
		  p=p->left;
	   
   }
   
   if(root==nil)
   {
   	root=tmp;
   }
   else 
   if(prev->right->data< x)
      prev->right=tmp;
   else
     prev->left=tmp;
     
     tmp->left=nil;
	tmp->right=nil;
	tmp->color=red;
	rb_insert_fixup(tmp);
   
}*/
rb_node*  rbtree :: ret_root()
{
	     rb_node*r= root;
	    return r;
}
void rbtree::rb_insert_fixup(rb_node *np)
{
	rb_node *uncle;
	while(np->parent->color==red)
	{
		if(np->parent==np->parent->parent->left)
		{
			uncle=np->parent->parent->right;
			if(uncle->color==red)         //case1
			{
				np->parent->color=black;
				uncle->color=black;
				np->parent->parent->color=red;
				np=np->parent->parent;
			}
			else
			{
				if(np==np->parent->right) //growth is in different direction
				{	
					np=np->parent;
					Left_Rotate(np);
				}
				np->parent->color=black;
				np->parent->parent->color=red;
				Right_Rotate(np->parent->parent);
			}
		}
		else
		{
			uncle=np->parent->parent->left;
			if(uncle->color==red)         //case1
			{
				np->parent->color=black;
				uncle->color=black;
				np->parent->parent->color=red;
				np=np->parent->parent;
			}
			else
			{
				if(np==np->parent->left) //growth is in different direction
				{	
					np=np->parent;
					Right_Rotate(np);
				}
				np->parent->color=black;
				np->parent->parent->color=red;
				Left_Rotate(np->parent->parent);
			}
		}
	}
	root->color=black;
}

rb_node* rbtree::search(int s)
{
	if(root==nil)
	 {
	 	cout<<"Tree is Empty.....";
	 	
	 }
	 else
	 {
	 	rb_node* p=root;
	   	while(p!=0)
		   {
	 		if(s==p->data)
	 		  return p;
	 		if(s<p->data)
	 		  p=p->left;
	 		else
	 		  p=p->right;
	 	
	 	  }
	 }
   return nil;
   	
}
void rbtree::inorder(rb_node *p)
{
	if(p->data!=0)
	{
		inorder(p->left);
		cout<<"\t( "<<p->data<<","<<p->color<<") \t";
		inorder(p->right);
	}
}
rb_node* rbtree::successor(rb_node *x)
{
	rb_node* y;
	if(x->right!=nil)
	{
		y=x->right;
		while(y->left!=nil)
		{
			y=y->left;
		}
		return y;
	}
	/*else
	{
		y=x->parent;
		while(y!=nil&&x==y->right)
		{
			x=y;
			y=y->parent;
		}
		return y;
	}*/
}
void rbtree::delete_n(int n)
{
	if(root==nil)
		throw"tree is empty";
	rb_node *z=search(n);
	rb_node *y,*x;
	if(z->left==nil||z->right==nil)
		y=z;
	else
		y=successor(z);
	if(y->left!=nil)
		x=y->left;
	else
		x=y->right;
	x->parent=y->parent;
	if(y->parent==nil)
		root=x;
	else if(y==y->parent->left)
				y->parent->left=x;
	else	y->parent->right=x;
	if(y!=z)
	{
		z->data=y->data;

	}
	if(y->color==black)
	{
		delete_fixup(x);
	}
}
void rbtree::delete_fixup(rb_node *x)
{
	rb_node *w;
	while(x!=root&&x->color==black)
	{
		if(x==x->parent->left)
		{
			w=x->parent->right;
			if(w->color==red)       //case 1
			{
				w->color=black;
				x->parent->color=red;
				Left_Rotate(x->parent);
				w=x->parent->right;
			}
			else
			{
				if(w->left->color==black&&w->right->color==black)  //case 2
				{
					w->color=red;
					x=x->parent;
				}
				else if(w->left->color==red&&w->right->color==black)   //case 3
				{
					w->left->color=black;
					w->color=red;
					Right_Rotate(w);
					w=x->parent->right;
				}
				if(w->right->color==red)
				{
					w->color=x->parent->color;        //case 4
					x->parent->color=black;
					w->right->color=black;
					Left_Rotate(x->parent);
					x=root;
				}
			}
		}
		else
		{
			w=x->parent->left;
			if(w->color==red)       //case 5
			{
				w->color=black;
				x->parent->color=red;
				Right_Rotate(x->parent);
				w=x->parent->left;
			}
			else
			{
				if(w->left->color==black&&w->right->color==black)  //case 6
				{
					w->color=red;
					x=x->parent;
				}
				else if(w->left->color==black&&w->right->color==red)   //case 7
				{
					w->right->color=black;
					w->color=red;
					Left_Rotate(w);
					w=x->parent->left;
				}
				if(w->left->color==red)
				{
					w->color=x->parent->color;        //case 8
					x->parent->color=black;
					w->left->color=black;
					Right_Rotate(x->parent);
					x=root;
				}
			}
		}
	}
	x->color=black;
}

int main()
{
	rbtree rb;
	int choice,x;
	char k;
	do{

			cout<<"\n\n\t\t\tRED BLACK TREE\t\t\t\n";
			cout<<"\n1. Insert an element";
			cout<<"\n2. Search for an element";
			cout<<"\n3. Display the RB Tree";
			cout<<"\n4. Delete an element";
			cout<<"\n\n Enter your choice : ";
			cin>>choice;
			switch(choice)
			{
			case 1:
				cout<<"\nEnter the element you want to insert : ";
				cin>>x;
				rb.insert(x);
				break;
			case 2:{
				cout<<"\nEnter the element you want to search : ";
				cin>>x;
				rb_node* n=rb.search(x);
				if(n->data!=0)
					cout<<x<<" is present in RB Tree with color: "<<(n->color==0?"Red":"Black");
				else
					cout<<"\nElement isn't present in the list";
				break;
				   }
			
			case 3:
			{
			
				rb_node* r=rb.ret_root();
				cout<<"\nRB tree in inorder   : ";
				rb.inorder(r);
				break;
			}

			case 4:
				cout<<"\nEnter the element you want to delete : ";
				cin>>x;
				try
				{
					rb.delete_n(x);
				}
				catch(const char* s)
				{
					cout<<s;
				}
				break;
			default: 
				cout<<"\nWrong choice";
				break;
			}
			cout<<"\n Do you want to enter more? (y/n) : ";
			cin>>k;

	}while(k=='y'||k=='Y');
	
	
	return 0;
}
