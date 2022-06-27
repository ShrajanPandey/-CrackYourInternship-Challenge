class Solution {
public:

    int q = 0;
    bool isMatching( string &s , string &p , int curS , int curP , map<int,int> &after , vector<vector<int>> &arr ){
        
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
            return arr[curS][curP] = isMatching( s, p , curS+1 , curP+1 , after , arr);
        }
        
        if( p[curP] == '*' ){
            
            int possibleMoves = s.length() - after[curP] - curP;
            cout << possibleMoves << endl;
            for( int i = 0 ; i <= possibleMoves ; ++i ){

                if( isMatching( s, p , curS+i , curP+1 , after , arr) ){
                    return arr[curS][curP] = 1;
                }
            }
            
        }
        
        return arr[curS][curP] = 0;
        
    }
    
    bool isMatch(string s, string p) {
        
        int q = 0;
        
        map<int,int> noAfter;
        int c = 0;
        
        for( int i = p.length()-1 ; i >= 0 ;--i ){
            
            if( p[i] == '*' ){
                noAfter[i] = c;
            }
            else 
                ++c;
            
        }
        
        for( int j = 0 ; j < p.length() ; ++j ){
            
            if( p[j] == '*' ){
                noAfter[j] -= q;
                ++q;
            }
            
        }
        
        // memset(arr , -1 , sizeof(arr));
        vector<vector<int>> arr(s.length()+1 , vector<int> (p.length()+1,-1));
        
        return isMatching( s , p , 0 , 0, noAfter , arr );
        
    }
};