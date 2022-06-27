class Solution {
public:
    int minPartitions(string n) {
        
        int maxi = INT_MIN;
        
        for( int i = 0 ; i < n.length() ; ++i ){
            maxi = max( maxi , (int)n[i]-'0');
            if( maxi == 9 ){
                return 9;
            }
        }
        
        return maxi;
        
    }
};