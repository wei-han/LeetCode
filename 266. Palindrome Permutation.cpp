class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> hash;
        for(char c : s){
            hash[c] +=1;
        }
        int odd = 0;
        for(auto pair: hash){
            if(pair.second%2==1) odd++;
            if(odd>1) return false;
        }
        return true;
    }
};
