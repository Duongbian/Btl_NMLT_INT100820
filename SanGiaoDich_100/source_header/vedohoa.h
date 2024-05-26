#pragma once
#pragma comment(lib, "winmm.lib")

char thoat_thitruong[] = "Bâm ESC"; // nut thoat trong phien thi truong
char mua[] = "Mua vào";
char ban[] = "Bán ra";
char lenh[] = "Command";
char fema[] = "FEM";
char tencp[] =  "Mã CP";
char taisan[] = "Tài san:";
char donvi[] = "$"; // don vi tien te
char stock[] = "Smart Market";
char taisanrong[] = "10000"; // so tien trong tai khoan ban dau
char thoat[] = "Bâm ESC de thoat";
char femagr[] = "FEMA GROUP";
char cn1[] = "KHOP LENH THEO PHIEN";
char cn2[] = "KHOP LENH THI TRUONG";

char phiensang[] =  "Phiên Sáng  ";
char phienchieu[] = "Phiên Chiêu ";
char gio1[] =  "9:00 ";
char gio2[] = "10:15";
char gio3[] = "11:15";
char gio4[] = "14:15";
char gio5[] = "15:15";
char gio6[] = "16:15";


char sohuu[] = "Co phieu da mua";

char khoiluong[] = "Khôi luong cô phiêu giao dich";

char socp[] = "0"; // so cp so huu

char gia1[] = "50$"; // bang gia
char gia2[] = "150$";
char gia3[] = "200$";
char gia4[] = "300$";
char gia5[] = "450$";

char m_mua[] = "Bâm M";
char b_ban[] = "Bâm S";

char tennguoidung[] = "Tên nguòi dùng: User230212xxx";
char id[] = "ID: 230212xxxx";
char ten_san[] = "San: UETES / HOSE";
char mso_thue[] = "Mã sô thuê: 230212xxxxx";
char user_taikhoan[] = "Tài khoan: ";
char danhgia_taichinh[] = "Dánh giá tài chính: Câp nhât gân nhât phiên hôm nay";
char danhgia_cp[] = "Giá cô phiêu";
char news[] = "Tin liên quan: ";

extern int phien_sang_chieu;

void tranggioithieu(int a)
{
    
     if (a==1)
     {
        readimagefile("trang1.jpg",0,0,1300,700);
     } else if ( a == 2)
     {
        readimagefile("trang2.jpg",0,0,1300,700);
     } else if ( a == 3) {
        readimagefile("trang3.jpg",0,0,1300,700);
     } else if ( a == 4)
     {
        readimagefile("trang4.jpg",0,0,1300,700);
     } else if ( a == 5)
     {
        readimagefile("trang5.jpg",0,0,1300,700);
     }
}
void menu()
{
     setcolor(BLUE);
     //chu U
     setfillstyle(SOLID_FILL,BLUE); // to chu U mau xanh
     bar(300,100,350,300);
     bar(350,250,450,300);
     bar(400,100,450,250);
     
     //chu E
     setcolor(RED);
     setfillstyle(SOLID_FILL,RED); // to chu E mau do
     bar(500,100,550,300);
     bar(550,100,600,140);
     bar(550,180,600,220);
     bar(550,260,600,300);
     
     //chu T
     setcolor(GREEN);
     setfillstyle(SOLID_FILL,GREEN);
     bar(650,100,800,140);
     bar(700,140,750,300);
     
     settextstyle(6,0,4);
     outtextxy(650,350,stock);
     setfillstyle(SOLID_FILL,WHITE);
     
     delay(2000);
     cleardevice();

}
void bangdieukhien() // khop lenh theo thi truong
{
     
     line(1000,0,1000,700); // duong doc
     line(0,540,1300,540); //duong ngang
     line(1075,0,1075,540); 
     line(0,40,1000,40); // duong ngang tren cung
     line(0,630,1000,630);
     rectangle(1125,150,1275,200); // ve o dat lenh mua
     rectangle(1125,350,1275,400); // ve o dat lenh ban
     rectangle(890,5,990,35); // ve o chuc nang thoat
     
     settextstyle(0,0,2);
     outtextxy(1150,50,lenh);
     outtextxy(1150,165,mua);
     outtextxy(892,13, thoat_thitruong);
     
     settextstyle(0,0,1);
     outtextxy(1185,185, m_mua); // bam m de mua
     outtextxy(1185,385, b_ban);
     
     
     settextstyle(0,0,2);
     setfillstyle(SOLID_FILL, WHITE);
     outtextxy(1150,365,ban);
     outtextxy(10,585,tencp);
     
     
     settextstyle(0,0,1);
    
     settextstyle(0,0,2);
     rectangle(100,570,250,620);
     outtextxy(140,585,fema);
     outtextxy(400,585,taisan); 
     outtextxy(910,585,donvi);
     
     settextstyle(0,0,2);
     outtextxy(1010,550,sohuu);
     outtextxy(10,650, news);  
     
     for(int i = 0;i <= 1000; i+=10) 
     {
         putpixel(i,490,WHITE);
         putpixel(i,390,WHITE);
         putpixel(i,340,WHITE);
         putpixel(i,240,WHITE);
         putpixel(i,90,WHITE);
         
     }
     setcolor(CYAN);
     settextstyle(0,0,2);
     outtextxy(1005,490,gia1);
     outtextxy(1005,390,gia2);
     outtextxy(1005,340,gia3);
     outtextxy(1005,240,gia4);
     outtextxy(1005,90,gia5);
     settextstyle(0,0,2);
     setcolor(LIGHTGREEN);
     outtextxy(10,15,khoiluong);
     setcolor(WHITE);
     if (phien_sang_chieu % 2 == 1) {  // phiên sáng
        settextstyle(0,0,2);
        outtextxy(650,15,phiensang);
        settextstyle(0,0,1);
        outtextxy(90,545,gio1);
        outtextxy(490,545,gio2);
        outtextxy(890,545,gio3);
        
     } else { // phiên chiêu
        settextstyle(0,0,2);
        outtextxy(650,15,phienchieu);
        settextstyle(0,0,1);
        outtextxy(90,545,gio4);
        outtextxy(490,545,gio5);
        outtextxy(890,545,gio6);
     }
     settextstyle(0,0,2);           
     
}
void bangdieukhien_codinh() // khop lenh theo phien co dinh
{
     
     line(1000,0,1000,700); // duong doc
     line(0,540,1300,540); //duong ngang
     line(1075,0,1075,540); 
     line(0,40,1000,40); // duong ngang tren cung
     
     rectangle(1125,150,1275,200); // ve o dat lenh mua
     
     
     settextstyle(0,0,2);
     outtextxy(1150,50,lenh);
     outtextxy(1150,165,mua);
     
     settextstyle(0,0,1);
     outtextxy(1185,185, m_mua); // bam m de mua
     
     
     settextstyle(0,0,2);
     setfillstyle(SOLID_FILL, WHITE);
     
     
     settextstyle(0,0,1);
     outtextxy(10,580,tencp);
     settextstyle(0,0,2);
     rectangle(100,570,250,620);
     outtextxy(130,585,fema);
     outtextxy(400,585,taisan); 
     outtextxy(910,585,donvi);
     
     settextstyle(0,0,2);
     outtextxy(1010,550,sohuu);
     
     
     for(int i = 0;i <= 1000; i+=10) 
     {
         putpixel(i,490,WHITE);
         putpixel(i,390,WHITE);
         putpixel(i,340,WHITE);
         putpixel(i,240,WHITE);
         putpixel(i,90,WHITE);
         
     }
     setcolor(CYAN);
     settextstyle(0,0,2);
     outtextxy(1005,490,gia1);
     outtextxy(1005,390,gia2);
     outtextxy(1005,340,gia3);
     outtextxy(1005,240,gia4);
     outtextxy(1005,90,gia5);
     settextstyle(0,0,2);
     setcolor(LIGHTGREEN);
     outtextxy(10,15,khoiluong);
     setcolor(WHITE);
     
}
void gioithieu()
{    
    int trang = 1; // trang bat dau = 1
    int mousex, mousey;
    while (trang != 0) { // trang ve 0 la thoat
          
          tranggioithieu(trang); 
          if (ismouseclick(WM_LBUTTONDOWN)){
             getmouseclick(WM_LBUTTONDOWN,mousex,mousey);
             if (mousex >= 26 && mousex <= 269 && mousey >= 500 && mousey <= 690) // lui trang
             {
                trang--; 
                cleardevice();
             }
             if (mousex >= 1040 && mousex <= 1282 && mousey >= 500 && mousey <= 690) // sang trang
             {
                trang++;
                cleardevice();
             }
             clearmouseclick(WM_LBUTTONDOWN);
          }
    }
}
void loading()
{
     char vao[] = "Dang mo biêu dô"; // thu tuc vao chuong trinh
     char cham[] = ".";
     settextstyle(0,0,3);
     outtextxy(400,300,vao);
     delay(1000);
     outtextxy(780,300,cham);
     delay(1000);
     outtextxy(810,300,cham);
     delay(1000);
     outtextxy(840,300,cham); 
     delay(1000);
     cleardevice();
     setcolor(WHITE);
     setlinestyle(SOLID_LINE,0,1);
     
}
void user_giaodien() // dung cho muc tai khoan
{
     // ve avarta
     setcolor(CYAN);
     rectangle(0,0,1300,300); 
     rectangle(50,50,250,250);
     circle(150,100,40);
     rectangle(75,140,225,250);
     line(105,150,105,250);
     line(195,150,195,250);
     
     settextstyle(0,0,2);
     setcolor(YELLOW);
     outtextxy(300,65,tennguoidung); 
     outtextxy(300,100, id);
     outtextxy(300,135, ten_san);
     outtextxy(300,170, mso_thue);
     outtextxy(300, 205, user_taikhoan);
     
     settextstyle(0,0,3);
     setcolor(WHITE);
     outtextxy(50,330,danhgia_taichinh);
     line(650,380,650,650);
     outtextxy(780,370,danhgia_cp);
     
     
     
     
     
     
}
