class NumArray {
public:
//psum[i] means sum from 0 to i-1.
    NumArray(vector<int> nums) {
        int sum = 0;
        psum.push_back(sum);
        for(int item: nums){
            sum += item;
            psum.push_back(sum);
            
        }
    }
    
    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
