class Solution {
public:
    void combination(vector<vector<int>> &result, vector<int> item, int k, int n){
        if(item.size() == k && n==0) {
            result.push_back(item);
            return;
        }
        if( item.size()<k ){
            for(int i = item.empty()? 1: item.back()+1 ; i<=9; i++){
                if(n-i < 0) break;
                item.push_back(i);
                combination(result, item, k, n-i);
                item.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> item;
        combination(result, item, k, n);
        return result;
    }
};
