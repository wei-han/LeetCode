class Solution {
public:
    int firstUniqChar(string s) {
        int freq[256]={0};
        for(char item:s){
            freq[item]++;
        }
        
        for(int i = 0; i<s.size(); i++){
            if(freq[s[i]] == 1) return i;
        }
        return -1;
    }
};
