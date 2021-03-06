class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));
        solve(board, 0, n, res);
        return res;
    }

private:
    void solve(vector<string> &board, int row, int n, vector<vector<string>> &res){
        if(row==n){
            res.push_back(board);
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(valid(board, row, i, n)){
                board[row][i]='Q';
                solve(board, row+1, n, res);
                board[row][i]='.';
            }
        }
    }
    
    bool valid(vector<string> &board, int row, int col, int n){
        for(int i = 0; i<n; i++)
            if(board[i][col]=='Q') return false;
        for(int i = row-1, j = col+1; i>=0 && j<n; i--, j++)
            if(board[i][j]=='Q') return false;
        for(int i = row-1, j = col-1; i>=0 && j>=0; i--, j--)
            if(board[i][j]=='Q') return false;
        return true;
    }
};
