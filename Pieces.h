#include <vector>
#include <string>
#include "Cell.h"

class Piece{
    public:
        virtual ~Piece();
        virtual vector<Cell*> possible_movements(Cell* cell) = 0;
        string toString();

    protected:
        char type;
};


class Knight: public Piece{
    public:
        Knight();
        Knight(char type);
        
    private:
        vector<Cell*> possible_movements(Cell* cell);
        string toString();
};

class Bishop: public Piece{
    public:
        Bishop();
        Bishop(char type);
        
    private:
        vector<Cell*> possible_movements(Cell* cell);
        string toString();
};