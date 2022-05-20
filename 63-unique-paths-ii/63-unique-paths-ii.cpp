class Solution {
public:
    
    map<pair<int,int>,int> visited;
    int uniquePaths(vector<vector<int>> &hurdle , int n , int m ){
        
        if( n == 1 && m == 1 ){
            return 1;    
        }
        if( n == 0 || m == 0 || hurdle[n-1][m-1] == 1 ){
            return 0;
        }
        
        if( visited.count(make_pair(n,m)) ){
            return visited[make_pair(n,m)];
        }
        
        int ans = uniquePaths(hurdle , n-1 , m ) + uniquePaths(hurdle , n , m-1 );
        return visited[make_pair(n,m)] = ans;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int n = obstacleGrid.size(),m = obstacleGrid[0].size();
        if( obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1 ){
            return 0;
        }
        
        return uniquePaths(obstacleGrid, n , m );
        
    }
};