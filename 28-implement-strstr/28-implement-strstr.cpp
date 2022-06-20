class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if( needle.length() == 0 ){
            return 0;
        }
        
        if( needle.length() > haystack.length() ){
            return -1;
        }

        for( int i = 0 ; i < haystack.length() ; ++i ){
            
            if( i + needle.length() > haystack.length() ){
                break;
            }
            
            if( haystack[i] == needle[0] ){
                
                int j = 0, k = i;
                bool ans = 1;
                
                while( j < needle.length() && k < haystack.length() ){
                    if( needle[j] != haystack[k] ){
                        ans = 0;
                        break;
                    }
                    ++j;
                    ++k;
                }
                
                if( ans && j == needle.length() ){
                    return i;
                }
                
            }
            
        }
        
        return -1;
        
    }
};