class Solution {
public:
    
    int longestSubsequence(string s, int k) {
            
        int maxCount = 0,j = 0;
        string cur;
        long long a = 0;
        
        while(j < s.length()){
            
            cur += s[j];
           bitset<1000> bits(cur);
            a = bits.to_ulong();
       
            if(a > k){

                int currCount = cur.length()-1;
                if(currCount > maxCount)
                    maxCount = currCount;

                    string p;
                    bool x = 1;
                    for( int i = 0 ; i < cur.length() ; ++i ){
                        if( x && cur[i] == '1' ){
                            x = 0;
                            continue;
                        }
                        p += cur[i];
                }

                cur = p;

            } 
            
             j++;
            
        }
        
        
        if( a <= k )
            maxCount = max( (int)cur.length() , maxCount );
        
        return maxCount;
        
    }
};