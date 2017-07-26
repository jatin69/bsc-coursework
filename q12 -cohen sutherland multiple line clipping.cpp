#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>

void drawLine(int,int,int,int);
int xmin,xmax,ymin,ymax;

int main(){
	clrscr();
	int gm,gd=DETECT;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	
	int n;
	cout<<"Enter windows coordinates (bottom-left,top-right) : ";	cin>>xmin>>ymin>>xmax>>ymax;
	cout<<"Enter no. of points "; 	cin>>n;
	int *x=new int[n+1]; 	
	int *y=new int[n+1];
	
	cout<<"Enter n points : ";
	for(int i=0;i<n;i++){ 	cin>>x[i]; 	cin>>y[i]; 	}
	x[n]=x[0];
	y[n]=y[0];
	
	clrscr();
	cleardevice();
	
	cout<<"unclipped is : ";
	rectangle(xmin,ymin,xmax,ymax);
	for(i=0;i<n;i++){
		line(x[i],y[i],x[i+1],y[i+1]);
	}
	
	getch();
	clrscr();
	cleardevice();
cout<<"clipped is : ";
		
	rectangle(xmin,ymin,xmax,ymax);

		setcolor(15);
	for(i=0;i<n;i++){
		drawLine(x[i],y[i],x[i+1],y[i+1]);
	}
	
	getch();
	closegraph();
	return 0;
}


void drawLine(int x1,int y1,int x2,int y2){

	int start[4],end[4];
	for(int i=0;i<4;i++){		start[i]=0; 	end[i]=0; 	}
	
	float slope=((float)y2-y1)/(x2-x1);
	
	if(x1<xmin) start[0]=1;
	if(x1>xmax) start[1]=1;
	if(y1>ymax) start[2]=1;
	if(y1<ymin) start[3]=1;
	
	if(x2<xmin) end[0]=1;
	if(x2>xmax) end[1]=1;
	if(y2>ymax) end[2]=1;
	if(y2<ymin) end[3]=1;
	
	int code[4]={0};
	for(i=0;i<4;i++)
	{	code[i]=start[i]&&end[i]; }
	
	// if code is 0000
	if(! (code[0]&&code[1]&&code[2]&&code[3])){
		
		// if start and end is in 0000
		if(!start[0] && !start[1] && !start[2] && !start[3] && !end[0] && !end[1] && !end[2] && !end[3]){
			line(x1,y1,x2,y2);
		}
		else{
			// or, is start and end is not in 0000
			if(!start[2]  && start[3]){
				x1=x1+(ymin-y1)/slope;
				y1=ymin;
			}
			if(!end[2]  && end[3]){
				x2=x2+(ymin-y2)/slope;
				y2=ymin;
			}
			if(start[2]  && !start[3]){
				x1=x1+(ymax-y1)/slope;
				y1=ymax;
			}
			if(end[2]  && !end[3]){
				x2=x2+(ymax-y2)/slope;
				y2=ymax;
			}
			if(!start[1]  && start[0]){
				y1=y1+(xmin-x1)*slope;
				x1=xmin;
			}
			if(!end[1]  && end[0]){
				y2=y2+(xmin-x2)*slope;
				x2=xmin;
			}
			if(start[1]  && !start[0]){
				y1=y1+(xmax-x1)*slope;
				x1=xmax;
			}
			if(end[1]  && !end[0]){
				y2=y2+(xmax-x2)*slope;
				x2=xmax;
			}
			line(x1,y1,x2,y2);
		}
	}
}