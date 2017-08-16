class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;
         while(lo < hi)
         {
             int mid = (lo + hi) / 2;
             if(nums[mid] > nums[hi])
                 lo = mid+1;
             else if(nums[mid] < nums[hi])
                 hi = mid;
         }
        return nums[lo];
    }
};
