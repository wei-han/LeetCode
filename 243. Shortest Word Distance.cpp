class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int pos1 =-1, pos2 = -1;
        int res = words.size();
        for(auto it = words.begin(); it!=words.end(); it++){
            if( *it == word1) pos1 = it-words.begin();
            else if( *it == word2) pos2 = it-words.begin();
            else continue;
            
            if(pos1>-1 && pos2>-1 && abs(pos1 - pos2)<res) res = abs(pos1-pos2);
        }
        return res;
    }
};
