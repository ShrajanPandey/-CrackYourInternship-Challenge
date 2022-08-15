class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        int ans = m[s[s.length()-1]];
        for(int i = s.length()-2 ; i >= 0 ; --i ){
            
            if( m[s[i+1]] > m[s[i]] ){
                ans -= m[s[i]];
            }
            else{
                ans += m[s[i]];
            }
            
        }
        
        
        return ans;
        
    }
};