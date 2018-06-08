class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){
            int lo = i+1, hi = nums.size()-1;
            while(lo< hi){
                if(nums[i]+nums[lo]+nums[hi]<target) {
                    ans+= hi-lo;
                    lo++;
                }
                else hi--;                
            }
        }
        return ans;
    }
};

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int ans=0;
        sub(nums, 0, 0, target, ans, 0 );
        return ans;
    }
    
    void sub(vector<int>& nums,int begin, int sum, int target, int& ans, int count){
        if(count == 3 && sum<target) {
            ans++;
            return;
        }
        if(count == 3 && sum>= target) return;
        if(begin+2-count >=nums.size()) return;
        for(int i = begin; i<nums.size(); i++){
            sub(nums, i+1, sum+nums[i], target, ans, count+1);
        }
    }
};
