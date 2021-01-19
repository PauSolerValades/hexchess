#include <vector>


class Grid{
    private:
        int cells;
        vector<vector<Cell>>


    public:
        isValidCell(int x, int y, int z){
            if(x+y+z==0)
                return true;
            else
                return false;
        }

}