#include <iostream>
#include <string>
#include <fstream>
#include "Cell.h"
#include "Grid.h"

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

    int i, j;

    vector<vector<int>> grid;

    for(j=6; j<=11; j++)
    {
        vector<int> *myVector = new vector<int>(j);

        
        for(i=0; i<j; i++)
        {
            (*myVector)[i] = i;
        }

        grid.push_back((*myVector));
    }

    for(i=0; i<grid.size(); i++)
    {
        cout << grid.size() << endl;
        for(j=0; j<grid[i].size(); j++)
        {
            cout << grid[i][j] << endl;
        }

        cout << endl;
    }

    //Grid grid(91, );
}