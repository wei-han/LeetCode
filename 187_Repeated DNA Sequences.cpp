class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> hash;
        vector<string> ans;
        for(int i = 9; i < s.length(); i++){
            string temp = s.substr(i-9, 10);
            unordered_map<string, bool>::iterator it = hash.find(temp);
            if( it == hash.end()){
                hash[temp] = true;
            }
            else if (it->second){
                ans.push_back(temp);
                it->second = false;
            }
        }
        return ans;
        
    }
};


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, bool> hash;
        vector<string> ans;
        int len = s.length();
        for(int i = 0; i < len-9; i++) // s.length() is size_t, unsigned int type. It cannot be compared with int.
        {
            string temp = s.substr(i, 10);
            unordered_map<string, bool>::iterator it = hash.find(temp);
            if( it == hash.end()){
                hash(temp) = true;
            }
            else if (it->second){
                ans.push_back(temp);
                it->second = false;
            }
        }
        return ans;
        
    }
};
