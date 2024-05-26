#pragma once

extern int x_goc;
extern int y_goc;
int y_cu = 0;
int y_giam = 0;
extern int g_biendogiam;
extern int gia_cp;
extern int biendochung;


void tang_tang()
{
     srand(time(0));
     int biendotang = rand()%9+4; // bien do tang ngau nhien
     biendochung = (biendotang*-1);
     gia_cp += biendotang; // gia co phieu tang
     
     y_cu = y_goc;
     setcolor(GREEN);
     //setlinestyle(SOLID_LINE,0,8);
     y_goc-=biendotang;
     setfillstyle(SOLID_FILL, GREEN);
     bar(x_goc,y_goc,x_goc+14,y_cu); // ve do thi tang, o day gia co phieu se o tren hinh chu nhat
     setlinestyle(SOLID_LINE,0,1);
     line(x_goc+7,y_goc,x_goc+7,y_goc-15);
     line(x_goc+7,y_cu,x_goc+7,y_cu+15);
     
    
     
}
void giam()
{
     srand(time(0));
     int biendogiam = rand()%11+5; // bien do giam ngau nhien
     biendochung = biendogiam;
     g_biendogiam = biendogiam;
     gia_cp -= biendogiam; // gia co phieu giam
     
     y_cu = y_goc; 
     setcolor(RED);
     //setlinestyle(SOLID_LINE,0,8);
     y_goc+=biendogiam;
     setfillstyle(SOLID_FILL, RED);
     bar(x_goc,y_goc,x_goc+14,y_goc-biendogiam); // ve do thi giam, o day gia co phieu se o phia duoi hinh chu nhat
     setlinestyle(SOLID_LINE,0,1);
     line(x_goc+7,y_goc,x_goc+7,y_goc+15); // ve gia thap nhat o 1 thoi diem
     line(x_goc+7,y_goc,x_goc+7,y_goc-biendogiam-15); // ve giap cao nhat o 1 thoi diem
}
