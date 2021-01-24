#include <vector>
#include "Pieces.h"
#include "Cell.h"

Piece::~Piece() = default;
string Piece::toString(){ 
    string a = "";
    a += type;
    return a; 
}

Horse::Horse(char type){
    this->type = type;
}

vector<Cell*> Horse::possible_movements(Cell* cell){

    vector<Cell*> cells;

    return cells;    
}

