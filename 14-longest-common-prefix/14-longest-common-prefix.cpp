class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if( strs.size() == 0 ){
            return "";
        }
        
        sort(strs.begin(),strs.end());
        int ans = 0;
        int i = 0;
        
        while( i < min(strs[0].length() ,strs[strs.size()-1].length()) ){
            
            if( strs[0][i] != strs[strs.size()-1][i] ){
                break;
            }
            ++ans;
            ++i;
            
        }
        
        return strs[0].substr(0,ans);
        
        
    }
};