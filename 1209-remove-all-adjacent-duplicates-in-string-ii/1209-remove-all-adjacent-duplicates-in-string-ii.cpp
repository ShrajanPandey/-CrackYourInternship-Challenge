class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        for( int i = s.length()-1 ; i >= 0 ; --i ){
            if( st.empty() || st.top().first != s[i] ){
                st.push({s[i],1});
            }
            else{
                pair<char,int> cur = st.top();
                st.push({s[i],cur.second+1});
                if( st.top().second == k ){
                    int a = k;
                    while( a-- ){
                        st.pop();
                    }
                }
            }
        }
        
        string ans;
        while( st.empty() != 1 ){
            ans += st.top().first;
            st.pop();
        }
        
        // reverse(ans.begin(),ans.end());
        return ans;
        
    }
};