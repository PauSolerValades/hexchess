#include <vector>
#include <string>
#include "Cell.h"

#ifndef PIECE_H 
#define PIECE_H


class Piece{
    public:
        virtual vector<Cell*> possible_movements(Cell* cell);
        ~Piece();
        string toString();

    private:
        Piece();

    protected:
        char type;
};

class Horse: public Piece{
    public:
        Horse() = default;
        Horse(char type) : Piece();
        vector<Cell*> possible_movements(Cell* cell);
        string toString();
};

#endif