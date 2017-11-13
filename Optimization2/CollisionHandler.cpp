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
    for(int k=0;k<figures.size();k++) {
        figure=figures[k];
        for(int j=figure->y;j<figure->y+figure->getSizeY();j++) {
            for(int i=figure->x;i<figure->x+figure->getSizeX();i++) {
                collisionGrid[j][i]=k;
            }
        }
    }
}

void CollisionHandler::clean() {
    for(int j=0;j<collisionGrid.size();j++) {
        for(int i=0;i<collisionGrid[j].size();i++) {
            collisionGrid[j][i]=0;
        }
    }
}

void CollisionHandler::pushFigure(Figure* figure) {
    figures.push_back(figure);
}

int* CollisionHandler::shotImpactCheck(Figure* figure) {
    int *x=new int();
    for(int j=figure->y;j<figure->y+figure->getSizeY();j++) {
        for(int i=figure->x;i<figure->x+figure->getSizeX();i++) {
            *x=collisionGrid[j][i];
            if(x!=0) {
                break;
            }
        }
    }
    return x;
}
