#include <vector>
#include <string>
#include "Coord.h"

#ifndef PIECE_H 
#define PIECE_H

class Piece{
    public:
        virtual ~Piece();
        virtual vector<Coord*> possible_movements(Coord* coord) = 0;
        string toString();
        char getType();

    protected:
        char type;
};

class Nopiece: public Piece{
    public:
        Nopiece();

    private:
        vector<Coord*> possible_movements(Coord* Coord);
};

class Knight: public Piece{
    public:
        Knight();
        Knight(char type);
        
    private:
        vector<Coord*> possible_movements(Coord* coord);
};

class Bishop: public Piece{
    public:
        Bishop();
        Bishop(char type);
        
    private:
        vector<Coord*> possible_movements(Coord* Coord);
};
#endif