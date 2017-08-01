class Solution {
int m;
int n;
public:
    bool exist(vector<vector<char>>& board, string word) {

        m = board.size();
        n = board[0].size();
        
        for(int i = 0; i<m; i++)
            for(int j = 0; j<n; j++)
            {
                if (isFound(board, word.c_str(), i, j))
                    return true;
            }
        return false;
        
    }

    
    bool isFound(vector<vector<char>> board, const char* p, int x, int y )
    {
        if(x<0 || y<0 || x >= m || y>=n || board[x][y] == '\0' || *p!=board[x][y]) return false;
        
        if(*(p+1) == '\0') return true;
        
        char t = board[x][y];
        board[x][y] = '\0';
        if(isFound(board, p+1, x-1,y) || isFound(board, p+1, x,y-1) || isFound(board, p+1, x+1,y) || isFound(board, p+1, x,y+1))
            return true;
        board[x][y] = t;
        return false;
    }
};
