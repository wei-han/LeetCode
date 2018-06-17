class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size());
        
        for(int i = 0; i<temperatures.size(); i++){
            while(!stk.empty() && temperatures[i]>temperatures[stk.top()]){
                int temp = stk.top();
                stk.pop();
                res[temp] = i-temp;
            }
            stk.push(i);
        }
        return res;
    }
};
