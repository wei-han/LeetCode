class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, left =0, right =0;
        for(int i = 0; i<nums.size(); i++){
            right++;
            if(nums[i]==0){
                left = right;
                right = 0;
            }
            res = max(res, left+right);
        }
        return res;
    }
};
