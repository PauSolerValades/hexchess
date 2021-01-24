#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Cell.h"
//#include "Grid.h"

using namespace std;

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

    int i, j, f;
    vector<vector<Cell>> grid;
    
    f = 0;
    for(j=6; j<=11; ++j)
    {
        vector<Cell> row;

        if(j%2==0)
        {
            for(i=0; i<j; ++i)
            {   
                cout << i << endl;
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
        

        grid.push_back(row);
        ++f;
    }

    for(j=11; j>=6; --j)
    {
        vector<Cell> row;

        if(j%2==0)
        {
            for(i=0; i<j; ++i)
            {   
                cout << i << endl;
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
        

        grid.push_back(row);
        ++f;
    }

    for(i=0; i<grid.size(); i++)
    {
        cout << grid[i].size() << endl;
        for(j=0; j<grid[i].size(); j++)
        {
            cout << grid[i][j].toString() << endl;
        }

        cout << endl;
    }
    
    //Grid grid(91, );
}