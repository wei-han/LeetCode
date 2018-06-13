class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int>hash;
        for(char c: J){
            hash[c] = 1;
        }
        int count=0;
        for(char c: S){
            if(hash.find(c)!=hash.end()) count++;
        }
        
        return count;
    }
};
