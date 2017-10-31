#include "miniwin.h"
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include<windows.h>	

#define HORSPACE 2
#define VERSPACE 2

#define HORIZONTAL 800
#define VERTICAL 600

#define IZQUIERDA 75
#define DERECHA  77

#define NOLINES true

#define BLANCO 0
#define NEGRO 1
#define MARRON 2
#define GRIS_OSCURO 3
#define GRIS 4
#define GRIS_CLARO 5
#define GRIS_MUY_CLARO 6
#define NARANJA_CLARO 7
#define NARANJA 8
#define NARANJA_OSCURO 9
#define AZUL_MUY_OSCURO 10
#define AZUL_OSCURO 11
#define AZUL 12
#define AZUL_CLARO 13
#define AZUL_MUY_CLARO 14

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

int findColor(std::string a) {
    if(a=="X") return BLANCO;
    else if(a=="N") return NEGRO;
    else if(a=="M") return MARRON;
    else if(a=="GO") return GRIS_OSCURO;
    else if(a=="G") return GRIS;
    else if(a=="GC") return GRIS_CLARO;
    else if(a=="GCC") return GRIS_MUY_CLARO;
    else if(a=="NC") return NARANJA_CLARO;
    else if(a=="NA") return NARANJA;
    else if(a=="NO") return NARANJA_OSCURO;
    else if(a=="AOO") return AZUL_MUY_OSCURO;
    else if(a=="AO") return AZUL_OSCURO;
    else if(a=="A") return AZUL;
    else if(a=="AC") return AZUL_CLARO;
    else if(a=="ACC") return AZUL_MUY_CLARO;
    return 0;
}

std::string* spaceship(int size) {
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

void paint(int ix,int iy,int spacex, int spacey,std::string* colores,int direction) {
     int a=0;
     int b=0;
     if(direction==1 || direction==3) {
          a=iy+spacey;
          b=ix+spacex;        
     } else {
          a=ix+spacex;
          b=iy+spacey;          
     }                       
     int grid[a][b];
     std::string temp1="";
     std::string temp2="";
     std::string temp3="";
     int sizes=0;
     int hor=0;
     int repeat=0;
     bool semi=false;
     char character;
     if(direction==1 || direction ==3) {
                     
     for(int i=ix;i<b;i++) {
        for(int j=iy;j<a;j++) {
            grid[j][i]=0;
        }
     }
     
     } else {
            
     for(int i=iy;i<b;i++) {
        for(int j=ix;j<a;j++) {
            grid[j][i]=0;
        }
     }       
            
     }
     for(int j=0;j<spacey;j++) {
           temp1=colores[j];
           sizes=temp1.length();
           for(int i=0;i<sizes;i++) {
                 character=temp1.at(i);
                 if(character==',') {
                      if(semi) {
                           repeat=atoi(temp3.c_str());
                           while(repeat>0) {
                                /*switch(direction) {
                                case 0:
                                    grid[hor+ix][j+iy]=findColor(temp2);
                                    break;
                                case 1:
                                    grid[j+iy][hor+ix]=findColor(temp2);
                                    break;
                                case 2:
                                    grid[hor+ix][b-1-j]=findColor(temp2);
                                    break;
                                case 3:
                                    grid[hor+ix][j+iy]=findColor(temp2);
                                }*/
                                grid[hor+ix][j+iy]=findColor(temp2);
                                hor++;
                                repeat--;
                           }
                           temp2="";
                           temp3="";
                           semi=false;
                      } else {
                           /*  
                           switch(direction) {
                                case 0:
                                    grid[hor+ix][j+iy]=findColor(temp2);
                                    break;
                                case 1:
                                    grid[j+iy][hor+ix]=findColor(temp2);
                                    break;
                                case 2:
                                    grid[hor+ix][b-1-j]=findColor(temp2);
                                    break;
                                case 3:
                                    grid[hor+ix][j+iy]=findColor(temp2);
                           } */
                           grid[hor+ix][j+iy]=findColor(temp2);
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
     for(int i=iy;i<b;i++) {
        for(int j=ix;j<a;j++) {
            if(grid[j][i]==0) continue;
            choose_color(grid[j][i]);
            if(NOLINES) {
                 rectangulo_lleno(j*HORSPACE,i*VERSPACE,(j+1)*HORSPACE,(i+1)*VERSPACE);
            } else {
                 rectangulo_lleno(j*HORSPACE+1,i*VERSPACE+1,(j+1)*HORSPACE,(i+1)*VERSPACE);
            }
        }
     }
}

void paint_figures(int a,int b) {
     paint(a,b,30,28,spaceship(28),0);
     //paint(31,1,35,28,spaceship(28),1);
     //paint(61,1,30,28,spaceship(28),2);
     //paint(91,1,30,28,spaceship(28),3);
     //if(!NOLINES)cuadricula(HORIZONTAL,VERTICAL);   
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
}
/*
void change_coords(char key) {
     switch(key) {
         case IZQUIERDA:
              x_ax=x_ax-1;
              break;
         case DERECHA:
              x_ax=x_ax+1;
              break;
         case 'z':
             exits=false;               
     }    
}

void detect_movement() {
     if(kbhit()) {
         char key=getch();
         change_coords(key);
     }
}*/

int main() {
    main_paint();
    char key;
    int x_ax=10;
    int y_ax=10;
    bool exits=true;
    while(exits) {
        white_canvas(800,600);
        paint_figures(x_ax,y_ax);        
        refresca();
        Sleep(1000);
        if(!_kbhit()) {
              x_ax++;
              y_ax++;      
        }
    }
    return 0;
}
