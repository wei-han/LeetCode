class Solution {
public:
    bool isHappy(int n) {
        unordered_map <int, bool> check;
        while( n != 1)
        {
            if(check.find(n) != check.end()) return false;
            check[n] = true;
            
            n = getSum(n);
        }
        return true;
    }
    
    int getSum(int n)
    {
        int sum=0;
        while(n){
            int remainder = n % 10;
            sum += remainder*remainder;
            n = n / 10;
        }

        return sum;
    }
};
