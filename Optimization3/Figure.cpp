#include "Figure.h"

Figure::Figure(unsigned int hor,unsigned int ver,unsigned int hor_size,unsigned int ver_size,std::string *colors,bool hitbox) {
    x=hor;
    y=ver;
    sizex=hor_size;
    sizey=ver_size;
    initializeStructure();
    setStructure(colors);
    if(hitbox) {
        setHitbox();
    }
}

void Figure::initializeStructure() {
    structure.resize(sizex);
    for(unsigned int i=0;i<sizex;i++) {
        structure[i].resize(sizey);
    }
}

void Figure::setStructure(std::string* colors) {
    std::string temp1="",temp2="",temp3="";
    int sizes=0,repeat=0,horizontal=0;
    bool semi=false;
    char character;
    for(unsigned int j=0;j<sizey;j++) {
        temp1=colors[j];
        sizes=temp1.length();
        for(int i=0;i<sizes;i++) {
            character=temp1.at(i);
            if(character==',') {
                if(semi) {
                    repeat=atoi(temp3.c_str());
                    while(repeat>0) {
                        structure[horizontal][j]=findColor(temp2);
                        horizontal++;
                        repeat--;
                    }
                    temp3="";
                    semi=false;
                } else {
                    structure[horizontal][j]=findColor(temp2);
                    horizontal++;
                }
                temp2="";
            } else if(character=='-') {
                semi=true;
            } else if(semi) {
                temp3+=character;
            } else {
                temp2+=character;
            }
        }
        horizontal=0;
    }
    delete &colors;
}

int Figure::findColor(std::string a) {
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

void Figure::setHitbox() {
    hitbox.resize(structure[0].size());
    for(unsigned int k=0;k<hitbox.size();k++) {
        hitbox[k].resize(structure.size());
    }
    for(unsigned int j=0;j<hitbox.size();j++) {
        for(unsigned int i=0;i<hitbox[j].size();i++) {
            hitbox[j][i]=false;
            if(structure[i][j]!=0) {
                hitbox[j][i]=true;
            }
        }
    }
}

