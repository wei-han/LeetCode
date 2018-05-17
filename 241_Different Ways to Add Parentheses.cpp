class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i = 0; i<input.size(); i++){
            char c= input[i];
            if(ispunct(c)){
                for(int a: diffWaysToCompute(input.substr(0,i))){
                    for(int b: diffWaysToCompute(input.substr(i+1))){
                        if(c == '+') res.push_back(a+b);
                        if(c == '-') res.push_back(a-b);
                        if(c == '*') res.push_back(a*b);
                    }
                }
            }
        }
        if(res.size() == 0) res.push_back(stoi(input));
        return res;
    }
};
