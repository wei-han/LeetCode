class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int len = costs.size();
        if(len == 0) return 0;
        int lastR = costs[0][0];
        int lastG = costs[0][1];
        int lastB = costs[0][2];
        
        int curR, curG, curB;
        for(int i = 1; i<len; i++){
            curR = min(lastG, lastB) + costs[i][0];
            curG = min(lastR, lastB) + costs[i][1];
            curB = min(lastR, lastG) + costs[i][2];
            
            lastR = curR;
            lastG = curG;
            lastB = curB;
        }
        
        return min(lastR, min(lastG, lastB));
    }
};
