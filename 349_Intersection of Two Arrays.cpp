class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        vector<int> res;
        for(int item : nums1){
            set.insert(item);
        }
        for(int item : nums2){
            if(set.find(item) != set.end()){
                res.push_back(item);
                set.erase(item);
            }
        }
        return res;
    }
};
