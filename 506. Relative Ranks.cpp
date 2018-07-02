class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        vector<string> res(nums.size());
        
        for(int i = 0; i<nums.size(); i++){
            pq.push({nums[i], i});
        }
        int count = 1;
        for(int i = 0; i<nums.size(); i++){
            if(count == 1) {res[pq.top().second] = "Gold Medal"; pq.pop(); count++;}
            else if(count == 2) {res[pq.top().second] = "Silver Medal"; pq.pop(); count++;}
            else if(count == 3) {res[pq.top().second] = "Bronze Medal"; pq.pop(); count++;}
            else {res[pq.top().second] = to_string(count); pq.pop(); count++;}
        }
        
        return res;
    }
};
