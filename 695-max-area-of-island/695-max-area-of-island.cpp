class Solution {
public:
    int n , m;
    
    int areaOfIsland( vector<vector<int>> &grid , int i , int j ){
        
        if( i < 0 || j < 0 || i >= n || j >= m ){
            return 0;
        }
        
        if( grid[i][j] != 1 ){
            return 0;
        }
        
        grid[i][j] = -1;
        
        return 1 + areaOfIsland(grid, i+1 , j) + areaOfIsland( grid , i-1 , j) + areaOfIsland( grid , i , j+1 ) + areaOfIsland( grid , i , j-1);
        
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        n = grid.size() , m = grid[0].size();
        
        for( int i = 0 ; i < n ; ++i ){
            
            for(int j = 0 ; j < m ; ++j ){
                
                if( grid[i][j] == 1 ){
                    maxArea = max(maxArea , areaOfIsland( grid , i , j ));
                }
                
            }
            
        }
        
        return maxArea;
        
    }
};