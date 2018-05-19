class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        int b = 0;
        unordered_map<char, int> hash;
        for(int i = 0; i<secret.size(); i++){
            if(secret[i] == guess[i]) a++;
            auto it = hash.find(secret[i]);
            if(it==hash.end()) hash.insert(make_pair(secret[i], 1));
            else it->second++;
        }
        
        for(int i = 0; i < guess.size(); i++){
            auto itr = hash.find(guess[i]);
            if(itr !=hash.end() && itr->second >0){
                b++;
                itr->second--;
            }
        }
        return to_string(a) + "A" + to_string(b-a) + "B";        
    }
};
