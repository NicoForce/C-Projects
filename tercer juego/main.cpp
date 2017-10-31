#include "miniwin.h"

#define SPACING 20

#define HORIZONTAL 24
#define VERTICAL 30

#define VERDE 0
#define NEGRO 1
#define ROJO 2
#define ROJO_OSCURO 3
#define CREMA 4
#define MARRON 5
#define BLANCO 6
#define AMARILLO 7
#define AZULE 8
#define CELESTE 9
#define MARRON_OSCURO 10
#define MARRON_CLARO 11

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
        case VERDE:
            color_rgb(64, 255, 0);
            break;
        case NEGRO:
            color_rgb(50,50,50);
            break;
        case ROJO:
            color_rgb(255,0,0);
            break;
        case ROJO_OSCURO:
            color_rgb(153, 0, 0);
            break;
        case CREMA:
            color_rgb(255, 204, 153);
            break;
        case MARRON:
            color_rgb(153, 77, 0);
            break;
        case BLANCO:
            color_rgb(255,255,255);
            break;
        case AMARILLO:
            color_rgb(255, 255, 51);
            break;
        case AZULE:
            color_rgb(51, 153, 255);
            break;
        case CELESTE:
            color_rgb(0, 191, 255);
            break;
        case MARRON_OSCURO:
            color_rgb(77, 38, 0);
            break;
        case MARRON_CLARO:
            color_rgb(198, 140, 83);
    }
}

void paint_mario(int x, int y) {
     int a=x/SPACING;
     int b=y/SPACING;
     int grid[a][b];
     for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            grid[j][i]=0;
        }
     }
     for(int i=10;i<=15;i++){grid[i][0]=NEGRO;}
     grid[8][1]=NEGRO;grid[9][1]=NEGRO;for(int i=10;i<=15;i++){grid[i][1]=ROJO;}grid[16][1]=NEGRO;grid[17][1]=NEGRO;
     grid[7][2]=NEGRO;for(int i=8;i<=11;i++){grid[i][2]=ROJO;}grid[12][2]=BLANCO;grid[13][2]=BLANCO;for(int i=14;i<=17;i++){grid[i][2]=ROJO;}grid[18][2]=NEGRO;
     grid[5][3]=NEGRO;grid[6][3]=NEGRO;grid[7][3]=ROJO_OSCURO;for(int i=8;i<=10;i++){grid[i][3]=ROJO;}for(int i=11;i<=14;i++){grid[i][3]=BLANCO;}for(int i=15;i<=18;i++){grid[i][3]=ROJO;}grid[19][3]=NEGRO;
     grid[1][4]=NEGRO;grid[2][4]=NEGRO;grid[4][4]=NEGRO;grid[5][4]=BLANCO;grid[6][4]=BLANCO;grid[7][4]=NEGRO;grid[8][4]=ROJO_OSCURO;grid[9][4]=ROJO_OSCURO;for(int i=10;i<=15;i++){grid[i][4]=NEGRO;}grid[16][4]=ROJO_OSCURO;grid[17][4]=ROJO_OSCURO;grid[18][4]=ROJO;grid[19][4]=NEGRO;
     grid[0][5]=NEGRO;grid[1][5]=BLANCO;grid[2][5]=BLANCO;grid[3][5]=NEGRO;grid[4][5]=NEGRO;grid[5][5]=BLANCO;grid[6][5]=BLANCO;for(int i=7;i<=9;i++){grid[i][5]=NEGRO;}for(int i=10;i<=15;i++){grid[i][5]=ROJO;}grid[16][5]=NEGRO;grid[17][5]=NEGRO;grid[18][5]=ROJO_OSCURO;grid[19][5]=ROJO;grid[20][5]=NEGRO;
     grid[0][6]=NEGRO;grid[1][6]=BLANCO;grid[2][6]=BLANCO;grid[3][6]=BLANCO;grid[4][6]=NEGRO;grid[5][6]=BLANCO;grid[6][6]=BLANCO;grid[7][6]=NEGRO;grid[8][6]=ROJO_OSCURO;grid[9][6]=ROJO_OSCURO;for(int i=10;i<=15;i++){grid[i][6]=NEGRO;}grid[16][6]=ROJO_OSCURO;grid[17][6]=ROJO_OSCURO;grid[18][6]=NEGRO;grid[19][6]=ROJO_OSCURO;grid[20][6]=NEGRO;
     grid[1][7]=NEGRO;grid[2][7]=BLANCO;grid[3][7]=BLANCO;for(int i=5;i<=9;i++){grid[i][7]=NEGRO;}grid[10][7]=BLANCO;grid[11][7]=BLANCO;grid[12][7]=CREMA;grid[13][7]=CREMA;grid[14][7]=BLANCO;grid[15][7]=BLANCO;grid[16][7]=NEGRO;grid[17][7]=NEGRO;grid[18][7]=MARRON;grid[19][7]=NEGRO;grid[20][7]=NEGRO;
     grid[0][8]=NEGRO;for(int i=1;i<=3;i++){grid[i][8]=BLANCO;}grid[4][8]=NEGRO;for(int i=5;i<=7;i++){grid[i][8]=BLANCO;}grid[8][8]=NEGRO;grid[9][8]=BLANCO;grid[10][8]=BLANCO;grid[11][8]=NEGRO;grid[12][8]=CREMA;grid[13][8]=CREMA;grid[14][8]=NEGRO;grid[15][8]=BLANCO;grid[16][8]=BLANCO;grid[17][8]=CREMA;grid[18][8]=MARRON;grid[19][8]=CREMA;grid[20][8]=CREMA;grid[21][8]=NEGRO;
     grid[0][9]=NEGRO;for(int i=1;i<=3;i++){grid[i][9]=BLANCO;}grid[4][9]=NEGRO;for(int i=5;i<=7;i++){grid[i][9]=BLANCO;}grid[8][9]=NEGRO;grid[9][9]=BLANCO;grid[10][9]=BLANCO;grid[11][9]=NEGRO;grid[12][9]=CREMA;grid[13][9]=CREMA;grid[14][9]=NEGRO;grid[15][9]=BLANCO;grid[16][9]=BLANCO;grid[17][9]=CREMA;grid[18][9]=NEGRO;grid[19][9]=CREMA;grid[20][9]=CREMA;grid[21][9]=NEGRO;
     grid[0][10]=NEGRO;for(int i=1;i<=4;i++){grid[i][10]=BLANCO;}grid[5][10]=NEGRO;grid[6][10]=NEGRO;grid[7][10]=BLANCO;grid[8][10]=NEGRO;for(int i=9;i<=18;i++){grid[i][10]=CREMA;}grid[19][10]=NEGRO;grid[20][10]=CREMA;grid[21][10]=NEGRO;
     grid[1][11]=NEGRO;grid[2][11]=NEGRO;for(int i=3;i<=6;i++){grid[i][11]=BLANCO;}grid[7][11]=NEGRO;grid[8][11]=CREMA;grid[9][11]=CREMA;grid[10][11]=NEGRO;for(int i=11;i<=14;i++){grid[i][11]=CREMA;}grid[15][11]=NEGRO;for(int i=16;i<=18;i++){grid[i][11]=CREMA;}grid[19][11]=NEGRO;grid[20][11]=CREMA;grid[21][11]=NEGRO;
     for(int i=3;i<=6;i++){grid[i][12]=NEGRO;}grid[7][12]=ROJO_OSCURO;for(int i=8;i<=11;i++){grid[i][12]=NEGRO;}grid[12][12]=CREMA;grid[13][12]=CREMA;for(int i=14;i<=17;i++){grid[i][12]=NEGRO;}grid[18][12]=CREMA;grid[19][12]=NEGRO;grid[20][12]=NEGRO;
     grid[4][13]=NEGRO;for(int i=5;i<=7;i++){grid[i][13]=ROJO_OSCURO;}for(int i=8;i<=18;i++){grid[i][13]=NEGRO;}
     grid[4][14]=NEGRO;for(int i=5;i<=8;i++){grid[i][14]=ROJO_OSCURO;}grid[9][14]=NEGRO;grid[10][14]=CREMA;for(int i=11;i<=14;i++){grid[i][14]=NEGRO;}grid[15][14]=CREMA;grid[16][14]=CREMA;grid[17][14]=NEGRO;grid[18][14]=NEGRO;
     grid[5][15]=NEGRO;for(int i=6;i<=8;i++){grid[i][15]=ROJO_OSCURO;}grid[9][15]=NEGRO;grid[10][15]=NEGRO;for(int i=11;i<=14;i++){grid[i][15]=CREMA;}grid[15][15]=NEGRO;grid[16][15]=NEGRO;grid[17][15]=ROJO;grid[18][15]=ROJO;grid[19][15]=NEGRO;grid[20][15]=NEGRO;
     grid[5][16]=NEGRO;for(int i=6;i<=8;i++){grid[i][16]=ROJO_OSCURO;}grid[9][16]=CELESTE;grid[10][16]=CELESTE;for(int i=11;i<=14;i++){grid[i][16]=NEGRO;}grid[15][16]=ROJO;grid[16][16]=CELESTE;grid[17][16]=NEGRO;for(int i=18;i<=20;i++){grid[i][16]=ROJO;}grid[21][16]=NEGRO;
     grid[6][17]=NEGRO;grid[7][17]=ROJO_OSCURO;for(int i=8;i<=11;i++){grid[i][17]=CELESTE;}grid[12][17]=ROJO_OSCURO;grid[13][17]=ROJO_OSCURO;grid[14][17]=ROJO;grid[15][17]=ROJO;grid[16][17]=CELESTE;grid[17][17]=NEGRO;for(int i=18;i<=20;i++){grid[i][17]=ROJO;}grid[21][17]=ROJO_OSCURO;grid[22][17]=NEGRO;
     grid[7][18]=NEGRO;grid[8][18]=CELESTE;grid[9][18]=CELESTE;grid[10][18]=AMARILLO;grid[11][18]=AMARILLO;grid[12][18]=CELESTE;grid[13][18]=ROJO_OSCURO;grid[14][18]=ROJO_OSCURO;grid[15][18]=CELESTE;grid[16][18]=AMARILLO;grid[17][18]=AMARILLO;grid[18][18]=NEGRO;for(int i=19;i<=21;i++){grid[i][18]=ROJO_OSCURO;}grid[22][18]=NEGRO;
     grid[7][19]=NEGRO;grid[8][19]=CELESTE;grid[9][19]=CELESTE;grid[10][19]=AMARILLO;grid[11][19]=AMARILLO;grid[12][19]=CELESTE;grid[13][19]=CELESTE;grid[14][19]=CELESTE;grid[15][19]=CELESTE;grid[16][19]=AMARILLO;grid[17][19]=AMARILLO;grid[18][19]=NEGRO;for(int i=19;i<=21;i++){grid[i][19]=ROJO_OSCURO;}grid[22][19]=NEGRO;
     grid[7][20]=NEGRO;grid[8][20]=AZULE;for(int i=9;i<=17;i++){grid[i][20]=CELESTE;}grid[18][20]=NEGRO;grid[19][20]=ROJO_OSCURO;grid[20][20]=ROJO_OSCURO;grid[21][20]=NEGRO;
     grid[7][21]=NEGRO;grid[8][21]=AZULE;grid[9][21]=AZULE;for(int i=10;i<=17;i++){grid[i][21]=CELESTE;}grid[18][21]=AZULE;grid[19][21]=NEGRO;grid[20][21]=NEGRO;
     grid[6][22]=NEGRO;for(int i=7;i<=11;i++){grid[i][22]=AZULE;}for(int i=12;i<=15;i++){grid[i][22]=CELESTE;}for(int i=16;i<=18;i++){grid[i][22]=AZULE;}grid[19][22]=NEGRO;
     grid[6][23]=NEGRO;for(int i=7;i<=18;i++){grid[i][23]=AZULE;}grid[19][23]=NEGRO;
     grid[5][24]=NEGRO;for(int i=6;i<=19;i++){grid[i][24]=AZULE;}grid[20][24]=NEGRO;
     grid[5][25]=NEGRO;for(int i=6;i<=10;i++){grid[i][25]=AZULE;}for(int i=11;i<=14;i++){grid[i][25]=NEGRO;}for(int i=15;i<=19;i++){grid[i][25]=AZULE;}grid[20][25]=NEGRO;
     for(int i=3;i<=5;i++){grid[i][26]=NEGRO;}for(int i=6;i<=9;i++){grid[i][26]=AZULE;}for(int i=10;i<=15;i++){grid[i][26]=NEGRO;}for(int i=16;i<=19;i++){grid[i][26]=AZULE;}for(int i=20;i<=22;i++){grid[i][26]=NEGRO;}
     grid[2][27]=NEGRO;grid[3][27]=NEGRO;grid[4][27]=MARRON_OSCURO;grid[5][27]=MARRON_CLARO;grid[6][27]=MARRON_OSCURO;grid[7][27]=MARRON_OSCURO;grid[8][27]=MARRON;grid[9][27]=MARRON;grid[10][27]=MARRON_OSCURO;grid[11][27]=NEGRO;grid[14][27]=NEGRO;grid[15][27]=MARRON_OSCURO;grid[16][27]=MARRON;grid[17][27]=MARRON;grid[18][27]=MARRON_OSCURO;grid[19][27]=MARRON_OSCURO;grid[20][27]=MARRON_CLARO;grid[21][27]=MARRON_CLARO;grid[22][27]=NEGRO;grid[23][27]=NEGRO;
     grid[3][28]=NEGRO;for(int i=4;i<=10;i++){grid[i][28]=MARRON;}grid[11][28]=NEGRO;grid[14][28]=NEGRO;for(int i=15;i<=21;i++){grid[i][28]=MARRON;}grid[22][28]=NEGRO;
     for(int i=4;i<=10;i++){grid[i][29]=NEGRO;}for(int i=15;i<=21;i++){grid[i][29]=NEGRO;}
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
     paint_mario(x,y);
     cuadricula(x,y);
}

int main() {
    ej2();
    refresca();
    return 0;
}
