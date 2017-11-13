#include "Figure.h"

class CollisionHandler
{
    public:
        std::vector<std::vector<int> > collisionGrid;
        std::vector<Figure*> figures;
        int collitions;
        CollisionHandler(int,int);
        void hitbox();
        void clean();
        void pushFigure(Figure*);
        void shotImpactCheck(Figure*);
};
