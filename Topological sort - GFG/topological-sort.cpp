// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<int> topoSortAns(int V , vector<int> adj[] , vector<int> &indegree){
	      
	     vector<int> ans;  
	    queue<int> readyJobs;
	    
	    //inserting 9 indegree vertices as they are not dependent on anything
	    for( int i = 0 ; i < V ; ++i ){
	        if( indegree[i] == 0 ){
	            readyJobs.push(i);
	        }
	    }
	    
	    //bfs
	    while( readyJobs.empty() != 1 ){
	        int cur = readyJobs.front();
	        readyJobs.pop();
	        for( int i = 0 ; i < adj[cur].size() ; ++i ){
	           indegree[adj[cur][i]]--;
	           if( indegree[adj[cur][i]] == 0 ){
	               readyJobs.push(adj[cur][i]);
	           }
	        }
	        ans.push_back(cur);
	    }
	    
	    return ans;
	    
	}
	
	void dfs(int v ,  vector<int> adj[] , stack<int> &ans , vector<int> &visited ){
	    
	    visited[v] = 1;
	    
	    for( auto i = adj[v].begin() ; i != adj[v].end() ; ++i ){
	        if( visited[*i] == 0 ){
	            dfs(*i, adj , ans , visited);
	        }
	    }
	    
	    ans.push(v);
	    
	}
	

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans;
	    stack<int> p;
	    
	    vector<int> visited(V,0);
	    for( int i = 0 ; i < V ; ++i ){
	        if( visited[i] == 0 ){
	            dfs( i , adj , p , visited);
	        }
	    }
	    
	    while( p.empty() != 1 ){
	        ans.push_back(p.top());
	        p.pop();
	    }
	    
	    return ans;
	    
	   // vector<int> indegree(V,0);
	   // for( int i = 0 ; i < V ; ++i ){
	   //     for( int j = 0 ; j < adj[i].size() ; ++j ){
	   //         indegree[adj[i][j]]++;
	   //     }
	   // }
	    
	   // return topoSortAns(V , adj , indegree);
	 
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends