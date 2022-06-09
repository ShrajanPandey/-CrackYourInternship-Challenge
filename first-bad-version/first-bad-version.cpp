// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int left = 1 , right = n;
        
        while( left < right ){
            
            int mid = left + ( right - left )/2;
            if( mid < n && isBadVersion(mid) == 0 && isBadVersion(mid+1) ){
                return mid+1;
            }
            
            if( isBadVersion(mid) == 0 ){
                left = mid+1;
            }
            else{
                right = mid;
            }
            
        }
        
        return left;
            
    }
};