// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.


bool check( bool graph[][101] , int c , int curNode , int n , vector<int> &color){
    
    for( int i = 0 ; i < n ; ++i ){
        
        if( curNode != i && graph[curNode][i] && color[i] == c ){
            return 0;
        }
        
    }
    
    return 1;
    
}

bool fill(bool graph[][101] , int curNode , int m , int n , vector<int> &color){
    
    if( curNode == n ){
        return 1;
    }
    
    for( int c = 1 ; c <= m ; ++c ){
        
        if( check(graph , c , curNode , n , color) == 0 ){
            continue;
        }
        
        color[curNode] = c;
        if( fill(graph , curNode + 1 , m , n , color ) ){
            return 1;
        }
        color[curNode] = 0;
        
    }
    
    return 0;
    
}

bool graphColoring(bool graph[101][101], int colors , int nodes) {
    
    int n = nodes;
    int m = colors;
    vector<int> color( n , 0 );
    return fill( graph , 0 , m , n , color);
    
}


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends