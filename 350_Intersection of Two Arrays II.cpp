class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        vector<int> res;
        for(int item: nums1){
            if(hash.find(item)!=hash.end()) hash[item]++;
            hash.insert(make_pair(item, 1));
        }
        
        for(int item: nums2){
            if(hash.find(item) != hash.end() && hash[item]>0){
                res.push_back(item);
                hash[item]--;
            }
        }
        return res;
    }
};
