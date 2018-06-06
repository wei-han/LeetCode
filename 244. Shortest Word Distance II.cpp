class WordDistance {
public:
    WordDistance(vector<string> words) {
        for(int i=0; i<words.size(); i++){
            hash[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int res = INT_MAX;
        int i = 0, j = 0;
        while(i<hash[word1].size() && j<hash[word2].size()){
            res = min(res, abs(hash[word1][i] - hash[word2][j]));
            hash[word1][i] < hash[word2][j] ? i++: j++;
        }
        return res;
    }
    
    unordered_map<string, vector<int>> hash;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
