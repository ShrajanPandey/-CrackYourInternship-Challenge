class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int mx = nums[0], mi = nums[0];
        int ans = mx;
        
        for(int i = 1 ; i < nums.size() ; ++i ){
            
            int pmx = mx, pmi = mi;
            
            mx = max({pmx*nums[i] , nums[i] , pmi*nums[i]} );
            mi = min({pmi*nums[i] , nums[i] , pmx*nums[i]} );
            cout << mx << ' ' << mi << endl;
            ans = max( ans , mx );
            
        }
        
        return ans;
        
    }
};