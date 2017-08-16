class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) return 0;
        stack<int> temp;
        
        for(int i = 0; i<tokens.size(); i++)
        {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                temp.push(atoi(tokens[i].c_str()));
            else
            {
                int o2 = temp.top();
                temp.pop();
                int o1 = temp.top();
                temp.pop();
                int o3;
                switch(tokens[i][0])//change the string to char
                {
                    case '+':
                        o3 = o1 + o2;
                        break;
                    case '-':
                        o3 = o1 - o2;
                        break;
                    case '*':
                        o3 = o1 * o2;
                        break;
                    case '/':
                        o3 = o1 / o2;
                        break;
                    default:
                        ;                        
                }
                temp.push(o3);                
            }
        }
        return temp.top();
    }
};
