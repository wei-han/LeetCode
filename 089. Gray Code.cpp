class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        bitset<32> item;
        sub(res, item, n);
        return res;
    }
    
    void sub(vector<int>&res, bitset<32>&item, int n){
        if(n==0){
            res.push_back(item.to_ulong());
            return;
        }
        
        sub(res, item, n-1);
        item.flip(n-1);
        sub(res, item, n-1);
    }
};
