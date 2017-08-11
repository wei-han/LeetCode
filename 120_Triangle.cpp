class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        
        if(len == 0) return 0;
            
        for(int i = 1; i < len; i++)
        {
            triangle[i][0] += triangle[i-1][0];
            
            for(int j = 1; j < triangle[i].size() -1; j++)
            {
                triangle[i][j] += min( triangle[i-1][j-1], triangle[i-1][j]);
            }
            
            triangle[i][triangle[i].size()-1] +=triangle[i-1][triangle[i-1].size()-1];
        }
        
        int ans = triangle[len-1][0];
        for(int i = 0; i<len; i++)
        {
            ans = min(ans, triangle[len-1][i]);
        }
        
        return ans;
        
    }
};
