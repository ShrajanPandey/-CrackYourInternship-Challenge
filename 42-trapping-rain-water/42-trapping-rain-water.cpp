class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> preM(height.size()) , sufM(height.size());
        
        int m = 0;
        
        for( int i = 0 ; i < height.size() ; ++i ){
            m = max( m , height[i]);
            preM[i] = m;
        }
        
        m = 0;
        for(int i = height.size()-1 ; i >= 0 ; --i ){
            m = max( m , height[i]);
            sufM[i] = m;
        }
        
        int ans = 0;
        for( int i = 0; i < height.size() ; ++i ){
            ans += (min(preM[i] , sufM[i])-height[i]);
        }
        
        return ans;
        
    }
};