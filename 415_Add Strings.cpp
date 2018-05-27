class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1;
        int carry = 0;
        string res = "";        
        
        while(i>=0 || j>=0 || carry){
            int sum = 0;
            sum+= i<0?0: (num1[i--]-'0');
            sum+= j<0?0: (num2[j--]-'0');            
            sum+=carry;
            carry = sum/10;
            res = to_string(sum%10) + res;            
        }        
        return res;
    }
};

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i= num1.size()-1, j = num2.size()-1;
        string res ="";
        int dig1=0, dig2=0, carry = 0;
        
        while(i>=0 && j>=0){
            dig1 = num1[i--] - '0';
            dig2 = num2[j--] - '0';
            res = to_string((dig1 + dig2 + carry)%10) + res;
            carry = (dig1+dig2 + carry ) /10;            
        }
        while(i>=0){
            dig1 = num1[i--] - '0';
            res = to_string((dig1 + carry)%10) + res;
            carry = (dig1 + carry)/10;
        }
        
        while(j>=0){
            dig2 = num2[j--] - '0';
            res = to_string((dig2 + carry)%10) + res;
            carry = (dig2 + carry)/10;
        }
        while(carry>0){
            res = to_string(carry)+res;
            carry = carry/10;
        }
        
        return res;
        
    }
};
