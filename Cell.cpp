#include <string>
#include "Cell.h"

using namespace std;


Cell::Cell() = default;
Cell::Cell(int xp, int yp, char piecep){
    x=xp;
    y=yp;
    piece=piecep;
}
string Cell::toString(){
    return "(" + to_string(x) + "," + to_string(y) +") -> " + piece;
}