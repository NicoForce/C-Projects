#include "miniwin.h"
#include <string.h>
#include <cstdlib>

#define HORSPACE 20
#define VERSPACE 20

#define HORIZONTAL 21
#define VERTICAL 24

#define NOLINES false

#define BLANCO 0
#define NEGRO 1
#define VERDE_CLARO 2
#define VERDE 3
#define VERDE_OSCURO 4
#define NARANJA_OSCURO 5
#define NARANJA_CLARO 6
#define MARRON 7
#define AMARILLO 8

using namespace miniwin;

void white_canvas(int x, int y) {
     color_rgb(255,255,255);
     rectangulo_lleno(0,0,x,y);
}

void cuadricula(int x, int y) {
      color_rgb(0,0,0);
      for(int i=0;i<x;i=i+HORSPACE) {
           linea(i,0,i,y);
      }
      for(int i=0;i<y;i=i+VERSPACE) {
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
        case VERDE_CLARO:
             color_rgb(153, 255, 153);
             break;
        case VERDE:
             color_rgb(71, 209, 71);
             break;
        case VERDE_OSCURO:
             color_rgb(0, 153, 0);
             break;
        case NARANJA_OSCURO:
             color_rgb(255, 102, 0);
             break;
        case NARANJA_CLARO:
             color_rgb(255, 204, 0);
             break;
        case MARRON:
             color_rgb(115, 77, 38);
             break;
        case AMARILLO:
             color_rgb(255, 255, 0);
    }
}

int findColor(std::string a) {
    if(a=="B") return BLANCO;
    else if(a=="N") return NEGRO;
    else if(a=="VC") return VERDE_CLARO;
    else if(a=="V") return VERDE;
    else if(a=="VO") return VERDE_OSCURO;
    else if(a=="NO") return NARANJA_OSCURO;
    else if(a=="NC") return NARANJA_CLARO;
    else if(a=="M") return MARRON;
    else if(a=="A") return AMARILLO;
    return 0;
}

void paint(int x, int y) {
     int a=HORIZONTAL;
     int b=VERTICAL;
     int grid[a][b];
     std::string temp1="";
     std::string temp2="";
     std::string temp3="";
     std::string colores[VERTICAL];
     int sizes=0;
     int hor=0;
     int repeat=0;
     bool semi=false;
     char character;
     colores[0]="B-9,N-5,B-7,";
     colores[1]="B-8,N,VC-2,V-3,N,B-6,";
     colores[2]="B-7,N,VC-2,V-4,VO,N,B-5,";
     colores[3]="B-6,N,VC-2,V-5,VO-2,N,B-4,";
     colores[4]="B-5,N,VC,NO-9,VO,N,B-3,";
     colores[5]="B-5,NO-2,NC-9,NO-2,B-3,";
     colores[6]="B-4,NO,NC-13,NO,B-2,";
     colores[7]="B-3,NO-2,NC-2,B,N,NC-5,B,N,NC,NO-2,B-2,";
     colores[8]="B-2,NO-4,NC,N-2,NO-5,N-2,NO-3,B-2,";
     colores[9]="B,NO-2,NC,NO-3,N-2,NO-5,N-2,NO-3,B-2,";
     colores[10]="NO-2,NC,NO-6,V-5,NO-4,B-3,";
     colores[11]="B,NO-3,B,N-2,VC-2,V-5,VO-2,N-2,B-3,";
     colores[12]="B,NO-2,B,N,M-2,N,VC,V-4,VO-2,N,M-2,N,B-2,";
     colores[13]="B,NO,B,N,M-2,N,VC,N-7,V,N,M-2,N,B,";
     colores[14]="B-2,N,M-2,N,VC-2,N,B-5,N,V,VO,N,M-2,N,";
     colores[15]="B-2,N,M-2,N,VC-3,N,B-3,N,VC,V,VO,N,M-2,N,";
     colores[16]="B-2,N,M-2,N,VC-2,V-2,N,B,N,VC,V-2,VO,N,M-2,N,";
     colores[17]="B-2,N,M-2,N,VC-2,V-2,VO,N,VC-2,V-2,VO,N,M-2,N,";
     colores[18]="B-3,N-2,VC,N,VC,V-2,VO,N,VC-2,V,VO,N,VC,N-2,B,";
     colores[19]="B-3,N,VC-3,N,V,VO,N-3,VC-2,N,VC-3,N,B,";
     colores[20]="B-2,N,VC-2,V-2,VO,N-2,B-3,N-2,VC-2,V-2,VO,N,";
     colores[21]="B-2,N,VC,V-2,VO-2,N,B-5,N,VC,V-2,VO-2,N,";
     colores[22]="B-2,N,V-2,VO-3,N,A-5,N,V-2,VO-3,N,";
     colores[23]="B-3,N-5,B-7,N-5,B,";
     for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            grid[j][i]=0;
        }
     }
     for(int j=0;j<VERTICAL;j++) {
           temp1=colores[j];
           sizes=temp1.length();
           for(int i=0;i<sizes;i++) {
                 character=temp1.at(i);
                 if(character==',') {
                      if(semi) {
                           repeat=atoi(temp3.c_str());
                           while(repeat>0) {
                                grid[hor][j]=findColor(temp2);
                                hor++;
                                repeat--;
                           }
                           temp2="";
                           temp3="";
                           semi=false;
                      } else {
                           grid[hor][j]=findColor(temp2);
                           temp2="";
                           hor++;
                      }
                 }  else if(character=='-'){
                      semi=true;
                 } else if(semi) {
                      temp3+=character;
                 } else {
                      temp2+=character;
                 }
           }
           hor=0;
     }
     for(int i=0;i<b;i++) {
        for(int j=0;j<a;j++) {
            choose_color(grid[j][i]);
            if(NOLINES) {
                 rectangulo_lleno(j*HORSPACE,i*VERSPACE,(j+1)*HORSPACE,(i+1)*VERSPACE);
            } else {
                 rectangulo_lleno(j*HORSPACE+1,i*VERSPACE+1,(j+1)*HORSPACE,(i+1)*VERSPACE);
            }
        }
     }
}

void main_paint() {
     int x=0,y=0;
     if(NOLINES) {
          x=HORIZONTAL*HORSPACE;
          y=VERTICAL*VERSPACE;
     } else {
          x=HORIZONTAL*HORSPACE+1;
          y=VERTICAL*VERSPACE+1;
     }
     vredimensiona(x,y);
     //white_canvas(x,y);
     paint(x,y);
     if(!NOLINES)cuadricula(x,y);
}

int main() {
    main_paint();
    refresca();
    return 0;
}
