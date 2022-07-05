class Solution {
public:
    int dfs( unordered_map<int,vector<int>> &adjList , vector<int> &visited , int cur , int &no ){
    
        visited[cur]  = 1;
        int edges = adjList[cur].size();
        ++no;
        
        for( auto neighbour : adjList[cur] ){
            if( visited[neighbour] == 0 ){
                edges += dfs( adjList , visited , neighbour , no );
            }
        }
        
        return edges;
        
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        unordered_map<int,vector<int>> adjList;
        
        for( int i = 0 ; i < connections.size() ; ++i ){
            adjList[connections[i][1]].push_back(connections[i][0]);
            adjList[connections[i][0]].push_back(connections[i][1]);
        }
        
        vector<int> visited(n ,0);
        int components = 0;
        int extraEdges = 0;
        
        for( int i = 0 ; i < n ; ++i ){
            if( visited[i] == 0 ){
                int no = 0;
                int edges = dfs( adjList , visited , i , no);
                extraEdges += (edges/2-no+1);
                ++components;
            }
        }
        
        if( extraEdges < components-1 ){
            return -1;
        }
        
        return components-1;
            
    }
};