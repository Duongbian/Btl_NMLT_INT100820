#pragma once

extern void user_giaodien();
extern int tai_khoan;
char duong[] = "+";
char am[] = "-";
char giacp[] = "Giá cô phiêu phiên truoc: ";
char giacp_hientai[] = "Giá cô phiêu hiên tai: ";
extern int tai_khoan_check; 
extern int gia_cp;
extern int gia_cp_check;
int a[6] = {50,450,100,480,170,400}; // mang ve duong ziczac tang
int b[6] = {50,550,100,520,170,570}; // mang ve duong ziczac giam
void capnhatgiatri_user(int x1, int y1, int x2, int y2, int giatri, int co_chu, int color) // cap nhat do hoa tren man hinh trong khoang x1,x2,y1,y2
{
     setfillstyle(SOLID_FILL,WHITE);
     char chuyendoi[40];
     sprintf(chuyendoi, "%d", giatri); // su dung ham tu C de chuyen tu char sang int
     setfillstyle(SOLID_FILL,BLACK);
     bar(x1,y1,x2,y2);
     settextstyle(0,0,co_chu); // set co chu
     setcolor(color); /// mau chu 
     outtextxy(x1+10,y1,chuyendoi); // ve do hoa lien tuc cap nhat khoi luong giao dich
}

void danhgiataichinh()
{
     setcolor(GREEN);
     setlinestyle(SOLID_LINE,0,3);
     drawpoly(3,a); // ham ve duong ziczac
     
     line(160,390,180,410);
     line(160,390,185,385); // mui ten tang
     line(185,385,180,410);
     setfillstyle(SOLID_FILL, GREEN);
     
     
     setcolor(RED);
     drawpoly(3,b);
     line(180,560,160,590);
     line(185,585,180,560);
     line(185,585,160,590);
     setfillstyle(SOLID_FILL, RED);
     
     setcolor(WHITE);
     
     
}
void danhgiacp() {
     settextstyle(0,0,3);
     outtextxy(670,440, giacp);
     capnhatgiatri_user(670,480,970,550,gia_cp_check,3,14);
     setcolor(WHITE);
     outtextxy(670,580, giacp_hientai);
     capnhatgiatri_user(670,620,970,690,gia_cp,3,3);
     
}
void user() // cac tinh nang giao dien user
{
     int user_taikhoan = tai_khoan;
     bool is_quit = false;
     while (is_quit == false)
     {
          user_giaodien();
          danhgiataichinh();
          danhgiacp();
          if (( tai_khoan - tai_khoan_check ) >= 0) {
              setcolor(GREEN);
              int taikhoan_duong = tai_khoan - tai_khoan_check;
              
              capnhatgiatri_user(260,400,360,480,taikhoan_duong,6,2); // 2. Xanh la cay
              outtextxy(220,400,duong);
              setfillstyle(SOLID_FILL, BLACK);
              bar(260,530,360,580);
          } else {
              setcolor(RED);
              int taikhoan_am = tai_khoan_check - tai_khoan;
              capnhatgiatri_user(260,530,360,580,taikhoan_am,6,4); // 4. Do
              outtextxy(220,530,am);
              setfillstyle(SOLID_FILL, BLACK);
              bar(260,400,360,480);
              
          }
          capnhatgiatri_user(450,200,680,250,user_taikhoan,3,15);
          if(kbhit()) {
              char ch = getch();
              if (ch == 27)
              {
                 break;
              }
          }               
     }
}
