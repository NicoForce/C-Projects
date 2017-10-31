#include <iostream>
#include <cstdio>
#include <windows.h>
#include <conio.h>

#define CARACTER 1

#define VELOCIDAD 20

// Caracteres i, j, k, l (pueden servir para otras cosas)
#define ARRIBA 'i'       // 105
#define ABAJO 'k'        // 106
#define IZQUIERDA 'j'    // 107
#define DERECHA 'l'      // 108

// limites de la pantalla
#define LIMITE_SUPERIOR 1
#define LIMITE_INFERIOR 25
#define LIMITE_DERECHO 80
#define LIMITE_IZQUIERDO 1

using namespace std;

// Definicion de la clase PELOTA
class PELOTA {
private:
   // Coordenadas
   int x;   // Coordenada x
   int y;   // Coordenada y
   
   // Direccion de movimiento
   int direccion_horizontal;
   int direccion_vertical;
   
public:
   PELOTA(int, int);
   void setX(int);
   void setY(int);
   int getX();
   int getY();
   void toString();
   void pintar();
   void borrar();
   void mover();
   void gotoxy(int x,int y);
   void setDireccionVertical(int direccion) { direccion_vertical = direccion; }
	void setDireccionHorizontal(int direccion) { direccion_horizontal = direccion; }
};

PELOTA::PELOTA(int x, int y) {
   this->x = x;
   this->y = y;
   direccion_vertical = ABAJO;
   direccion_horizontal = IZQUIERDA;
}


void PELOTA::setX(int x) { this->x = x; }
void PELOTA::setY(int y) { this->y = y; }


int PELOTA::getX() { return x; }
int PELOTA::getY() { return y; }


void PELOTA::toString() {
   cout << "\nCoordenadas del TANQUE\n";
   cout << "X = " << this->getX() << endl;
   cout << "y = " << this->getY() << endl;
}

void PELOTA::gotoxy (int x,int y) {
     HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y = y;
     SetConsoleCursorPosition (hcon, dwPos);    
}

void PELOTA::pintar() {
   gotoxy(getX(), getY());
   printf("%c", CARACTER);
}


void PELOTA::mover() {
   
   Sleep(VELOCIDAD);
   borrar();
   
   // Cuando la pelotita choque con los bordes, cambia de direccion
   if (x == LIMITE_DERECHO) direccion_horizontal = IZQUIERDA;
   if (x == LIMITE_IZQUIERDO) direccion_horizontal = DERECHA;
   if (y == LIMITE_SUPERIOR)  direccion_vertical = ABAJO;
   if (y == LIMITE_INFERIOR)  direccion_vertical = ARRIBA;

   if (direccion_horizontal == DERECHA) x++;
   if (direccion_horizontal == IZQUIERDA) x--;
   if (direccion_vertical == ABAJO) y++;
	if (direccion_vertical == ARRIBA) y--;

   pintar();
}

void PELOTA::borrar() {
   gotoxy(getX(), getY());
   cout << " ";
}


int main()
{
   PELOTA pelota1(5, 5);
   PELOTA pelota2(10, 10);
   PELOTA pelota3(15, 15);
   PELOTA pelota4(20, 1);
   PELOTA pelota5(50, 25);
   
   
   while (true) {
      pelota1.mover();
      pelota2.mover();
      pelota3.mover();
      pelota4.mover();
      pelota5.mover();
   }
   
   return 0;
}
