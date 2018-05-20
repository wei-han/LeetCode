class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream buf(str);
        istream_iterator<string> beg(buf), end;
        vector<string> tokens(beg, end);
        
        unordered_map<char, string> to;
        unordered_map<string, char> from;
        if(tokens.size() != pattern.size()) return false;
        for(int i = 0; i<pattern.size(); i++){
            if(to.find(pattern[i]) != to.end() && to[pattern[i]]!=tokens[i]) return false;
            else to.insert(make_pair(pattern[i],tokens[i]));
            
            if(from.find(tokens[i]) != from.end() && from[tokens[i]]!=pattern[i]) return false;
            else from.insert(make_pair(tokens[i], pattern[i]));
        }
        return true;
    }
};
