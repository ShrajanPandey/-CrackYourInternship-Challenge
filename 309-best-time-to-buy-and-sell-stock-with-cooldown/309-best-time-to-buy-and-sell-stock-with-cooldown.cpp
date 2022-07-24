class Solution {
public:

    int maxPro( vector<int> &prices , int i , int pre , vector<vector<int>> &memo ){
        
        if( i >= prices.size() ){
            return 0;
        }
        
        if( memo[i][pre+1] != -1 ){
            return memo[i][pre+1];
        }
        
        int ans = 0;
        if( pre == -1 ){
            ans = maxPro( prices , i+1 , i , memo );
        }
        else{
            ans = prices[i] - prices[pre] + maxPro( prices , i+2 , -1, memo );
        }
        
        return memo[i][pre+1] = max( ans , maxPro( prices , i+1 , pre , memo ));
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> memo (prices.size() +1 , vector<int> ( prices.size()+3 , -1));
        return maxPro( prices , 0 , -1 , memo );
        
    }
};