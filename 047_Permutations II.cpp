class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
            
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        per(ans, nums, 0);
        return ans;
       
        
    }
    void per(vector<vector<int>>& ans, vector<int> nums, int begin)//not by reference
    {
        if (begin >= nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for (int i = begin; i < nums.size(); i++)
        {   
            if(i!=begin && nums[i] == nums[begin]) continue;
         
            swap(nums[begin], nums[i]);
            per(ans, nums, begin+1);
//don't swap back!!
        }
        
    }
};

1122  1122
 ||    | |
//these two permutations are duplicate!!
