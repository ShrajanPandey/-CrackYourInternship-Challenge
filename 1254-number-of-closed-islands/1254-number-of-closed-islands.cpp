class Solution {
public:
    int n , m;
    vector<vector<int>> visited;
    
    bool isClosed(vector<vector<int>> &grid , int i , int j ){
        
        if( i < 0 || j < 0 || i >= n || j >= m ){
            return 0;
        }
        
        if( grid[i][j] == 1 || visited[i][j] ){
            return 1;
        }
        
        visited[i][j] = 1;
        bool a = isClosed(grid , i+1 , j) & isClosed(grid , i-1 , j ) & isClosed(grid , i , j+1) & isClosed(grid , i, j-1);
        
        return a;
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int ans = 0;
        n = grid.size() , m = grid[0].size();
        visited.resize(n , vector<int> (m , 0));
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < m ; ++j ){
                
                if( grid[i][j] == 0 && visited[i][j] == 0 ){
                    
                    if( isClosed(grid , i , j ) ){
                        ++ans;
                    }
                }
            }
        }
        
        return ans;
        
    }
};