class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int maxP = 0, minPrice = prices[0];
        for(int i = 0; i< prices.size(); i++)
        {
            minPrice = min(prices[i], minPrice);
            maxP = max(maxP, prices[i] - minPrice);
        }    
    
    return maxP;
    }
};

// Kadane's Algorithm
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0, maxP = 0;
        for(int i = 1 ; i < prices.size(); i++)
        {
            sum = max(0, sum+prices[i]-prices[i-1]);
            maxP = max(maxP, sum);
        }       
        return maxP;
    }
};
