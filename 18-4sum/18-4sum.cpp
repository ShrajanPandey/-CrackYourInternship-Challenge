class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        for( int i = 0 ; i < (int)nums.size()-3 ; ++i ){
            
            if( i == 0 || ( nums[i] != nums[i-1] ) ){
                
                if((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
                if((long long)nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
                
                for( int j = i+1 ; j < (int)nums.size()-2 ; ++j ){
                    
                    if( j == i+1 || (nums[j] != nums[j-1]) ){
                         
                        if((long long)nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                        if((long long)nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                
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