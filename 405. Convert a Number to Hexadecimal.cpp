class Solution {
public:
    string toHex(int num) {
        if(num==0) return "0";
        string hex = "0123456789abcdef";
        string res ="";
        int count = 0;
        while(num&&count<8){
            res = hex[num & 0xf] +res;
            num>>=4;
            count++;
        }
        return res;
    }
};
