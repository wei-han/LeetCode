class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> bag;
        for(int ele:nums){
            bag.insert(ele);
            if(bag.size()>3) bag.erase(bag.begin());
        }
        return bag.size() ==3? *bag.begin() : *bag.rbegin();
    }
};
