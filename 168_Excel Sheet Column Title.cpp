class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        char temp;
        
        while(n)
        {
            n--;
            temp = 'A' + n % 26;
            ans = temp + ans;
            n = n/26;
        }
        return ans;
    }
};
