#include <iostream>
#include <string.h>
#include <vector>
#include <cstdlib>

using namespace std;

class Prueba {
      private:
          int x;
          int y;
          vector<vector<int> > vec;
      public:          
          Prueba(){};
          Prueba(int,int,vector<vector<int> >);
          int getX(){return x;}             
          void setX(int a){ x=a;}
          int getY(){return y;}             
          void setY(int a) {y=a;}
          vector<vector<int> > getVec(){return vec;}
};

Prueba::Prueba(int a,int b,vector<vector<int> > c){
    x=a;
    y=b;
    vec=c;                             
}

int main() {
    unsigned int *a=new unsigned int;
    *a=10;
    vector<vector<int> > *v=new vector<vector<int> >;
    vector<vector<int> > *example=new vector<vector<int> >;
    (*v).resize(*a);
    for(int i=0; i<*a; ++i) {
            (*v)[i].resize(10);
    }
    for(int i=0; i<*a; ++i) {
            for(int j=0;j<10;j++) {
                    (*v)[i][j]=rand()%10+1;      
            }
    }
    Prueba *q=new Prueba(5,10,*v);
    cout<<q->getX()<<endl;
    *example=q->getVec();
    for(int i=0;i<*a;i++) {
            for(int j=0;j<10;j++) {
                   cout<<(*example)[i][j]<<" "; 
            }
            cout<<endl;
    }
    system("pause");
    return 0;   
}
