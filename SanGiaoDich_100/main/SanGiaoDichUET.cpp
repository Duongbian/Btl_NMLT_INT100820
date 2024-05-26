#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <stdlib.h>
#include <cstdio>
#include <string>
#include <ctime>
#include <mmsystem.h>

#include "vedohoa.h"
#include "thuattoantanggiam.h"
#include "khoplenh.h"
#include "user.h"
using namespace std;


char tai_san_bandau[] = "10000"; // ve tai san ban dau
char xoa_dulieu[] = "   ";

int biendochung = 0;
int g_biendogiam = 0; // su dung cho nhieu file
int gia_cp = 200; // gia co phieu theo san giao dich, ban dau niem yet o muc 200$
int tai_khoan = 10000; // tai khoan cua ban
int tai_khoan_check = 10000; // danh dau tai khoan
int gia_cp_check = 200; // danh dau gia co phieu

int x_goc = 30; // ve do thi ban dau theo x
int y_goc = 340; // theo y
int phien_sang_chieu=1;

int khoiluong_so = 1050000; // niem yet khoi luong co phieu
int cophieu_sohuu = 0; // theo tri truong
int cophieu_sohuu_codinh = 0; // theo phien

bool kq; // ko xoa duoc vi quen mat no dung vao chuc nang gi
bool tanglientiep = false;
bool giamlientiep = false;
int capnhat_ban = 0; // doi vs lenh theo thi truong
int ketthuc_ban = 0; // doi vs lenh theo phien
int capnhat_mua = 0; // cap nhat so luong mua vao khi dat du dieu kien


bool dung = false; // dieu kien dung doi voi dat lenh theo phien co dinh
bool quit2 = false; // thoat vong lap con

void capnhatgiatri(int x1, int y1, int x2, int y2, int giatri);
void nhap_mua();
void nhap_ban();
void sukienthitruong();
void nhap_mua_codinh();

int g_xacsuatsk[21] = {0,0,0,2,0,0,0,0,0,0,0,1,0,0,2,0,0,2,0,0,0}; // xac suat xay ra bien dong thi truong
int g_sukien[6] = {1,0,1,0,1,0}; // thong tin dua ve tot hay xau 1 tot 0 xau
int sobao_tot = 1; // tin tot theo tung trang
int sobao_xau = 1; // tin xau theo tung trang

char tintot1[] = "FEMA kí kêt hop tác cung câp pin xe diên cho Vinfast  ";
char tintot2[] = "FED giam lãi suât, dòng tiên vào chung khoán tang     ";
char tintot3[] = "FEMA xây dung nhà máy san xuât robot xanh o châu Âu   ";
char tintot4[] = "Tông thông My se tham chính thuc Viêt Nam trong 2 ngày";
char tintot5[] = "Tâp doàn FEMA báo lãi ky luc 11 ty Dollar trong 2 nam ";

char tinxau1[] = "Du án Age City dói vôn, FEMA lao dao tung trái phiêu  ";
char tinxau2[] = "FEMA bi cuc thuong mai TQ diêu tra chông bán phá giá  ";
char tinxau3[] = "Tình hình biên Do cang thang, thùng thuôc nô châm ngòi";
char tinxau4[] = "FEMA thu hôi 1000 robot trên thi truong vì lôi PLC    ";
char tinxau5[] = "Cô phiêu FEMA lao dao, liêu có phép màu nào xay ra    ";
int main(int argc, char *argv[])
{
    
    SetConsoleOutputCP(65001); // hàm doc tieng Viet tren man hinh console
    

    initwindow(1300,700,"SanGiaoDich.exe"); // Do hoa thuc (1250,700)
    menu();
    char ch; // kiem tra bam mua va ban;
    bool quit1 = false; // thoat vong lap chinh
     
    int mousex, mousey;
    

    while(1) // chuong trinh chinh toan bo
    {
             readimagefile("fema.jpg",0,0,1300,700);
             if (ismouseclick(WM_LBUTTONDOWN))
             {
                 getmouseclick(WM_LBUTTONDOWN,mousex,mousey);
                 if (mousex >= 300 && mousex <= 1000 && mousey >= 400 && mousey <= 600) // bam chuc nang danh theo thi truong
                 {
                     quit2 = false; // truong hop thoat ra vao lai thi mac dinh dang chay
                     cleardevice();
                     loading();
                     bangdieukhien();
                     bar(550,570,900,620);
                     outtextxy(560,578,tai_san_bandau);
                     if (quit2 == false) {
                         while (1) {
                               bangdieukhien();
                               if (kbhit())
                               {
                                   ch = getch();
                                   if (ch == 'm' || ch == 'M')
                                   {

                                        nhap_mua();
                                        capnhatgiatri(550,570,900,620,tai_khoan); // cap nhat tai khoan sau khi mua va ban
                                        cout << __DATE__ << " ";
                                        cout << __TIME__ << " Ban vua MUA " << capnhat_mua << " co phieu: Gia moi co phieu la " << gia_cp << " $ " << endl;
                                        cout << endl;
                                        cout << endl;
                                        ch = '\0'; // xoa vua nhap

                                    }
                                    if (ch == 's' || ch == 'S')
                                    {
                                        nhap_ban();
                                        capnhatgiatri(550,570,900,620,tai_khoan); // cap nhat tai khoan sau khi mua va ban
                                        cout << __DATE__ << " "; // Ngay
                                        cout << __TIME__ << " Ban vua BAN " << capnhat_ban << " co phieu: gia co phieu la " << gia_cp << " $ " << endl; // Gio
                                        cout << endl;
                                        cout << endl;
                                        ch = '\0'; // xoa vua nhap
                                    }
                                    if (ch == 27)
                                    {
                                       quit2 = true;

                                    }
                               } else { // truong hop ban khong mua hay ban hay thoat thi chuong trinh tiep tuc chay

                                 khoplenhthitruong();
                                 delay(1000);
                                 x_goc += 15;
                                 int news = rand()%21;
                                 srand(time(0));
                                 if (g_xacsuatsk[news] == 1) { // thi truong bien dong
                                    int tot_xau = rand() % 6;
                                    if (g_sukien[tot_xau] == 1) // tin vui 
                                    {
                                        setcolor(YELLOW);
                                        if (sobao_tot == 1) {
                                           outtextxy(220,650, tintot1);
                                           sobao_tot++;
                                        } else if (sobao_tot == 2) {
                                           outtextxy(220,650, tintot2);
                                           sobao_tot++;
                                        } else if (sobao_tot == 3) {
                                           outtextxy(220,650, tintot3);
                                           sobao_tot++;
                                        } else if (sobao_tot == 4) {
                                           outtextxy(220,650, tintot4);
                                           sobao_tot++;
                                        } else if (sobao_tot == 5) {
                                           outtextxy(220,650, tintot5);
                                           sobao_tot++;
                                        } else {
                                           sobao_tot = 1;
                                        }
                                        setcolor(WHITE);
                                        int biendong_tang = rand() % 4 + 5; // tang len may lan?
                                        delay(1000);
                                        for (int i = 0; i < biendong_tang; i++)
                                        {
                                            tang_tang();
                                            delay(1);
                                            if (y_goc <= 40)
                                            {
                                               break;
                                            }
                                        }
                                        x_goc += 15;
                                        
                                    } 
                                    else 
                                    {
                                        setcolor(YELLOW);
                                        if (sobao_xau == 1) {
                                           outtextxy(220,650, tinxau1);
                                           sobao_xau++;
                                        } else if (sobao_xau == 2) {
                                           outtextxy(220,650, tinxau2);
                                           sobao_xau++;
                                        } else if (sobao_xau == 3) {
                                           outtextxy(220,650, tinxau3);
                                           sobao_xau++;
                                        } else if (sobao_xau == 4) {
                                           outtextxy(220,650, tinxau4);
                                           sobao_xau++;
                                        } else if (sobao_xau == 5) {
                                           outtextxy(220,650, tinxau5);
                                           sobao_xau++;
                                        } else {
                                           sobao_xau = 1;
                                        }
                                        setcolor(WHITE);
                                        int biendong_giam = rand()%4 + 5; // giam di
                                        delay(1000);
                                        for (int i = 0; i < biendong_giam; i++)
                                        {
                                            giam();
                                            delay(1);
                                            if ( y_goc >= 510) 
                                            {
                                               break;
                                            }
                                        }
                                        x_goc += 15;
                                       
                                    }
                                 }else if (g_xacsuatsk[news] == 2) {
                                      setcolor(YELLOW);
                                      int kho_bao[8] = {1,2,3,4,5,6,7,8};
                                      int so_bao = rand()%8;
                                      if (kho_bao[so_bao] == 1) 
                                      {
                                         outtextxy(220,650,"Ngân hàng nhà nuóc giam lãi suât diêu hành            ");
                                         tanglientiep = true;
                                      } else if ( kho_bao[so_bao] == 2) 
                                      {
                                         outtextxy(220,650,"Thi truong BDS liên tuc nóng, ngáo giá dât ven        ");
                                         giamlientiep = true;
                                      } else if (kho_bao[so_bao] == 3 ) 
                                      {
                                         outtextxy(220,650,"Leo thang xung dôt o Trung Dông, giá dâu tang         ");
                                         
                                      } else if (kho_bao[so_bao] == 4) 
                                      {
                                         outtextxy(220,650,"Báo cáo tông kêt Quy II Kinh tê Viêt Nam but phá      ");
                                      } else if (kho_bao[so_bao] == 5 ) 
                                      {
                                         outtextxy(220,650,"Chung khoán châu Á tràn sac do, hôi chuông canh bao   ");
                                         giamlientiep = true;
                                      } else if (kho_bao[so_bao] == 6)
                                      {
                                         outtextxy(220,650,"Hon 60.000 ty dâu tu vào doanh nghiêp san xuât        ");
                                         tanglientiep = true;
                                      } else if (kho_bao[so_bao] == 7) 
                                      {
                                         outtextxy(220,650,"Phuong Tây áp dat 1000 lênh câm vân vao Nga           ");
                                      } else if (kho_bao[so_bao] == 8)
                                      {
                                         outtextxy(220,650,"Hôi nghi G20 se duoc tô chuc o Viêt Nam vào tháng sau ");
                                      }
                                      
                                 } else {
                                      continue;
                                 }

                                 
                               } 
                               setcolor(WHITE);
                               
                               if (quit2)
                               {
                                   cleardevice();
                                   break;
                               }
                               
                               capnhatgiatri(1005,580,1250,610,cophieu_sohuu); // cap nhat co phieu ban dang so huu

                         }
                     }

                     clearmouseclick(WM_LBUTTONDOWN);
                 }
                 if (mousex >= 300 && mousex <= 1000 && mousey>= 300 && mousey <= 400) // bam chuc nang khop lenh co dinh
                 {
                     x_goc = 30;
                     y_goc = 340;
                     gia_cp = 200;
                     cophieu_sohuu_codinh = 0;
                     quit2 = false;
                     dung = false;
                     cleardevice();
                     loading();
                     bangdieukhien_codinh();
                     capnhatgiatri(550,570,900,620,tai_khoan);
                     capnhatgiatri(1005,580,1250,610,cophieu_sohuu_codinh);
                     if (quit2 == false) {
                         while (1) {
                             if (x_goc >= 984)
                             {
                                 ketthuc_ban = cophieu_sohuu_codinh*gia_cp;
                                 tai_khoan += ketthuc_ban;
                                 capnhatgiatri(550,570,900,620,tai_khoan);
                                 quit2 = true;
                                 delay(5000);
                                 MessageBeep(MB_OK);
                                 x_goc = 30;
                             }
                             if (kbhit())
                             {
                                 ch = getch();
                                 if ( ch == 'm' || ch == 'M')
                                 {
                                      nhap_mua_codinh();
                                      setcolor(CYAN);
                                      line(0,y_goc, 1000, y_goc);
                                      capnhatgiatri(550,570,900,620,tai_khoan); // cap nhat tai khoan sau khi mua va ban
                                      cout << __DATE__ << " ";
                                      cout << __TIME__ << " Ban vua MUA " << capnhat_mua << " co phieu: Gia moi co phieu la " << gia_cp << " $ " << endl;
                                      cout << endl;
                                      cout << endl;
                                      ch = '\0'; // xoa vua nhap
                                 }
                             } else {
                                 khoplenhcodinh();
                             }
                             if (y_goc >= 540) { // truong hop co phieu rot day xuong 0
                                   settextstyle(0,0,3);
                                   outtextxy(150, 200, cpsap);
                                   outtextxy(50, 300, xinloi);
                                   delay(10000);
                                   cleardevice();
                                   quit2 = true;
                             }
                             if (quit2)
                             {
                               cleardevice();
                               break;
                             }
                             delay(1000);
                         }
                     }
                     clearmouseclick(WM_LBUTTONDOWN);

                 }
                 if (mousex >= 1053 && mousex <= 1283 && mousey >= 13 && mousey <= 75)
                 {
                    gioithieu(); // gioi thieu ve tap doan
                 }
                 if (mousex >= 1136 && mousex <= 1299 && mousey >= 250 && mousey <= 323)
                 {
                    quit1 = true; // thoat chuong trinh khi o ngoai menu
                 }
                 if (mousex >= 1054 && mousex <= 1299 && mousey >= 170 && mousey <= 244)
                 {
                    cleardevice();
                    user(); // chuc nang nguoi dung 
                    capnhatgiatri(480,200,680,250,tai_khoan);
                 }
           }
           
           if (quit1) // quit1 = true thoat chuong trinh chinh
           {
             break;
           }

   }
   closegraph();
   cout << "NGUOI DUNG SU DUNG PHAN MEM LUC: " <<__TIME__ << endl;
   cout << endl;
   cout << "@Neu co bat cu thac mac gi, hay doc huong dan va dieu khoan su dung o ben ngoai" << endl;
   cout << endl;
   cout << "Nhom tac gia bai tap lon:" << endl;
   cout << "Truong nhom: NGUYEN TUNG DUONG" << endl;
   cout << "Dong truong nhom: VU DANG DUONG" <<endl;
   cout << endl;
   cout << endl;
   
   system("pause");
   return 0;
}


void capnhatgiatri(int x1, int y1, int x2, int y2, int giatri) // cap nhat do hoa tren man hinh trong khoang x1,x2,y1,y2
{
     setfillstyle(SOLID_FILL,WHITE);
     char chuyendoi[40];
     sprintf(chuyendoi, "%d", giatri); // su dung ham tu C de chuyen tu char sang int
     bar(x1,y1,x2,y2);
     settextstyle(0,0,2);
     outtextxy(x1+10,y1+12,chuyendoi); // ve do hoa lien tuc cap nhat khoi luong giao dich
}
void nhap_mua()
{
     char mua; // bien nhan du lieu tu ban phim
     char nhap_muavao[10]; // chuoi nhan du lieu tu ban phim
     rectangle(1125,210,1275, 240);
     int vitri_nhap = 1130;
     bool thoat3 = false; // danh dau thoat vong lap
     int tamthoi_mua = 0;
     while(1) // bat dau nhap chuong trinh
     {
             if (kbhit())
             {

                 mua = getch();
                 int i = 0; // danh dau ki tu vua nhap tu ban phim
                 if (isdigit(mua)) // kiem tra nhap vao co phai so khong?
                 {
                    nhap_muavao[i++] = mua; // dua gia tri vao chuoi roi tang bien truy cap len 1
                    tamthoi_mua = tamthoi_mua*10 + (mua - '0'); // chuyen tu char sang int
                    char saochep = nhap_muavao[i-1]; // dung chuoi de chua cac ki tu vua nhap vao
                    char update[2] = {saochep,'\0'}; // dua vao mot chuoi khac
                    settextstyle(0,0,2);
                    outtextxy(vitri_nhap,215,update); // hien thi so vua nhap
                    vitri_nhap += 15; // dua vi tri nhap vao vung tiep theo

                 }

                 if (mua == 13) {
                    nhap_muavao[i] = '\0'; // ngat chuoi ki tu
                    int check = 0;
                    int check_quasotien = 0; // kiem tra mua vao co trong muc tai khoan cho phep
                    check_quasotien = tamthoi_mua*gia_cp; // lay gia tri tai san mua vai
                    if ((tai_khoan-check_quasotien) < 0 ) // lay tai khoan hien tai - gia tri mua vao xem < 0 ?
                    {
                       thoat3 = true; // thoat khi mua vao khong hop le
                    } else {
                       cophieu_sohuu += tamthoi_mua;
                       capnhat_mua = tamthoi_mua;
                       tai_khoan -= check_quasotien; // tru di so tien trong tai khoan sau khi mua co phieu
                       cout << "So tai khoan la: " << tai_khoan << " $ " << endl;

                    }
                    while (nhap_muavao[check] != '\0')
                    {
                          nhap_muavao[check] = '\0'; // xoa het mang vua nhap
                          check++;
                    }
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(1125,210,1280,250);
                    thoat3 = true; // dung chuong trinh
                 } else if ( mua == 8 || mua == '\b') // xoa
                 {

                        i--; // giam i 1 don vi
                        outtextxy(vitri_nhap-15,215,xoa_dulieu); // xoa bang cach ve ki tu rong
                        vitri_nhap -= 15; // lui vi tri hien thi
                        tamthoi_mua /= 10; // giam gia tri di mot chu so
                        nhap_muavao[i] = '\0'; // danh dau vi tri ki tu trong chuoi vua xoa = rong

                 } else {
                        continue;
                 }
             }
             if (thoat3){
                break;
             }


     }
}
void nhap_mua_codinh()
{
     char mua; // bien nhan du lieu tu ban phim
     char nhap_muavao[10]; // chuoi nhan du lieu tu ban phim
     rectangle(1125,210,1275, 240);
     int vitri_nhap = 1130;
     bool thoat3 = false; // danh dau thoat vong lap
     int tamthoi_mua = 0;
     while(1) // bat dau nhap chuong trinh
     {
             if (kbhit())
             {

                 mua = getch();
                 int i = 0; // danh dau ki tu vua nhap tu ban phim
                 if (isdigit(mua)) // kiem tra nhap vao co phai so khong?
                 {
                    nhap_muavao[i++] = mua; // dua gia tri vao chuoi roi tang bien truy cap len 1
                    tamthoi_mua = tamthoi_mua*10 + (mua - '0'); // chuyen tu char sang int
                    char saochep = nhap_muavao[i-1]; // dung chuoi de chua cac ki tu vua nhap vao
                    char update[2] = {saochep,'\0'}; // dua vao mot chuoi khac
                    settextstyle(0,0,2);
                    outtextxy(vitri_nhap,215,update); // hien thi so vua nhap
                    vitri_nhap += 15; // dua vi tri nhap vao vung tiep theo

                 }

                 if (mua == 13) {
                    nhap_muavao[i] = '\0'; // ngat chuoi ki tu
                    int check = 0;
                    int check_quasotien = 0; // kiem tra mua vao co trong muc tai khoan cho phep
                    check_quasotien = tamthoi_mua*gia_cp; // lay gia tri tai san mua vai
                    if ((tai_khoan-check_quasotien) < 0 ) // lay tai khoan hien tai - gia tri mua vao xem < 0 ?
                    {
                       thoat3 = true; // thoat khi mua vao khong hop le
                    } else {
                       cophieu_sohuu_codinh += tamthoi_mua;
                       capnhat_mua = tamthoi_mua;
                       tai_khoan -= check_quasotien; // tru di so tien trong tai khoan sau khi mua co phieu
                       cout << "So tai khoan la: " << tai_khoan << " $ " << endl;

                    }
                    while (nhap_muavao[check] != '\0')
                    {
                          nhap_muavao[check] = '\0'; // xoa het mang vua nhap
                          check++;
                    }
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(1125,210,1280,240);
                    thoat3 = true; // dung chuong trinh
                 } else if ( mua == 8 || mua == '\b')
                 {

                        i--; // giam i 1 don vi
                        outtextxy(vitri_nhap-15,215,xoa_dulieu); // xoa bang cach ve ki tu rong
                        vitri_nhap -= 15; // lui vi tri hien thi
                        tamthoi_mua /= 10;
                        nhap_muavao[i] = '\0'; // danh dau vi tri ki tu trong chuoi vua xoa = rong

                 } else {
                        continue;
                 }
             }
             if (thoat3){
                break;
             }


     }
}
void nhap_ban()
{
     char ban;
     char nhap_banra[10];
     rectangle(1125,410,1275, 440);
     int vitri_nhap = 1130;
     bool thoat3 = false; // danh dau thoat vong lap
     int tamthoi_ban = 0;
     while(1) // bat dau nhap chuong trinh
     {
             if (kbhit())
             {

                 ban = getch();
                 int i = 0; // danh dau ki tu vua nhap tu ban phim
                 if (isdigit(ban)) // kiem tra nhap vao co phai so khong?
                 {
                    if ( ban == 8)
                    {
                        i--; // giam i 1 don vi
                        outtextxy(vitri_nhap-15,215,xoa_dulieu); // xoa bang cach ve ki tu rong
                        vitri_nhap -= 15; // lui vi tri hien thi
                        tamthoi_ban /= 10;
                        nhap_banra[i] = '\0'; // danh dau vi tri ki tu trong chuoi vua xoa = rong
                    } else {
                        nhap_banra[i++] = ban; // gan gia tri "ban" vao vi tri i roi tang i len 1 ( su dung hau to )
                        tamthoi_ban = tamthoi_ban*10 + (ban - '0'); // chuyen tu char sang int
                        char saochep = nhap_banra[i-1]; // dung chuoi de chua cac ki tu vua nhap vao
                        char update[2] = {saochep,'\0'}; // dua vao mot chuoi khac
                        settextstyle(0,0,2);
                        outtextxy(vitri_nhap,415,update); // hien thi so vua nhap
                        vitri_nhap += 15; // dua vi tri nhap vao vung tiep theo
                    }
                 }

                 if (ban == 13) {
                    nhap_banra[i] = '\0'; // ngat chuoi ki tu
                    int check = 0;
                    int check_am = 0;
                    int capnhatgiaban = cophieu_sohuu*gia_cp;
                    check_am = cophieu_sohuu - tamthoi_ban;

                    if ( check_am < 0){ // kiem tra so luong ban co hon so luong co phieu so huu khong
                         thoat3 = true;
                    }
                    else {
                        cophieu_sohuu -= tamthoi_ban; // co phieu dang so huu giam xuong voi so luong tuong duong co phieu ban di
                        capnhat_ban = tamthoi_ban; // co mot bien luu tru
                        tai_khoan += capnhatgiaban; // tang tien khi ban
                        cout << "so tai khoan la: " << tai_khoan << " $ " << endl;

                    }
                    while (nhap_banra[check] != '\0')
                    {
                          nhap_banra[check] = '\0'; // xoa bo mang
                          check++;
                    }
                    setfillstyle(SOLID_FILL, BLACK);
                    bar(1125,410,1280,450);
                    thoat3 = true; // dung chuong trinh
                 } else if (ban == 8 || ban == '\b') {
                    i--; // giam i 1 don vi
                    outtextxy(vitri_nhap-15,415,xoa_dulieu); // xoa bang cach ve ki tu rong
                    vitri_nhap -= 15; // lui vi tri hien thi
                    tamthoi_ban /= 10;
                    nhap_banra[i] = '\0'; // danh dau vi tri ki tu trong chuoi vua xoa = rong    
                 
                 } else {
                    continue;
                 }
             }
             if (thoat3){
                break;
             }



     }
}

