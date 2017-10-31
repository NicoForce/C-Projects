#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy (int x,int y) {
     HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y = y;
     SetConsoleCursorPosition (hcon, dwPos);    
}

char opcion;
int x=10;
int y=10;
int prex;
int prey;

int main() {
    while(opcion!='z') {
        gotoxy(x,y);
        printf("*");
        opcion=getch();
        prex=x;
        prey=y;
        gotoxy(prex,prey);
        printf(" ");
        switch (opcion) {
               case 'w': y--; break;
               case 's': y++; break;
               case 'a': x--; break;
               case 'd': x++; break;       
        }
    }                       
    return 0;
}
