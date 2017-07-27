class Solution {
public:
    string addBinary(string a, string b) {
        int a_len = a.length();
        int b_len = b.length();
        string ans;
        
        int carry = 0;
        
        for(int i = 0; i < min(a_len, b_len); i++)
        {
            int sum = (a.at(a_len - 1 - i) - '0') + (b.at(b_len - 1 - i) - '0') + carry;
            int temp = sum%2;
            carry = sum/2;
            ans = to_string(temp) + ans;
        }
        
        for( int i = min(a_len, b_len); i < max(a_len, b_len); i++ )
        {
            int sum = ((a_len > b_len? a.at(a_len - 1 - i):  b.at(b_len - 1 - i)) - '0') + carry;
            int temp = sum%2;
            carry = sum/2;
            ans = to_string(temp) + ans;
        }
        if(carry) ans = to_string(carry) + ans;
        
        return ans;
        
        
    }
};


class Solution {
public:
    string addBinary(string a, string b) {
        int a_l = a.length() - 1;
        int b_l = b.length() - 1;
        string ans;
        
        int sum = 0;
        
        while(a_l >= 0 || b_l >= 0 || sum==1)
        {
            sum += (a_l >= 0 ? a.at(a_l): '0') - '0';
            a_l--;
            sum += (b_l >= 0 ? b.at(b_l): '0') - '0';
            b_l--;
            ans = char(sum%2 + '0') + ans;
            sum = sum/2;          
        }

        
        return ans;
        
        
    }
};
