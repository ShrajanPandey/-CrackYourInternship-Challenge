class Solution {
public:

    bool isValid( vector<vector<char>> &board , char val, int i , int j ){
        
        int row = i - i%3, column = j - j%3;
    for(int x=0; x<9; x++) if(board[x][j] == val) return false;
    for(int y=0; y<9; y++) if(board[i][y] == val) return false;
    for(int x=0; x<3; x++)
    for(int y=0; y<3; y++)
        if(board[row+x][column+y] == val) return false;
    return true;
        
    }
    
    bool solve( vector<vector<char>> &board , int x = 0, int y = 0){
        
        if( x == 9 )return true;
        if( y == 9 )return solve(board , x+1 , 0);
        
        if( board[x][y] != '.' )return solve( board , x , y+1);
                    
        for( char c = '1' ; c <= '9' ; c++ ){

            if( isValid(board , c , x , y ) ){

                board[x][y] = c;

                if( solve( board , x , y+1) ){
                    return true;
                }
                else{
                    board[x][y] = '.';
                }
            }
        }
                    
        
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) {

        solve( board , 0 , 0 );
        
    }
};