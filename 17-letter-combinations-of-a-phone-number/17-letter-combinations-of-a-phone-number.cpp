class Solution {
public:
    map<int,string> m;
    
    vector<string> letterCombinations(string digits) {
        m[2] = "abc";
        m[3] = "def";m[4] = "ghi";m[5]="jkl";m[6]="mno";m[7] = "pqrs";m[8]="tuv";m[9]="wxyz";
        vector<string> ans;
        allPossible(digits , "" , ans );
        return ans;
    }
    
    void allPossible(string digit , string cur , vector<string> &ans ){
        
        if( digit.length() == 0 ){
            if( cur.length() )
            ans.push_back(cur);
            return;
        }
        
        int curDigit = digit[0]-'0';
        for( int i = 0 ; i < m[curDigit].length() ; ++i ){
            allPossible(digit.substr(1) , cur+m[curDigit][i] , ans );    
        }
        
    }
    
};