class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i = 0; i<words.size(); i++){
            if(check(words[i], pattern)) res.push_back(words[i]);
        }
        return res;
    }
private:
    bool check(string word, string pattern){
        if(word.size()!=pattern.size()) return false;
        unordered_map<char, char>to, from;
        for(int i = 0; i<word.size();i++){
            if(to.find(word[i])!=to.end() && to[word[i]]!=pattern[i]) return false;
            else to.insert({word[i], pattern[i]});
            
            if(from.find(pattern[i])!= from.end() && from[pattern[i]]!=word[i]) return false;
            else from.insert({pattern[i], word[i]});
        }
        return true;
    }
};
