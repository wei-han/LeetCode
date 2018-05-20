class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i<=num.size()/2; i++){
            for(int j = 1; max(i,j) <= num.size()-i-j; j++){
                if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
            }
        }
        return false;
    }
    
private:
    bool check(string num1, string num2, string nums){
        if((num1.size()>1 && num1[0] =='0')|| (num2.size()>1 && num2[0]=='0')) return false;
        
        string sum = add(num1, num2);
        if(sum.size()>nums.size() || sum != nums.substr(0,sum.size())) return false;
        if(sum == nums) return true;
        return check(num2, sum, nums.substr(sum.size()));
        
    }
    
    string add(string x, string y){
        long x_int = stoi(x);
        long y_int = stoi(y);
        return to_string(x_int + y_int);
    }
};
