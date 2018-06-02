class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int len = A.size();
        if(len<3) return 0;
        vector<int> res(len, 0);
        int ans=0;
        for(int i = 2; i<len; i++){
            if((A[i]-A[i-1]) == (A[i-1]-A[i-2])) {
                res[i] = res[i-1] +1;
            }
            ans += res[i];
        }
        return ans;        
    }
};
