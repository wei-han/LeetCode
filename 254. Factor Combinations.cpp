class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> item;
        sub(n, item, ans);
        return ans;
    }
    
    void sub(int n, vector<int>& item, vector<vector<int>>& ans){
        int i = item.empty()?2:item.back();
        for(; i<=n/i; i++){
            if(n%i==0) {
                item.push_back(i);
                sub(n/i, item, ans);                
                item.push_back(n/i);
                ans.push_back(item);
                item.pop_back();
                item.pop_back();
            }
        }
    }
};
