class Solution {
public:
    vector<int> parent , rank;
    
    int find(int x){
        if( parent[x] == x ){
            return x;
        }
        return parent[x] = find(parent[x]);    
    }
    
    void Union(int a , int b){
        
        int pa = find(a);
        int pb = find(b);
        
        if( pa == pb ){
            return;
        }
        
        if( rank[pa] > rank[pb] ){
            rank[pa] += rank[pb];
            parent[pb] = pa;
        }
        else{
            rank[pb] += rank[pa];
            parent[pa] = pb;
        }
        
    }
    
    bool isSimilar( string &a , string &b ){
        
        int c = 0;
        for( int i = 0 ; i < a.length() ; ++i ){
            if( a[i] != b[i] && ++c > 2 ){
                return false;
            }
        }
        
        return true;
        
    }
    
    int numSimilarGroups(vector<string>& strs) {
        
        int n = strs.size();
        int m = strs[0].size();
        parent.resize(n , 0);
        rank.resize(n , 1);
        
        for( int i = 0 ; i < n ; ++i ){
            parent[i] = i;
        }
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int j = i+1 ; j < n ; ++j ){
                
               if( isSimilar( strs[i] , strs[j] ) ){
                   Union(i , j);
               }
                
            }
            
        }
        
        set<int> ans;
        
        for( int i = 0 ; i < n ; ++i ){
            ans.insert(find(parent[i]));
        }
        
        return ans.size();
        
    }
};