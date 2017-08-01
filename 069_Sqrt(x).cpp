class Solution {
public:
    int mySqrt(int x) {
        
        for(long long i = 0;; i++)
        {
            if(i*i >x)
                return i-1;
        }
    }
};

//newton method!!
class Solution{
public:
int sqrt(int x){
    long r = x;
    while (r*r > x)
        r = (r + x/r) / 2;
    return r;
    }
};
