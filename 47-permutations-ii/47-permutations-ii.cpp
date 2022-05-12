class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    vector<int> p;
    map<int,int> m;
    
    vector<vector<int>> permute(vector<int> &nums ){
        
        if( p.size() == nums.size() ){
            if( s.count(p) == 0 ){
                s.insert(p);
                ans.push_back(p);
            }
            return ans;
        }
        
        for( auto x = m.begin() ; x != m.end() ; ++x ){
            
            if( x->second ){
                p.push_back(x->first);
                --x->second;
                permute(nums);
                ++x->second;
                p.pop_back();
            }
            
        }
        
        return ans;    
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums ) {
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            m[nums[i]]++;
        }
        
        return permute(nums);
        
    }
};