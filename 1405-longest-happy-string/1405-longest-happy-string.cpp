class Solution {
public:
    
    string longestDiverseString(int a, int b, int c, char aa = 'a' , char bb = 'b' , char cc = 'c') {
        
        if( a < b ){
            return longestDiverseString( b , a , c , bb , aa , cc );
        }
        else if( b < c ){
            return longestDiverseString( a , c , b , aa , cc , bb );
        }
        
        int a_no = min( 2 , a ), b_no = (a - a_no >= b ? 1 : 0);
        if( b == 0 ){
            return string(a_no,aa);
        }
        
        return string(a_no, aa) + string(b_no , bb ) + longestDiverseString( a-a_no , b-b_no , c , aa , bb , cc );
        
    }
};