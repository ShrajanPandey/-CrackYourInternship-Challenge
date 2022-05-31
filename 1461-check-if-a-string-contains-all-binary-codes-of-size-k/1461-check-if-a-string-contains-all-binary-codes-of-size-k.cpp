class Solution {
public:    
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string> allCodes;
        
        for( int i = 0 ; i < s.length() ; ++i ){
            
            if( i + k-1 < s.length() ){
                allCodes.insert(s.substr(i,k));
            }
            
        }

        if( allCodes.size() == pow(2,k) ){
            return true;
        }
        
        return false;
        
    }
};