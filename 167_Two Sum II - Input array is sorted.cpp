class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        vector<int> ans;
        while(lo < hi)
        {
            if(nums[lo] + nums[hi] < target) lo++;
            else if(nums[lo] + nums[hi] > target) hi--;
            else{
                ans.push_back(lo+1);
                ans.push_back(hi+1);
                return ans;
            }            
        }
    }
};
