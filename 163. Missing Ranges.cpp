class Solution {
    string range(int start, int end){
        if(start == end) return to_string(start);
        else return to_string(start)+"->"+to_string(end);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        
        long long pre = (long)lower;
        for(int i = 0; i<=nums.size(); i++){
            long long cur = i<nums.size()? (long)nums[i]:(long)upper+1;
            if(cur - pre>0) res.push_back(range(pre, cur-1));
            pre = cur+1;
        }
        return res;
    }
};
