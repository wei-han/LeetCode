class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int> (n,0));
        int left=0, right=n-1, top=0, bot=n-1, i=1;
        while(true)
        {
            for(int col = left; col <= right; col++)
            {
                matrix[top][col] = i++;
            }
            if(++top >bot) break;

            
            for(int row = top; row <= bot; row++)
            {
                matrix[row][right] = i++;
            }
            if(--right < left) break;

            
            for(int col = right; col >= left; col--)
            {
                matrix[bot][col] = i++;
            }
            if(--bot < top) break;

            
            for(int row = bot; row >= top; row--)
            {
                matrix[row][left] = i++;
            }
            if(++left > right) break;

        }
    
        
        return matrix;
        
    }
};
