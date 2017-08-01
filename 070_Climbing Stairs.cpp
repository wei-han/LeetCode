class Solution {
public:
    int climbStairs(int n) {
        int num1 = 1, num2 = 2, num3;
        if(n == 1) return 1;
        if(n == 2) return 2;
        while(n > 2)
        {
            num3 = num2 + num1;
            num1 = num2;
            num2 = num3;
            n--;
        }
        return num3;
        
    }

};
