#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	int xc=300,yc=250; 	// center coordinates
	int rad;
	int x=0;
	cout<<"\nEnter the radius of circle :-";
	cin>>rad;
	int y=rad;
	//int d=1-rad;
	int d=floor(1.25*r);
	putpixel(xc,yc,WHITE);
	while(x<=y)
	{
		if(d<0)
		{
			d+=((2*x)+3);
			x++;
		}
		else
		{
			d+=(2*(x-y))+5;
			x++;
			y--;
		}		
		putpixel(xc+x,yc+y,15); //8 way symmetry
		putpixel(xc+x,yc-y,15);
		
		putpixel(xc-x,yc+y,15);
		putpixel(xc-x,yc-y,15);
		
		putpixel(xc+y,yc+x,15);
		putpixel(xc+y,yc-x,15);
		
		putpixel(xc-y,yc+x,15);
		putpixel(xc-y,yc-x,15);
  }
	getch();
	closegraph();
}
