#include<graphics.h>
#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>
void main()
{
   clrscr();
   int tx,ty,c,t,i,j,k,sx,sy, x1,x2,y1,y2;
   float tx1;
   int gd = DETECT, gm;
   initgraph(&gd, &gm,"C:\\TC\\BGI");
   x1 = y2 = 100;
   x2 = y1 = 150;
   rectangle(x1,y1,x2,y2);

   cout<< "Enter Choice:\n1 :Translation \n2 :Rotation \n3 :Scaling \n4 :Shearing";
   cout<<"\nChoice :";
   cin>>c;

	switch(c)
	{
		case 1:
			cout<<"Enter tx & ty :";
			cin>>tx>>ty;
			rectangle(x1+tx, y1+ty, x2+tx, y2+ty);
			break;

		case 2 :
			int xx1, yy1, xx2, yy2, xx3, yy3, xx4, yy4;
			int ax1, ay1, ax2, ay2, ax3, ay3, ax4, ay4;
			int refx, refy;
			cout<<"Enter angle :";
			cin>>tx1;
			tx1=tx1*(3.14/180);

			refx = refy = 100;

			xx1 = yy1 = yy2 = xx4 = 100;
			xx2 = xx3 = yy3 = yy4 = 150;

			ax1 = refy +(xx1-refx)* cos(tx1)-(yy1-refy)*sin(tx1);
			ay1 = refy +(xx1-refx)* sin(tx1)+(yy1-refy)*cos(tx1);

			ax2 = refy +(xx2-refx)* cos(tx1)-(yy2-refy)*sin(tx1);
			ay2 = refy +(xx2-refx)* sin(tx1)+(yy2-refy)*cos(tx1);

			ax3 = refy +(xx3-refx)* cos(tx1)-(yy3-refy)*sin(tx1);
			ay3 = refy +(xx3-refx)* sin(tx1)+(yy3-refy)*cos(tx1);

			ax4 = refy +(xx4-refx)* cos(tx1)-(yy4-refy)*sin(tx1);
			ay4 = refy +(xx4-refx)* sin(tx1)+(yy4-refy)*cos(tx1);

			line(ax1,ay1, ax2, ay2);
			line(ax2,ay2, ax3, ay3);
			line(ax3,ay3, ax4, ay4);
			line(ax4,ay4, ax1, ay1);
			break;

		case 3 :
		   cout<<"Enter sx & sy :";
		   cin>>sx>>sy;
		   rectangle(x1*sx, y1*sy, x2*sx, y2*sy);
		   break;
		   
	case 4 :{
		// shearing
	}break;
		  

		default :
			cout<<"Not a valid choice";
   }
   getch();
   closegraph();
}


/*
shearing - 

float x1,y1,x2,y2;
	float shx,shy;
	char ch;
	x1=50;y1=100;x2=100;y2=200;
	rectangle(x1,y1,x2,y2);
	delay(10);
	cout<<"enter the direction of shear : ";
	cin>>ch;
	if(ch=='x')
	{
		cout<<"enter x-direction of shear : ";
		cin>>shx;
		y1=y1+shx*x1;
		y2=y2+shx*x2;
		setcolor(RED);
		rectangle(x1,y1,x2,y2);
	}
	else
	{
		cout<<"enter y-direction of shear : ";
		cin>>shy;
		x1=x1+shy*y1;
		x2=x2+shy*y2;
		setcolor(RED);
		rectangle(x1,y1,x2,y2);
	}

*/