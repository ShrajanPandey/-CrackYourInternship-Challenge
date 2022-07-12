// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int find( vector<int> &parent , int x){
        if(parent[x] == x ){
            return x;
        }
        return parent[x] = find(parent ,parent[x]);
    }
    
    void Union(vector<int> &parent , vector<int> &rank , int x , int y ){
        
        int pa = find(parent , x);
        int pb = find(parent , y);
        
        if( pa == pb ){
            return;
        }
        
        if( rank[pa] > rank[pb] ){
            rank[pa] += rank[pb];
            parent[pb] = pa;
        }
        else{
            rank[pb] += rank[pa];
            parent[pa] = pb;
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size() , m = grid[0].size();
        vector<int> parent(n*m,0);
        vector<int> rank( n*m , 0);
        
        for( int i = 0 ;i < n*m ; ++i ){
            parent[i] = i;
            rank[i] = 1;
        }
        
        vector<vector<int>> direc = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        
        for(int i = 0 ; i < n ; ++i ){
            for(int j = 0 ; j < m ; ++j ){
                if( grid[i][j] == '0' ){
                    continue;
                }        
                
                for( auto cur : direc ){
                    int x = i + cur[0];
                    int y = j + cur[1];
                    
                    if( x < n && y < m && x >= 0 && y >= 0 && grid[x][y] == '1' ){
                        Union(parent , rank , i*m+j , x*m+y);
                    }
                }        
            }
        }
        
        vector<int> unique(n*m , 0);
        int ans = 0;
        
        for( int i = 0 ; i < n ; ++i ){
            for(int j = 0 ; j < m ; ++j ){
                if( grid[i][j] == '1' ){
                    // cout << i << " " << j << endl;
                    int p = find(parent , i*m + j);
                    // cout << p << " " << i << " " << j << endl;
                    unique[p]++;
                    if( unique[p] == 1 ){
                        ++ans;
                    }
                }
            }
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends