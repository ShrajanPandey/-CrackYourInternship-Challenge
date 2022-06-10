class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        if( s.length() == 0 ){
            return 0;
        }
        
        int ans = 1, l = 0;
        for( int i = 0 ; i < s.length() ; ++i ){
            if( m.count(s[i]) > 0 ){
                if( l > m[s[i]])
                    ans = max( ans , i-l );
                else{
                    ans = max( ans , i-l);
                    l = m[s[i]]+1;
                }
                m[s[i]] = i;
            }
            else{
                m[s[i]] = i;
            }
        }
  
        if( l < (int)s.length() ){
            ans = max( ans , (int)(s.length())- l);
        }
        
        return ans;
    }
};