// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    void dfs( vector<int> adj[] , int v , int start , vector<int> &ans, vector<int> &visited ){
        
        if( visited[start] == 1 ){
            return;
        }
        
        ans.push_back(start);
        visited[start] = 1;
        
        auto a = adj[start];
        for(int i = 0 ; i < a.size() ; ++i ){
            if( visited[a[i]] == 0 ){
                dfs(adj , v , a[i] , ans , visited );    
            }
            
        }
        
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<int> visited( V , 0);
        dfs( adj , V , 0 , ans,visited);
        return ans;
        
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends