class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0 || (dividend ==INT_MIN && divisor ==-1) ) return INT_MAX;
        
        int sign = (dividend<0)^(divisor<0)?-1:1;
        unsigned long dvd = labs(dividend);
        unsigned long dvs = labs(divisor);
        int res = 0;
        while(dvd >= dvs){
            unsigned long temp = dvs;
            unsigned long times = 1;
            
            while(dvd >= (temp<<1)){
                temp<<=1;
                times<<=1;
            }
            dvd-=temp;
            res += times;
        }
        
        return sign==1 ?res:-res;
    }
};
