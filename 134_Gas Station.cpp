class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans=0;
        int sum=0;
        int min = gas[0] - cost[0];
        for(int i = 0; i < gas.size(); i++)
        {
            sum += gas[i] - cost[i];
            if(sum <= min)
            {
                min = sum;
                ans = i + 1;
            }
        }
        
        return sum<0 ? -1 : ans%gas.size();
        
    }
};
