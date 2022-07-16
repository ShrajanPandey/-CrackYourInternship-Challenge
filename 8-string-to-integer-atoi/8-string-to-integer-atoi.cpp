class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int i = 0;
        long long ans = 0;
        bool isNeg = 0;
        
        while( i < n && s[i] == ' ' ){
            ++i;
        }
        
        if( i < n && (s[i] == '-' || s[i] == '+')){
            isNeg = (s[i] == '-');
            ++i;
        }

        while( i < n && (s[i] >= '0' && s[i] <= '9') ){
            
            ans = ans*10 + (s[i]-'0');
            
            if( ans >= INT_MAX ){
                if( isNeg ){
                    if( -1*ans <= INT_MIN ){
                        return INT_MIN;
                    }
                }
                else{
                    return INT_MAX;
                }
            }
            ++i;
        }
        
        return (isNeg ? -1 : 1)*ans;
        
    }
};