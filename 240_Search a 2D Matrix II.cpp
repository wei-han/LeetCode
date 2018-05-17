class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0||matrix[0].size() == 0) return false;
        for(int i = 0; i<matrix.size() && matrix[i][0]<= target;i++){
            for(int j = 0; j<matrix[i].size()&&matrix[i][j]<=target; j++){
                if(matrix[i][j] == target) return true;                
            }
        }
        return false;
    }
};

//o(m+n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size() == 0) return false;
        
        int i = 0;
        int j = matrix[0].size()-1;
        
        while(i<matrix.size()&& j>=0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};
