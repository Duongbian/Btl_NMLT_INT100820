# pragma once

extern int x_goc;
extern int y_goc;
extern int y_cu;
extern int y_giam;
extern int khoiluong_so;
extern void capnhatgiatri(int x1, int y1, int x2, int y2, int giatri);
extern bool dung;
extern int tai_khoan;
extern int tai_khoan_check;
extern int gia_cp_check;
extern int gia_cp;
extern int g_biendogiam;
extern int phien_thoigian;
extern int cophieu_sohuu;
extern int phien_sang_chieu;

extern bool quit2;
extern bool tanglientiep;
extern bool giamlientiep;
extern void loading();


char cpsap[] = "Co phieu ve 0, Doanh nghiep pha san!";
char xinloi[] = "Chung toi xin loi co dong cua minh, se co den bu ";

int s = 0;
int bienthien = 0;
int sinh_xacsuat[28] = {1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0}; // xac suat len xuong ti le tang/giam 

void khoplenhthitruong() // chuc nang san khop lenh thi truong
{
     capnhatgiatri(550,570,900,620,tai_khoan);
     if (x_goc >= 984) // truong hop do thi chay het man hinh thi xoa di cap nhat tiep
     {
         PlaySound(TEXT("bell.wav"), NULL, SND_FILENAME | SND_ASYNC);
         delay(3000);
         cleardevice();
         loading();
         cleardevice();
         tai_khoan_check = tai_khoan;
         gia_cp_check = gia_cp; // cap nhat gia cp khi het phien
         x_goc=30; // dua vi tri x ve = 30
         phien_sang_chieu++;
     }
     if (y_goc >= 510) { // truong hop co phieu co kha nang rot day
         if (phien_sang_chieu > 4) // dam bao thi truong khong sap khi  chua qua 3 phien
             {
             if (y_goc >= 510)
             {
                 gia_cp = 200; // niem yet lai gia co phieu khi vao lai san
                 x_goc = 30;
                 y_goc = 340;
                 cophieu_sohuu = 0;
                 tai_khoan += 1000;
                 settextstyle(0,0,3);
                 outtextxy(150, 200, cpsap);
                 outtextxy(50, 300, xinloi);
                 delay(10000);
                 quit2 = true;
                 
             }
         }
         else // khi chua dduoc qua 2 phien
         {
                                       
             int batday = rand()%4+2; // nhu cau nguoi dung bat day thi truong
             for (int i =0 ; i < batday;i++)
             {
                 tang_tang();
                 delay(1000);
                 x_goc+=15;
             }
                                     
         }
     }
     if ( y_goc <= 40 )
     {
         int chot_lai = rand()%4+5; // co phieu len dinh thi se có kha nang chot loi
         for (int i = 0 ; i < chot_lai; i++ )
         {
             giam();
             delay(1);
             
         }
     }
     if (tanglientiep == true ) { // giai doan xu huong tang
        int nhip_do_tang = rand()%2 +2; //  xu huong tang lien tiep
        bienthien = rand()%2+2;
        for (int i = 0; i < nhip_do_tang; i++) {
            delay(1300);
            for (int j = 0; j < bienthien; j++)
            {
                tang_tang();
                delay(1);
            }
            
            x_goc+=15;
        }
        delay(1300);
        tanglientiep = false;
     } 
     if (giamlientiep == true ) {
        int nhip_do_giam = rand()%2+2;
        bienthien = rand()%2 + 2;
        for (int i = 0; i < nhip_do_giam; i++) {
            delay(1300);
            for (int j = 0; j < bienthien; j++)
            {
                if (y_goc >= 510) {
                   break;
                }
                giam();
                delay(1);
            }
            
            x_goc+=15;
        }
        delay(1300);
        giamlientiep = false;
     }
     delay(1000);
     srand(time(0));
     s = rand()%28; // lay ngau nhien chi so trong mang
     if (sinh_xacsuat[s] == 0)
     {
         bienthien = rand()%3+2;
         khoiluong_so -= rand()%501+2500; // giam khoi luong giao dich
         capnhatgiatri(480,2,600,38,khoiluong_so);
         for ( int i = 0; i < bienthien; i++) { // bien dong manh hay yeu?
             giam();
             delay(1);
         }
     }
     else {
         bienthien = rand()%3+2;
         khoiluong_so += rand()%901 + 2600;
         capnhatgiatri(480,2,600,38,khoiluong_so); // cap nhat thay doi khoi luong giao dich khi len gia
         for (int i = 0; i < bienthien; i++) {
             tang_tang();
             delay(1);
         }
     }
     setlinestyle(SOLID_LINE,0,1);
     setcolor(WHITE);
     //line(x_goc-15,y_cu-50,x_goc,y_goc-50); // ve cac duong bien thien
     
}
void khoplenhcodinh()
{
     if (x_goc == 30)
     {
         tang_tang();
     }
     else {
          if (dung == false) {
              srand(time(0));
              s = rand()%28; // lay chi so trong mang bang cach ngau nhien tu 0 den 27: Cong thuc rand()%(a-b+1) + a
              if (sinh_xacsuat[s] == 0) // giam
              {
                  
                   
                       giam();
              
              }
              else {
                  
                       tang_tang();
                       
                   
              }
              setcolor(YELLOW);
              setlinestyle(SOLID_LINE,0,1);
              line(x_goc-15,y_cu-50,x_goc,y_goc-50); // Ve duong bien thien
          }
     }
     setlinestyle(SOLID_LINE,0,1);
     x_goc+=15;
     setcolor(WHITE);
}
