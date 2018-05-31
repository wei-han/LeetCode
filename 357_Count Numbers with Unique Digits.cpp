class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> temp(11);
        int pre = 9;
        temp[1] = 10;
        temp[0] = 1;
        for(int i = 2; i<=10 ; i++){
            pre *= (11-i);
            temp[i] = pre + temp[i-1];
            if(i>n) break;
        }
        if(n<=10) return temp[n];
        else return temp[10];
    }
};
