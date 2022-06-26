class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int ans = 0, front = 0 , back = 0;
        int j = cardPoints.size(), i = 0;
        
        for( i = 0 ; i < k ; ++i ){
            front += cardPoints[i];
        }
        
        ans = front;
        --j;
        --i;
        
        while( i >= 0 ){
 
            front -= cardPoints[i];
            back += cardPoints[j];
            ans = max(ans , front + back);
            --j;
            --i;
            
        }
        
        return ans;
        
    }
};