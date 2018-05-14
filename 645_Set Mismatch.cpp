class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> res(2);
        vector<bool> temp(nums.size()+1, false);
        for(int item: nums){
            if(temp[item])  res[0] = item;
            temp[item] = true;
        }
        
        for(int i = 1; ; i++){
            if(!temp[i]){
                res[1] = i;
                return res;
            }
        }
    }
};
