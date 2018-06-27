class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int len = str.size();
        int i = 0, j = 0;
        while(j<len){
            i = j;
            while(j<len && str[j]!=' ')j++;
            reverse(str.begin()+i, str.begin()+j);
            j++;
        }
    }
};
