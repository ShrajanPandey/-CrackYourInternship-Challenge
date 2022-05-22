class Solution {
public:
    int count = 0;
    
    int countSubstrings(string s) {
        if (s.length() == 0) return 0;
        
        for (int i = 0; i < s.length(); i++) { // i is the mid point
            extendPalindrome(s, i, i); // odd length;
            extendPalindrome(s, i, i + 1); // even length
        }
        
        return count;
    }
    
    void extendPalindrome(string s, int left, int right) {
        while (left >=0 && right < s.length() && s[left] == s[right]) {
            count++; left--; right++;
        }
    }
    
};