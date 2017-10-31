#include "miniwin.h"
#include <string.h>
#include <cstdlib>

#define HORSPACE 13
#define VERSPACE 13

#define HORIZONTAL 21
#define VERTICAL 34

#define NOLINES false

#define BLANCO 0
#define NEGRO 1
#define ROJO 2
#define AZUL 3

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
             color_rgb(33, 35, 34);
             break;
        case ROJO:
             color_rgb(255,0,0);
             break;
        case AZUL:
             color_rgb(78, 157, 216);
    }
}

int findColor(std::string a) {
    if(a=="B") return BLANCO;
    else if(a=="N") return NEGRO;
    else if(a=="R") return ROJO;
    else if(a=="A") return AZUL;
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
     colores[0]="B-6,N-9,B-6,";
     colores[1]="B-5,N,R-9,N,B-5,";
     colores[2]="B-4,N,R-11,N,";
     colores[3]="B-3,N,R-13,N,";
     colores[4]="B-3,N,R-13,N,";
     colores[5]="B-3,N,R-13,N,";
     colores[6]="B-3,N,R-2,N,R-7,N,R-2,N,";
     colores[7]="B-3,N,R,N,B,N,R-5,N,B,N,R,N,";
     colores[8]="B-3,N,R,N,B-2,N,R-3,N,B-2,N,R,N,";
     colores[9]="B-3,N,R,N,B-3,N,R,N,B-3,N,R,N,";
     colores[10]="B-3,N,R,N,B-3,N,R,N,B-3,N,R,N,";
     colores[11]="B-4,N,R,N-3,R-3,N-3,R,N,";
     colores[12]="B-4,N,R-11,N,";
     colores[13]="B-5,N,R-9,N,";
     colores[14]="B-3,N-2,R,N,R-7,N,R,N-2,";
     colores[15]="B-2,N,R-4,N-7,R-4,N,";
     colores[16]="B,N,R-17,N,";
     colores[17]="N,R,A-2,R-3,N,R-2,N,R-2,N,R-3,A-2,R,N,";
     colores[18]="N,A-3,N,R-3,N,R,N,R,N,R-3,N,A-3,N,";
     colores[19]="N,A-3,N,A,R-3,N-3,R-3,A,N,A-3,N,";
     colores[20]="N,A-3,N,A-2,R,N-5,R,A-2,N,A-3,N,";
     colores[21]="N,A-3,N,A-2,N,R,N,R,N,R,N,A-2,N,A-3,N,";
     colores[22]="N,R-3,N,R-4,N,R,N,R-4,N,R-3,N,";
     colores[23]="N,R-3,N,R-11,N,R-3,N,";
     colores[24]="N,R-3,N,A-11,N,A-3,N,";
     colores[25]="B,N-4,A-11,N-4,";
     colores[26]="B-4,N,A-4,N-3,A-4,N,";
     colores[27]="B-4,N,A-4,N,B,N,A-4,N,";
     colores[28]="B-4,N,A-4,N,B,N,A-4,N,";
     colores[29]="B-4,N,A-4,N,B,N,A-4,N,";
     colores[30]="B-4,N,R-4,N,B,N,R-4,N,";
     colores[31]="B-4,N,R-4,N,B,N,R-4,N,";
     colores[32]="B-3,N,R-5,N,B,N,R-5,N,";
     colores[33]="B-3,N-7,B,N-7,";
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
