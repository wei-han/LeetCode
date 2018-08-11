class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        assert(k<=nums.size());
        nums.push_back(INT_MIN);
        int i = 0, j = k-1;
        double ans = sums(nums, i, j);
        while (j<nums.size()){
            if(nums[j+1]<nums[i])ans = max(ans, sums(nums, i, j));
            i++;j++;
        }
        return ans/k;
    }
private:
    double sums(vector<int>&nums, int i, int j){
        double res=0;
        for (int m = i; m<=j; m++){
            res+=nums[m];
        }
        return res;
    }
};
