class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int top = -1;
        int minSteps = 0;
        
        for( int i = 0; i < target.size() ; ++i ){
            
            if( top != -1 ){   
                if( top > target[i] ){
                    minSteps += top-target[i];
                }
            }
            
            top = target[i];
        
        }
     
        minSteps += top;   
        return minSteps;
        
    }
};