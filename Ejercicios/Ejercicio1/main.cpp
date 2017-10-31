#include "miniwin.h"
#include <string.h>
#include <cstdlib>

#define HORSPACE 20
#define VERSPACE 20

#define HORIZONTAL 18
#define VERTICAL 18

#define NOLINES false

#define BLANCO 0
#define AZUL 1
#define NEGRO 2
#define VERDE 3
#define CREMA 4

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
        case AZUL:
             color_rgb(0,0,255);
             break;
        case NEGRO:
             color_rgb(0,0,0);
             break;
        case VERDE:
             color_rgb(0, 204, 0);
             break;
        case CREMA:
             color_rgb(255, 204, 153);
    }
}

int findColor(std::string a) {
    if(a=="BLANCO") return BLANCO;
    else if(a=="AZUL") return AZUL;
    else if(a=="NEGRO") return NEGRO;
    else if(a=="VERDE") return VERDE;
    else if(a=="CREMA") return CREMA;
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
     colores[0]="AZUL-2,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,";
     colores[1]="BLANCO,VERDE-5,NEGRO-6,VERDE-5,AZUL,";
     colores[2]="AZUL,VERDE-3,NEGRO-2,VERDE-4,BLANCO-2,NEGRO-2,VERDE-3,BLANCO,";
     colores[3]="BLANCO,VERDE-2,NEGRO,BLANCO-2,VERDE-4,BLANCO-4,NEGRO,VERDE-2,AZUL,";
     colores[4]="AZUL,VERDE,NEGRO,BLANCO-2,VERDE-6,BLANCO-4,NEGRO,VERDE-2,AZUL,";
     colores[5]="BLANCO,VERDE,NEGRO,BLANCO,VERDE-2,BLANCO-4,VERDE-2,BLANCO-3,NEGRO,VERDE,AZUL,";
     colores[6]="AZUL,NEGRO,VERDE-3,BLANCO-6,VERDE-5,NEGRO,BLANCO,";
     colores[7]="BLANCO,NEGRO,VERDE-3,BLANCO-6,VERDE-2,BLANCO-2,VERDE,NEGRO,AZUL,";
     colores[8]="AZUL,NEGRO,BLANCO,VERDE-2,BLANCO-6,VERDE,BLANCO-4,NEGRO,BLANCO,";
     colores[9]="BLANCO,NEGRO,BLANCO-2,VERDE-2,BLANCO-4,VERDE-2,BLANCO-4,NEGRO,AZUL,";
     colores[10]="AZUL,NEGRO,BLANCO-2,VERDE-9,BLANCO-2,VERDE,NEGRO,BLANCO,";
     colores[11]="BLANCO,NEGRO,BLANCO,VERDE-2,NEGRO-8,VERDE-3,NEGRO,AZUL,";
     colores[12]="AZUL,VERDE,NEGRO-3,CREMA-2,NEGRO,CREMA-2,NEGRO,CREMA-2,NEGRO-3,VERDE,BLANCO,";
     colores[13]="BLANCO,VERDE-2,NEGRO,CREMA-3,NEGRO,CREMA-2,NEGRO,CREMA-3,NEGRO,VERDE-2,AZUL,";
     colores[14]="AZUL,VERDE-2,NEGRO,CREMA-10,NEGRO,VERDE-2,BLANCO,";
     colores[15]="BLANCO,VERDE-3,NEGRO,CREMA-8,NEGRO,VERDE-3,AZUL,";
     colores[16]="AZUL,VERDE-4,NEGRO-8,VERDE-4,BLANCO,";
     colores[17]="AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL,BLANCO,AZUL-2,";
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
