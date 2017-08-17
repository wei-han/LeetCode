class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int temp;
        for(int i = 0; i < s.length(); i++)
        {
            temp = s.at(i) - 'A' + 1;
            res = res* 26 + temp;
        }
        return res;
    }
};
