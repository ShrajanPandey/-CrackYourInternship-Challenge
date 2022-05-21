class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans = 0 , n = grid.size() , m = grid[0].size();
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                if( grid[i][j] == 1 ){
                    if( i != 0 && grid[i-1][j] == 0 ){
                        ++ans;
                    }
                    if( i+1 < n && grid[i+1][j] == 0 ){
                        ++ans;
                    }
                    if( j != 0 && grid[i][j-1] == 0 ){
                        ++ans;
                    }
                    if( j+1 < m && grid[i][j+1] == 0 ){
                        ++ans;
                    }
                    if( i == 0 ){
                        ++ans;
                    }
                    if( i == n-1 ){
                        ++ans;
                    }
                     if( j == 0 ){
                         ++ans;
                     }
                    if( j == m-1 ){
                        ++ans;
                    }
                }
            }
        }
        
        return ans;
        
    }
};