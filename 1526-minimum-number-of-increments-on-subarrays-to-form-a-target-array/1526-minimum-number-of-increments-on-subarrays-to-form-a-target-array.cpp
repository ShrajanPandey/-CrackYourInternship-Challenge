class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        stack<int> stk;
        int minSteps = 0;
        
        for( int i = 0; i < target.size() ; ++i ){
            
            if( stk.size() ){
                
                if( stk.top() > target[i] ){
                    minSteps += stk.top()-target[i];
                    stk.pop();
                    stk.push(target[i]);
                }
                else{
                    while( stk.empty() != 1 ){
                        stk.pop();
                    }
                    stk.push(target[i]);
                }
            }
            else{
                stk.push(target[i]);
            }
                
            
        }
        
        while( stk.size() ){
            minSteps += stk.top();
            stk.pop();
        }
        
        return minSteps;
        
    }
};