class Solution {
public:
    int numTrees(int n) {
        int ans[n+1]={}; //must be explicitly initialized!!
        ans[0] = 1;
        ans[1] = 1;
        for(int i = 2; i < n+1; i++)
        {
            for(int j = 0; j < i; j++)
                ans[i] += ans[j]*ans[i-j-1];
        }
        
        return ans[n];
        
    }
};
