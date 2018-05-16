class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(subrob(nums, 0, nums.size()-2), subrob(nums, 1, nums.size()-1));
    }
    
    int subrob(vector<int> nums, int start, int end){
        int ppre = 0, pre =0, ans = 0;
        for(int i = start; i <= end; i++){
            ans = max(nums[i]+ ppre, pre);
            ppre = pre;
            pre = ans;
        }
        return ans;
    }
};
