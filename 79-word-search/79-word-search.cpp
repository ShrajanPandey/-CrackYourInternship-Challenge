class Solution {
public:
    int n , m;
    
    bool isExist( vector<vector<char>> &board , string &word , int cur , int x , int y ){
    
        if( cur >= word.length() ){
            return true;
        }
        
        if( x == n || y == m || word[cur] != board[x][y] ){
            return false;
        }
        if( cur == word.length()-1 && board[x][y] == word[cur] ){
            return true;
        }
        
        
        bool ans = 0;
        char c = board[x][y];
        board[x][y] ='-';
        
        if( x < n-1 &&  board[x+1][y] != '-' && isExist(board , word , cur+1 , x+1 , y)){
            return true;
        }
        if( y < m-1 && board[x][y+1] != '-' && isExist(board , word , cur+1 ,  x , y+1) ){
            return true;
        }
        if( x > 0 && board[x-1][y] != '-' && isExist(board , word , cur+1 ,  x-1 , y) ){
            return true;
        }
        if( y > 0 && board[x][y-1] != '-' && isExist(board , word , cur+1 , x, y-1) ){
            return true;
        }
        
        board[x][y] = c;
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        n = board.size() , m = board[0].size();
        // vector<vector<int>> visit(n , vector<int> (m,0));
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
  
                if( word.length() == 1 && board[i][j] == word[0] ){
                    return true;
                }
                if( board[i][j] == word[0] && isExist(board , word , 0 , i , j ) ){
                    return true;
                }
            }
     
        }
        
        return false;
        
    }
};