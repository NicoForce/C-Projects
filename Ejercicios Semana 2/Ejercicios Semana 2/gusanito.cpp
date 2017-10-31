#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include <queue>
#include <stdlib.h>

#define VELOCIDAD 50

#define LIMITE_SUPERIOR 0
#define LIMITE_INFERIOR 29
#define LIMITE_IZQUIERDO 0
#define LIMITE_DERECHO 120

#define FUERA -1
#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

using namespace std;

int max_size=3;
int x=10;
int y=10;
int tailx=x-(max_size+1)*2;
int taily=y;
int direction=RIGHT;
int taildirection=RIGHT;
char opcion;
char onfront=' ';
bool moved=false;
char grid[LIMITE_DERECHO+1][LIMITE_INFERIOR+1];

struct coordenadas{
    coordenadas(int abs,int ord,int dir) : i(abs),j(ord),k(dir) {}

    int i;
    int j;
    int k;
};

coordenadas cordy(0,0,0);
queue<coordenadas> colacola;

void gridini() {
    for(int i=0;i<=LIMITE_DERECHO;i++) {
        for(int j=0;j<=LIMITE_INFERIOR;j++) {
            grid[i][j]=' ';
        }
    }
}

void gotoxy (int x,int y) {
     HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y = y;
     SetConsoleCursorPosition (hcon, dwPos);
}

void pointappear() {
    bool appeared=false;
    int a,b;
    while(!appeared) {
        a=rand()%(LIMITE_DERECHO-1)+1;
        b=rand()%(LIMITE_INFERIOR-1)+1;
        if(a%2==0) {
            if(grid[a][b]==' '){
                gotoxy(a,b);
                printf("+");
                grid[a][b]='+';
                gotoxy(x,y);
                appeared=true;
            }
        }

    }
}

void start_level () {
    for(int i=0;i<=(max_size-1)*2;i=i+2){
        gotoxy(x-i,y);
        printf("*");
        grid[x-i][y]='*';
    }
}

void gridlimits(){
    for(int i=0;i<=LIMITE_INFERIOR;i++) {
        gotoxy(LIMITE_IZQUIERDO,i);
        printf("|");
        grid[LIMITE_IZQUIERDO][i]='|';
    }
    for(int i=0;i<=LIMITE_INFERIOR;i++) {
        gotoxy(LIMITE_DERECHO,i);
        printf("|");
        grid[LIMITE_DERECHO][i]='|';
    }
    for(int i=1;i<=LIMITE_DERECHO-1;i++) {
        gotoxy(i,LIMITE_SUPERIOR);
        printf("-");
        grid[i][LIMITE_SUPERIOR]='-';
    }
    for(int i=1;i<=LIMITE_DERECHO-1;i++) {
        gotoxy(i,LIMITE_INFERIOR);
        printf("-");
        grid[i][LIMITE_INFERIOR]='-';
    }
}

int new_direction(char op,int dir) {
    switch(op) {
        case 'w':
            if(dir!=DOWN) {
                dir=UP;
            }
            break;
        case 'a':
            if(dir!=RIGHT) {
                dir=LEFT;
            }
            break;
        case 's':
            if(dir!=UP) {
                dir=DOWN;
            }
            break;
        case 'd':
            if(dir!=LEFT) {
                dir=RIGHT;
            }
            break;
        case 'z':
            dir=FUERA;
            break;
    }
    if(dir!=direction) {
        colacola.push(coordenadas(x,y,dir));
    }
    return dir;
}

int delete_tail() {
    if(!colacola.empty()) {
        cordy=colacola.front();
        if(tailx==cordy.i && taily==cordy.j) {
            taildirection=cordy.k;
            colacola.pop();
        }
    }
    gotoxy(tailx,taily);
    printf(" ");
    switch(taildirection) {
        case UP: taily--; break;
        case DOWN: taily++; break;
        case LEFT: tailx=tailx-2; break;
        case RIGHT: tailx=tailx+2; break;
    }
    return 0;
}

void tailincrease(){
    switch(taildirection) {
        case UP: taily++; break;
        case DOWN: taily--; break;
        case LEFT: tailx=tailx+2; break;
        case RIGHT: tailx=tailx-2; break;
    }
    gotoxy(tailx,taily);
    printf("*");
    gotoxy(x,y);
}

void fronthead(){
    char a=grid[x][y];
    if(a!=' '){
        switch(a){
            case '+':
                tailincrease();
                pointappear();
                break;
            case '*':
                direction=-1;
                break;
            case '-':
                direction=-1;
                break;
            case '|':
                direction=-1;
                break;
        }
    }
}

void move_snake(int dir) {
    switch(dir) {
        case UP: y--; break;
        case DOWN: y++; break;
        case LEFT: x=x-2; break;
        case RIGHT: x=x+2; break;
    }
    gotoxy(x,y);
    fronthead();
    printf("*");
    grid[x][y]='*';
    delete_tail();
    grid[tailx][taily]=' ';
}

int main() {
    system("MODE 121,30");
    gridini();
    gridlimits();
    start_level();
    pointappear();
    while(direction!=-1) {
            if(kbhit()) {
                 opcion=getch();
                 direction=new_direction(opcion,direction);
            }
            Sleep(VELOCIDAD);
            move_snake(direction);
    }
    return 0;
}
