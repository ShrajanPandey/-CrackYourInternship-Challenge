class Solution {
public:
    int n , m;
    
    bool isExist( vector<vector<char>> &board , string word , int x , int y ){
    
        if( word.length() == 0 ){
            return true;
        }
        
        if( x < 0 || y < 0 || x == n || y == m || word[0] != board[x][y] ){
            return false;
        }
        if( word.length() == 1 && board[x][y] == word[0] ){
            return true;
        }
        
        // v[x][y] = 1;
        char a = board[x][y];
        board[x][y] = '-';
        bool ans = 0;
        if( x < n-1 && isExist(board , word.substr(1)  , x+1 , y)){
            return true;
        }
        if( y < m-1 && isExist(board , word.substr(1),  x , y+1) ){
            return true;
        }
        if( x > 0 && isExist(board , word.substr(1)  ,  x-1 , y) ){
            return true;
        }
        if( y > 0 && isExist(board , word.substr(1) , x, y-1) ){
            return true;
        }
        
        // v[x][y] = 0;
        board[x][y] = a;
        return false;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        n = board.size() , m = board[0].size();
        vector<vector<int>> visit(n , vector<int> (m,0));
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
                // cout << board[i][j] << " ";
                if( word.length() == 1 && board[i][j] == word[0] ){
                    return true;
                }
                if( board[i][j] == word[0] && isExist(board , word , i , j ) ){
                    return true;
                }
            }
            // cout << endl;
        }
        
        return false;
        
    }
};