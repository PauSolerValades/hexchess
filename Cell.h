#include <string>

using namespace std;

class Cell{
    private:
        int x;
        int y;
    
    public:
        char piece;
        Cell(int x, int y);
        string toString();
};