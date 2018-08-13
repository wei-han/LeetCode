class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int res=0;
        for(int item: nums) pq.push(item);
        while(!pq.empty()){
            res+=pq.top();
            pq.pop();
            pq.pop();
        }
        return res;
    }
};
