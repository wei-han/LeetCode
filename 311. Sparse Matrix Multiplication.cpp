class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int am = A.size(), an = A[0].size();
        int bm = B.size(), bn = B[0].size();
         vector<vector<int>> res(am,vector<int>(bn,0));

        vector<vector<int>> az(am);
        vector<vector<int>> bz(bn);
        
        for(int i=0; i<am; i++)
            for(int j=0; j<an; j++)
                if(A[i][j]) az[i].push_back(j);
                
        for(int i = 0; i<bn; i++)
            for(int j = 0; j<bm; j++)
                if(B[j][i]) bz[i].push_back(j);
        
        for(int i = 0; i<am; i++){
            for(int j = 0; j<bn; j++){
                int m =0, n =0;
                while(m<az[i].size() && n<bz[j].size()){
                    if(az[i][m] == bz[j][n]){
                        res[i][j] += (A[i][az[i][m++]]*B[bz[j][n++]][j]);
                    }
                    else if(az[i][m] < bz[j][n]) m++;
                    else n++;
                }
            }
        }
        return res;
    }
};
