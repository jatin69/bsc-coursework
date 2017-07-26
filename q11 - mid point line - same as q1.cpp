#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void midpointline(int x0, int y0, int x1, int y1){
	double dx = x1 - x0;
	double dy = y1 - y0;
	int d = (2*dy)-dx;
	int a= 2*dy;
	int b= 2*(dy-dx);
	int x = x0; 
	int y = y0;
	putpixel(x,y,15);
	while(x<x1)
	{
		if(d<=0)
		{
			d +=a;
			x++;
		}
		else
		{
			d += b;
			x++;
			y++;
		}
		putpixel(x,y,15);
	}
	
}

void main(){
	clrscr();
	cout<<"\n Midpoint's line drawing algorithm\n\n";
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	int x1, y1, x0, y0;
	cout<<"Enter the start point";	cin>>x0>>y0;
	cout<<"Enter the end point"; 	cin>>x1>>y1;
	midpointline(x0,y0,x1,y1);
	
	getch();
	closegraph();
	
}