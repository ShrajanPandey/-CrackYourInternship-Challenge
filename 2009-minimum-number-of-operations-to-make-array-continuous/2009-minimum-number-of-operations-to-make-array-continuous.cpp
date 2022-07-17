class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        vector<int> p;
        int n = nums.size();
        
        set<int> st;
        
        for( int i = 0 ; i < n ; ++i ){
            st.insert(nums[i]);    
        }
        
        for ( auto s : st ){
            p.push_back(s);
        }
        
        int ans = 1;
        int l = 0 ,r = 0;
        --n;
        
        while( r < p.size() ){
            
            if( l == r ){
                ++r;
            }
            else if( p[r] - p[l] > n ){
                ++l;
            }
            else{
                ans = max( ans , r - l + 1 );
                ++r;
            }
            
        }
        
        return n-ans+1;
        
    }
};