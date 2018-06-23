class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        int len = s.size();
        
        for(int i = 0; i<len; i++){
            for(int j = 0; i-j>=0 && i+j<len && s[i-j]==s[i+j]; j++) res++;
            for(int j = 0; i-1-j>=0 && i+j<len && s[i-1-j] == s[i+j]; j++) res++;
        }
        
        return res;
    }
};
