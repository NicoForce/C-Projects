#include <vector>
#include <string>
#include <cstdlib>

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

class Figure
{
    private:
        unsigned int sizex;
        unsigned int sizey;

    public:
        unsigned int x;
        unsigned int y;
        std::vector<std::vector<int> > structure;

        Figure(unsigned int,unsigned int,unsigned int,unsigned int,std::string*);

        unsigned int getSizeX() { return sizex; }
        void setSizeX(unsigned int val) { sizex = val; }

        unsigned int getSizeY() { return sizey; }
        void setSizeY(unsigned int val) { sizey = val; }

        void initializeStructure();
        void setStructure(std::string*);

        int findColor(std::string);
};
