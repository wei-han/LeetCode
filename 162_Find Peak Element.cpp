class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        for(int i = 1; i < len - 1; i++)
        {
            if (nums[i-1] <nums[i] && nums[i] > nums[i+1])
                return i;
        }
        if(len > 1 && nums[0] > nums[1]) return 0;
        if(len > 1 && nums[len-1] > nums[len-2]) return len-1;
        if(len = 1) return 0;
    }
};
