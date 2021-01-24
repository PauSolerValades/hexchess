#include <vector>
#include "Grid.h"

using namespace std;

Grid::Grid() = default;

Grid::Grid(int num_cells_arg, vector<vector<Cell>> cells_arg){
    num_cells = num_cells_arg;
    cells = cells_arg;  
}

string Grid::toString()
{
    int i,j;
    string result;

    for(i=0; i<cells.size(); i++)
    {
        for(j=0; j<cells[i].size(); j++)
        {
            result += cells[i][j].toString() + "\n";
        }
        
        result += "\n";
    }

    return result;
    
}