#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(int hor, int ver)
{
    collisionGrid.resize(ver);
    for(int i=0;i<ver;i++) {
        collisionGrid[i].resize(hor);
    }
    collitions=0;
}

void CollisionHandler::hitbox() {
    Figure* figure;
    for(unsigned int k=0;k<figures.size();k++) {
        figure=figures[k];
        for(unsigned int j=figure->y;j<figure->y+figure->getSizeY();j++) {
            for(unsigned int i=figure->x;i<figure->x+figure->getSizeX();i++) {
                //possible mistake here
                if(figure->hitbox[j-figure->y][i-figure->x]) {
                    collisionGrid[j][i]=k+1;
                }
            }
        }
    }
}

void CollisionHandler::clean() {
    for(unsigned int j=0;j<collisionGrid.size();j++) {
        for(unsigned int i=0;i<collisionGrid[j].size();i++) {
            collisionGrid[j][i]=0;
        }
    }
}

void CollisionHandler::pushFigure(Figure* figure) {
    figures.push_back(figure);
}

void CollisionHandler::shotImpactCheck(Figure* figure) {
    int x;
    for(unsigned int j=figure->y;j<figure->y+figure->getSizeY();j++) {
        for(unsigned int i=figure->x;i<figure->x+figure->getSizeX();i++) {
            x=collisionGrid[j][i];
            if(x>0) {
                collitions=collisionGrid[j][i];
                break;
            }
        }
    }
}
