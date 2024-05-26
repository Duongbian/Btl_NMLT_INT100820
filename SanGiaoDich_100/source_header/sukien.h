#pragma once

int g_xacsuatsk[11] = {1,0,0,0,0,1,0,0,0,0,1}; // xac suat xay ra bien dong thi truong
int g_sukien[6] = {1,0,1,0,1,0}; // thong tin dua ve tot hay xau 1 tot 0 xau
extern void tang_tang();
extern void giam();
extern fstream tin_tot;
extern fstream tin_xau;

void sukienthitruong()
{
     
     int news = rand()%11;
     if (g_xacsuatsk[news] == 1) { // thi truong bien dong
        int tot_xau = rand()%6;
        if (g_sukien == 1) // tin vui 
        {
           int line = 1;
           
           int line_tot = {1,6,11,16,21}
           if (tin_tot.isopen()) {
               
               int biendong_tang = rand()%3 + 4; // tang len may lan?
               for (int i = 0; i < biendong_tang; i++)
               {
                   tang_tang();
                   delay(1000);
               }
           }
        } else {
           int biendong_giam = rand()%3+ 5; // giam di lien tuc??
           if (tin_xau.isopen()) {
              for (int i = 0 ; i < biendong_giam; i++)
              {
                  giam();
                  delay(1000);
              }
           }
           
        } 
     } else {
        continue;
     }
}
