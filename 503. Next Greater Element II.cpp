class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, -1);
        stack<int> stk;
        for(int i = 0; i<2*len; i++){
            while(!stk.empty() && nums[stk.top()]<nums[i%len]){
                res[stk.top()] = nums[i%len];
                stk.pop();
            }
            stk.push(i%len);
        }
        return res;
    }
};
