#include "miniwin.h"
#include "Figure.h"
#include<conio.h>

#define HORSPACE 4
#define VERSPACE 4

#define HORIZONTAL 800
#define VERTICAL 600

#define NOLINES true

using namespace miniwin;

Figure* background;
Figure* spaceship;

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
            color_rgb(70, 69, 67);
            break;
        case MARRON:
            color_rgb(121, 114, 96);
            break;
        case GRIS_OSCURO:
            color_rgb(142, 143, 135);
            break;
        case GRIS:
            color_rgb(183, 184, 175);
            break;
        case GRIS_CLARO:
            color_rgb(204, 201, 194);
            break;
        case GRIS_MUY_CLARO:
            color_rgb(216, 217, 212);
            break;
        case NARANJA_CLARO:
            color_rgb(255, 178, 115);
            break;
        case NARANJA:
            color_rgb(255, 116, 0);
            break;
        case NARANJA_OSCURO:
            color_rgb(191, 113, 48);
            break;
        case AZUL_MUY_OSCURO:
            color_rgb(45, 60, 130);
            break;
        case AZUL_OSCURO:
            color_rgb(7, 26, 113);
            break;
        case AZUL:
            color_rgb(21, 49, 174);
            break;
        case AZUL_CLARO:
            color_rgb(73, 98, 214);
            break;
        case AZUL_MUY_CLARO:
            color_rgb(111, 129, 214);
            break;
    }
}

std::string* spaceshipStructure(int size) {
    std::string* colores=new std::string[size];
    colores[0]="X-14,NC-2,";
    colores[1]="X-13,GCC,NA,NC,GCC,";
    colores[2]="X-12,N,GC,NA,NC,GC,GCC,";
    colores[3]="X-11,N,G-2,NA,NC,G,GC,GCC,";
    colores[4]="X-11,N,G,AO-3,ACC,GC,GCC,";
    colores[5]="X-10,N-2,G,AO,A-2,ACC,GC,GCC-2,";
    colores[6]="X-10,N,G,AO,AOO,A-2,AC,ACC,GC,GCC,";
    colores[7]="X-10,N,G,AO,AOO,A-2,AC,ACC,GC,GCC,";
    colores[8]="X-10,N,G,AO,AOO,A-2,AC,ACC,GC,GCC,";
    colores[9]="X-4,N,NO,N,X,N-3,G,AO,AOO,GCC-2,AC,ACC,GC,GCC,N-2,X,N,NO,N,";
    colores[10]="X-4,N,NA,N,X,N,GO,N,G,AO,N,GC-2,GCC,ACC,GC,GCC,GO,N,X,N,NA,N,";
    colores[11]="X-4,N,GO,N,X,N,GO,N,G,AO,N,G,GC,GCC,ACC,GC,GCC,GO,N,X,N,GO,N,";
    colores[12]="X-4,N-7,G,N,G-3,GC,GCC,GC,GCC-6,N,";
    colores[13]="X-4,N-2,G-5,N,G-5,GC,GCC,G,GC-4,GCC,N,";
    colores[14]="X-4,N,G-5,N,G-7,GCC,GC,G-4,GC,GCC,";
    colores[15]="X-3,N,G,N,M,N,G,N,G-9,GC,GCC,G,N,M,N,GC,GCC,";
    colores[16]="X-3,N,G,N-3,G,N,G-9,GC,GCC,G,N-3,GC,GCC,";
    colores[17]="X-2,N,GO,N,G-2,GC,GCC,N,G-3,N-4,G-2,GC,GCC,N,G-2,GC,GCC,GC,GCC,";
    colores[18]="X,N,G,GO,N,G-2,GC,GCC,G,N,G,N,G-4,N,G,N,GO,N,G-2,GC,GCC,G,GC,GCC,";
    colores[19]="N,G-2,GO,N,G-2,GC,GCC,G-2,N,G-6,N,G,GO,N,G-2,GC,GCC,G-2,GC,GCC,";
    colores[20]="N,NA-2,NO,N,G-2,GC,GCC,NA,G-3,NA-4,G-3,NO,N,G-2,GC,GCC,NC-3,GCC,";
    colores[21]="X,N-3,X,N,NC-2,GCC,G,NA,G,NA,G-4,NA,G,NA,GO,N,NC-2,GCC,X,GCC-3,";
    colores[22]="X-5,N,G,GC,GCC,N,G,NA,G-6,NA,G,N-2,G,GC,GCC,";
    colores[23]="X-5,N,G,GC,GCC,X,N-10,X,N,G,GC,GCC,";
    colores[24]="X-6,N-2,X-2,N,GO-2,N,X-2,N,GO-2,N,X-2,N-2,";
    colores[25]="X-10,N,NA-2,N,X-2,N,NA-2,N,";
    colores[26]="X-10,N,G-2,N,X-2,N,G-2,N,";
    colores[27]="X-11,N-2,X-4,N-2,";
    return colores;
}

void paint(Figure* figura) {
    int color=0;
    int x=figura->x;
    int y=figura->y;
    int sizex=figura->getSizeX();
    int sizey=figura->getSizeY();
    for(int i=x;i<x+sizex;i++) {
        for(int j=y;j<y+sizey;j++) {
            color=figura->structure[i-x][j-y];
            if(color==0) continue;
            choose_color(color);
            if(NOLINES) {
                 rectangulo_lleno(i*HORSPACE,j*VERSPACE,(i+1)*HORSPACE,(j+1)*VERSPACE);
            } else {
                 rectangulo_lleno(i*HORSPACE+1,j*VERSPACE+1,(i+1)*HORSPACE,(j+1)*VERSPACE);
            }
        }
     }
}

void paint_figures() {
     paint(spaceship);
}

void main_paint() {
     int x=0,y=0;
     if(NOLINES) {
          x=HORIZONTAL;
          y=VERTICAL;
     } else {
          x=HORIZONTAL+1;
          y=VERTICAL+1;
     }
     vredimensiona(x,y);
     if(!NOLINES) cuadricula(x,y);
     spaceship=new Figure(100,75,30,28,spaceshipStructure(28));
}

int main(){
    main_paint();
    int x = spaceship->x;
    int y = spaceship->y;
    int t = tecla();
    while(t != ESCAPE){
        if(t == IZQUIERDA){
            x=x-4;
            spaceship->x=x;
        } else if(t == DERECHA){
            x=x+4;
            spaceship->x=x;
        } else if(t == ARRIBA){
            y=y-4;
            spaceship->y=y;
        } else if(t == ABAJO){
            y=y+4;
            spaceship->y=y;
        }
        borra();
        paint_figures();
        refresca();
        espera(10);
        t= tecla();
    }
    return 0;
}
