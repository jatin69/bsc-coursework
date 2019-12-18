// Write a program to apply various 2D transformations on a 2D object(use homogeneous coordinates).

#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

void display();
void translate();
void reflection();
void rotation();
void shearing();
void scaling();

int n,c=0,i,j,disp[30];
float points[10][3],tem[10][3],t[3][3];

void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
	clrscr();
	cout<<"Enter no. of points\n";
	cin>>n;
	cout<<"Enter point(x,y) row-wise\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		cin>>points[i][j];
		points[i][j]=1;
	}
	points[n][0]=points[0][0];
	points[n][1]=points[0][1];
	while(c!=7)
	{
		cout<<"\n1. Display\n";
		cout<<"\n2. Translate\n";
		cout<<"\n3. Reflect\n";
		cout<<"\n4. Rotate\n";
		cout<<"\n5. Scaling\n";
		cout<<"\n6. Shearing\n";
		cout<<"\n7. Exit\n";
		cout<<"\nEnter your choice\n";
		cin>>c;
		switch(c)
		{
			case 1: display();
			break;
			case 2: translate();
			break;
			case 3: reflection();
			break;
			case 4: rotation();
			break;
			case 5: scaling();
			break;
			case 6: shearing();
			break;
			case 7:
			break;
			default: cout<<"Invalid choice\n";
			break;		
		}
	}
	getch();
	closegraph();
}

void translate()
{
	float x,y;
	cout<<"How many units you want to translate x and y coordinates\n";
	cin>>x>>y;
	j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			if(j==0)
				points[i][j]=points[i][j]+x;
			else
				points[i][j]=points[i][j]+y;
		}
	}
	points[n][0]=points[0][0];
	points[n][1]=points[0][1];
	cout<<"\nTranslation Successful\n";
}

void scaling()
{
	float x,y;
	cout<<"How many units you want to scale x and y coordinates\n";
	cin>>x>>y;
	j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		{
			if(j==0)
				points[i][j]=points[i][j]*x;
			else
				points[i][j]=points[i][j]*y;
		}
	}
	points[n][0]=points[0][0];
	points[n][1]=points[0][1];
	cout<<"\nScaling Successful\n";
}

void reflection()
{
	int c;
	float temp;
	cout<<"\n1. reflect around x-axis or y=0";
	cout<<"\n2. reflect around y-axis or x=0";
	cout<<"\n3. reflect around y=x\n";
	cout<<"\n4. reflect around y=-x\n";
	cin>>c;
	if(c==1)
	{
		for(i=0;i<n;i++)
			points[i][1]=-points[i][1];
	}
	else if(c==2)
	{
		for(i=0;i<n;i++)
			points[i][0]=-points[i][0];
	}
	else if(c==3)
	{
		for(i=0;i<n;i++)
		{
			temp=points[i][0];
			points[i][0]=points[i][1];
			points[i][1]=temp;
		}		
	}
	else if(c==4)
	{
		for(i=0;i<n;i++)
		{
			temp=points[i][0];
			points[i][0]=-points[i][1];
			points[i][1]=-temp;
		}			
	}	
	points[n][0]=points[0][0];
	points[n][1]=points[0][1];
	cout<<"\nReflection Successful\n";
}

void shearing()
{
	int s,f,t,i,j;
	char c;
	cout<<"\nFor x shear press x, for y shear press y\n";
	cin>>c;
	cout<<"How many units you want to shear?\n";
	cin>>s;
	if(c=='x')
	{
		for(i=0;i<n;i++)
			points[i][0]=points[i][0]+s*points[i][1];
	}
	else if(c=='y')
	{
		for(i=0;i<n;i++)
			points[i][1]=points[i][1]+s*points[i][0];
	}
	points[n][0]=points[0][0];
	points[n][1]=points[0][1];
	cout<<"\nShearing Successful\n";
}

void rotation()
{
	int c;
	float x,y;
	double d;
	cout<<"\nFor rotation about origin enter 1, for rotation about arbitrary point enter 2\n";
	cin>>c;
	cout<<"How many degree you want to rotate the points?\n";
	cin>>d;
	d=(d*3.141/180.0);
	if(c==1)
	{	
		t[0][0]=cos(d);
		t[0][1]=sin(d);
		t[1][0]=-sin(d);
		t[1][1]=cos(d);
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				if(j==0)
					tem[i][0]=points[i][0]*t[0][0]+points[i][1]*t[1][0];
				else
					tem[i][1]=points[i][0]*t[0][1]+points[i][1]*t[1][1];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
				points[i][j]=tem[i][j];
		}
	}
	else if(c==2)
	{	
		cout<<"Enter the x and y coordinates of arbitrary points\n";
		cin>>x>>y;
		t[0][0]=cos(d);
		t[0][1]=sin(d);
		t[1][0]=-sin(d);
		t[1][1]=cos(d);
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				if(j==0)
					points[i][0]=points[i][0]-x;
				else
					points[i][1]=points[i][1]-y;
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				if(j==0)
					tem[i][0]=points[i][0]*t[0][0]+points[i][1]*t[1][0];
				else
					tem[i][1]=points[i][0]*t[0][1]+points[i][1]*t[1][1];
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<2;j++)
			{
				points[i][j]=tem[i][j];
				if(j==0)
					points[i][0]=points[i][0]+x;
				else
					points[i][1]=points[i][1]+y;
			}
		}
	}
	points[n][0]=points[0][0];
	points[n][1]=points[0][1];
	cout<<"\nRotation Successful\n";
}

void display()
{
	clrscr();
	for(i=0;i<=n;i++)
	{
		disp[2*i]=10*points[i][0]+310;
		disp[2*i+1]=-10*points[i][1]+195;
	}
	i=0;
	int j=0;
	while(j<400)
	{
		putpixel(310,j,RED);
		j++;
	}
	while(i<700)
	{
		putpixel(i,195,RED);
		i++;
	}
	if(n==1)
		putpixel(disp[0],disp[1],WHITE);
	else
		drawpoly(n+2,disp);
	getch();
}
