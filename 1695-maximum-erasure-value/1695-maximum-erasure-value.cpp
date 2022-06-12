class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int s = 0;
        unordered_map<int,int> m;
        int ansS = 0;
        
        vector<int> p;
        for( int i = 0 ; i < nums.size() ;++i ){
            s += nums[i];
            p.push_back(s);
        }
        
        s = 0;
        for( int i = 0 ; i < nums.size() ; ++i ){
            if( m.count(nums[i]) && m[nums[i]] >= s ){
                // cout << p[i-1]-p[s] + nums[s] << " " << s << endl; 
                ansS = max( ansS , p[i-1]-p[s] + nums[s]);
                s = max(s , m[nums[i]]+1);
                m[nums[i]] = i;
                // cout << s << endl;
            }
            else{
                m[nums[i]] = i;
            }
        }

        ansS = max( ansS , p[nums.size()-1] - p[s] + nums[s] );
        
        return ansS;
        
    }
};