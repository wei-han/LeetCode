class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len > 1)
            k = k % len;
        else 
            return;
        k = len - k;
        vector<int> rot(nums.begin(), nums.begin()+k);
        nums.erase(nums.begin(), nums.begin() + k);
        
        nums.insert(nums.end(), rot.begin(), rot.end());
        
    }
};
