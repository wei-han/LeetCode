class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> curr;
        if(numRows < 1) return ans;
        if(numRows >= 1) ans.push_back({1});
        
        for(int i = 2; i <= numRows; i++)
        {
            curr.push_back(1);
            for(int j = 0; j < ans.back().size(); j++)
            {
                int temp = ans.back()[j] + ( j < ans.back().size()-1 ? ans.back()[j+1] : 0 );
                curr.push_back(temp);
            }
            ans.push_back(curr);
            curr={};
            
        }
        return ans;
        
    }
};
