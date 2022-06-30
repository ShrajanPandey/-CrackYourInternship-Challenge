class Solution {
public:
    int n , m;
    
    bool isExist( vector<vector<char>> &board , string &word , int cur , vector<vector<int>> &v , int x , int y ){
    
        if( cur >= word.length() ){
            return true;
        }
        
        if( x == n || y == m || word[cur] != board[x][y] ){
            return false;
        }
        if( cur == word.length()-1 && board[x][y] == word[cur] ){
            return true;
        }
        
        v[x][y] = 1;
        bool ans = 0;
        if( x < n-1 &&  v[x+1][y] == 0 && isExist(board , word , cur+1 , v , x+1 , y)){
            return true;
        }
        if( y < m-1 && v[x][y+1] == 0 && isExist(board , word , cur+1 , v,  x , y+1) ){
            return true;
        }
        if( x > 0 && v[x-1][y] == 0 && isExist(board , word , cur+1 , v ,  x-1 , y) ){
            return true;
        }
        if( y > 0 && v[x][y-1] == 0 && isExist(board , word , cur+1 , v , x, y-1) ){
            return true;
        }
        
        v[x][y] = 0;
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        n = board.size() , m = board[0].size();
        vector<vector<int>> visit(n , vector<int> (m,0));
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
  
                if( word.length() == 1 && board[i][j] == word[0] ){
                    return true;
                }
                if( board[i][j] == word[0] && isExist(board , word , 0 , visit , i , j ) ){
                    return true;
                }
            }
     
        }
        
        return false;
        
    }
};