class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        vector<vector<int>> bucket(nums.size()+1);
        vector<int> res;
        
        for(int item: nums){
            hash[item]++;
        }
        
        for(auto item: hash){
            bucket[item.second].push_back(item.first);
        }
        
        for(int i = bucket.size()-1; i>=0 && res.size()<k; i--){
            for(int number: bucket[i]){
                res.push_back(number);
                if(res.size()==k) break;
            }
        }
        return res;
        
    }
};
