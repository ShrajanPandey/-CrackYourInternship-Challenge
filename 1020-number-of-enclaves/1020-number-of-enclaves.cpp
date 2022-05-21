class Solution {
public:
    int n , m, c ;
    vector<vector<int>> visited;
    
    bool isPossible( vector<vector<int>> &grid , int i , int j ){
        
        if( i < 0 || j < 0 || i >= n || j >= m ){
            return 0;
        }
        
        if( grid[i][j] == 0 || visited[i][j] == 1 ){
            return 1;
        }
        
        visited[i][j] = 1;
        ++c;
        
        return (isPossible(grid , i+1 , j ) & isPossible(grid , i-1 , j) & isPossible( grid , i , j+1) & isPossible( grid , i,j-1));
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        int ans = 0;
        visited.resize(n , vector<int> (m , 0));

        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                if( grid[i][j] == 1 && visited[i][j] == 0 ){
                    c = 0;
                    if( isPossible( grid , i , j ) ) {
                        ans += c;
                    }
                }
            }
            
        }
        
        return ans;
        
    }
};