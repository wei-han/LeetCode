class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> item;
        vector<vector<string>> ans;
        create(s, 0, item, ans);
        return ans;
        
    }
    
    void create(string s, int begin, vector<string> item, vector<vector<string>> &ans)
    {
        if(begin == s.length())
        {
            ans.push_back(item);
            return;
        }
        
        for(int i = begin; i < s.length(); i++)
        {
            int left = begin, right = i;
            while(left<right&&s[left]==s[right]) 
            {
                left++;
                right--;
            }
            if(left>=right)
            {
                item.push_back(s.substr(begin, i-begin+1));
                create(s, i+1, item, ans);
                item.pop_back();
            }
        }
    }
};
