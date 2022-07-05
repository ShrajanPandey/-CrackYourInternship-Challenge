class Solution {
public:
    
    int findParent(vector<int> &parent , int x){
        if( parent[x] == x ){
            return x;
        }
        return parent[x] = findParent(parent,parent[x]);
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if( connections.size() < n-1 ){
            return -1;
        }
        
        vector<int> parent(n,0);
        for( int i = 0 ; i < n; ++i ){
            parent[i] = i;
        }
        
        int extraEdge = 0;
        for( int i = 0 ; i < connections.size() ; ++i ){
            int pren1 = findParent(parent, connections[i][0]);
            int pren2 = findParent(parent, connections[i][1]);
            if( pren1 == pren2 ){
                ++extraEdge;
            }
            else parent[pren1] = pren2;
        }
        
        int components = 0;
        for( int i = 0 ; i < n ; ++i ){
            if( parent[i] == i ){
                ++components;
            }
        }
        
        return components-1;
        
    }
};