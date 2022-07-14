class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        vector<int> fStack;
        
        int j = 0;
        for(auto x : pushed){
            fStack.push_back(x);
            while( fStack.size() && fStack.back() == popped[j] ){
                fStack.pop_back();
                ++j;
            }
        }
        
        return fStack.size() == 0;
        
    }
};