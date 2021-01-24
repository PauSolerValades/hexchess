#include <string>

#ifndef CELL_H 
#define CELL_H

using namespace std;

class Cell{
    private:
        int x;
        int y;
    
    public:
        Cell();
        Cell(int x, int y);
        string toString();
};
#endif