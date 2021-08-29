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
void start_game();

int main()
{

    //menú

    int option = 0;
    
    do{

        cout << "WELCOME TO HEXCHESS!" << endl;

        cout << "1. Start Game" << endl;
        cout << "2. Quit" << endl;

        cin >> option;

        switch(option){
            case 1:
                start_game();
                break;


            case 2:
                cout << "See you soon!" << endl;
                option =0;
                break;
                
            
            default:
                cout << "Què fas, marrec?" << endl;
        }
    }while(option !=0);
    
    exit(0);
    /*
    string input;
    ifstream Grid("hexagonalGrid.txt");

    while(getline(Grid, input))
    {
        cout << input << endl;
    }

    Grid.close();
    */

    /*
    int i,j,k;

    Grid* grid;
    Cell* actual_cell;
    vector<Coord*> results, diagonals;
    grid = init_grid();
    actual_cell = grid->acces_cell(2,4);

    
    Coord* coord = new Coord(0,-5,5);
    
    results = bishopWhite->possible_movements(coord);
    diagonals = kingWhite->possible_movements(coord);
    results = towerWhite->possible_movements(coord);
    results = queenWhite->possible_movements(coord);
    results = pawnBlack->possible_movements(coord);
    results = knightWhite->possible_movements(coord);
    actual_cell->setPiece(bishopWhite);
    cout << grid->toString() << endl;

    for(i=0; i<results.size(); ++i){
        cout << results[i]->toString() << endl;
    }
    cout << results.size() << endl;
    /*
    for(i=0; i<diagonals.size(); ++i){
        cout << diagonals[i]->toString() << endl;
    }
    cout << diagonals.size() << endl;
    */
}

void start_game(){
    
    Grid* grid;
    Cell* actual_cell;

    grid = init_grid();

    Bishop* bishopWhiteA = new Bishop('B','W');
    Bishop* bishopWhiteB = new Bishop('B','W');
    Bishop* bishopWhiteC = new Bishop('B','W');
    King* kingWhite = new King('K','W');
    Tower* towerWhiteA = new Tower('T','W');
    Tower* towerWhiteB = new Tower('T','W');
    Queen* queenWhite = new Queen('Q','W');
    Knight* knightWhiteA = new Knight('H','W');
    Knight* knightWhiteB = new Knight('H','W');
    PawnW* pawnWhiteA = new PawnW('P');
    PawnW* pawnWhiteB = new PawnW('P');
    PawnW* pawnWhiteC = new PawnW('P');
    PawnW* pawnWhiteD = new PawnW('P');
    PawnW* pawnWhiteE = new PawnW('P');
    PawnW* pawnWhiteF = new PawnW('P');
    PawnW* pawnWhiteG = new PawnW('P');
    PawnW* pawnWhiteH = new PawnW('P');
    PawnW* pawnWhiteI = new PawnW('P');

    grid->acces_cell(5,17)->setPiece(bishopWhiteA);
    grid->acces_cell(5,19)->setPiece(bishopWhiteB);
    grid->acces_cell(5,21)->setPiece(bishopWhiteC);
    grid->acces_cell(4,18)->setPiece(kingWhite);
    grid->acces_cell(6,18)->setPiece(queenWhite);
    grid->acces_cell(7,17)->setPiece(knightWhiteB);
    grid->acces_cell(3,17)->setPiece(knightWhiteA);
    grid->acces_cell(2,14)->setPiece(towerWhiteA);
    grid->acces_cell(8,14)->setPiece(towerWhiteB);
    grid->acces_cell(1,13)->setPiece(pawnWhiteA);
    grid->acces_cell(2,11)->setPiece(pawnWhiteB);
    grid->acces_cell(3,13)->setPiece(pawnWhiteC);
    grid->acces_cell(4,12)->setPiece(pawnWhiteD);
    grid->acces_cell(5,13)->setPiece(pawnWhiteE);
    grid->acces_cell(6,14)->setPiece(pawnWhiteF);
    grid->acces_cell(7,13)->setPiece(pawnWhiteG);
    grid->acces_cell(8,12)->setPiece(pawnWhiteH);
    grid->acces_cell(9,13)->setPiece(pawnWhiteI);


    Bishop* bishopBlackA = new Bishop('B','B');
    Bishop* bishopBlackB = new Bishop('B','B');
    Bishop* bishopBlackC = new Bishop('B','B');
    King* kingBlack = new King('K','B');
    Tower* towerBlackA = new Tower('T','B');
    Tower* towerBlackB = new Tower('T','B');
    Queen* queenBlack = new Queen('Q','B');
    Knight* knightBlackA = new Knight('H','B');
    Knight* knightBlackB = new Knight('H','B');
    PawnB* pawnBlackA = new PawnB('P');
    PawnB* pawnBlackB = new PawnB('P');
    PawnB* pawnBlackC = new PawnB('P');
    PawnB* pawnBlackD = new PawnB('P');
    PawnB* pawnBlackE = new PawnB('P');
    PawnB* pawnBlackF = new PawnB('P');
    PawnB* pawnBlackG = new PawnB('P');
    PawnB* pawnBlackH = new PawnB('P');
    PawnB* pawnBlackI = new PawnB('P');

    grid->acces_cell(5,1)->setPiece(bishopBlackA);
    grid->acces_cell(5,3)->setPiece(bishopBlackB);
    grid->acces_cell(5,5)->setPiece(bishopBlackC);
    grid->acces_cell(4,0)->setPiece(kingBlack);
    grid->acces_cell(6,0)->setPiece(queenBlack);
    grid->acces_cell(7,1)->setPiece(knightBlackB);
    grid->acces_cell(3,1)->setPiece(knightBlackA);
    grid->acces_cell(2,0)->setPiece(towerBlackA);
    grid->acces_cell(8,0)->setPiece(towerBlackB);
    grid->acces_cell(1,1)->setPiece(pawnBlackA);
    grid->acces_cell(2,0)->setPiece(pawnBlackB);
    grid->acces_cell(3,1)->setPiece(pawnBlackC);
    grid->acces_cell(4,0)->setPiece(pawnBlackD);
    grid->acces_cell(5,1)->setPiece(pawnBlackE);
    grid->acces_cell(6,0)->setPiece(pawnBlackF);
    grid->acces_cell(7,1)->setPiece(pawnBlackG);
    grid->acces_cell(8,0)->setPiece(pawnBlackH);
    grid->acces_cell(9,1)->setPiece(pawnBlackI);

    cout << grid->toString() << endl;
}

Grid* init_grid()
{
    //thats a mess of a function lol
    int i, j, f, cells = 91;

    vector<vector<Cell>> gridVector;
    Nopiece* np = new Nopiece();
    
    f = 0;
    for(j=-5; j<=0; ++j)
    {
        vector<Cell> row;

        if(j%2!=0){
            for(i=-2-f; i<=0; ++i){
                Coord k(j, 2*i-1);
                Cell c(j, 2*i-1, k, np);
                row.push_back(c);
            }

            for(i=0; i<=2+f; ++i){
                Coord k(j, 2*i+1);
                Cell c(j, 2*i+1, k, np);
                row.push_back(c);
            }
        }
        else
        {
            for(i=-2-f; i<=0; ++i){
                Coord k(j, 2*i);
                Cell c(j, 2*i, k, np);
                row.push_back(c);
            }

            for(i=1; i<=2+f; ++i){
                Coord k(j, 2*i);
                Cell c(j, 2*i, k, np);
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
                Cell c(j, 2*i, k, np);
                row.push_back(c);
            }

            for(i=1; i<=2+f; ++i)
            {   
                Coord k(j, 2*i);
                Cell c(j, 2*i, k, np);
                row.push_back(c);
            }
        }
        else
        {
            for(i=-2-f; i<=0; ++i)
            {   
                Coord k(j, 2*i-1);
                Cell c(j, 2*i-1, k, np);
                row.push_back(c);
            }

            for(i=0; i<=2+f; ++i)
            {   
                Coord k(j, 2*i+1);
                Cell c(j, 2*i+1, k, np);
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