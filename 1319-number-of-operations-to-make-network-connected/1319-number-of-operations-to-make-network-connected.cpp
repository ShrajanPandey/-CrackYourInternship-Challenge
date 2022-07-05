class Solution {
public:
    void dfs( unordered_map<int,vector<int>> &adjList , vector<int> &visited , int cur ){
    
        visited[cur]  = 1;
        
        for( auto neighbour : adjList[cur] ){
            if( visited[neighbour] == 0 ){
                dfs( adjList , visited , neighbour );
            }
        }

    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if( connections.size() < n-1 ){
            return -1;
        }
        
        unordered_map<int,vector<int>> adjList;
        
        for( int i = 0 ; i < connections.size() ; ++i ){
            adjList[connections[i][1]].push_back(connections[i][0]);
            adjList[connections[i][0]].push_back(connections[i][1]);
        }
        
        vector<int> visited(n ,0);
        int components = 0;
     
        for( int i = 0 ; i < n ; ++i ){
            if( visited[i] == 0 ){
                dfs( adjList , visited , i );
                ++components;
            }
        }
        
        return components-1;
            
    }
};