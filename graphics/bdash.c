#include<stdio.h>
#include<graphics.h>
#include<math.h>
void main()
{
    int gd=DETECT,gm,x,y,x1=50,y1=50,x2=400,y2=400,dx,dy,i,e,k,j;
    int d=1,a=2,n=1;
    float xinc,yinc;
    initgraph(&gd,&gm,"");
    cleardevice();
    dx=x2-x1;
    dy=y2-y1;
    if(x1<x2)
        xinc=1;
    else
        xinc=-1;
    if(y1<y2)
        yinc=1;
    else
        yinc=-1;
    x=x1;
    y=y1;
    if(dx>=dy)
     { e=(2*dy)-dx;
        k=0;
        while(x1!=x2)
        {
            if(d==1)
                a=1;
            if(k%10==0 && d==1)
                a=5;
            if(e<0)
                e=e+2*dy;
            else
            {
                e=e+2*(dy-dx);
                y=y+yinc*a;
            }
            x=x+xinc*a;
            k++;
            for(j=0;j<n;j++)
            { putpixel((int)(x+j),(int)(y-j),WHITE);
                delay(100);
            }
        }
    }
    else
    {  k=0;
        e=(2*dx)-dy;
        while(y1!=y2)
        {
            if(d==1)
                a=1;
            if(k%10==0 && d==1)
                a=4;
            if(e<0)
                e=e+2*dx;
            else
            {
                e=e+2*(dx-dy);
                x=x+xinc*a;
            }
            y=y+yinc*a;
            k++;
            for(j=0;j<n;j++)
            {
                putpixel((int)(x-j),(int)(y+j),WHITE);
                delay(100);
            }
        }
    }
    getch();
    closegraph();
    restorecrtmode();
}
