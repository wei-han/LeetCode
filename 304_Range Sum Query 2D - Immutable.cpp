class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        vector<int> zero(1,0);
        for(int i = 0; i<matrix.size(); i++){
            temp.push_back(zero);
        }
        
        for(int i = 0; i<matrix.size();i++){
            int sum = 0;
            for(int j = 0; j<matrix[i].size(); j++){
                sum+=matrix[i][j];
                temp[i].push_back(sum);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i<= row2; i++){
            sum+= (temp[i][col2+1]-temp[i][col1]);
        }
        return sum;
    }

private:
    vector<vector<int>> temp;
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
