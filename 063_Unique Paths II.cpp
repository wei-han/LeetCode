class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        if(m==0) return 0;
        int n = obs[0].size();
        if (n==0) return 0;
        
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++ )
        {   
            if (obs[0][i] == 1) break;
            ans[i] = 1;
        }
        
        for(int i = 1; i < m; i++)
        {
            if(ans[0]==0 || obs[i][0]==1) ans[0] = 0;
                
            for(int j = 1; j < n; j++)
            {
                if (obs[i][j] == 1) ans[j]=0;
                else ans[j] = ans[j] + ans[j-1];
            }
        }
        
        return ans[n-1];
        
    }
};
