class Solution {
public:
    set<string> s;
    int n;
    string anss;
    
    bool ans(int n , string cur ){
        
        if( n == 0 ){
            if( s.count(cur) == 0 ){
                anss = cur;
                return 1;
            }
            return 0;
        }
        
        return ans( n-1 , cur + '0') || ans( n-1 , cur + '1');
        
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        
        for( int i = 0 ; i < nums.size() ; ++i ){
            s.insert(nums[i]);
        }
        
        n = nums.size();
        
        ans(n , "");
        return anss;
        
    }
    
};