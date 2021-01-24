#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Cell.h"
#include "Grid.h"

using namespace std;

Grid* init_grid()
{
    int i, j, f, cells;
    vector<vector<Cell>> gridVector;
    
    f = 0;
    for(j=6; j<=11; ++j)
    {
        vector<Cell> row;

        if(j%2==0)
        {
            for(i=0; i<j; ++i)
            {   
                Cell c(f, 2*i, '_');

                row.push_back(c);
            }
        }
        else
        {
            for(i=0; i<j; ++i)
            {
                Cell c(f, 2*i+1, '_');

                row.push_back(c);
            }
        }
        
        gridVector.push_back(row);
        ++f;

        cells+=j;
    }

    for(j=10; j>=6; --j)
    {
        vector<Cell> row;

        if(j%2!=0)
        {
            for(i=0; i<j; ++i)
            {   
                Cell c(f, 2*i, '_');

                row.push_back(c);
            }
        }
        else
        {
            for(i=0; i<j; ++i)
            {
                Cell c(f, 2*i+1, '_');

                row.push_back(c);
            }
        }
        
        gridVector.push_back(row);
        ++f;

        cells+=j;
    }

    Grid *grid = new Grid(cells, gridVector);

    return grid;
}

int main()
{
    /*
    string input;
    ifstream Grid("hexagonalGrid.txt");

    while(getline(Grid, input))
    {
        cout << input << endl;
    }

    Grid.close();
    */

    Grid* grid;
    grid = init_grid();

    cout << grid->toString() << endl;

}