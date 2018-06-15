class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        vector<int> res;
        for(int i = 0; i<len; i++){
            int m = abs(nums[i])-1;
            nums[m] = -abs(nums[m]);
        }
        
        for(int i = 0; i<len; i++){
            if(nums[i]>0) res.push_back(i+1);
        }
        return res;
    }
};
