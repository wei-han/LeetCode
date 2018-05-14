class Solution {
public:
    int getMoneyAmount(int n) {
        int table[n+1][n+1];
        for(int i = 1; i<n+1; i++){
            table[i][i] = 0;
        }
        for(int l = 2; l <= n; l++){
            for(int i = 1; i<= n - l + 1; i++){
                int j = i+l-1;
                int res = INT_MAX;
                for(int k = i+1; k<j; k++){
                    int local = k + max(table[i][k-1], table[k+1][j]);
                    res = min(local, res);
                }

                res = min(res, i + table[i+1][j]);
                res = min(res, j + table[i][j-1]);
                table[i][j] = res;
            }
        }
        return table[1][n];    
        }


};
