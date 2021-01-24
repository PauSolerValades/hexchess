#include <string>

using namespace std;

class Cell{
    private:
        int x;
        int y;
    
    public:
        char piece;
        Cell();
        Cell(int x, int y, char piece);
        string toString();
};