class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        vector<int> bytes(words.size(), 0);
        for(int i = 0; i<words.size(); i++){
            for(int j = 0; j<words[i].size(); j++){
                bytes[i] |= 1<< (words[i][j]-'a');
            }
        }
        
        for(int i = 0; i<bytes.size(); i++){
            for(int j = i+1; j<bytes.size(); j++){
                if((bytes[i]&bytes[j]) ==0) {
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};
