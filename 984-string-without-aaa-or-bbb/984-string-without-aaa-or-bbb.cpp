class Solution {
public:
    string strWithout3a3b(int a, int b, char aa = 'a' , char bb = 'b') {
        
        if( a < b ){
           return strWithout3a3b( b , a , bb , aa );
        }

        string ans;
        
        while( a-- > 0 ){
            ans += aa;
            if( a > b ){
                ans += aa;
                --a;
            }
            if( b ){
                ans += bb;
                --b;
            }
        }
        
        return ans;
        
    }
};