#include <vector>
#include "Cell.h"

using namespace std;

class Grid{
    private:
        int num_cells;
        vector<vector<Cell*>> cells;

    public:
        Grid(int num_cells_arg, vector<vector<Cell*>> cells_arg){
            num_cells = num_cells_arg;
            cells = cells_arg;

        }


};

