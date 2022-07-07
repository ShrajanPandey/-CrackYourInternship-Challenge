class Solution {
public:
    map<pair<int,int>,bool> m;
    
    bool isInterleave(string &s1, string &s2, string &s3 , int si1 = 0 , int si2 = 0 , string ans = "" , int si = 0 ) {
        
        if( si1 >= s1.length() && si2 >= s2.length() ){
            if( ans == s3 ){
                return true;
            }
            return false;
        }
        
        if( m.count({si1,si2}) ){
            return m[{si1,si2}];
        }
        
        bool isPos = 0;
        if( si1 < s1.length() && s1[si1] == s3[si] )
            isPos = isInterleave( s1 , s2 , s3 , si1+1 , si2 , ans+s1[si1] , si+1);
        if( isPos == 0 && si2 < s2.length() && s2[si2] == s3[si] )
            isPos = isInterleave( s1 , s2 , s3 , si1 , si2+1 , ans+s2[si2] , si+1);
        
        return m[{si1,si2}] = isPos;
        
    }
};