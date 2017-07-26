#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main()
{
	clrscr();
	cout<<"\nBresenham's line drawing algorithm\n\n";
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	int x1, y1, x0, y0;
	cout<<"Enter the 1st point";	cin>>x0>>y0;
	cout<<"Enter the 2nd point"; 	cin>>x1>>y1;
	
	int dx = x1 - x0;
	int dy = y1 - y0;
	int d = (2*dy)-dx;
	
	int a= 2*dy;
	int b=-2*dx;
	
	int x = x0; 
	int y = y0;
	
	while(x<x1)
	{
		if(d<=0)
		{
			d +=a;;
			putpixel(x, y, RED);
			x++;
		}
		else
		{
			d += (a+b);
			putpixel(x, y, RED);
			x++;
			y++;
		}
	}
	getch();
	closegraph();
}