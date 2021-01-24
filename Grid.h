#include <vector>
#include <string>
#include "Cell.h"

using namespace std;

class Grid{
    private:
        int num_cells;
        vector<vector<Cell>> cells;

    public:
        Grid();
        Grid(int num_cells_arg, vector<vector<Cell>> cells_arg);
        string toString();
        Cell* acces_cell(int x, int y);
};