class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        int n = answerKey.size();
        int ans = 0;
        
        char cur = 'T';
        for( int p = 0 ; p < 2 ; ++p ){
            
            int leftPar = 0 , rightPar = 0, count = 0;
            
            if( p == 0 )
                cur = 'T';
            else
                cur = 'F';
            
            while( leftPar < n && rightPar < n ){

                if( answerKey[rightPar] != cur ){
                    ++count;
                }

                while( count > k ){

                    if( answerKey[leftPar] != cur ){
                        --count;
                    }
                    ++leftPar;

                }

                ans = max( ans , rightPar-leftPar+1 );
                ++rightPar;

            }
            
        }
        
        return ans;
        
    }
};