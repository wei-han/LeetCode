//state machine
class Solution {
public:
    int maxProfit(vector<int>& price) {
        int len = price.size();
        if(len<2) return 0;
        vector<int> s0(len);
        vector<int> s1(len);
        vector<int> s2(len);
        s0[0] = INT_MIN;
        s1[0] = -price[0];
        s2[0] = 0;
        
        for(int i = 1; i < price.size(); i++){
            s0[i] = s1[i-1]+price[i];
            s1[i] = max(s1[i-1], s2[i-1]-price[i]);
            s2[i] = max(s0[i-1], s2[i-1]);
        }
        return max(s0[len-1], s2[len-1]);
    }
};
