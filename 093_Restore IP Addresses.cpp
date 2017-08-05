class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string item;
        vector<string> ans;
        for(int a = 1; a<=3; a++)
            for(int b = 1; b<=3; b++)
                for(int c = 1; c<=3; c++)
                    for(int d = 1; d<=3; d++)
                    {
                        if(a+b+c+d == s.length())
                        {
                            int first = stoi(s.substr(0, a));
                            int second = stoi(s.substr(a, b));
                            int third = stoi(s.substr(a+b, c));
                            int fourth = stoi(s.substr(a+b+c, d));
                            if(first<=255 && second<=255 && third<=255 && fourth<=255)
                            {
                                if((item = to_string(first)+'.'+to_string(second)+'.'+to_string(third)+'.'+to_string(fourth)).length()==s.length()+3)
                                {
                                    ans.push_back(item);
                                }
                            }
                            
                        }
                    } 
        return ans;
    }
};


//dfs method
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string item;
        dfs(s, 0, 0, item, ans);
        return ans;
        
    }
    void dfs(string s, int start, int step, string item, vector<string> &ans)
    {
        if(step == 4 && start == s.length())
        {
            item = item.substr(0, s.length()+3);
            ans.push_back(item);
            return;
        }
        if(s.length()-start > (4-step)*3) return;
        if(s.length()-start < (4-step)) return;
        int num=0;
        for(int i = start; i<start+4; i++)
        {
            num = num*10 + (s[i] -'0');
            if(num<=255)
            {
                item = item+s[i];
                dfs(s, i+1, step+1, item+'.', ans);
            }
            if(num==0) break;
        }
    }
};
