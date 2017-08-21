class Solution {
public:
    int rob(vector<int>& nums) {
        int ans = 0;
        int pre = 0;
        int ppre = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            ans = max(nums[i] + ppre, pre);//if robbing, take the current ans the node pre-pre; if not robbing, take the pre.
            ppre = pre;
            pre = ans;
        }
        return ans;
    }
    
};
