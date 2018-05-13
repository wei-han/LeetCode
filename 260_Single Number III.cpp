class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        vector<int> res ={0,0};
        for(int item:nums){
            sum ^= item;
        }
        sum &= -sum;
        for(int item: nums){
            if(item & sum) res[0] ^= item;            
            else res[1] ^= item;
        }
        return res;
        
    }
};
