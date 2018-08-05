class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        int len = grid.size();
        for(int i = 0; i<len; i++){
            for(int j = 0; j <len; j++){
                if(grid[i][j]>0) res++;
            }
        }
        
        for(int i = 0; i<len; i++){
            int temp = 0;
            for(int j = 0; j<len; j++){
                temp = max(temp, grid[i][j]);
            }
            res += temp;
        }
        for(int j = 0; j<len; j++){
            int temp = 0;
            for(int i = 0; i<len; i++){
                temp = max(temp, grid[i][j]);
            }
            res += temp;
        }
        return res;
    }
};
