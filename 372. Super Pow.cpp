//ab%k = (a%k*b%k)%k;
class Solution {
public:
    const int base = 1337;
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int first = b.back();
        b.pop_back();
        return pow(superPow(a,b), 10)*pow(a,first)%base;
    }
    
    int pow(int a, int k){
        int result = 1;
        for(int i = 0; i<k; i++){
            result = (result*(a%base))%base;
        }
        return result;
    }
};
