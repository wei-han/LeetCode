class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res(A.size());
        for(int i = 0; i<A.size(); i++){
            for(int j = 0; j<B.size();j++){
                if(B[j]==A[i]) res[i] = j;
            }
        }
        return res;
    }
};
