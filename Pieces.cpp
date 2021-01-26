#include <vector>
#include <iostream>

#include "Pieces.h"
#include "Coord.h"

Piece::~Piece() = default;
string Piece::toString(){ 
    string a = "";
    a += type;
    return a; 
}
char Piece::getType(){
    return this->type;
}

Nopiece::Nopiece(){
    this->type = ' ';
}
vector<Coord*> Nopiece::possible_movements(Coord* coord){
    vector<Coord*> coords(0);
    return coords;
}

Knight::Knight() = default;
Knight::Knight(char type){
    this->type = type;
}
vector<Coord*> Knight::possible_movements(Coord* coord){

    vector<Coord*> cells(1,0);

    return cells;    
}

Bishop::Bishop() = default;
Bishop::Bishop(char type){
    this->type = type;
}
vector<Coord*> Bishop::possible_movements(Coord* coord){

    vector<Coord*> toCheck, protopossible, results;
    int i, j, k;
    
    //moving by diagonals: adding +-1 to two coord and +-2 to one
    //for each cell we calculate the 3 possible diagonals.
    //the map goes as far as +-10 in each coordinate,

    //first axis
    for(i=coord->x, j=coord->y, k=coord->z; i<=10 && j<=10 && k<=10; i+=2, --j, --k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    for(i=coord->x, j=coord->y, k=coord->z; abs(i)<=10 && abs(j)<=10 && abs(k)<=10; i-=2, ++j, ++k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    //second axis
    for(i=coord->x, j=coord->y, k=coord->z; abs(i)<=10 && abs(j)<=10 && abs(k)<=10; ++i, j-=2, ++k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    for(i=coord->x, j=coord->y, k=coord->z; abs(i)<=10 && abs(j)<=10 && abs(k)<=10; --i, j+=2, --k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    //third axis
    for(i=coord->x, j=coord->y, k=coord->z; abs(i)<=10 && abs(j)<=10 && abs(k)<=10; --i, --j, k+=2){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    for(i=coord->x, j=coord->y, k=coord->z; abs(i)<=10 && abs(j)<=10 && abs(k)<=10; ++i, ++j, k-=2){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    return results;    
}

