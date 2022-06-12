class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       
        unordered_set<char> st;
        int i = 0 , j = 0;
        int ans = 0, c = 0;
        
        while( i < s.length() && j < s.length() ){
            
            if( st.count(s[j]) == 0 ){
                ++c;
                ans = max( ans , c );
                st.insert(s[j]);
                ++j;
            }    
            else{
                --c;
                st.erase(s[i]);
                ++i;
            }
        }
        
        return ans;
        
    }
};