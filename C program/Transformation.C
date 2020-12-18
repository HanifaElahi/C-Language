#include<graphics.h>
#include<math.h>
#include<conio.h>

int gdriver=DETECT, gmode;
int i,j,k,midx,midy;
char des;
int given[3][10],n;
float factor[3][3]={{0.0,0.0,0.0},{0.0,0.0,0.0},{0.0,0.0,0.0}},answer[3][10];






void mirrorfixed()
{
 float m;
 int a,b;
 clrscr();
 printf("Slop of line required...!\nPress Y if slop is infinity");
 des=getch();
 if(des == 'y'|| des == 'Y')
 {
  printf("\nEnter x-intercept value:");
  scanf("%d",&a);
  factor[0][0] = -1.0;
  factor[0][2] = 2*a;
  factor[1][1] = 1.0;
  factor[2][2] = 1.0;
 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();
 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }
    setcolor(GREEN);
    line(a+getmaxx()/2,0,a+getmaxx()/2,479);
 }
 else
 {
  printf("Enter Y-intercept value:");
  scanf("%d",&b);
  printf("Enter value of slop:");
  scanf("%f",&m);

  factor[0][0] = (1-m*m)/(1+m*m);
  factor[0][1] = (2*m)/(1+m*m);
  factor[0][2] = (-2*b*m)/(1+m*m);
  factor[1][0] = (2*m)/(1+m*m);
  factor[1][1] = (m*m-1)/(1+m*m);
  factor[1][2] = (2*b)/(1+m*m);
  factor[2][2] = (1+m*m)/(1+m*m);

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();
 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }
    setcolor(GREEN);
    line(500+getmaxx()/2,-1*(m*500+b)+getmaxy()/2,-500+getmaxx()/2,-1*(m*-500+b)+getmaxy()/2);
 }
}






void scalefixed()
{
 float sx,sy;
 clrscr();
 printf("Scalling factors Sx and Sy required...!\nEnter Sx and Sy\n");
 scanf("%f%f",&sx,&sy);
 factor[0][0] = sx;
 factor[0][2] = given[0][0]*(1-sx);
 factor[1][1] = sy;
 factor[1][2] = given[1][0]*(1-sy);
 factor[2][2] = 1.0;

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();


 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }


}










void rotatefixed()
{
 float angle;
 clrscr();
 printf("Angle required...!\nEnter value of angle(in degrees):");
 scanf("%f",&angle);
 angle *= 0.0174533;
 printf("1:Clockwise\t2:Anti clockwise");
 des=getch();
 if(des == '1')
	angle *= -1;

 factor[0][0] = (cos(angle));
 factor[0][1] = (-1*sin(angle));
 factor[0][2] = (given[0][0]*(1-cos(angle))+(given[1][0]*sin(angle)));
 factor[1][0] = (sin(angle));
 factor[1][1] = (cos(angle));
 factor[1][2] = (given[1][0]*(1-cos(angle))-(given[0][0]*sin(angle)));
 factor[2][0] = 0;
 factor[2][1] = 0;
 factor[2][2] = 1;

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();


 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }


}










void scale()
{
 float sx,sy;
 clrscr();
 printf("Scalling factors Sx and Sy required...!\nEnter Sx and Sy\n");
 scanf("%f%f",&sx,&sy);
 factor[0][0] = sx;
 factor[1][1] = sy;
 factor[2][2] = 1.0;

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();


 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }


}














void mirrory()
{
 clrscr();
 factor[0][0] = -1.0;
 factor[1][1] = 1.0;
 factor[2][2] = 1.0;

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();


 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }

}















void mirrorx()
{
 clrscr();
 factor[0][0] = 1.0;
 factor[1][1] = -1.0;
 factor[2][2] = 1.0;

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();


 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }

}















void rotate()
{
 float angle;
 clrscr();
 printf("Angle required...!\nEnter value of angle(in degrees):");
 scanf("%f",&angle);
 angle *= 0.0174533;
 printf("1:Clockwise\t2:Anti clockwise");
 des=getch();
 if(des == '1')
	angle *= -1;

 factor[0][0] = (cos(angle));
 factor[0][1] = (-1*sin(angle));
 //factor[0][2] = (given[0][0]*(1-cos(angle))+(given[1][0]*sin(angle)));
 factor[1][0] = (sin(angle));
 factor[1][1] = (cos(angle));
 //factor[1][2] = (given[1][0]*(1-cos(angle))-(given[0][0]*sin(angle)));
 factor[2][0] = 0;
 factor[2][1] = 0;
 factor[2][2] = 1;

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }

    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();


 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }


}











void translate()
{
 int a,b;
 clrscr();
 printf("\nTranslation vector required...!\nEnter value of a and b\n");
 scanf("%d%d",&a,&b);
 factor[0][0] = 1.0;
 factor[0][2] = a;
 factor[1][1] = 1.0;
 factor[1][2] = b;
 factor[2][2] = 1.0;

 for(i=0; i<3; i++)
 {
	for(j=0; j<n; j++)
	{
		for(k=0; k<3; k++)
		{
			answer[i][j] += (factor[i][k] * given[k][j]);
		}
	}
 }


    printf("\n\n\nGiven metrix is:\n");
    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%d\t\t",given[i][j]);
	}
	printf("\n");
    }
    printf("\n\n\nResultant metrix is:\n");

    for(i=0; i<3; i++)
    {
	for(j=0; j<n; j++)
	{
		printf("%.3f\t\t",answer[i][j]);
	}
	printf("\n");
    }
  getch();
  clrscr();

 initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
 midx = getmaxx()/2;
 midy = getmaxy()/2;
 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);

 setcolor(BLUE);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j-n+1]+midx,(-1*given[1][j-n+1])+midy);
	}
	else
	{
		line(given[0][j]+midx,(-1*given[1][j])+midy,given[0][j+1]+midx,(-1*given[1][j+1])+midy);
	}
 }

 setcolor(RED);
 for(j=0; j<n; j++)
 {
	if(j == n-1)
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j-n+1]+midx,(-1*answer[1][j-n+1])+midy);
	}
	else
	{
		line(answer[0][j]+midx,(-1*answer[1][j])+midy,answer[0][j+1]+midx,(-1*answer[1][j+1])+midy);
	}
 }

}










void main()
{

 clrscr();
 printf("Enter total number of vertices(e.g 3 for triangle)\n");


 scanf("%d",&n);         //Related to input
 for(j=0; j<n; j++)
 {
	for(i=0; i<2; i++)
	{
		if(i == 0)
			printf("Enter x coordinate value of %d vertex:",j+1);
		else
			printf("Enter y coordinate value of %d vertex:",j+1);
		scanf("%d",&given[i][j]);
		answer[i][j] = 0.0;
	}
 }
 for(j=0; j<n; j++)
 {
	given[2][j] = 1;
	answer[2][j] = 0.0;
 }

 printf("\nWhat do you want to do:\n");
 printf("1:Translation\n2:Rotation\n3:Mirroring about x axis\n4:Mirroring about y axis\n5:Scalling\n6:Rotation about fixed point(first pint will be fixed point)\n7:Scalling about fixed point(first point will be fixed point)\n8:Mirroring about a fixed line");
 des=getch();
 if(des == '1')
	translate();
 else if(des == '2')
	rotate();
 else if(des == '3')
	mirrorx();
 else if(des == '4')
	mirrory();
 else if(des == '5')
	scale();
 else if(des == '6')
	rotatefixed();
 else if(des == '7')
	scalefixed();
 else if(des == '8')
	mirrorfixed();
 getch();



 /*initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

 line(getmaxx()/2.0,0,getmaxx()/2,getmaxy());
 line(0,getmaxy()/2,getmaxx(),getmaxy()/2);
 line(100 + getmaxx()/2 , -50 + getmaxy()/2 , -20 + getmaxx()/2 , 10 + getmaxy()/2);
 line(-100 + getmaxx()/2 , -100 + getmaxy()/2 , 100 + getmaxx()/2 , -50 + getmaxy()/2);
 line(-20 + getmaxx()/2 , 10 + getmaxy()/2 , -100 + getmaxx()/2 , -100 + getmaxy()/2);
 getch();*/
 closegraph();
}