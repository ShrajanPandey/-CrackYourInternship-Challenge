class Solution {
public:
    string numberToWords(int num) {
        
        if( num == 0 ){
            return "Zero";
        }
        
        string given = to_string(num);
        
        vector<string> below_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen","Twenty"};
        
        if( num <= 20 ){
            return below_20[num];
        }
        
        map<int,string> m;
        m[100] = "Hundred";
        m[1000] = "Thousand";
        m[1000000] = "Million";
        m[1000000000] = "Billion";
        
        vector<string> tens = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        
        string ans;
        
        vector<int> toCheck = {1000000000,1000000,1000,100,10,1};
        
        int i = 0;
        while( num ){
            
            int cur = toCheck[i];
            int n = num/cur;
            
            if( num <= 20 ){
                if( ans.length() ){
                    ans += ' ';
                }
                ans += below_20[num];
                break;
            }
            
            num %= cur;
            
            if( n && cur >= 100 ){
   
                int p = n/100;
                n %= 100;
                
                if( p ){
                    if( ans.length() ){
                        ans += ' ';
                    }
                    ans += below_20[p] + " " + m[100];
                }
                
                if( n && n <= 20 ){
                    if( ans.length() ){
                        ans += ' ';
                    }
                    ans += below_20[n];
                }
                else{
                    p = n/10;
                    n %= 10;
                    
                    if( p ){
                        if( ans.length() ){
                            ans += ' ';
                        }
                        ans += tens[p];  
                    }
                    
                    if( n ){
                        if( ans.length() ){
                            ans += ' ';
                        }
                        ans += below_20[n];
                    }
                }
                
                if( ans.length() ){
                    ans += ' ';
                }
                ans += m[cur];
                ++i;
                continue;
            }
            
            if( n && cur == 10 ){
                if( ans.length() ){
                    ans += ' ';
                }
                ans += tens[n];
            }
            
            if( n && cur == 1 ){
                if( ans.length() ){
                    ans += ' ';
                }
                ans += below_20[n];
            }
            
            ++i;
            
        }
        
        return ans;
        
    }
};