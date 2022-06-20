class Solution {
public:
    string multiply(string nums1, string nums2) {
        
        reverse(nums1.begin(),nums1.end());
        reverse(nums2.begin(),nums2.end());
        
        if( (nums1.length() == 1 && nums1 == "0") || (nums2.length() == 1 && nums2 == "0") ){
            return "0";
        }
        
        int size1 = nums1.length() , size2 = nums2.length();
        
        string ans;
        
        for( int i = 0 ; i < size1 ; ++i ){
            
            int carry = 0;
            string curPro;
            
            for( int j = 0 ; j < size2 ; ++j ){
                
                int pro = (nums1[i] - '0')*(nums2[j] - '0') + carry;
                carry = pro/10;
                curPro += (pro%10 + '0');
                
            }
            
            if( carry ){
                curPro += (carry + '0');
            }
            
            if( i != 0 ){
                
                int k = 0, q = i;
                carry = 0;
                while( q < ans.length() && k < curPro.length() ){
                    int sum = (ans[q] - '0')+ (curPro[k]-'0') + carry;
                    carry = sum/10;
                    ans[q] = (sum%10 + '0');
                    ++q;
                    ++k;
                }
                
                while( q < ans.length() && carry != 0 ){
                    
                    int sum = (ans[q] - '0') + carry;
                    carry = sum/10;
                    ans[q] = (sum%10 + '0');
                    ++q;
                    
                }
                
                while( k < curPro.length() ){
                    int sum = (curPro[k]-'0') + carry;
                    ans += (sum%10 + '0');
                    carry = sum/10;
                    ++k;
                }
                
                if( carry ){
                    ans += (carry + '0');
                }
                
            }
            else{
                ans = curPro;
            }
            
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};