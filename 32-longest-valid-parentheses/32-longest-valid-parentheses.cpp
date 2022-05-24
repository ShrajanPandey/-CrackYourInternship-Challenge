class Solution {
public:
    
    int longestValidParentheses(string s) {
        
        // vector<int> v;
        
        stack<int> st;
        st.push(-1);
        
        int ans = 0;
        for( int i = 0; i < s.length() ; ++i ){
            
            if( s[i] == '('){
                st.push(i);
            }    
            else{
                st.pop();
                if( st.empty() ){
                    st.push(i);
                }    
                else{
                    ans = max( ans , i - st.top());
                }
            }
            
        }
        
//         int pre = s.length();
//         while( st.empty() != 1 ){
            
//             ans = max( ans ,pre -(int) st.top()-1 );
//             pre = st.top();
//             // cout << pre << " ";
//             st.pop();
            
//         }
//         cout << endl;
        
//         ans = max( ans , pre );
        
        return ans;
        
    }
};