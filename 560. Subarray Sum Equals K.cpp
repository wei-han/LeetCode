class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int res = 0, sum = 0;
        hash[0] = 1;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            if(hash.find(sum-k)!=hash.end()) res+=hash[sum-k];
            hash[sum]++;
        }
        return res;
    }
};
