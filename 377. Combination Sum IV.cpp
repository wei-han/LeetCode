class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res[target+1] ={0};
        res[0] = 1;
        sort(nums.begin(), nums.end());
        for(int i = 1; i<=target; i++){
            for(int item: nums){
                if(i<item) break;
                else res[i] +=res[i-item];
            }
        }
        
        return res[target];
    }
};
