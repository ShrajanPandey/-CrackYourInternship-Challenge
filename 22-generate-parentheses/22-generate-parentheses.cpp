class Solution {
public:
    vector<string> ans;
    
    void generate(int n , int o , string cur ){
        
        if( n == 0 ){
            if( o == 0 ){
                ans.push_back(cur);
            }
            return;
        }
        
        if( o ){
            generate(n-1 , o-1 , cur + ')');
            generate(n-1 , o+1 , cur + '(');
        }
        else{
            generate(n-1 , o+1 , cur + '(');
        }
        
    }
    
    vector<string> generateParenthesis(int n, int o = 0 , string cur = "") {
        
        generate(2*n , 0 , "");
        return ans;
        
    }
};