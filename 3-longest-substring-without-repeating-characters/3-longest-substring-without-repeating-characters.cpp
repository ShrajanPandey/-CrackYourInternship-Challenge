class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        //O(2*n)
        unordered_map<char,int> st;
        int ans = 0, low = 0;
        
        for( int i = 0 ; i < s.length() ; ++i ){
            
            if( st.count(s[i]) && st[s[i]] >= low ){
                ans = max( ans , i - low );
                low = st[s[i]]+1;
                st[s[i]] = i;
            }
            else{
                st[s[i]] = i;
            }
            
        }
        
        ans = max( ans , (int)s.length() - low );
        
        
        return ans;
        
    }
};