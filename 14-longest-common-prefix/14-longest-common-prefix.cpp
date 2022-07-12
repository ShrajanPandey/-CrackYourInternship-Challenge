class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if( strs.size() == 0 ){
            return "";
        }
        
        int len = 0;
        for( int i = 0 ; i < strs.size() ; ++i ){
            if( i == 0 ){
                len = strs[i].length();
            }
            else{
                int j = 0;
                int k = 0;
                while( j < strs[i].length() ){
                    if( strs[i][j] != strs[i-1][j] ){
                        break;
                    }
                    ++j;
                    ++k;
                }
                len = min(len , k);
            }
        }
        
        return strs[0].substr(0,len);
        
    }
};