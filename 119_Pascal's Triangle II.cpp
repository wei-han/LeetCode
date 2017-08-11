class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        if (rowIndex < 0) return ans;
        
        ans = {1};
        for(int i = 0; i < rowIndex; i++)
        {
            ans.insert(ans.begin(), 0);
            for(int j = 0; j <ans.size(); j++)
            {
                ans[j] = ans[j] + (j < ans.size() - 1 ? ans[j+1] : 0);
            }
        }
        return ans;
    }
};
