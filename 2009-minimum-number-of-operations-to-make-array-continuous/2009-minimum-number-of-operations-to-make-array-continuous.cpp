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
        
        int ans = INT_MAX;
                
        for( int i = 0 ; i < p.size() ; ++i ){
            
            int last = p[i] + n-1;
            auto op = lower_bound(p.begin()+i,p.end(),last);
            if( op == p.end() || *op > last ){
                --op;
            }
            
            int size = (op - p.begin())-i+1;
            int moves = n - size;

            ans = min( ans, moves);
                
        }
        
        return ans;
        
    }
};