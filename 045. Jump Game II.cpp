class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int cur = 0, next = 0, i = 0, level = 0;
        
        while(cur>= i){
            level++;
            for(;i<=cur; i++){
                next = max(next,nums[i]+i);
                if(next>=nums.size()-1) return level;
            }
            cur = next;
        }
        return level;
    }
};
