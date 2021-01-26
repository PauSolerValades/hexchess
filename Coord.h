#include <string>

using namespace std;

#ifndef COORD_H 
#define COORD_H

class Coord{
    public:
        Coord();
        Coord(int x, int y);
        Coord(int x, int y, int z);
        string toString();

        //this should be private and have getters and setter but idk rn
        int x;
        int y;
        int z;
};
#endif