#include<graphics.h>
#include<iostream.h>
#include<conio.h>

void main()
{	
	clrscr();
	int gd=DETECT,gm;
	int x[4],y[4];
	float u1,u2,u3,u4,xp,yp;
	initgraph(&gd,&gm,"C:\\TurbcoC3\\BGI");
	settextstyle(5,HORIZ_DIR,6);
	outtextxy(150,0,"Hermite Curve");
	gotoxy(10,10);
	for(int i=0; i<4; i++)
	{
		cout<<"\nEnter the point "<<i+1<<" ";
		cin>>x[i]>>y[i];
	}
 
	/*cout<<"Enter the coordinates of First Endpoint(X,Y)";
    cin>>Geometry[0][0]>>Geometry[0][1];
    cout<<"Enter the coordinates of second Endpoint(X,Y)";
    cin>>Geometry[1][0]>>Geometry[1][1];
    cout<<"Enter the coordinates of tangent to the first Endpoint(X,Y)";
    cin>>Geometry[2][0]>>Geometry[2][1];
    cout<<"Enter the coordinates of tangent to second Endpoint(X,Y)";
    cin>>Geometry[3][0]>>Geometry[3][1];*/
	
    
	cleardevice();
	//putpixel(Geometry[0][0],Geometry[0][1],WHITE);
	for(float t=0.0;t<=1.0;t+=0.001)
	{
	    u1 =  2*t*t*t - 3*t*t + 1;
	    u2 = -2*t*t*t + 3*t*t;
	    u3 =  t*t*t - 2*t*t + t;
	    u4 =  t*t*t - t*t;

	    xp = u1*x[0]+u2*x[1]+u3*x[2]+u4*x[3];
	    yp = u1*y[0]+u2*y[1]+u3*y[2]+u4*x[3];
		
		putpixel(xp,yp,WHITE);
	}
	for(i=0; i<4; i++)
		putpixel( x[i], y[i],WHITE);

	//putpixel(Geometry[1][0],Geometry[1][1],WHITE);
	getch();
	closegraph();
}
