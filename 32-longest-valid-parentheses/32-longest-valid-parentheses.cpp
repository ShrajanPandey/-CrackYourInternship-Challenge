class Solution {
public:
    
    int longestValidParentheses(string s) {
        
        vector<int> v;
        
        stack<int> st;
        int ans = 0, c = 0;
        for( int i = 0; i < s.length() ; ++i ){
            
            if( s[i] == '('){
                st.push(i);
            }    
            else{
                if( st.empty() == 0 && s[st.top()] == '(' ){
                    st.pop();
                }    
                else{
                    st.push(i);
                }
            }
            
        }
        
        int pre = s.length();
        while( st.empty() != 1 ){
            
            ans = max( ans ,pre -(int) st.top()-1 );
            pre = st.top();
            // cout << pre << " ";
            st.pop();
            
        }
        cout << endl;
        
        ans = max( ans , pre );
        
        return ans;
        
    }
};