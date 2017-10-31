#include "miniwin.h"
#define SPACING 20
#define HORIZONTAL 27
#define VERTICAL 33
#define BLANCO 0
#define NEGRO 1
#define ROSA_OSCURO 2
#define ROSA_CLARO 3
#define GRIS_OSCURO 4
#define GRIS 5
#define GRIS_CLARO 6
#define GRIS_MUY_CLARO 7
#define CREMA 8
#define AZULE 9
#define AZUL_OSCURO 10
#define CELESTE 11

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
            color_rgb(0,0,0);
            break;
        case ROSA_OSCURO:
            color_rgb(191, 64, 128);
            break;
        case ROSA_CLARO:
            color_rgb(230, 179, 204);
            break;
        case GRIS_OSCURO:
            color_rgb(77, 77, 77);
            break;
        case GRIS:
            color_rgb(166, 166, 166);
            break;
        case GRIS_CLARO:
            color_rgb(191, 191, 191);
            break;
        case GRIS_MUY_CLARO:
            color_rgb(223, 223, 223);
            break;
        case CREMA:
            color_rgb(255, 204, 153);
            break;
        case AZULE:
            color_rgb(26, 26, 255);
            break;
        case AZUL_OSCURO:
            color_rgb(0, 0, 128);
            break;
        case CELESTE:
            color_rgb(102, 217, 255);
    }
}

void paint_bomberman(int x, int y) {
     int a=x/SPACING;
     int b=y/SPACING;
     int grid[a][b];
     for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            grid[j][i]=0;
        }
     }
     grid[6][1]=NEGRO;grid[7][1]=NEGRO;grid[8][1]=NEGRO;
     grid[5][2]=NEGRO;grid[6][2]=ROSA_OSCURO;grid[7][2]=ROSA_OSCURO;grid[8][2]=ROSA_OSCURO;grid[9][2]=NEGRO;
     grid[4][3]=NEGRO;grid[5][3]=ROSA_OSCURO;grid[6][3]=ROSA_OSCURO;grid[7][3]=ROSA_CLARO;/*grid[8][3]=BLANCO;*/grid[9][3]=ROSA_OSCURO;grid[10][3]=NEGRO;
     grid[4][4]=NEGRO;grid[5][4]=ROSA_OSCURO;grid[6][4]=ROSA_OSCURO;grid[7][4]=ROSA_CLARO;grid[8][4]=ROSA_CLARO;grid[9][4]=ROSA_OSCURO;grid[10][4]=NEGRO;grid[11][4]=NEGRO;grid[12][4]=NEGRO;grid[13][4]=NEGRO;grid[14][4]=NEGRO;grid[15][4]=NEGRO;grid[16][4]=NEGRO;grid[17][4]=NEGRO;
     grid[4][5]=NEGRO;grid[5][5]=ROSA_OSCURO;grid[6][5]=ROSA_OSCURO;grid[7][5]=ROSA_OSCURO;grid[8][5]=ROSA_OSCURO;grid[9][5]=GRIS_OSCURO;grid[10][5]=GRIS;grid[11][5]=GRIS_CLARO;grid[12][5]=GRIS_MUY_CLARO;grid[13][5]=GRIS_MUY_CLARO;grid[14][5]=GRIS_MUY_CLARO;grid[15][5]=GRIS_MUY_CLARO;grid[16][5]=GRIS_CLARO;grid[17][5]=GRIS;grid[18][5]=NEGRO;grid[19][5]=NEGRO;
     grid[5][6]=NEGRO;grid[6][6]=ROSA_OSCURO;grid[7][6]=GRIS_OSCURO;grid[8][6]=GRIS;grid[9][6]=GRIS_CLARO;grid[10][6]=GRIS_MUY_CLARO;grid[11][6]=GRIS_MUY_CLARO;grid[12][6]=GRIS_MUY_CLARO;grid[13][6]=GRIS_MUY_CLARO;grid[14][6]=GRIS_MUY_CLARO;grid[15][6]=GRIS_MUY_CLARO;grid[16][6]=GRIS_MUY_CLARO;/*grid[17][6]=BLANCO;*/grid[18][6]=GRIS_MUY_CLARO;grid[19][6]=GRIS_CLARO;grid[20][6]=NEGRO;
     grid[5][7]=NEGRO;grid[6][7]=GRIS_OSCURO;grid[7][7]=GRIS;grid[8][7]=GRIS_CLARO;for(int i=9;i<=19;i++){grid[i][7]=GRIS_MUY_CLARO;}grid[20][7]=GRIS_CLARO;grid[21][7]=NEGRO;
     grid[5][8]=NEGRO;grid[6][8]=GRIS;grid[7][8]=GRIS;for(int i=8;i<=11;i++){grid[i][8]=GRIS_MUY_CLARO;}grid[12][8]=NEGRO;for(int i=13;i<=17;i++){grid[i][8]=GRIS_MUY_CLARO;}grid[18][8]=NEGRO;grid[19][8]=GRIS_MUY_CLARO;grid[20][8]=GRIS_MUY_CLARO;grid[21][8]=NEGRO;
     grid[4][9]=NEGRO;grid[5][9]=GRIS_OSCURO;grid[6][9]=GRIS;grid[7][9]=GRIS_CLARO;for(int i=8;i<=12;i++){grid[i][9]=GRIS_MUY_CLARO;}grid[13][9]=NEGRO;grid[14][9]=GRIS_MUY_CLARO;grid[15][9]=GRIS_MUY_CLARO;grid[16][9]=GRIS_MUY_CLARO;grid[17][9]=NEGRO;for(int i=18;i<=20;i++){grid[i][9]=GRIS_MUY_CLARO;}grid[21][9]=GRIS_CLARO;grid[22][9]=NEGRO;
     grid[4][10]=NEGRO;grid[5][10]=GRIS_OSCURO;grid[6][10]=GRIS;grid[7][10]=GRIS_MUY_CLARO;grid[8][10]=GRIS_MUY_CLARO;for(int i=9;i<=13;i++){grid[i][10]=ROSA_OSCURO;}grid[14][10]=NEGRO;grid[15][10]=ROSA_OSCURO;grid[16][10]=NEGRO;for(int i=17;i<=20;i++){grid[i][10]=ROSA_OSCURO;}grid[21][10]=GRIS_CLARO;grid[22][10]=NEGRO;
     grid[4][11]=NEGRO;grid[5][11]=GRIS_OSCURO;grid[6][11]=GRIS;grid[7][11]=GRIS_MUY_CLARO;
     grid[4][12]=NEGRO;grid[5][12]=GRIS_OSCURO;grid[6][12]=GRIS;grid[7][12]=GRIS_MUY_CLARO;
     grid[4][13]=NEGRO;grid[5][13]=GRIS_OSCURO;grid[6][13]=GRIS;grid[7][13]=GRIS_CLARO;
     grid[4][14]=NEGRO;grid[5][14]=GRIS_OSCURO;grid[6][14]=GRIS;grid[7][14]=GRIS;
     grid[5][15]=NEGRO;grid[6][15]=GRIS;grid[7][15]=GRIS;
     grid[5][16]=NEGRO;grid[6][16]=GRIS_OSCURO;grid[7][16]=GRIS;
     grid[6][17]=NEGRO;grid[7][17]=GRIS_OSCURO;grid[23][17]=NEGRO;grid[24][17]=NEGRO;
     for(int j=11;j<=17;j++) {grid[8][j]=ROSA_OSCURO;for(int i=9;i<=12;i++){grid[i][j]=CREMA;}grid[13][j]=NEGRO;for(int i=14;i<=16;i++){grid[i][j]=CREMA;}grid[17][j]=NEGRO;for(int i=18;i<=20;i++){grid[i][j]=CREMA;}grid[21][j]=ROSA_OSCURO;grid[22][j]=NEGRO;}
     grid[7][18]=NEGRO;grid[8][18]=NEGRO;for(int i=9;i<=20;i++){grid[i][18]=ROSA_OSCURO;}grid[21][18]=NEGRO;for(int i=22;i<=24;i++){grid[i][18]=ROSA_OSCURO;}grid[25][18]=NEGRO;
     grid[6][19]=NEGRO;grid[7][19]=GRIS_MUY_CLARO;grid[8][19]=GRIS_MUY_CLARO;for(int i=9;i<=11;i++){grid[i][19]=ROSA_OSCURO;}for(int i=12;i<=20;i++){grid[i][19]=NEGRO;}grid[21][19]=ROSA_OSCURO;grid[22][19]=ROSA_OSCURO;grid[23][19]=ROSA_CLARO;/*grid[24][19]=BLANCO;*/grid[25][19]=NEGRO;
     grid[6][20]=NEGRO;grid[7][20]=GRIS_MUY_CLARO;grid[8][20]=ROSA_OSCURO;grid[9][20]=ROSA_OSCURO;grid[10][20]=ROSA_CLARO;/*grid[11][20]=BLANCCO;*/grid[12][20]=ROSA_OSCURO;for(int i=13;i<=15;i++){grid[i][20]=AZULE;}grid[16][20]=CELESTE;grid[17][20]=CELESTE;grid[18][20]=AZUL_OSCURO;grid[19][20]=GRIS_MUY_CLARO;grid[20][20]=GRIS_MUY_CLARO;grid[21][20]=ROSA_OSCURO;grid[22][20]=ROSA_OSCURO;grid[23][20]=ROSA_CLARO;grid[24][20]=ROSA_CLARO;grid[25][20]=NEGRO;
     grid[6][21]=NEGRO;grid[7][21]=GRIS_OSCURO;grid[8][21]=ROSA_OSCURO;grid[9][21]=ROSA_OSCURO;grid[10][21]=ROSA_CLARO;grid[11][21]=ROSA_CLARO;grid[12][21]=ROSA_OSCURO;grid[13][21]=AZULE;grid[14][21]=AZULE;grid[15][21]=CELESTE;/*grid[16][21]=BLANCO;*/grid[17][21]=CELESTE;grid[18][21]=AZUL_OSCURO;grid[19][21]=GRIS_OSCURO;grid[20][21]=GRIS_OSCURO;for(int i=21;i<=24;i++){grid[i][21]=ROSA_OSCURO;}grid[25][21]=NEGRO;
     grid[7][22]=AZUL_OSCURO;for(int i=8;i<=12;i++){grid[i][22]=ROSA_OSCURO;}grid[13][22]=AZULE;grid[14][22]=AZULE;for(int i=15;i<=17;i++){grid[i][22]=CELESTE;}for(int i=18;i<=24;i++){grid[i][22]=NEGRO;}
     grid[6][23]=NEGRO;grid[7][23]=NEGRO;grid[8][23]=AZUL_OSCURO;for(int i=9;i<=11;i++){grid[i][23]=ROSA_OSCURO;}grid[12][23]=NEGRO;for(int i=13;i<=15;i++){grid[i][23]=CREMA;}grid[16][23]=NEGRO;grid[17][23]=NEGRO;grid[18][23]=AZUL_OSCURO;
     grid[5][24]=NEGRO;grid[6][24]=GRIS_OSCURO;grid[7][24]=GRIS_MUY_CLARO;grid[8][24]=AZUL_OSCURO;grid[9][24]=AZUL_OSCURO;for(int i=10;i<=14;i++){grid[i][24]=AZULE;}grid[15][24]=CELESTE;grid[16][24]=AZULE;grid[17][24]=AZUL_OSCURO;grid[18][24]=NEGRO;
     grid[4][25]=NEGRO;grid[5][25]=GRIS_OSCURO;for(int i=6;i<=8;i++){grid[i][25]=GRIS_MUY_CLARO;}grid[9][25]=AZUL_OSCURO;grid[10][25]=AZUL_OSCURO;for(int i=11;i<=13;i++){grid[i][25]=AZULE;}grid[14][25]=CELESTE;grid[15][25]=AZULE;grid[16][25]=AZUL_OSCURO;grid[17][25]=GRIS_MUY_CLARO;grid[18][25]=GRIS_OSCURO;grid[19][25]=NEGRO;
     grid[3][26]=NEGRO;grid[4][26]=NEGRO;for(int i=5;i<=7;i++){grid[i][26]=GRIS_MUY_CLARO;}grid[8][26]=GRIS_OSCURO;grid[9][26]=GRIS_OSCURO;grid[10][26]=NEGRO;for(int i=11;i<=14;i++){grid[i][26]=AZUL_OSCURO;}grid[15][26]=NEGRO;grid[16][26]=GRIS_OSCURO;grid[17][26]=GRIS_MUY_CLARO;grid[18][26]=GRIS_MUY_CLARO;grid[19][26]=GRIS_OSCURO;grid[20][26]=NEGRO;grid[21][26]=NEGRO;
     grid[2][27]=NEGRO;for(int i=3;i<=9;i++){grid[i][27]=ROSA_OSCURO;}grid[10][27]=NEGRO;grid[15][27]=NEGRO;for(int i=16;i<=21;i++){grid[i][27]=ROSA_OSCURO;}grid[22][27]=NEGRO;
     grid[1][28]=NEGRO;for(int i=2;i<=5;i++){grid[i][28]=ROSA_OSCURO;}grid[6][28]=ROSA_CLARO;grid[7][28]=ROSA_CLARO;grid[9][28]=ROSA_CLARO;grid[10][28]=ROSA_OSCURO;grid[11][28]=NEGRO;grid[14][28]=NEGRO;for(int i=15;i<=18;i++){grid[i][28]=ROSA_OSCURO;}grid[19][28]=ROSA_CLARO;grid[20][28]=ROSA_CLARO;grid[22][28]=ROSA_OSCURO;grid[23][28]=NEGRO;
     grid[1][29]=NEGRO;for(int i=2;i<=6;i++){grid[i][29]=ROSA_OSCURO;}grid[7][29]=ROSA_CLARO;grid[8][29]=ROSA_CLARO;grid[9][29]=ROSA_OSCURO;grid[10][29]=ROSA_OSCURO;grid[11][29]=NEGRO;grid[14][29]=NEGRO;for(int i=15;i<=19;i++){grid[i][29]=ROSA_OSCURO;}grid[20][29]=ROSA_CLARO;grid[21][29]=ROSA_CLARO;grid[22][29]=ROSA_OSCURO;grid[23][29]=NEGRO;
     grid[2][30]=NEGRO;for(int i=3;i<=9;i++){grid[i][30]=ROSA_OSCURO;}grid[10][30]=NEGRO;grid[15][30]=NEGRO;for(int i=16;i<=21;i++){grid[i][30]=ROSA_OSCURO;}grid[22][30]=NEGRO;
     for(int i=3;i<=9;i++){grid[i][31]=NEGRO;}for(int i=16;i<=21;i++){grid[i][31]=NEGRO;}
     for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            choose_color(grid[j][i]);
            rectangulo_lleno(j*SPACING+1,i*SPACING+1,(j+1)*SPACING+1,(i+1)*SPACING+1);
        }
     }
}

void ej2() {
     int x=HORIZONTAL*SPACING+1;
     int y=VERTICAL*SPACING+1;
     vredimensiona(x,y);
     paint_bomberman(x,y);
     //cuadricula(x,y);
}

int main() {
    ej2();
    refresca();
    return 0;
}
