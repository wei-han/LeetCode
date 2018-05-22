class Solution {
public:
    char findTheDifference(string s, string t) {
        char res=0;
        for(char item: s){
            res ^= item;
        }
        for(char item: t){
            res ^= item;
        }        
        return res;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> hash;
        for(char c:s){
            if(hash.find(c) != hash.end()) hash[c]++;
            hash.insert(make_pair(c, 1));
        }
        
        for(char c:t){
            if(hash.find(c)!= hash.end() &&hash[c]!=0){
                hash[c]--;
            }
            else{
                return c;
            }
        }
    }
};
