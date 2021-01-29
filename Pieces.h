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
        char piece;
        vector<Coord*> get_neighbours(Coord* coord);
        vector<Coord*> get_diagonals(Coord* coord);
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
        Knight(char piece, char type);
        vector<Coord*> possible_movements(Coord* coord);
};

class Bishop: public Piece{
    public:
        Bishop();
        Bishop(char piece, char type);
        vector<Coord*> possible_movements(Coord* Coord);
};

class PawnW: public Piece{
    public:
        PawnW();
        PawnW(char piece);
        vector<Coord*> possible_movements(Coord* Coord);

};

class PawnB: public Piece{
    public:
        PawnB();
        PawnB(char piece);
        vector<Coord*> possible_movements(Coord* Coord);

};

class King: public Piece{
    public:
        King();
        King(char piece, char type);
        vector<Coord*> possible_movements(Coord* Coord);

};

class Tower: public Piece{
    public:
        Tower();
        Tower(char piece, char type);
        vector<Coord*> possible_movements(Coord* Coord);
        
};

class Queen: public Piece{
    public:
        Queen();
        Queen(char piece, char type);
        vector<Coord*> possible_movements(Coord* Coord);
};
#endif