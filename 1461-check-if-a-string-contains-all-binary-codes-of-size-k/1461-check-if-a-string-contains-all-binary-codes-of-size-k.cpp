class Solution {
public:
    long long power(int k ){
        
        int a = 1;
        while( k-- ){
            a *= 2;
        }
        
        return a;
        
    }
    
    bool hasAllCodes(string s, int k) {
        
        set<string> allCodes;
        
        for( int i = 0 ; i < s.length() ; ++i ){
            
            if( i + k-1 < s.length() ){
                allCodes.insert(s.substr(i,k));
            }
            
        }
        
        // cout << power(k) << endl;
        if( allCodes.size() == power(k) ){
            return true;
        }
        
        return false;
        
    }
};