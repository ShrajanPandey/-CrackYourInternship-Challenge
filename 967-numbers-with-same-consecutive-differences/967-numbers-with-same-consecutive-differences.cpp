class Solution {
public:
    void generateAll( int n , int k , string curNo , vector<int> &ans ){
        
        if( n == 0 ){
            ans.push_back(stoll(curNo));
            return;
        }
        
        int lastDigit = curNo[curNo.length()-1]-'0';
        if( lastDigit + k <= 9 ){
            generateAll(n-1 , k , curNo + (char)(lastDigit+k+'0'), ans);
        }
        if( k != 0 && lastDigit-k >= 0 ){
            generateAll(n-1 , k , curNo + (char)(lastDigit-k+'0'), ans);
        }
     
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
                 
        string curNo;
        for( int i = 1 ; i <= 9 ; ++i ){
            generateAll(n-1 , k , curNo + (char)(i+'0'), ans );
        }
        
        return ans;
        
    }
};