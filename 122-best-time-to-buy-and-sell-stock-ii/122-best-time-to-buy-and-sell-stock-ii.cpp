class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        
        int ans = 0 , n = prices.size() , i = 0, buy = 9 , sell = 0;
        
        while( i < n-1 ){
            
            while( i+1 < n && prices[i+1] <= prices[i] ){
                ++i;
            }
            buy = prices[i];            
        
            while( i+1 < n && prices[i+1] > prices[i] ){
                ++i;
            }
            sell = prices[i];
            
            ans += sell - buy;
            
        }
        
        return ans;
        
    }
};