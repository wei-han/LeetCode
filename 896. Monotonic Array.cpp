class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool inc = true, dec = true;
        for(int i = 0; i<A.size()-1; i++){
            inc &= (A[i]<=A[i+1]);
            dec &= (A[i]>=A[i+1]);
        }
        return inc||dec;
    }
};
