class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> memo(len, -1);
        memo[len - 1] = 1;
        
        for(int i = len -2; i > -1; i--)
        {
            for(int j = i+1; j < i+nums[i]+1; j++)
            {
                if(memo[j] == 1)
                {
                    memo[i] = 1;
                    break;
                }
            }          
        }
        return (memo[0]==1);
    }
};


//tricky solution, update the farthest reach 
bool canJump(int A[], int n) {
    int i = 0;
    for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + A[i], reach);
    return i == n;
}
