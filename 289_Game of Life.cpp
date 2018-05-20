class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = m ? board[0].size() : 0;
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                int count = 0;
                for(int s=max(i-1,0); s<min(m,i+2); s++){
                    for(int t=max(j-1,0); t<min(n,j+2); t++){
                        count+= board[s][t]&1;
                    }
                }
                if(count ==3 || count-board[i][j]==3){
                    board[i][j] |= 2;
                }
            }
        }
        
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n; j++){
                board[i][j]>>=1;
            }
        }
    }     
};
