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
vector<Coord*> Piece::get_neighbours(Coord* coord){
    
    int i,j;
    vector<Coord*> result;

    //using axial coordinates to iterate
    for(i=-1;i<=1;++i){
        for(j=-1; j<=1; ++j){
            if(i!=j && abs(coord->x+i)<=5 && abs(coord->y+j)<=5){
                Coord* c = new Coord(coord->x+i, coord->y+j,-coord->x-coord->y);
                result.push_back(c);
            }
        }
    }

    return result;
}
vector<Coord*> Piece::get_diagonals(Coord* coord){

    vector<Coord*> result;
    
    //i wish i coud have found a more elegant way
    if(abs(coord->x+2)<=5 && abs(coord->y-1)<=5 && abs(coord->z-1)<=5){
        Coord* c1 = new Coord(coord->x+2, coord->y-1, coord->z-1);
        result.push_back(c1);
    }

    if(abs(coord->x-2)<=5 && abs(coord->y+1)<=5 && abs(coord->z+1)<=5){
        Coord* c2 = new Coord(coord->x-2, coord->y+1, coord->z+1);
        result.push_back(c2);
    }

    if(abs(coord->x+1)<=5 && abs(coord->y-2)<=5 && abs(coord->z+1)<=5){
        Coord* c3 = new Coord(coord->x+1, coord->y-2, coord->z+1);
        result.push_back(c3);
    }

    if(abs(coord->x-1)<=5 && abs(coord->y+2)<=5 && abs(coord->z-1)<=5){
        Coord* c4 = new Coord(coord->x-1, coord->y+2, coord->z-1);
        result.push_back(c4);
    }

    if(abs(coord->x+1)<=5 && abs(coord->y+1)<=5 && abs(coord->z-2)<=5){
        Coord* c5 = new Coord(coord->x+1, coord->y+1, coord->z-2);
        result.push_back(c5);
    }

    if(abs(coord->x-1)<=5 && abs(coord->y-1)<=5 && abs(coord->z+2)<=5){
        Coord* c6 = new Coord(coord->x-1, coord->y-1, coord->z+2);
        result.push_back(c6);
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
Knight::Knight(char piece, char type){
    this->piece=piece;
    this->type = type;
}
vector<Coord*> Knight::possible_movements(Coord* coord){

    vector<Coord*> cells(1,0);

    return cells;    
}

Bishop::Bishop() = default;
Bishop::Bishop(char piece, char type){
    this->piece=piece;
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

King::King() = default;
King::King(char piece, char team){
    this->piece=piece;
    this->type=team;
}
vector<Coord*> King::possible_movements(Coord* coord){
    vector<Coord*> result, merge1, merge2;

    merge1 = this->get_neighbours(coord);
    merge2 = this->get_diagonals(coord);

    result.resize(merge1.size() + merge2.size());
    std::move(merge1.begin(), merge1.end(), result.begin());
    std::move(merge2.begin(), merge2.end(), result.begin()+merge1.size());

    return result;
}

