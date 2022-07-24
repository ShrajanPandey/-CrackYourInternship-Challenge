class Solution {
public:
    string strWithout3a3b(int a, int b, char aa = 'a' , char bb = 'b') {
        
        if( a < b ){
            return strWithout3a3b( b , a , bb , aa );
        }
        
        int a_no = min( 2 , a ) , b_no = (a-a_no >= b ? 1 : 0);
        if( b == 0 ){
            return string(a_no , aa);
        }
        
        return string(a_no , aa) + string(b_no , bb ) + strWithout3a3b( a-a_no , b-b_no, aa , bb);
        
    }
};