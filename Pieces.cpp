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
vector<Coord*> Piece::get_diagonals(Coord* coord){
    
    int i;
    vector<Coord*> result, real_result;

    Coord* c1 = new Coord(coord->x+2, coord->y-1, coord->z-1);
    Coord* c2 = new Coord(coord->x-2, coord->y+1, coord->z+1);
    Coord* c3 = new Coord(coord->x+1, coord->y-2, coord->z+1);
    Coord* c4 = new Coord(coord->x-1, coord->y+2, coord->z-1);
    Coord* c5 = new Coord(coord->x+1, coord->y+1, coord->z-2);
    Coord* c6 = new Coord(coord->x-1, coord->y-1, coord->z+2);
    
    result.push_back(c1);
    result.push_back(c2);
    result.push_back(c3);
    result.push_back(c4);
    result.push_back(c5);
    result.push_back(c6);

    for(i=0; i<result.size(); ++i){
        if(abs(result[i]->x)>=5 || abs(result[i]->y)>=5 || abs(result[i]->z)>=5){
            real_result.push_back(result[i]);
        }
    }

    return result;
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
    for(i=coord->x+2, j=coord->y-1, k=coord->z-1; i<=5 && j<=5 && k<=5; i+=2, --j, --k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    for(i=coord->x-2, j=coord->y+1, k=coord->z+1; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; i-=2, ++j, ++k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    //second axis
    for(i=coord->x+1, j=coord->y-2, k=coord->z+1; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; ++i, j-=2, ++k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    for(i=coord->x-1, j=coord->y+2, k=coord->z-1; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; --i, j+=2, --k){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    //third axis
    for(i=coord->x-1, j=coord->y-1, k=coord->z+2; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; --i, --j, k+=2){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    for(i=coord->x+1, j=coord->y+1, k=coord->z-2; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; ++i, ++j, k-=2){
        Coord* c1 = new Coord(i,j,k);
        results.push_back(c1);
    }

    return results;    
}

