class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = 0 , j = 0;
        while( i < m ){
            if( j < n && nums1[i] > nums2[j] ){
                int t = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = t;
                sort(nums2.begin(),nums2.end());
            }    
            ++i;
        }
        
        while( j < n ){
            nums1[i] = nums2[j];
            ++i;
            ++j;
        }
        
        
    }
};