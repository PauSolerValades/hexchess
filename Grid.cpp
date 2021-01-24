#include <vector>
#include "Grid.h"

using namespace std;

Grid::Grid() = default;

Grid::Grid(int num_cells_arg, vector<vector<Cell>> cells_arg){
    num_cells = num_cells_arg;
    cells = cells_arg;  
}

/*acces_cell recives the double coordinates of a concrete cell
of the grid and return a pointer where the requested cell is stored 
in the cells list. Now we can work with double coordinates in the pro
gram logic and keep meaningful coordinates in everything else*/
Cell* Grid::acces_cell(int x, int y){
    
    int a;
    Cell *c;

    if(x%2==0)
        a = (int) y/2;
    else
        a = (int) (y-1)/2;

    c = &(this->cells[x][a]);

    return c;
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