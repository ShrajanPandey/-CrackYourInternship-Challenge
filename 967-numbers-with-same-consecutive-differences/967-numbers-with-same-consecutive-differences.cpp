class Solution {
public:
    void generateAll( int n , int k , string curNo , vector<int> &ans ){
        
        if( n == 0 ){
            ans.push_back(stoll(curNo));
            return;
        }
        
        if( curNo.length() == 0 ){
            
            for( int i = 1 ; i <= 9 ; ++i ){
                generateAll(n-1 , k , curNo + (char)(i+'0'), ans );
            }
            
            return;
        }
        
        int lastDigit = curNo[curNo.length()-1]-'0';
        int one = abs(lastDigit-k);
        int two = abs(lastDigit+k);
        
        if( one != two ){
            if( one < 10 && abs(one-lastDigit) == k )
                generateAll(n-1 , k , curNo + (char)(one + '0') , ans);
            if( two < 10 && abs(two-lastDigit) == k ){
                generateAll(n-1 , k , curNo + (char)(two + '0') , ans);
            }
        }
        else{
            
            if( abs(one-lastDigit) == k && one < 10 ){
                generateAll(n-1 , k , curNo + (char)(one + '0') , ans );
            }
        }
        
    }
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        vector<int> ans;
        generateAll(n , k , "" , ans);
        
        return ans;
        
    }
};