class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int minSteps = target[0];
        
        for( int i = 1 ; i < target.size() ; ++i ){
            minSteps += max( target[i]-target[i-1] , 0);
        }
        
        return minSteps;
        
    }
};