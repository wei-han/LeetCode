class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>>hash;
        for(string str: strings){
            hash[encode(str)].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto item:hash){
            vector<string> group = item.second;
            sort(group.begin(), group.end());
            ans.push_back(group);
        }
        return ans;
    }
    
    string encode(string str){
        int diff;
        string res;
        for(int i = 1; i<str.size(); i++){
            diff = str[i]-str[i-1];
            diff = diff>=0? diff: diff+26;
            res += 'a'+diff;
        }
        return res;
    }
};
