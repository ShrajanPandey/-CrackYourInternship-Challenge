class Solution {
public:
    bool isInt( string s , int si , int ei ){
        
        if( si > ei ){
            return false;
        }
        
        bool b = (s[si] == '+' || s[si] == '-') ? 1 : 0 ;
        if( si == ei && b ){
            return false;
        }
        
        for( int i = b + si ; i <= ei ; ++i ){
            if( (s[i] < '0' || s[i] > '9' ) ){
                return false;
            }
        }
        return true;
        
    }
    
    bool isDecimal( string &s , int si , int ei ){
 
        if( si > ei ){
            return false;
        }

        bool b = (s[si] == '+' || s[si] == '-') ? 1 : 0 ;
        if( si == ei && (b || s[si] == '.') ){
            return false;
        }
        
        bool dec = s[si] == '.' ? 1 : 0;
        int j = 0;
        for( int i = dec + b + si ; i <= ei ; ++i ){

            if( s[i] != '.' && (s[i] < '0' || s[i] > '9' ) ){
                return false;
            }
            if( s[i] >= '0' && s[i] <= '9' ){
                ++j;
            }
            if( s[i] == '.' ){
                if( dec ){
                    return false;
                }
                dec = 1;
            }
        }
        
        if( j == 0 ){
            return false;
        }
        return true;
        
    }
    
    bool isNumber(string s) {
        
        if( s[0] == 'e' || s[0] == 'E' ){
            return false;
        }
        
        bool d = 0;
        for( int i = 0 ;i < s.length() ; ++i ){
            if( s[i] == 'e' || s[i] == 'E' ){
                return (isInt(s ,i+1 , s.length()-1) && isDecimal(s , 0 , i-1));
            }
        }
        
        // cout << "LOL" << " " << s << endl;
        return isDecimal( s, 0 , s.length()-1 ) ;
        
    }
};