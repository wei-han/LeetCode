class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> bag;
        for(int i = 0; i<nums.size(); i++){
            if(i>k) bag.erase((long)nums[i-k-1]);
            auto ptr = bag.lower_bound((long)nums[i] - (long)t);
            if(ptr != bag.end() && (*ptr)-(long)nums[i] <= (long)t) return true;
            bag.insert((long)nums[i]);
        }
        
        return false;
    }
};


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() <2 || t<0) return false;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j<nums.size() && j<= k+i; j++){
                if(nums[j]/2.0 - nums[i]/2.0 <= t/2.0 && nums[j]/2.0 - nums[i]/2.0 >= -t/2.0) return true;
            }
        }
        return false;
    }
};
