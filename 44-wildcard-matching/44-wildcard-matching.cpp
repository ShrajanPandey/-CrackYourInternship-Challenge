class Solution {
public:

    bool isMatching( string &s , string &p , int curS , int curP , vector<vector<int>> &arr){
        
        // cout << curS << " M " << curP << endl;
        
        if( curS >= s.length() && curP >= p.length() ){
            return 1;
        }    
        
        if( curP >= p.length() ){
            return 0;
        }
        
        if( curS >= s.length() ){
            for( int j = curP ; j < p.length() ; ++j ){
                if( p[j] != '*' ){
                    return 0;
                }
            }
            return 1;
        }
        
        
        if( arr[curS][curP] != -1 ){
            return arr[curS][curP];
        }
        
        if( s[curS] == p[curP] || p[curP] == '?' ){
            return arr[curS][curP] = isMatching( s, p , curS+1 , curP+1 , arr );
        }
        
        if( p[curP] == '*' ){
            
            for( int j = curS ; j <= s.length() ; ++j ){
                
                if( isMatching( s , p , j , curP+1 , arr ) ){
                    return arr[curS][curP] = 1;
                }
                
            }
            
        }
        
        return arr[curS][curP] = 0;
        
    }
    
    bool isMatch(string s, string p) {
        
        vector<vector<int>> arr(s.length()+1 , vector<int> (p.length()+1 , -1));
        
        return isMatching( s , p , 0 , 0 , arr);
        
    }
};