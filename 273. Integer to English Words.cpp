class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        return int_str(num).substr(1);
    }
private:

    
    string int_str(int n){
        string b20[]= {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine",                          "Ten","Eleven","Twelve","Thirteen", "Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string b100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        if(n>=1000000000){
            return int_str(n/1000000000)+ " Billion" + int_str(n%1000000000);
        }
        else if(n>=1000000){
            return int_str(n/1000000) + " Million" + int_str(n%1000000);
        }
        else if(n>=1000){
            return int_str(n/1000) + " Thousand" +int_str(n%1000);
        }
        else if(n>=100){
            return int_str(n/100) + " Hundred" + int_str(n%100);
        }
        else if(n>=20){
            return " " + b100[n/10-2] + int_str(n%10);
        }
        else if(n>=1){
            return " " + b20[n-1];
        }
        else {
            return "";
        }
    }
};
