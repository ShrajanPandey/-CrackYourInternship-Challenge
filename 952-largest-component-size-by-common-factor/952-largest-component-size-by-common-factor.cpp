class Solution {
public:
    vector<int> parent,rank;
    
    int find( int i ){
        
        if( parent[i] == i ){
            return i;
        }
        
        return parent[i] = find(parent[i]);
        
    }
    
    void Union(int a , int b ){
        
        int pa = find(a);
        int pb = find(b);
        
        if( pa == pb ){
            return;    
        }
        
        if( rank[pa] > rank[pb] ){
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }
        else{
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }
        
    }
    
    int largestComponentSize(vector<int>& nums) {
        
        int n = nums.size();
        int maxEle = *max_element(nums.begin(),nums.end());

        parent.resize(maxEle+1);
        rank.resize(maxEle+1,1);
        
        for( int i = 0 ; i < maxEle+1 ; ++i ){
            parent[i] = i;
        }
        
        for( int i = 0 ; i < n ; ++i ){
            
            for( int f = 2 ; f <= sqrt(nums[i]) ; ++f ){
                if( nums[i]%f == 0 ){
                    Union(nums[i],f);
                    Union(nums[i],nums[i]/f);
                }
            }
            
        }
        
        int ans = 0;
        unordered_map<int,int> m;
        
        for( int i = 0 ; i < n ; ++i ){
            ans = max( ans , ++m[find(nums[i])]);
        }
        
        return ans;
        
    }
    
};