class Solution {
public:
    bool check(vector<vector<int>> &graph , vector<int> &color , int cur ){
        
        queue<int> bfs;
        bfs.push(cur);
        color[cur] = 1;
        
        while( bfs.empty() != 1 ){
            
            int c = bfs.front();
            bfs.pop();
            
            for( auto i : graph[c] ){
                if( color[i] == -1 ){
                    color[i] = 1-color[c];
                    bfs.push(i);
                }
                else if( color[i] == color[c] ){
                    return false;
                }
            }
            
        }
        
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size()+1 , -1);
        
        for( int i = 0 ; i < graph.size() ; ++i ){
            if( color[i] == -1 ){
                if( check(graph , color , i ) == false ){
                    return false;
                }
            }
        }
        
        return true;
        
    }
    
};