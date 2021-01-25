#include <string>
#include "Coord.h"

using namespace std;

Coord::Coord() = default;
Coord::Coord(int x, int y){
    int a, b, c;
    this->x = (x - y)/2;
    this->z = y;
    this->y = -this->x-this->z;
}
Coord::Coord(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}
string Coord::toString(){
    return "(" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ")";
}