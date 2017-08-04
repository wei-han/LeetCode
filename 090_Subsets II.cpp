class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<int> subset;
        vector<vector<int>> ans;
        
        proc(nums, 0, subset, ans);
        return ans;
        
    }
    void proc(vector<int> nums, int begin, vector<int> &subset, vector<vector<int>> &ans)
    {
        ans.push_back(subset);
        
        for(int i = begin; i < nums.size(); i++)
        {
            if(i == begin || nums[i] != nums[i-1])
            {
                subset.push_back(nums[i]);
                proc(nums, i+1, subset, ans);
                subset.pop_back();
            }
            
        }
    }
};
