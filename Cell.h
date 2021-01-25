#include <string>
#include "Coord.h"

#ifndef CELL_H 
#define CELL_H

using namespace std;

class Cell{
    private:
        int x;
        int y;
        
    
    public:
        Cell();
        Cell(int x, int y, Coord cubic);
        string toString();
        Coord cubic;
};
#endif