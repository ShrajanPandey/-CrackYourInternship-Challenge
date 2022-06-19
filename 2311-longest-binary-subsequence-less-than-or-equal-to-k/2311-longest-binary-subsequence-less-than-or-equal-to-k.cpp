class Solution {
public:
    int ans = 0;
    int arr[1001][1001];
    
    int len(string &s , int k , int i , string cur){
        
        bitset<64> bits(cur);
        long long a = bits.to_ulong();
        cout << a << " " << cur.length() << endl;
        if( a > k ){
            return -1;
        }
        
        if( i == s.length() ){
            return 0;
        }
        
        if( arr[i][a] != -1 ){
            return arr[i][a];
        }
        
        int p = len(s , k , i+1 , cur), o = cur.length();
        if( p != -1 )
            o =  1 + len(s , k , i+1 , cur + s[i]);
    
        return arr[i][a] = max( o , p );
        
    }
    
    int longestSubsequence(string s, int k) {
        
        // ans = 0;
        // memset(arr , -1 , sizeof(arr));
        // return len(s , k , 0 , "");
        
//         int zero = 0;
//         for( int i = 0 ; i < s.length() ; ++i ){
//             if( s[i] == '0' ){
//                 ++zero;
//             }
//             ans = max( ans , zero + )
//         }
        
        
        int zero = 0;
        int maxCount = 0;
        int j=0;
        int sum = 0;
        string cur;
        int count = 0;
        long long a = 0;
        
        while(j < s.length()){
            
            if( s[j] == '0' ){
                ++zero;
            }
            
            cur += s[j];
           bitset<1000> bits(cur);
            a = bits.to_ulong();
            cout << cur << " " << cur.length() << " " << a << endl;
             if(a > k){
                    cout << a << " " << cur.length()-1  << " " << maxCount << endl;
                  int currCount = cur.length()-1;
                  if(currCount > maxCount)
                      maxCount = currCount;
                 
                 while( a > k ){
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
                     bitset<1000> bits(cur);
                    a = bits.to_ulong();
                 }
                 
             } 
            
             j++;
        }
        
         // << " " << " " << a << " " << maxCount << endl;
        
        if( a <= k )
            maxCount = max( (int)cur.length() , maxCount );
        
        return maxCount;
        
    }
};