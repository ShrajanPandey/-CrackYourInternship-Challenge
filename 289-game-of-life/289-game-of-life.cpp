class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans;
        
        int n = board.size() , m = board[0].size();
        ans.resize(n , vector<int>(m , 0));
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                int c = 0;
                if( i+1 < n && board[i+1][j] == 1 ){
                    ++c;
                }
                if( i-1 >= 0 && board[i-1][j] == 1 ){
                    ++c;
                }
                if( i+1 < n && j+1 < m && board[i+1][j+1] == 1 ){
                    ++c;
                }
                if( i-1 >= 0 && j+1 < m && board[i-1][j+1] == 1 ){
                    ++c;
                }
                if( i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1 ){
                    ++c;
                }
                if( i+1 < n && j-1 >= 0 && board[i+1][j-1] == 1 ){
                    ++c;
                }
                if( j+1 < m && board[i][j+1] == 1 ){
                    ++c;
                }
                if( j-1 >= 0 && board[i][j-1] == 1 ){
                    ++c;
                }
                if(board[i][j] == 1 ){
                    if( c < 2 ){
                        ans[i][j] = 0;
                    }
                    else if( c <= 3 ){
                        ans[i][j] = 1;
                    }
                    else{
                        ans[i][j] = 0;
                    }
                }
                else{
                    if( c == 3 ){
                        ans[i][j] = 1;
                    }
                }
                
            }
            
        }
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                board[i][j] = ans[i][j];
                
            }
            
        }
        
    }
};