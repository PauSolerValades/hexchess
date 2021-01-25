#include <string>
#include "Cell.h"

using namespace std;

Cell::Cell() = default;
Cell::Cell(int x, int y, Coord cubic){
    this->x=x;
    this->y=y;
    this->cubic=cubic;
}
string Cell::toString(){
    return "(" + to_string(x) + "," + to_string(y) +")";
}