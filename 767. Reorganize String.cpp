class Solution {
public:
    string reorganizeString(string S) {
        int len = S.size();
        vector<int> map(26);
        for(char c: S) map[c-'a']++;
        vector<pair<int, char>> sorted;
        for(int i = 0; i<26; i++){
            if(map[i]>0) sorted.push_back({map[i],'a'+i});
            if(map[i]>(len+1)/2) return "";
        }
        sort(sorted.rbegin(), sorted.rend());
        string str;
        for(auto p: sorted){
            str += string(p.first, p.second);
        }
        string ans;
        for(int i = 0, j = (len+1)/2; i<(len+1)/2 ;i++, j++){
            ans+=str[i];
            if(j<len) ans+=str[j];
        }
        return ans;
    }
};
