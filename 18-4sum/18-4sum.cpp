class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for( int i = 0 ; i < (int)nums.size()-3 ; ++i ){
            
            if( i == 0 || ( nums[i] != nums[i-1] ) ){
                
                for( int j = i+1 ; j < (int)nums.size()-2 ; ++j ){

                    if( j == i+1 || (nums[j] != nums[j-1]) ){
                
                        long long reqSum = (long long)target - nums[i] - nums[j];
                        int lo = j+1 , hi = nums.size()-1;

                        while( lo < hi ){

                            if( (long long)nums[lo] + nums[hi] == reqSum ){
                                ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});

                                while( lo < hi && nums[lo] == nums[lo+1] ){
                                    ++lo;
                                }

                                while( lo < hi && nums[hi] == nums[hi-1] ){
                                    --hi;
                                }

                                ++lo;
                                --hi;

                            }
                            else if( nums[lo] + nums[hi] < reqSum ){
                                ++lo;
                            }
                            else{
                                --hi;
                            }

                        }
                        
                    }


                }
                
            }
            
        }
        
        return ans;
        
    }
};