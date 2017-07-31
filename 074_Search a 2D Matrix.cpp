//search row then column. log(m*n) = logm + logn .......
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        
        int lo = 0, hi = matrix.size() - 1;
        //int i=0;
        
        while (lo < hi)
        {
            int mid = (lo + hi)/2 + 1;
            if(matrix[mid][0] > target) hi = mid -1;
            else lo = mid;
        }
        int row = lo;
        //if(i==0) return false;
        
        lo = 0;
        hi = matrix[0].size( ) - 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) lo = mid+1;
            else hi = mid - 1;
        }
        
        return false;
     
    }
};
