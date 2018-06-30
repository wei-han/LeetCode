class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> hash;
        vector<int> res;
        
        for(int n: nums){
            while(!stk.empty() && stk.top()<n){
                hash[stk.top()] = n;
                stk.pop();
            }
            stk.push(n);
        }
        
        for(int n: findNums){
            if(hash.find(n)!=hash.end()) res.push_back(hash[n]);
            else res.push_back(-1);
        }
        
        return res;
    }
};
