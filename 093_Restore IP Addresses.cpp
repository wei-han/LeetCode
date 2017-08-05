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



class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
    }
    
    void solve(string &s, string item, vector<string> ans)
    {
        if(item.size() == s.size()+3)
        {
            ans.push_back(item);
            return;
        }
        
        for(int i = begin; i < s.length(); i++)
        {
            if(int temp = stoi(s.c_str(), , ))
        }
    }
};
