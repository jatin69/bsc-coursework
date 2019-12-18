#include<iostream.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	clrscr();
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	setcolor(RED);
	line(100,100,50,200);
	line(100,100,150,200);
	line(50,200,400,200);
	line(100,100,350,100);
	line(350,100,400,200);
	line(50,200,50,400);
	line(150,200,150,400);
	line(50,400,400,400);
	line(400,200,400,400);
	getch();
	return 0;
}