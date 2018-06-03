class Solution {
public:
    vector<pair<int, int>> res;
    vector<vector<int>> status;
    
    void dfs(vector<vector<int>>& mat, int x, int y,int pre, int statusval){
        if(x<0 || x>= mat.size() || y<0 || y>= mat[0].size() || mat[x][y] < pre || status[x][y]==3 || status[x][y] == statusval) 
            return;
        status[x][y] |= statusval;
        if(status[x][y] == 3) res.push_back({x,y});
        dfs(mat, x-1, y, mat[x][y], status[x][y]);
        dfs(mat, x+1, y, mat[x][y], status[x][y]);
        dfs(mat, x, y-1, mat[x][y], status[x][y]);
        dfs(mat, x, y+1, mat[x][y], status[x][y]);        
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() ==0) return res;
        int m = matrix.size(), n = matrix[0].size();
        status.resize(m, vector<int>(n, 0));
        
        for(int i = 0; i<m; i++ ){
            dfs(matrix, i, 0, INT_MIN, 1);
            dfs(matrix, i, n-1, INT_MIN, 2);
        }
        
        for(int i = 0; i<n; i++ ){
            dfs(matrix, 0, i, INT_MIN, 1);
            dfs(matrix, m-1, i, INT_MIN, 2);
        }
        return res;
    }
};
