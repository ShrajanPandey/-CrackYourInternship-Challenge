// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool wat( int V , vector<int> adj[] , int start ,vector<bool> &visited , int parent){
        
        visited[start] = 1;
        for( int i = 0 ; i < adj[start].size() ; ++i ){
            if( visited[adj[start][i]] == 0 ){
                if( wat(V , adj, adj[start][i] ,visited , start) ){
                    return true;
                }
            }
            else if( adj[start][i] != parent ){
                return true;
            }
        }
        
        return false;
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,0);
        for( int i = 0 ; i < V ; ++i ){
            if( visited[i] == 0 ){
                if( wat(V , adj , i, visited , -1) ){
                    return true;
                }
            }    
        }
        
        return false;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends