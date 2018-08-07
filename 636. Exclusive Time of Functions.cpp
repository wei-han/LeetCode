struct Log{
    int id;
    string status;
    int time;
};
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n,0);
        stack<Log> stk;
        for(string item: logs){
            stringstream ss(item);
            string t1, t2, t3;
            getline(ss, t1, ':');
            getline(ss, t2, ':');
            getline(ss, t3, ':');
            Log temp = {stoi(t1), t2, stoi(t3)};
            
            if(temp.status == "start") stk.push(temp);
            else{
                int add = temp.time - stk.top().time + 1;
                res[stk.top().id] += add;
                stk.pop();
                if(!stk.empty())
                    res[stk.top().id] -= add;
            }
        }
        return res;
    }
};
