class Solution {
public:
    int longestPalindrome(string s) {
        int odd = 0;
        for(char c = 'A'; c<='z'; c++ ){
            odd += count(s.begin(), s.end(), c) &1;
        }
        
        return s.size() - odd +  ((odd>0) ? 1:0);
    }
};
