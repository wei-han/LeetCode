class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> item;
        vector<vector<int>> ans;
        
        oneCom(k, 1, n, item, ans);
        return ans;      
    }
    
    void oneCom(int k, int begin, int n, vector<int>& item, vector<vector<int>>& ans)
    {
     
        
        if(k == 0) 
        {
            ans.push_back(item);
            return;
        }
        
        for(int i = begin; i < n - k + 2; i++)
        {
            item.push_back(i);
            oneCom(k-1, i+1, n, item, ans);
            item.pop_back();
        }
     }
};
