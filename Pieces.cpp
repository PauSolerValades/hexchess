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
    int i;
    vector<Coord*> result;

    for(i=1; i<3; ++i){

        if(abs(coord->x+i)<=5 && abs(coord->y-3)<=5){
            Coord* c1 = new Coord(coord->x+i,coord->y-3,-(coord->x+i)-(coord->y-3));
            Coord* c2 = new Coord(-(coord->x+i),-(coord->y-3),(coord->x+i) +(coord->y-3));
            result.push_back(c1);
            result.push_back(c2);
        }

        if(abs(coord->x-i)<=5 && abs(coord->y-3+i)<=5){
            Coord* c3 = new Coord(coord->x-i,coord->y-3+i,-(coord->x-i)-(coord->y-3+i));
            Coord* c4 = new Coord(-(coord->x-i),-(coord->y-3+i),(coord->x-i) + (coord->y-3+i));
            result.push_back(c3);
            result.push_back(c4);
        }

        if(abs(coord->x+3)<=5 && abs(coord->y-3+i)<=5){
            Coord* c5 = new Coord(coord->x+3, coord->y-3+i,-(coord->y-3+i)-(coord->x+3));
            Coord* c6 = new Coord(-(coord->x+3), -(coord->y-3+i),(coord->y-3+i)+(coord->x+3));
            result.push_back(c5);
            result.push_back(c6);
        }
    }
    return result;    
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

Tower::Tower() = default;
Tower::Tower(char piece, char team){
    this->piece=piece;
    this->type=team;    
}
vector<Coord*> Tower::possible_movements(Coord* coord){
    /*
    if a system more similar to the calculate diagonals would save
    a bit of calulations because you can obtain the whole axis with
    only one loop by substracting i and adding i to the coord while
    i incrementing.
    */
    
    int i, j;
    vector<Coord*> result;

    //first axis
    for(i=coord->x+1, j=coord->y-1; abs(i)<=5 && abs(j)<=5; ++i, --j){
        Coord* c1 = new Coord(i,j,-i-j);
        result.push_back(c1);
    }

    for(i=coord->x-1, j=coord->y+1; abs(i)<=5 && abs(j)<=5; --i, ++j){
        Coord* c1 = new Coord(i,j,-i-j);
        result.push_back(c1);
    }

    //second axis
    for(i=coord->x+1; abs(i)<=5; ++i){
        Coord* c1 = new Coord(i,coord->y,-i-coord->y);
        result.push_back(c1);
    }

    for(i=coord->x-1; abs(i)<=5; --i){
        Coord* c1 = new Coord(i,coord->y,-i - coord->y);
        result.push_back(c1);
    }

    //third axis
    for(i=coord->x+1; abs(i)<=5; ++i){
        Coord* c1 = new Coord(coord->x,i,-i - coord->x);
        result.push_back(c1);
    }

    for(i=coord->x-1; abs(i)<=5; --i){
        Coord* c1 = new Coord(coord->x,i,-i - coord->x);
        result.push_back(c1);
    }

    return result;
}

Queen::Queen() = default;
Queen::Queen(char piece, char type){
    this->piece=piece;
    this->type=type;
}
vector<Coord*> Queen::possible_movements(Coord* coord){

    /*
    This is just a copypaste code of the bishop and the tower.
    I thought to make another inheritance of bishop and tower to queen,
    but i had to check how is possible to inherit this without
    breaking anything

    TODO: check inheritance to bishop and tower
    */
    int i, j, k;
    vector<Coord*> result;

    for(i=coord->x+1, j=coord->y-1; abs(i)<=5 && abs(j)<=5; ++i, --j){
        Coord* c1 = new Coord(i,j,-i-j);
        result.push_back(c1);
    }

    for(i=coord->x-1, j=coord->y+1; abs(i)<=5 && abs(j)<=5; --i, ++j){
        Coord* c1 = new Coord(i,j,-i-j);
        result.push_back(c1);
    }

    for(i=coord->x+1; abs(i)<=5; ++i){
        Coord* c1 = new Coord(i,coord->y,-i-coord->y);
        result.push_back(c1);
    }

    for(i=coord->x-1; abs(i)<=5; --i){
        Coord* c1 = new Coord(i,coord->y,-i - coord->y);
        result.push_back(c1);
    }

    for(i=coord->x+1; abs(i)<=5; ++i){
        Coord* c1 = new Coord(coord->x,i,-i - coord->x);
        result.push_back(c1);
    }

    for(i=coord->x-1; abs(i)<=5; --i){
        Coord* c1 = new Coord(coord->x,i,-i - coord->x);
        result.push_back(c1);
    }

    //first axis
    for(i=coord->x+2, j=coord->y-1, k=coord->z-1; i<=5 && j<=5 && k<=5; i+=2, --j, --k){
        Coord* c1 = new Coord(i,j,k);
        result.push_back(c1);
    }

    for(i=coord->x-2, j=coord->y+1, k=coord->z+1; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; i-=2, ++j, ++k){
        Coord* c1 = new Coord(i,j,k);
        result.push_back(c1);
    }

    //second axis
    for(i=coord->x+1, j=coord->y-2, k=coord->z+1; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; ++i, j-=2, ++k){
        Coord* c1 = new Coord(i,j,k);
        result.push_back(c1);
    }

    for(i=coord->x-1, j=coord->y+2, k=coord->z-1; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; --i, j+=2, --k){
        Coord* c1 = new Coord(i,j,k);
        result.push_back(c1);
    }

    //third axis
    for(i=coord->x-1, j=coord->y-1, k=coord->z+2; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; --i, --j, k+=2){
        Coord* c1 = new Coord(i,j,k);
        result.push_back(c1);
    }

    for(i=coord->x+1, j=coord->y+1, k=coord->z-2; abs(i)<=5 && abs(j)<=5 && abs(k)<=5; ++i, ++j, k-=2){
        Coord* c1 = new Coord(i,j,k);
        result.push_back(c1);
    }

    return result;
}

PawnB::PawnB() = default;
PawnB::PawnB(char piece){
    this->piece = piece;
    this->type = 'B';
} 
vector<Coord*> PawnB::possible_movements(Coord* coord){
    int i;
    vector<Coord*> result;

    Coord* c1 = new Coord(coord->x-1,coord->y+1,-coord->x-coord->y);
    Coord* c2 = new Coord(coord->x,coord->y+1,-coord->x-coord->y);
    Coord* c3 = new Coord(coord->x+1,coord->y,-coord->x-coord->y);

    result.push_back(c1);
    result.push_back(c2);
    result.push_back(c3);

    return result; 
}

PawnW::PawnW() = default;
PawnW::PawnW(char piece){
    this->piece = piece;
    this->type = 'W';
}
vector<Coord*> PawnW::possible_movements(Coord* coord){
    int i;
    vector<Coord*> result;

    Coord* c1 = new Coord(coord->x+1,coord->y-1,-coord->x-coord->y);
    Coord* c2 = new Coord(coord->x,coord->y-1,-coord->x-coord->y);
    Coord* c3 = new Coord(coord->x-1,coord->y,-coord->x-coord->y);

    result.push_back(c1);
    result.push_back(c2);
    result.push_back(c3);

    return result; 
} 