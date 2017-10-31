#include "miniwin.h"
#include <string.h>
#include <cstdlib>

#define HORSPACE 10
#define VERSPACE 10

#define HORIZONTAL 25
#define VERTICAL 30

#define NOLINES false

#define GRIS 0
#define NEGRO 1
#define VERDE_CLARO 2
#define VERDE 3
#define VERDE_OSCURO 4
#define BLANCO 5
#define ROJO 6
#define ROJO_OSCURO 7
#define ROSA_CLARO 8
#define ROSA_OSCURO 9

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
        case GRIS:
            color_rgb(110, 126, 142);
            break;
        case NEGRO:
             color_rgb(24, 40, 56);
             break;
        case VERDE_CLARO:
             color_rgb(152, 238, 41);
             break;
        case VERDE:
             color_rgb(39, 205, 37);
             break;
        case VERDE_OSCURO:
             color_rgb(0, 128, 0);
             break;
        case BLANCO:
             color_rgb(255, 255, 255);
             break;
        case ROJO:
             color_rgb(255, 0, 0);
             break;
        case ROJO_OSCURO:
             color_rgb(175, 31, 30);
             break;
        case ROSA_CLARO:
             color_rgb(255, 103, 186);
             break;
        case ROSA_OSCURO:
             color_rgb(255, 27, 144);
    }
}

int findColor(std::string a) {
    if(a=="G") return GRIS;
    else if(a=="N") return NEGRO;
    else if(a=="VC") return VERDE_CLARO;
    else if(a=="V") return VERDE;
    else if(a=="VO") return VERDE_OSCURO;
    else if(a=="B") return BLANCO;
    else if(a=="R") return ROJO;
    else if(a=="RR") return ROJO_OSCURO;
    else if(a=="RC") return ROSA_CLARO;
    else if(a=="RO") return ROSA_OSCURO;
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
     colores[0]="G-13,N-2,G,N-2,G-7,";
     colores[1]="G-12,N,V,VC,N,V,VC,N,G-6,";
     colores[2]="G-11,N,VO,V,B-5,N,G-5,";
     colores[3]="G-8,N-4,VO,B-2,N,B,N,B,N,G-5,";
     colores[4]="G-7,N,R-3,N,B-3,N,B,N,B,N,G-5,";
     colores[5]="G-7,N,RR,R,N-2,B-7,N-3,G-3,";
     colores[6]="G-7,N-3,VC,B,N,B-3,N,B,N,VC-3,N,G-2,";
     colores[7]="G-6,N,R,N,V,VC-3,N-3,VC,N,VC-2,B-2,VC,N,G,";
     colores[8]="G-5,N,RR,R,N,V,VC-2,B-3,VC,V,VC-3,N,VC,N,VC,N,";
     colores[9]="G-5,N,RR-2,N,VO,V,B-4,V-2,VC-7,N,";
     colores[10]="G-6,N-3,VO,V,B-4,N,V-2,VC-6,N,";
     colores[11]="G-7,N-2,VO-2,RC,B-2,RC,N,VO,V-3,VC-3,V,N,";
     colores[12]="G-7,N,R,N,VO-2,RC-2,N-2,VO-2,V-6,N,";
     colores[13]="G-8,N-3,VO-2,RC-2,N,VO-4,V-3,N,G,";
     colores[14]="G-8,N,R,N,VO,V,RO,RC,B,N,VO-4,N-2,G-2,";
     colores[15]="G-5,N-5,VO,V-2,RO-2,N-6,G-4,";
     colores[16]="G-4,N,R-2,N-3,VO,V,B-3,N-3,G-7,";
     colores[17]="G-2,N-2,R-2,N-2,VC-4,B-3,N,B,VC,N,G-6,";
     colores[18]="N-3,V,N-2,V-2,VC-2,N,B-4,N-2,B,VC,N,G-5,";
     colores[19]="N,VC,B,N-2,VC-4,N,B-5,N-3,VC,N,G-5,";
     colores[20]="N,B,VO,N,VC-3,B-2,VC,N,B-4,N-2,VC-2,N,G-5,";
     colores[21]="N,B-2,N,V,VC-2,B-2,N-2,B-3,N-2,VC-3,N,G-5,";
     colores[22]="G,N,B,N,VO,V,VC-4,N,B-3,N-2,V-3,N,G-5,";
     colores[23]="G,N,B-2,N,VO,V-3,N,B-2,RC,N-5,";
     colores[24]="G-2,N-7,RC-4,N,";
     colores[25]="G-2,N,RR,R-3,N,RO-2,N-3,";
     colores[26]="G-2,N,RR,R-3,N-3,R,N-3,";
     colores[27]="G,N,RR-3,R,B,R,N,RR,R-3,B,N,";
     colores[28]="G,N,RR-2,R-4,N,RR-2,R-3,N,";
     colores[29]="G,N-14,";
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
