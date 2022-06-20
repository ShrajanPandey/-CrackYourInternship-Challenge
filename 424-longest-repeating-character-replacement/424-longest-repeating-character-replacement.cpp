class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int ans = 0;
        char curChar = 'A';
        int n = s.length();
        
        for( int j = 0 ; j < 26 ; ++j ){
            
            int leftIdx = 0 , rightIdx = 0;
            int count = 0;
            
            while( leftIdx < n && rightIdx < n ){
                
                if( s[rightIdx] != curChar ){
                    ++count;
                }
                
                while( count > k ){
                    
                    if( s[leftIdx] != curChar ){
                        --count;
                    }
                    ++leftIdx;
                    
                }
                
                ans = max( ans , rightIdx - leftIdx + 1 );
                ++rightIdx;
                
            }
            
            ans = max( ans , rightIdx - leftIdx);
            ++curChar;
            
        }
        
        return ans;
        
    }
};