class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        while (num>0){
            num -= i;
            i+=2;
        }
        
        return num==0;
    }
};

//naive solution
class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i = 1; i<= ceil(num/2.0); i++){
            if((i*i) ==num) return true;
        }
        return false;
    }
};
