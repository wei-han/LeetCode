//exceeds time limit
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num: nums){
            total += num;
        }
        if(total & 1) return false;
        int target = total/2;
        return search(nums, target, 0);
    }
    
    bool search(vector<int>& nums, int target, int begin){
        if(target <= 0) return target ==0;
        
        for(int i = begin; i < nums.size(); i++){
            if(search(nums, target - nums[i], i+1)) return true;            
        }
        return false;
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int num: nums) sum+=num;
        if(sum%2) return false;
        int target =sum/2;
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int num: nums){
            for(int i = target; i>=num; i--){ // can only start from the end
                dp[i] = dp[i] || dp[i-num];
            }
        }
        return dp[target];
    }
    
};
