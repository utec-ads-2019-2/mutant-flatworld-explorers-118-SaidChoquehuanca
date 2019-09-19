#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> lostinX;
vector<int> lostinY;
int limX;
int limY;
char orientacion;
string instrucciones;
int posicionX;
int posicionY;
bool lost=false;

bool mover(int x,int y){
    if( orientacion == 'N'){
        if ((y+1)>limY) return false;
    }
    else if( orientacion == 'W') {
        if ((x-1)<0) return false;
    }
    else if( orientacion == 'S') {
        if((y-1)<0) return false;
    }
    else if( orientacion == 'E') {
        if((x+1)>limX) return false;
    }
    return true;
}

bool iscent(int x, int y){
    for (int i = 0; i < lostinX.size(); ++i) {
        if(lostinX[i]==x and  lostinY[i]==y){
            return true;
        }
    }
    return false;
}

void move(){
    if(mover(posicionX,posicionY)){
        if (orientacion == 'N'){
            posicionY++;
        }
        else if (orientacion == 'S'){
            posicionY--;
        }
        else if (orientacion == 'E'){
            posicionX++;
        }
        else if (orientacion == 'W'){
            posicionX--;
        }
    }
    else if(!iscent(posicionX, posicionY)) {
        lost = true;
        lostinX.push_back(posicionX);
        lostinY.push_back(posicionY);
    }
}
void CambiarOrientacion(char instruccion){
    switch(instruccion){
        case 'R':{
        if (orientacion == 'N'){
            orientacion = 'E';
        }
        else if (orientacion == 'S'){
            orientacion = 'W';
        }
        else if (orientacion == 'E'){
            orientacion = 'S';
        }
        else if (orientacion == 'W'){
            orientacion = 'N';
        }
        break;}
        case 'L':{
        if(orientacion == 'N'){
            orientacion = 'W';
        }
        else if(orientacion == 'S'){
            orientacion = 'E';
        }
        else if(orientacion == 'E'){
            orientacion = 'N';
        }
        else if(orientacion == 'W'){
            orientacion = 'S';
        }
        break;}
    }
}

int main() {
    cin>>limX>>limY;
    while(cin>>posicionX>>posicionY>>orientacion){
        cin>>instrucciones;
        for(int i = 0; i < instrucciones.length(); ++i) {

            if (instrucciones[i] == 'L'){
                CambiarOrientacion('L');
            }
            else if(instrucciones[i] == 'R'){
                CambiarOrientacion('R');
            }
            else if (instrucciones[i] == 'F'){
                move();
            }

            if(lost) break;

        }
        if(lost) cout<<posicionX<<" "<<posicionY<<" "<<orientacion<<" LOST"<<endl;

        else cout<<posicionX<<" "<<posicionY<<" "<<orientacion<<endl;

        lost = false;

    }
    return 0;
}


