class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    
        if( nums.size() == 0 ){
            return {};
        }
        
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for( int i = 0 ; i < (int)nums.size()-2 ; ++i ){
            
            if( nums[i] > 0 ){
                break;
            }
            if( i == 0 || ( i > 0 && nums[i] != nums[i-1] ) ){
                
                int lo = i+1 , hi = nums.size()-1;
                int sum = -nums[i];
                while( lo < hi ){
                    
                    if( nums[lo] + nums[hi] == sum ){

                        ans.push_back({nums[i],nums[lo],nums[hi]});

                        while( lo < hi && nums[lo] == nums[lo+1] ){
                            ++lo;
                        }
                        while( lo < hi && nums[hi] == nums[hi-1] ){
                            --hi;
                        }

                        ++lo;
                        --hi;
                    }
                    else if( nums[lo] + nums[hi] < sum ){
                        ++lo;
                    }
                    else{
                        --hi;
                    }
                    
                }
                
            }
            
        }
        
        return ans;
        
    }
};