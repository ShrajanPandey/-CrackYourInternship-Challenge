class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<int>> pal;
    
    bool isPal( string &s , int i ,int j ){
        
        if( i >= j ){
            return true;
        }
        
        if( pal[i][j] != -1 ){
            return pal[i][j];
        }
        
        return pal[i][j] = (s[i] == s[j] ) && isPal( s , i+1 , j-1 );
        
    }
    
    void allPos( string &s , int start , vector<string> &cur ){
        
        if( start >= s.length() ){
            ans.push_back(cur);
            return;
        }
        
        for( int k = start ; k < s.length() ; ++k ){
            
            if( isPal( s , start , k ) ){
                cur.push_back(s.substr(start , k-start+1 ));
                allPos( s , k+1 , cur );
                cur.pop_back();
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
                
        pal.resize(s.length() , vector<int>(s.length() , -1));
        vector<string> cur;
        
        // if( isPal( s , 0 , s.length()-1 ) && s.length() > 1 ){
        //     ans.push_back({s});
        // }
        
        allPos( s , 0 ,cur);
        
        return ans;
        
    }
};