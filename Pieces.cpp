#include <vector>
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
    int i;
    
    toCheck.push_back(coord);

    while(toCheck.size() != 0){
        Coord c1(toCheck[0]->x+2, toCheck[0]->y-1, toCheck[0]->z-1);
        Coord c2(toCheck[0]->x-2, toCheck[0]->y+1, toCheck[0]->z+1);
        Coord c3(toCheck[0]->x-1, toCheck[0]->y+2, toCheck[0]->z-1);
        Coord c4(toCheck[0]->x+1, toCheck[0]->y-2, toCheck[0]->z+1);
        Coord c5(toCheck[0]->x-1, toCheck[0]->y-1, toCheck[0]->z+2);
        Coord c6(toCheck[0]->x+1, toCheck[0]->y+1, toCheck[0]->z-2);
        
        toCheck.erase(toCheck.begin());

        Coord* c1_ptr = &c1;
        Coord* c2_ptr = &c2;
        Coord* c3_ptr = &c3;
        Coord* c4_ptr = &c4;
        Coord* c5_ptr = &c5;
        Coord* c6_ptr = &c6;

        protopossible.push_back(c1_ptr);
        protopossible.push_back(c2_ptr);
        protopossible.push_back(c3_ptr);
        protopossible.push_back(c4_ptr);
        protopossible.push_back(c5_ptr);
        protopossible.push_back(c6_ptr);

        for(i=0; i<6; ++i){
            if(abs(protopossible[i]->x) <= 6 && abs(protopossible[i]->y) <= 6 && abs(protopossible[i]->z) <= 6){
                toCheck.push_back(protopossible[i]);
            }
        }
    }
    //moving by diagonals: adding +-1 to two coord and +-2 to one


    return results;    
}

