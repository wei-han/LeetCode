class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i = 1; i<=s.size(); i++){
            for(int j = i-1; j>=0; j--){
                if(dp[j]){
                    string temp = s.substr(j, i-j);
                    for(string item: wordDict){
                        if(item == temp) dp[i] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
