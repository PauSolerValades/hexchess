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

    vector<vector<Cell*>> grid;

    for(j=6; j<=11; j++)
    {
        vector<Cell*> *myVector = new vector<Cell*>(j);
        
        for(i=0; i<j; i++)
        {
            Cell *c;

            if(j%2==0){
                c = new Cell(j,2*i);
            }
            else
            {
                c = new Cell(j,2*i+1);
            }

            (*myVector)[i] = c;
        }

        grid.push_back((*myVector));
    }

    for(j=11; j>=6; j--)
    {
        vector<Cell*> *myVector = new vector<Cell*>(j);
        
        for(i=0; i<j; i++)
        {
            Cell *c;

            if(j%2==0){
                c = new Cell(j,2*i);
            }
            else
            {
                c = new Cell(j,2*i+1);
            }
            
            (*myVector)[i] = c;
        }

        grid.push_back((*myVector));
    }

    for(i=0; i<grid.size(); i++)
    {
        cout << grid.size() << endl;
        for(j=0; j<grid[i].size(); j++)
        {
            cout << grid[i][j]->toString() << endl;
        }

        cout << endl;
    }
    /*
    for(i=0; i<grid.size(); i++)
    {
        cout << grid.size() << endl;
        for(j=0; j<grid[i].size(); j++)
        {
            cout << grid[i][j] << endl;
        }

        cout << endl;
    }
    */
    //Grid grid(91, );
}