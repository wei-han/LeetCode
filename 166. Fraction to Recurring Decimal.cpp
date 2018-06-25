//use remainder as indication of recurring, not the quetient;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if(numerator==0) return "0";
        if(numerator<0 ^ denominator<0) res += '-';
        long long num = numerator<0? -1* (long) numerator : (long)numerator;
        long long den = denominator<0? -1* (long) denominator : (long)denominator;
        
        res+=to_string(num/den);
        long long rem = num%den;
        if(!rem) return res;
        res+=".";
        rem *= 10;
        
        unordered_map<long, long> hash;
        while(rem){
            long long que = rem/den;
            if(hash.find(rem)!=hash.end()){
                res.insert(hash[rem], 1, '(');
                res+=")";
                break;
            }
            hash[rem] = res.size();
            res+=to_string(que);
            rem = (rem%den)*10;    
        }        
        return res;
     }
};
