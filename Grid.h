#include <vector>

using namespace std;

class Grid{
    private:
        int num_cells;
        vector<vector<Cell*>> cells;

    public:
        Grid(int num_cells_arg, vector<vector<Cell*>> cells_arg);

};