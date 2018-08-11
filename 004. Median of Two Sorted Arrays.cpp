class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()> nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int low = 0, high = m, i, half = (m+n+1)/2;
        
        while(low <=high){
            int i = (low+high)/2;
            int j = half - i;
            
            if(i>0 && nums1[i-1]>nums2[j]){
                high = i-1;
            }
            else if( i<m && nums2[j-1]>nums1[i]){
                low = i+1;
            }
            else{
                int max_left, min_right;
                if(i==0) max_left = nums2[j-1];
                else if( j ==0) max_left = nums1[i-1];
                else max_left = max(nums2[j-1], nums1[i-1]);
                
                if((m+n)%2 == 1) return max_left;
                
                if(i == m) min_right = nums2[j];
                else if(j == n) min_right = nums1[i];
                else min_right = min(nums2[j],nums1[i]);
                
                return (min_right + max_left)/2.0;
            }
        }
    }
};
