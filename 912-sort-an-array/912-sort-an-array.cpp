class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        priority_queue<int> p;
        
        for( int i = 0; i < nums.size() ; ++i ){
            p.push(nums[i]);
        }
        
        for( int j = nums.size()-1 ; j >= 0 ; --j ){
            nums[j] = p.top();
            p.pop();
        }
        
        return nums;
        
    }
};