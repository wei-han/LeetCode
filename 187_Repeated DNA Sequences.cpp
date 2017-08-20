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
        
        for(int i = 0; i < s.length()-9; i++) // when the length is less than 9 , error thrown out.{
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
