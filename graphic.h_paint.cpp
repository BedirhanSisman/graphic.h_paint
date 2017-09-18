#include <graphics.h>
#include <stdio.h>
void windowform()
{
int i,j;
setcolor(15);
outtextxy(400,530,îùCopyrights @îù);
outtextxy(400,550,îùbedirhanSismanîù);
//Start Building Tools
bar(100,100,500,500);
setcolor(1);
outtextxy(5,5, ìPaintîù);

setcolor(4);
outtextxy(5,75, ìTools:îù);

bar(5,20,80,45);
setbkcolor(15);
setcolor(2);
outtextxy(5,25,îùEXITîù);

bar(5,100,80,180);
setbkcolor(15);
setcolor(2);
outtextxy(5,110,îùPencilîù);

bar(5,200,80,280);
setbkcolor(15);
setcolor(2);
outtextxy(5,210,îùLineîù);
line(5,250,80,250);

bar(5,300,80,380);
setbkcolor(15);
setcolor(2);
outtextxy(5,310,îùCircleîù);
circle(50,350,25);

bar(5,400,80,480);
setbkcolor(15);
setcolor(2);
outtextxy(5,410,îùRectangleîù);
rectangle(30,430,70,475);

bar(250,520,350,580);
setbkcolor(15);
setcolor(2);
outtextxy(275,530,îùEraserîù);

bar(100,30,500,80);

//End Building Tools

//Start Building Colors
setbkcolor(0);
outtextxy(520,75,îùColor:îù);
//For Red color
for(i=120;i<=180;i++)
{
for(j=520;j<=580;j++)
{
putpixel(j,i,4);
}
}

//For Green color
for(i=220;i<=280;i++)
{
for(j=520;j<=580;j++)
{
putpixel(j,i,2);
}
}

//For Blue color
for(i=320;i<=380;i++)
{
for(j=520;j<=580;j++)
{
putpixel(j,i,1);
}
}

//End Building Colors
}

int drawnow(int xcl, int ycl,char cmd,int clr)
{
setcolor(clr);
if(cmd==íeí)
{
setcolor(9);
outtextxy(200,200,îùexit clciked will exit in 5 secondsîù);
delay(5000);
exit(1);
}
else if(cmd==ípí)
{
clearmouseclick(WM_LBUTTONUP);
while(!ismouseclick(WM_LBUTTONUP))
{
if(xcl < 500 && xcl > 100 && ycl < 500 && ycl >100)
{
putpixel(xcl-1,ycl-1,clr);
putpixel(xcl,ycl-1,clr);
putpixel(xcl+1,ycl-1,clr);
putpixel(xcl-1,ycl,clr);
putpixel(xcl,ycl,clr);
putpixel(xcl+1,ycl,clr);
putpixel(xcl-1,ycl+1,clr);
putpixel(xcl,ycl+1,clr);
putpixel(xcl+1,ycl+1,clr);
xcl= mousex() , ycl= mousey();
}
else
{
break;
}
}
}
else if(cmd==ílí)
{
int nx,ny;
outtextxy(110,40,îùEnter end point of line in x, y ì);
scanf(ì%d %dîù,&nx,&ny);
nx=nx+xcl;ny=ny+ycl;
line(xcl,ycl,nx,ny);
bar(100,30,500,80);
}
else if(cmd==ící)
{
int r;
outtextxy(110,40,îùEnter radius of circleîù);
scanf(ì%dîù,&r);
circle(xcl,ycl,r);
bar(100,30,500,80);
}
else if(cmd==írí)
{
int xe,ye;
outtextxy(110,40,îùBottom end point of rectangleîù);
scanf(ì%d %dîù,&xe,&ye);
xe=xe+xcl;ye=ye+ycl;
rectangle(xcl,ycl,xe,ye);
bar(100,30,500,80);
}
else if(cmd==ísí)
{
clearmouseclick(WM_LBUTTONUP);
while(!ismouseclick(WM_LBUTTONUP))
{
if(xcl < 500 && xcl > 100 && ycl < 500 && ycl >100)
{
putpixel(xcl-1,ycl-1,15);
putpixel(xcl,ycl-1,15);
putpixel(xcl+1,ycl-1,15);
putpixel(xcl-1,ycl,15);
putpixel(xcl,ycl,15);
putpixel(xcl+1,ycl,15);
putpixel(xcl-1,ycl+1,15);
putpixel(xcl,ycl+1,15);
putpixel(xcl+1,ycl+1,15);
xcl= mousex() , ycl= mousey();
}
else
{
break;
}
}
}
else
{
return(1);
}
}

void mouseclick()
{
int xcl,ycl,clr=4;
char cmd;

while(1) //starts infinite loop
{
clearmouseclick(WM_LBUTTONDOWN);
if(ismouseclick(WM_LBUTTONDOWN)) //Detects Mouse Click
{
xcl = mousex(); ycl = mousey();//Traces x , y of mouse position
clearmouseclick(WM_LBUTTONDOWN);
//Start assocoating an command to respective click on window
if(xcl<80 && xcl>5)
{
if(ycl<45 && ycl>20)
{
cmd=íeí;
drawnow(xcl,ycl,cmd,clr);
}
else if(ycl<180 && ycl>100)
{
cmd=ípí;
}
else if(ycl<280 && ycl>200)
{
cmd=ílí;
}
else if(ycl<380 && ycl>300)
{
cmd=ící;
}
else if(ycl<480 && ycl>400)
{
cmd=írí;
}
else
{
cmd=íní;
}
}

else if(xcl<350 && xcl>250 && ycl<580 && ycl>520)
{
cmd=ísí;
}

else if(xcl<500 && xcl>100 && ycl<500 && ycl>100)
{
drawnow(xcl,ycl,cmd,clr);
}

else if(xcl<580 && xcl>520)
{
if(ycl<180 && ycl>120)
{
clr=4;
}
if(ycl<280 && ycl>220)
{
clr=2;
}
if(ycl<380 && ycl>320)
{
clr=1;
}
}

else cmd=íní;
}
}
delay(50);
}

int main()
{
printf(ìInput Datas:\nîù);
initwindow(600, 600,îùSimple Paint Program using C by bedirhanSismanîù,20,20);
windowform();
mouseclick();
}
