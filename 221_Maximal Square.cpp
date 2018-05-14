class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.size() > 0 ? matrix[0].size() : 0;
        int table[m+1][n+1];
        for(int i = 0; i<m+1; i++){
            for(int j = 0; j<n+1; j++){
                table[i][j] = 0;
            }
        }
        int res = 0;
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(matrix[i-1][j-1] == '1'){
                    table[i][j] = min(table[i-1][j-1], min(table[i][j-1], table[i-1][j])) + 1;
                }
                res = max(table[i][j], res);
            }
        }
        return res*res;
        
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix.size() > 0 ? matrix[0].size() : 0;
        vector<int> table(n+1,0);
        
        int res = 0;
        
        for(int i = 1; i<m+1; i++){
            int temp = 0;
            for(int j = 1; j<n+1; j++){
                swap(temp, table[j]);
                if(matrix[i-1][j-1] == '1'){
                    table[j] = min(temp, min(table[j-1], table[j])) + 1;
                } else{
                    table[j] = 0;
                }
                res = max(table[j], res);
            }
        }
        return res*res;        
    }
};
