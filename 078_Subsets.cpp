class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> item;
        vector<vector<int>> ans;
        
        set(nums, 0, item, ans);
            
        return ans;
        
    }
    void set(vector<int> nums, int begin, vector<int>& item, vector<vector<int>>& ans)
    {    
        ans.push_back(item);
       
        for(int i = begin; i < nums.size(); i++)
        {
            item.push_back(nums[i]);
            set(nums, i+1, item, ans);
            item.pop_back();
        }
    }
};
