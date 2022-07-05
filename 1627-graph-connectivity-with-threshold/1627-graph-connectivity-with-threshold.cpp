class Solution {
public:
    vector<int> parent , size;
    
    int find( int child ){
        
        if( parent[child] == child ){
            return child;
        } 
        return parent[child] = find(parent[child]);
        
    }
    
    bool Union(int a , int b ){
        
        int pa = find(a);
        int pb = find(b);
        
        if( pa == pb ){
            return false;
        }
        
        if( size[pa] > size[pb] ){
            size[pa] += size[pb];
            parent[pb] = pa;
        }
        else{
            size[pb] += size[pa];
            parent[pa] = pb;
        }
        
        return true;
        
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        
        parent.resize(n+1 , 0);
        size.resize(n+1 , 1);
        
        for( int i = 0 ; i <= n ; ++i ){
            parent[i] = i;
        }
        
        for( int i = threshold+1 ; i <= n ; ++i ){
            for( int x = i*2 ; x <= n ; x += i ){
                Union(i , x);
            }    
        }
        
        vector<bool> ans;
        
        for( auto query : queries ){
            int pa = find(query[0]);
            int pb = find(query[1]);
            if( pa == pb ){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        
        return ans;
        
    }
};