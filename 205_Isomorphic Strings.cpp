class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char to[256] = {0}, from[256] = {0};
        int len = s.size();
        
        for(int i = 0; i < s.size(); i++){
            if(to[s[i]] != 0 && to[s[i]] != t[i]) return false;
            else to[s[i]] = t[i];
            
            if(from[t[i]] !=0 && from[t[i]] != s[i]) return false;
            else from[t[i]] = s[i];
         }
        return true;
    }
};
