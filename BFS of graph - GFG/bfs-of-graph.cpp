// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(vector<int> adj[] , vector<int> &ans , int V , int si  , vector<bool> &visit){
        
        queue<int> q;
        q.push(si);
        
        while( q.empty() != 1 ){
            int cur = q.front();
            q.pop();
            for( auto x : adj[cur] ){
                if( visit[x] == 0 ){
                    visit[x] = 1;
                    q.push(x);
                }
            }
            ans.push_back(cur);
        }
        
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<bool> visit(V,0);
        bfs(adj , ans , V , 0, visit);
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends