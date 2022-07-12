class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<string,int> m;
        m["I"] = 1;
        m["V"] = 5;
        m["X"] = 10;
        m["L"] = 50;
        m["C"] = 100;
        m["D"] = 500;
        m["M"] = 1000;
        m["IV"] = 4;
        m["IX"] = 9;
        m["XL"] = 40;
        m["XC"] = 90;
        m["CD"] = 400;
        m["CM"] = 900;
        
        int ans = 0;
        for(int i = s.length()-1 ; i >= 0 ; --i ){
            
            string p;
            p += s[i];
            
            if( i > 0 ){
                
                string q = p;
                q = s[i-1] + q;
                if( m.count(q) ){
                    ans += m[q];
                    --i;
                    continue;
                }
                
            }
            
            ans += m[p];
            
        }
        
        
        return ans;
        
    }
};