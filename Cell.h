#include <string>
#include "Coord.h"
#include "Pieces.h"

#ifndef CELL_H 
#define CELL_H

using namespace std;

class Cell{
    private:
        int x;
        int y;
        Piece* piece;   
    
    public:
        Cell();
        Cell(int x, int y, Coord cubic, Piece* piece);
        string toString();
        Coord cubic;
        void setPiece(Piece* piece);
        Piece* getPiece();
};
#endif