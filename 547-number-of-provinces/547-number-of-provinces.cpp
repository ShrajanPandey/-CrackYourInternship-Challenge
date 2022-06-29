class Solution {
public:
    void dfs( unordered_map<int,vector<int>> &connected , vector<int> &visited , int curProvince ){
        
        visited[curProvince] = 1;
        
        for( auto i = connected[curProvince].begin() ; i != connected[curProvince].end() ; ++i ){
            
            if( visited[*i] == 0 ){
                dfs( connected , visited , *i);
            }
   
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        unordered_map<int,vector<int>> connected;
        int n = isConnected.size();
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = 0 ; j < n ; ++j ){
                if( isConnected[i][j] ){
                    connected[i].push_back(j);
                    connected[j].push_back(i);
                }
            }
            
        }
        
        vector<int> visited(n , 0);
        int ans = 0;
        
        for( int i = 0 ; i < n ; ++i ){
            
            if( visited[i] == 0 ){
                dfs( connected , visited , i);
                ++ans;
            }
        }
        
        return ans;
        
        
    }
};