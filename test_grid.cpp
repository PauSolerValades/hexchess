#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include "Cell.h"
#include "Grid.h"
#include "Pieces.h"
#include "Coord.h"

using namespace std;

Grid* init_grid();

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
    Cell* actual_cell;

    grid = init_grid();

    actual_cell = grid->acces_cell(2,4);

    cout << actual_cell->cubic.toString() << endl;

    cout << grid->toString() << endl;

}

Grid* init_grid()
{
    //thats a mess of a function lol
    int i, j, f, cells = 91;
    vector<vector<Cell>> gridVector;
    
    f = 0;
    for(j=-5; j<=0; ++j)
    {
        vector<Cell> row;

        if(j%2!=0){
            for(i=-2-f; i<=0; ++i){
                Coord k(j, 2*i-1);
                Cell c(j, 2*i-1, k);
                row.push_back(c);
            }

            for(i=0; i<=2+f; ++i){
                Coord k(j, 2*i+1);
                Cell c(j, 2*i+1, k);
                row.push_back(c);
            }
        }
        else
        {
            for(i=-2-f; i<=0; ++i){
                Coord k(j, 2*i);
                Cell c(j, 2*i, k);
                row.push_back(c);
            }

            for(i=1; i<=2+f; ++i){
                Coord k(j, 2*i);
                Cell c(j, 2*i, k);
                row.push_back(c);
            }
        }

        gridVector.push_back(row);
        
        cells+=abs(j);
        if(j<0 && j%2)
            ++f;
    }

    f=2;
    for(j=1; j<=5; ++j)
    {
        vector<Cell> row;

        if(j%2==0)
        {
            for(i=-2-f; i<=0; ++i)
            {   
                Coord k(j, 2*i);
                Cell c(j, 2*i, k);
                row.push_back(c);
            }

            for(i=1; i<=2+f; ++i)
            {   
                Coord k(j, 2*i);
                Cell c(j, 2*i, k);
                row.push_back(c);
            }
        }
        else
        {
            for(i=-2-f; i<=0; ++i)
            {   
                Coord k(j, 2*i-1);
                Cell c(j, 2*i-1, k);
                row.push_back(c);
            }

            for(i=0; i<=2+f; ++i)
            {   
                Coord k(j, 2*i+1);
                Cell c(j, 2*i+1, k);
                row.push_back(c);
            }
        }

        //cout << row.size() << endl;
        gridVector.push_back(row);

        if(j%2==0)
            --f;
    }
    
    Grid *grid = new Grid(cells, gridVector);

    return grid;
}