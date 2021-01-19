class Grid{
    private:
        int cells;


    public:
        isValidCell(int x, int y, int z){
            if(x+y+z==0)
                return true;
            else
                return false;
        }

}