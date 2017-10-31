#include "miniwin.h"

#define SPACING 20

#define HORIZONTAL 16
#define VERTICAL 18

#define BLANCO 0
#define NEGRO 1
#define VERDE 2

using namespace miniwin;

void white_canvas(int x, int y) {
     color_rgb(255,255,255);
     rectangulo_lleno(0,0,x,y);
}

void cuadricula(int x, int y) {
      color_rgb(0,0,0);
      for(int i=0;i<x;i=i+SPACING) {
           linea(i,0,i,y);
      }
      for(int i=0;i<y;i=i+SPACING) {
           linea(0,i,x,i);
      }
}

void choose_color(int c) {
    switch(c) {
        case BLANCO:
            color_rgb(255,255,255);
            break;
        case NEGRO:
            color_rgb(38, 38, 38);
            break;
        case VERDE:
            color_rgb(136, 255, 77);
    }
}

void paint_hongo(int x, int y) {
     int a=x/SPACING;
     int b=y/SPACING;
     int grid[a][b];
     for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            grid[j][i]=0;
        }
     }
     //grid[6][1]=NEGRO;grid[7][1]=NEGRO;grid[8][1]=NEGRO;
     grid[0][0]=NEGRO;grid[1][0]=NEGRO;grid[14][0]=NEGRO;grid[15][0]=NEGRO;
     grid[0][1]=NEGRO;grid[1][1]=VERDE;grid[2][1]=NEGRO;grid[13][1]=NEGRO;grid[14][1]=VERDE;grid[15][1]=NEGRO;
     grid[1][2]=NEGRO;grid[2][2]=VERDE;grid[3][2]=NEGRO;for(int i=5;i<=10;i++){grid[i][2]=NEGRO;}grid[12][2]=NEGRO;grid[13][2]=VERDE;grid[14][2]=NEGRO;
     grid[2][3]=NEGRO;grid[3][3]=VERDE;grid[4][3]=NEGRO;grid[5][3]=NEGRO;for(int i=6;i<=9;i++){grid[i][3]=VERDE;}grid[10][3]=NEGRO;grid[11][3]=NEGRO;grid[12][3]=VERDE;grid[13][3]=NEGRO;
     grid[2][4]=NEGRO;grid[3][4]=NEGRO;for(int i=4;i<=11;i++){grid[i][4]=VERDE;}grid[12][4]=NEGRO;grid[13][4]=NEGRO;
     grid[1][5]=NEGRO;grid[2][5]=NEGRO;for(int i=3;i<=12;i++){grid[i][5]=VERDE;}grid[13][5]=NEGRO;grid[14][5]=NEGRO;
     grid[1][6]=NEGRO;for(int i=2;i<=4;i++){grid[i][6]=VERDE;}grid[5][6]=NEGRO;for(int i=6;i<=9;i++){grid[i][6]=VERDE;}grid[10][6]=NEGRO;for(int i=11;i<=13;i++){grid[i][6]=VERDE;}grid[14][6]=NEGRO;

     grid[0][7]=NEGRO;grid[1][7]=NEGRO;for(int i=2;i<=13;i++){grid[i][7]=VERDE;}grid[14][7]=NEGRO;grid[15][7]=NEGRO;
     grid[0][8]=NEGRO;for(int i=1;i<=14;i++){grid[i][8]=VERDE;}grid[15][8]=NEGRO;
     for(int i=0;i<=15;i++){grid[i][9]=NEGRO;}
     grid[0][10]=NEGRO;for(int i=1;i<=14;i++){grid[i][10]=VERDE;}grid[15][10]=NEGRO;
     grid[0][11]=NEGRO;for(int i=1;i<=14;i++){grid[i][11]=VERDE;}grid[15][11]=NEGRO;
     grid[0][12]=NEGRO;grid[1][12]=VERDE;grid[2][12]=VERDE;for(int i=3;i<=12;i++){grid[i][12]=NEGRO;}grid[13][12]=VERDE;grid[14][12]=VERDE;grid[15][12]=NEGRO;
     for(int i=0;i<=3;i++){grid[i][13]=NEGRO;}grid[6][13]=NEGRO;grid[9][13]=NEGRO;for(int i=12;i<=15;i++){grid[i][13]=NEGRO;}
     grid[1][14]=NEGRO;grid[2][14]=NEGRO;grid[6][14]=NEGRO;grid[9][14]=NEGRO;grid[13][14]=NEGRO;grid[14][14]=NEGRO;
     grid[2][15]=NEGRO;grid[13][15]=NEGRO;
     grid[2][16]=NEGRO;grid[3][16]=NEGRO;grid[12][16]=NEGRO;grid[13][16]=NEGRO;
     for(int i=3;i<=12;i++){grid[i][17]=NEGRO;}
     for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            choose_color(grid[j][i]);
            rectangulo_lleno(j*SPACING+1,i*SPACING+1,(j+1)*SPACING,(i+1)*SPACING);
        }
     }
}

void ej2() {
     int x=HORIZONTAL*SPACING+1;
     int y=VERTICAL*SPACING+1;
     vredimensiona(x,y);
     paint_hongo(x,y);
     cuadricula(x,y);
}

int main() {
    ej2();
    refresca();
    return 0;
}
