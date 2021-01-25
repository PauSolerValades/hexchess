#include <vector>
#include "Pieces.h"
#include "Cell.h"

Piece::~Piece() = default;
string Piece::toString(){ 
    string a = "";
    a += type;
    return a; 
}

Knight::Knight() = default;
Knight::Knight(char type){
    this->type = type;
}
vector<Cell*> Knight::possible_movements(Cell* cell){

    vector<Cell*> cells(1,0);

    return cells;    
}

Bishop::Bishop() = default;
Bishop::Bishop(char type){
    this->type = type;
}
vector<Cell*> Bishop::possible_movements(Cell* cell){

    vector<Cell*> cells(1,0);

    return cells;    
}

