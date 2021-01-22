#include <string>

using namespace std;

class Cell{
    private:
        int x;
        int y;

    public:
        char piece;
        Cell(int x, int y, char piece){
            x=x;
            y=y;
            piece=piece;
        }

        string toString(){
            return "(" + to_string(x) + "," + to_string(y) +")";
        }
};