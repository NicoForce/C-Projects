#include "miniwin.h"

#define ALTO 600
#define ANCHO 800

using namespace miniwin;

struct Pelota{
        float x,y;
        float dx,dy;
        float radio;
};

void circle(Pelota& P) {
    circulo(P.x,P.y,P.radio);
}

void mover(Pelota& P) {
    P.x+=P.dx;
    P.y+=P.dy;
    if(P.x>ANCHO-P.radio) {
        P.dx=-P.dx;
        P.x=ANCHO-P.radio;
    } else if(P.x<0+P.radio) {
        P.dx=-P.dx;
        P.x=0+P.radio;
    }
    if(P.y>ALTO-P.radio) {
        P.dy=-P.dy;
        P.y=ALTO-P.radio;
    } else if(P.y<0+P.radio) {
        P.dy=-P.dy;
        P.y=0+P.radio;
    }
}

void start() {
    vredimensiona(ANCHO, ALTO);
}

int main() {
    start();
    Pelota A={50,50,2,2,20};
    Pelota B={500,500,-2,1,30};
    Pelota C={200,10,2,10,50};
    Pelota D={80,400,-5,-1,5};
    Pelota E={330,240,6,-3,20};
    Pelota F={700,590,1,-1,25};
    while(tecla()!=ESCAPE) {
        borra();
        circle(A);
        circle(B);
        circle(C);
        circle(D);
        circle(E);
        circle(F);
        refresca();
        mover(A);
        mover(B);
        mover(C);
        mover(D);
        mover(E);
        mover(F);
        espera(10);
    }
    return 0;
}
