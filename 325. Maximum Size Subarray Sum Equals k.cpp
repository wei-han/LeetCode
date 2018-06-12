class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int maxlen = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum+= nums[i];
            if(sum == k) 
                maxlen = i+1;
            else if(hash.find(sum - k) != hash.end()) 
                maxlen = max(maxlen, i-hash[sum-k]);
            
            if(hash.find(sum) == hash.end()) hash[sum] = i;
        }
        
        return maxlen;
    }
};
