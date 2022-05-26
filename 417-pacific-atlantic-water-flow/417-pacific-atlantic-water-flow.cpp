class Solution {
public:
    vector<vector<int>> ans;
    int n , m;
    vector<vector<int>> visited;
    
    void dfs( vector<vector<int>> &heights , int x , int y , int pre , int val ){
        
        if( x < 0 || y < 0 || x >= n || y >= m || heights[x][y] < pre || ( (visited[x][y]&val) == val) ){
            return;
        }
        
        visited[x][y] |= val;
        
        if( visited[x][y] == 3 ){
            ans.push_back({x,y});
        }
        
        dfs( heights , x+1 , y , heights[x][y] , visited[x][y]);
        dfs( heights , x-1 , y , heights[x][y] , visited[x][y]);
        dfs( heights , x , y+1 , heights[x][y] , visited[x][y]);
        dfs( heights , x , y-1 , heights[x][y] , visited[x][y]);
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
            
        n = heights.size() , m = heights[0].size();
        visited.resize(n, vector<int>(m, 0));
        
        for( int i = 0 ; i < n ; ++i ){
            dfs( heights , i , 0 , INT_MIN , 1);
            dfs( heights , i , m-1 , INT_MIN , 2);
        }
        
        for( int i = 0 ; i < m ; ++i ){
            dfs( heights , 0 , i , INT_MIN , 1 );
            dfs( heights , n-1 , i , INT_MIN , 2 );
        }
        
        return ans;
        
    }
};