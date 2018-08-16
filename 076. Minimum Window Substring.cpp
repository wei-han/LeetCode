class Solution {
public:
    string minWindow(string s, string t) {
        int begin = 0, end = 0, count = 0, head = 0, dist = INT_MAX;
        vector<int> hash(128,0);
        for(char c: t) hash[c]++;
        while(end<s.size()){
            if(hash[s[end++]]-->0) count++;
            while(count==t.size()){
                if(end-begin<dist){
                    dist = end-begin;
                    head = begin;
                }
                if(hash[s[begin++]]++==0) count--;
            }
        }
        return dist<INT_MAX ? s.substr(head, dist):"";
    }
};
