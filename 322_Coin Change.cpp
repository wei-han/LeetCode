class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>ans(amount+1, 0);
        for(int i = 0; i<coins.size(); i++){
            if(coins[i]<= amount)ans[coins[i]] = 1;
        }
        
        for(int i = 1; i<=amount;i++){
            int res  = INT_MAX;
            for(int coin: coins){
                if(i>=coin && ans[i-coin] != -1 )
                res = min(res, ans[i-coin]+1);
            }
            if(res == INT_MAX) ans[i] =-1;
            else ans[i] = res;
            
        }
        return ans[amount];
        
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>ans(amount+1, amount+1);
        
        ans[0] = 0;
        
        for(int i = 1; i<=amount;i++){
            int res  = INT_MAX;
            for(int coin: coins){
                if(i>=coin ) ans[i] = min(ans[i], ans[i-coin]+1);
            }
        }
        return ans[amount] < amount+1 ? ans[amount] : -1;
        
    }
};
