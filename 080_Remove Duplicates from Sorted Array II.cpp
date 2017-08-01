class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int dup = 0;
        for(int i = 2; i < nums.size(); i++)
        {   
            if(nums[i] == nums[i-2 - dup]) dup++;
            else nums[i-dup] = nums[i];
        }
        
        return nums.size()-dup;
    }
};
