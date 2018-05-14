class Solution {
public:
    int integerBreak(int n) {
        vector<int> product(n+1);
        product[1] = 1;
        
        for(int i = 2; i<=n; i++ ){
            int temp = 0;
            for(int j = 1; j < i; j++){
                temp = max(temp, max(j, product[j])*max(i-j, product[i-j]));
            }
            product[i] = temp;
        }
        return product[n];
    }
};
