class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long long k = 5; //
        
        while(k <= n)
        {
            ans += n/k;
            k *= 5;
                
        }
        return ans;
    }
};
