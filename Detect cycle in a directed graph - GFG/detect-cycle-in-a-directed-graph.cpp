// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    bool wat(int V , vector<int> adj[] , int start , vector<bool> &visited , vector<bool> &active ){
        
        active[start] = true;
        visited[start] = true;
        for( int i = 0 ; i < adj[start].size() ; ++i ){
            if( visited[adj[start][i]] == 0 ){
                if( wat(V , adj , adj[start][i] , visited , active) ){
                    return true;
                }
            }
            else if( active[adj[start][i]] ){
                return true;
            }
        }
        active[start] = false;
        
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<bool> visited(V,0), active(V,0);
        for( int i = 0 ; i < V ; ++i ){
            if( visited[i] == 0 ){
                if( wat(V , adj ,i , visited , active ) ){
                    return true;
                }
            }    
        }
        
        return false;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends