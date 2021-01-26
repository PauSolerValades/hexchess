#include <string>
#include "Cell.h"

using namespace std;

Cell::Cell() = default;
Cell::Cell(int x, int y, Coord cubic, Piece* piece){
    this->x=x;
    this->y=y;
    this->cubic=cubic;
    this->piece=piece;
}
string Cell::toString(){
    return cubic.toString() + "(" + to_string(x) + "," + to_string(y) +") -> " + piece->toString();
}
void Cell::setPiece(Piece* piece){
    this->piece = piece;
}
Piece* Cell::getPiece(){
    return this->piece;
}