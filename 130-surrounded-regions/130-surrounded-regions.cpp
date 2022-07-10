class Solution {
public:
    void dfs(vector<vector<char>> &board , int i , int j , vector<vector<int>> &visited ){
        
        if( i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] == 1 ){
            return;
        }
        
        if( board[i][j] == 'X' ){
            return;
        }
        
        visited[i][j] = 1;
        
        vector<int> direc = {1,0,-1,0,1};
        
        for( int p = 0 ; p < 4 ; ++p ){
            int x = i + direc[p];
            int y = j + direc[p+1];
            
            dfs( board , x , y , visited);
        }
        
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        vector<vector<int>> visited( board.size() ,vector<int> (board[0].size(),0));
        int n = board.size() , m = board[0].size();
        
        for( int i = 0 ; i < m ; ++i ){
            if( visited[0][i] == 0 && board[0][i] == 'O' ){
                dfs(board , 0 , i , visited);
            }
            if( visited[n-1][i] == 0 && board[n-1][i] == 'O' ){
                dfs( board , n-1 ,i , visited);
            }
        }
        
        for( int i = 0 ; i < n ; ++i ){
            if( visited[i][0] == 0 && board[i][0] == 'O' ){
                dfs(board , i , 0 , visited);
            }
            if( visited[i][m-1] == 0 && board[i][m-1] == 'O' ){
                dfs( board , i ,m-1, visited);
            }
        }
        
        for( int i = 0 ; i < n ; ++i ){
            for( int j = 0 ; j < m ; ++j ){
                if( visited[i][j] == 0 && board[i][j] == 'O' ){
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};