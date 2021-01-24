#include <vector>
#include "Grid.h"

using namespace std;

Grid::Grid(int num_cells_arg, vector<vector<Cell*>> cells_arg){
    num_cells = num_cells_arg;
    cells = cells_arg;  
}