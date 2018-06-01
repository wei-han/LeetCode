class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y) return false;
        if(x==z|| y==z) return true;
        return z%__gcd(x,y)==0;
    }
};
