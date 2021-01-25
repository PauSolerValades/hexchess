#include <string>

using namespace std;

#ifndef COORD_H 
#define COORD_H

class Coord{
    private:
        int x;
        int y;
        int z;
    
    public:
        Coord();
        Coord(int x, int y);
        Coord(int x, int y, int z);
        string toString();
};
#endif