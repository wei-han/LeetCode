class Solution {
public:
    string nextClosestTime(string time) {
        int min[] = {600, 60, 10, 1};
        size_t colon = time.find(':');
        int cur = stoi(time.substr(0, colon))*60 + stoi(time.substr(colon+1, 2));
        
        string ans = "0000";
        
        for(int i = 1, d = 0; i<=24*60 && d<4; i++){
            int next = (cur+i)%(24*60);
            for(d=0;d<4;d++){
                ans[d] = '0' + next/min[d];
                next %= min[d];
                if(time.find(ans[d]) == string::npos) break;
            }
        }
        return ans.substr(0,2) + ":" + ans.substr(2,2);
    }
};
