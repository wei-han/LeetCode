class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, sum = 0, minlen = INT_MAX;
        bool flag = false;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum>=s){
                flag = true;
                minlen = min(minlen, i-start+1);
                sum -= nums[start++];
            }
        }
        return flag ? minlen : 0;
    }
};
