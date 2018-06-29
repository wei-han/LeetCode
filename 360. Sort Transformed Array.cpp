class Solution {
    int quad(int a, int b, int c, int x){
        return a*x*x+b*x+c;
    }
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int len=nums.size();
        int i = 0, j = len-1;
        vector<int> res(len);
        int start = a>=0? len-1:0;
        while(i<=j){
            if(a>=0){
                res[start--] = quad(a,b,c,nums[i])>quad(a,b,c,nums[j])? quad(a,b,c,nums[i++]):quad(a,b,c,nums[j--]);
            }else{
                res[start++] = quad(a,b,c,nums[i])<quad(a,b,c,nums[j])? quad(a,b,c,nums[i++]):quad(a,b,c,nums[j--]);
            }                
        }
        return res;
    }
};
