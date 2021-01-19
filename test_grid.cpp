#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    string input;
    ifstream Grid("hexagonalGrid.txt");

    while(getline(Grid, input))
    {
        cout << input << endl;
    }

    Grid.close();

}