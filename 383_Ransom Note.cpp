class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>hash;
        for(char c:magazine){
            hash[c]++;
        }
        
        for(char c: ransomNote){
            if(hash.find(c)!=hash.end() && hash[c]>0){
                hash[c]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
