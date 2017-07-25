class Solution {
public:
    double myPow(double x, int n) {
                unsigned long p;

        if(n < 0)
        {
            x = 1/x;
            p = -n;
        }
        else p = n;
        
        double ans = 1;
        
        while(p) //use bitwise method to implement the exponent!
        {
            if(p & 1) ans *= x;
            x *= x;
            p = p>>1;
        }
        return ans;
        
    }
};
