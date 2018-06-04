class Solution {
public:
    int findNthDigit(int n) {
        long base = 9;
        int digits = 1;
        int num = 1;
        
        while(n - base*digits > 0){
            n -= base*digits;
            digits++;
            base *=10;
            num*=10;
        }

        num += (n-1)/digits;
        
        string res = to_string(num);
        return res[(n-1)%digits] - '0';
    }
};

//exceeds the time limit
class Solution {
public:
    int findNthDigit(int n) {
        string number ="";
        int i = 1;
        while(number.size() < n){
            number = number + to_string(i);
            i++;
        }
        return number[n-1] - '0';
    }
};
