class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int total = words.size();
        if(total<=0) return {};
        int len = words[0].size();
        unordered_map<string,int> table, check;
        vector<int> res;
        for (string word : words) table[word]++;
        
        for(int i = 0; i<s.size()-total*len+1;i++){
            int count = 0;
            for(;count<total; count++){
                string temp = s.substr(i+count*len,len);
                if(table.find(temp) != table.end()){
                    check[temp]++;
                    if(check[temp]>table[temp]) break;
                }
                else break;
            }
            if(count==total) res.push_back(i);
            check.clear();
        }
        return res;
    }
};
