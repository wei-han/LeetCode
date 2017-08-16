class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int imax, imin;
        imax = imin = ans;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < 0)
                swap(imax, imin);
            //the max/min product of the subarray ending with current element!!
            imax = max(imax*nums[i], nums[i]);
            imin = min(imin*nums[i], nums[i]);
            
            ans = max(ans, imax);            
        }
        
        return ans;
        
    }
};
