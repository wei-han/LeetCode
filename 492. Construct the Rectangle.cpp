class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = ceil(sqrt(area));
        for(int i = 0; l+i<= area; i++){
            if((l+i)*(area/(l+i)) == area) return {l+i,area/(l+i)};
        }        
    }
};
