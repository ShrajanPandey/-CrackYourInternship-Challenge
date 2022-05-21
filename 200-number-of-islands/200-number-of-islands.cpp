class Solution {
public:
    int n , m;
    vector<vector<int>> visited;
    
    void dfs( vector<vector<char>> &grid , int i , int j ){
            
        if( i < 0 || j < 0 || i >= n || j >= m ){
            return;
        }
        
        if( visited[i][j] || grid[i][j] == '0' ){
            return;
        }
        
        visited[i][j] = 1;
        dfs( grid , i+1 , j );
        dfs( grid , i-1 , j);
        dfs( grid , i , j+1);
        dfs( grid , i , j-1);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size() , m = grid[0].size();
        visited.resize(n , vector<int>(m , 0));
        int islands = 0;
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                // cout << visited[i][j] << " " << grid[i][j] << " I " << i << " J " << j << endl;
                if( grid[i][j] == '1' && visited[i][j] == 0 ){
                    // cout << i << " " << j << endl;
                    dfs(grid, i , j );
                    ++islands;
                }
                
            }
            
        }
        
        return islands;
        
    }
};